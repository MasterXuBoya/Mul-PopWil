#ifndef FILTER_H
#define FILTER_H

#include <stdexcept>

#include "Eigen/Core"
#include "Eigen/LU"


namespace eigenkf {
    /**
    * @brief The SimpleState class
    * 卡尔曼滤波中状态的数据结构
    */
    template<int dimension>
    class SimpleState {
    public:
        static const int DIM = dimension;       //状态向量维数
        typedef typename Eigen::Matrix<double, dimension, 1> VecState;
        typedef typename Eigen::Matrix<double, dimension, dimension> MatStateState;

        VecState x;                             //状态向量
        MatStateState covariance;               //状态估计协方差矩阵 P
        SimpleState() :
            x(VecState::Random()),
            covariance(MatStateState::Identity()) {}

        SimpleState& operator = (const SimpleState &ref)
        {
            x = ref.x;
            covariance = ref.covariance;
            return *this;
        }

        SimpleState(VecState _x, MatStateState _cov):
            x(_x),covariance(_cov)
        {
        }

        SimpleState(double sigma) :
            x(VecState::Random()*sigma),
            covariance(MatStateState::Identity()*sigma)
        {
            for (int i = 0; i < DIM; i++)
                x(i, 0) += 1.0;
        }

    };

    template<int MeasureDim, class StateType>
    class LinearProcessModel {
    public:
        static const int MEASUREDIM = MeasureDim;
        typedef typename Eigen::Matrix<double, StateType::DIM, StateType::DIM> TransitionMat;
        typedef typename Eigen::Matrix<double, StateType::DIM, StateType::DIM> ProcessNoiseCov;
        typedef typename Eigen::Matrix<double, MeasureDim, StateType::DIM> MeasureMat;
        typedef typename Eigen::Matrix<double, MeasureDim, MeasureDim> MeasureNoiseCov;
        typedef typename Eigen::Matrix<double, MeasureDim, 1> MeasureState;


        TransitionMat F;                //系统状态转移矩阵
        ProcessNoiseCov Q;              //系统状态转移噪声协方差矩阵
        MeasureMat H;                   //系统测量矩阵
        MeasureNoiseCov R;              //系统测量噪声协方差矩阵
        MeasureState residual;

        LinearProcessModel()
        {

        }

        //LinearProcessModel(const LinearProcessModel &ref)
        //{
        //	*this = ref;
        //}

        LinearProcessModel(TransitionMat &_F, MeasureMat &_H, double sigma, double delta) :
            F(_F),
            H(_H),
            Q(ProcessNoiseCov::Identity() * sigma),
            R(MeasureNoiseCov::Identity() * delta),
            residual(MeasureState::Random())
        {

        }

        LinearProcessModel&  operator =(const LinearProcessModel &ref)
        {
            this->F = ref.F;
            this->Q = ref.Q;
            this->H = ref.H;
            this->R = ref.R;
            this->residual = ref.residual;

            return *this;
        }


    };

    template<class StateType, class ProcessModelType>
    class KalmanFilter {
    public:
        typedef typename Eigen::Matrix<double, StateType::DIM, StateType::DIM> MatStateState;
        typedef typename Eigen::Matrix<double, StateType::DIM, 1> VecState;
        typedef typename Eigen::Matrix<double, StateType::DIM, ProcessModelType::MEASUREDIM> KalManGain;
        typedef typename Eigen::Matrix<double, ProcessModelType::MEASUREDIM, ProcessModelType::MEASUREDIM> SysUncertainty;
        typedef typename ProcessModelType::TransitionMat TransitionMat;
        typedef typename ProcessModelType::MeasureMat MeasureMat;
        typedef typename ProcessModelType::ProcessNoiseCov ProcessNoiseCov;
        typedef typename ProcessModelType::MeasureState MeasureState;
        StateType state;                //卡尔曼滤波的隐状态
        ProcessModelType processModel;
        KalManGain K;
        SysUncertainty S;

        KalmanFilter()
        {

        }

        KalmanFilter(StateType _s, ProcessModelType _p) :
            state(_s), processModel(_p), K(KalManGain::Random()), S(SysUncertainty::Random())
        {

        }


        KalmanFilter(double s_sigma, TransitionMat &_F, MeasureMat &_H, double p_sigma, double p_delta) :
            state(s_sigma), processModel(_F,_H,p_sigma,p_delta), K(KalManGain::Random()), S(SysUncertainty::Random())
        {

        }

        void predict()
        {
            // step 1. predict state
            // x_hat = Fx + Bu
            state.x = processModel.F * state.x;
            //step 2. predict P
            // P_hat = FPF' + Q
            state.covariance = processModel.F * state.covariance *  processModel.F.transpose() + processModel.Q;
        }

        void predict(TransitionMat F)
        {
            // step 1. predict state
            // x_hat = Fx + Bu
            state.x = F * state.x;
            //step 2. predict P
            // P_hat = FPF' + Q
            state.covariance = F * state.covariance *  F.transpose() + processModel.Q;
        }

        void predict(TransitionMat F, ProcessNoiseCov Q)
        {
            // step 1. predict state
            // x_hat = Fx + Bu
            state.x = F * state.x;
            //step 2. predict P
            // P_hat = FPF' + Q
            state.covariance = F * state.covariance *  F.transpose() + Q;
        }

        void update(MeasureState z)
        {
            //step 1. compute residual between measurement and prediction
            processModel.residual = z - processModel.H * state.x;

            //step 2. S = HPH' + R
            //project system uncertainty into measurement space
            S = processModel.H * state.covariance * processModel.H.transpose() + processModel.R;

            //step 3. K = PH'inv(S)
            //map system uncertainty into kalman gain
            K = state.covariance * processModel.H.transpose()*S.inverse();

            //step 4. x = x + Ky
            //predict new x with residual
            state.x = state.x + K * processModel.residual;


            //step 5. P = (I - KH)P(I - KH)' + KRK'
            //This is more numerically stable
            // and works for non - optimal K vs the equation
            //P = (I - KH)P usually seen in the literature.

            MatStateState I_KH = MatStateState::Identity() - K * processModel.H;
            state.covariance = I_KH * state.covariance * I_KH.transpose() + K * processModel.R * K.transpose();
        }

        void update(MeasureState z , MeasureMat H)
        {
            //step 1. compute residual between measurement and prediction
            processModel.residual = z - H * state.x;

            //step 2. S = HPH' + R
            //project system uncertainty into measurement space
            S = H * state.covariance * H.transpose() + processModel.R;

            //step 3. K = PH'inv(S)
            //map system uncertainty into kalman gain
            K = state.covariance * H.transpose()*S.inverse();
            //K = state.covariance * H.transpose()*S;
            //step 4. x = x + Ky
            //predict new x with residual
            state.x = state.x + K * processModel.residual;


            //step 5. P = (I - KH)P(I - KH)' + KRK'
            //This is more numerically stable
            // and works for non - optimal K vs the equation
            //P = (I - KH)P usually seen in the literature.

            //state.covariance = (MatStateState::Identity() - K * processModel.H)*state.covariance;

            MatStateState I_KH = MatStateState::Identity() - K * H;
            state.covariance = I_KH * state.covariance * I_KH.transpose() + K * processModel.R * K.transpose();
        }

    };

}



#endif // FILTER_H
