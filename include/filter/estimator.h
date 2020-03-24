#ifndef ESTIMATOR_H
#define ESTIMATOR_H


#include "filter.h"
#include "Eigen/Core"



/**
 *  order为卡尔曼滤波辨识谐波次数
 */
#include <cmath>

#define PI acos(-1)

template<int order>
class LinearKalmanEstimator {
public:
    static const int ORDER = order;
    typedef typename eigenkf::SimpleState<order * 2>  HarmonicStateType;
    typedef typename eigenkf::LinearProcessModel<1, HarmonicStateType> LinearModelType;
    typedef typename eigenkf::KalmanFilter<HarmonicStateType, LinearModelType> KFEstimatorType;

    typedef typename HarmonicStateType::VecState  HarmonicVecState;
    typedef typename LinearModelType::TransitionMat TransitionMat;
    typedef typename LinearModelType::MeasureMat MeasureMat;
    typedef typename LinearModelType::MeasureState MeasureState;

    typedef typename Eigen::Matrix<double, order, 1> AmpVecType;
    typedef typename Eigen::Matrix<double, order, 1> PhaseVecType;



    KFEstimatorType KFEstimator;
    double  fundamentalFreq;
    double  fundamentalVel;
    double  epsilon;
    AmpVecType AmpVecState;
    PhaseVecType PhaseVecState;



    LinearKalmanEstimator()
    {
    }

    LinearKalmanEstimator(double _fundFreq, double s_sigma, TransitionMat &_F, MeasureMat &_H, double p_sigma, double p_delta) :
        fundamentalFreq(_fundFreq),
        fundamentalVel(2*PI*_fundFreq),
        KFEstimator(s_sigma, _F, _H, p_sigma, p_delta),
        AmpVecState(AmpVecType::Identity()),
        PhaseVecState(PhaseVecType::Identity()),
        epsilon(1e-10)
    {
    }
    void Estimate(double measure, double dt)
    {
        //step 1. predict
        KFEstimator.predict();
        //construct MeasureMatrix
        MeasureMat H;
        for (int i = 1; i <= ORDER; i++)
        {
            H(0,2*(i-1)) = sin(i*fundamentalVel*dt);
            H(0, 2 * (i - 1) + 1) = cos(i*fundamentalVel*dt);
        }
        MeasureState z;
        z << measure;

        KFEstimator.update(z, H);
    }

//    void Estimate(double measure, double dt,int step)
//    {
//        //step 1. predict
//        KFEstimator.predict();
//        //construct MeasureMatrix
//        MeasureMat H;
//        for (int i = 1; i <= ORDER; i++)
//        {
//            H(0, 2 * (i - 1)) = sin(i*fundamentalVel*dt);
//            H(0, 2 * (i - 1) + 1) = cos(i*fundamentalVel*dt);
//        }
//        if (step % 1000 == 0) std::cout << "step :" << step << std::endl;
//        if (step % 1000 == 0) std::cout << "H matrix" << std::endl << H << std::endl << std::endl;
//        MeasureState z;
//        z << measure;
//        if (step % 1000 == 0)  std::cout << "z" << std::endl << z << std::endl << std::endl;
//        KFEstimator.update(z, H);
//        if (step % 1000 == 0)
//        {
//            std::cout << "state " << std::endl;
//            std::cout << KFEstimator.state.x << std::endl << std::endl << std::endl;
//        }
//    }

    void GetEstimateAmpPhase()
    {
        for (int k = 1; k <= ORDER; k++)
        {
            double x1 = KFEstimator.state.x(2 * (k - 1), 0);
            double x2 = KFEstimator.state.x(2 * (k - 1) + 1, 0);

            AmpVecState(k - 1, 0) = sqrt(x1*x1 + x2*x2);
            PhaseVecState(k - 1, 0) = atan(x2 / (x1+epsilon));
        }
    }


    void GenerateHarmonicWave(double dt)
    {
        GetEstimateAmpPhase();
        double s;
        for (int k = 1; k <= ORDER; k++)
        {
            double A = AmpVecState(k - 1, 0);
            double P = PhaseVecState(k - 1, 0);
            s += A*sin(fundamentalVel*dt + P);
        }
        return s;
    }
};

#endif // ESTIMATOR_H
