#include "signalprocess.h"
#include"fftw3.h"
#include<qdebug.h>
#include<math.h>

#define EARTHMAXDATACNT 10000

SignalProcess::SignalProcess(){
}

void SignalProcess::fft(int N, double input[], double output[][2]){
    int i;
    fftw_complex *din=NULL,*out=NULL;
    fftw_plan p;
    qDebug()<<"fft start:  N="<<N;
    din  = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    if((din==NULL)||(out==NULL))
        qDebug()<<"Error:insufficient available memory\n";
    else{
        for(i=0; i<N; i++){
            din[i][0] = input[i];
            din[i][1] = 0;
        }
    }
    p = fftw_plan_dft_1d(N, din, out, FFTW_FORWARD,FFTW_ESTIMATE);
    fftw_execute(p); /* repeat as needed */
    for(i=0;i<N;i++){//一定要在此处对output进行赋值，否则程序会崩溃，不能在destroy和free之后
        output[i][0]=out[i][0];
        output[i][1]=out[i][1];
    }
    //    for(i=0;i<N;i++)
    //        qDebug()<<i<<"  "<<din[i][0]<<"  "<<din[i][1];
    //    qDebug()<<"din has been print out"<<endl;
    //    for(i=0;i<N;i++)
    //        qDebug()<<out[i][0]<<"  "<<out[i][1];
    fftw_destroy_plan(p);
    fftw_cleanup();
    if(din!=NULL) fftw_free(din);
    if(out!=NULL) fftw_free(out);
    qDebug()<<"fft end";
}

void SignalProcess::ifft(int N, double input[][2], double output[]){
    int i;
    fftw_complex *din,*out;
    fftw_plan p;
    qDebug()<<"ifft start";
    din  = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    if((din==NULL)||(out==NULL))
        qDebug()<<"Error:insufficient available memory\n";
    else{
        for(i=0; i<N; i++){
            din[i][0] = input[i][0];
            din[i][1] = input[i][1];
        }
    }
    p = fftw_plan_dft_1d(N, din, out, FFTW_BACKWARD,FFTW_ESTIMATE);
    fftw_execute(p); /* repeat as needed */
    for(i=0;i<N;i++)//一定要在此处对output进行赋值，否则程序会崩溃，不能在destroy和free之后
        output[i]=out[i][0]/N;
    fftw_destroy_plan(p);
    fftw_cleanup();
    if(din!=NULL) fftw_free(din);
    if(out!=NULL) fftw_free(out);
    qDebug()<<"ifft finished";
}

void SignalProcess::fft_Amp_phase(int N, double output[][2], double Amp[], double phase[]){
    int i;
    for(i=0;i<N;i++){
        Amp[i]=sqrt(pow(output[i][0],2)+pow(output[i][1],2));
        phase[i]=atan2(output[i][1],output[i][0]);
    }
}

void SignalProcess::power_spectrum (int N, double Amp[], double power[]){
    int i;
    for(i=0;i<N;i++)
        power[i]=Amp[i]*Amp[i]/N;
}

void SignalProcess::inteFD(int &N, int fs, double X[], double Y[]){
    if(N%2==0) N--;//确保样本数是奇数个，便于处理
    if(N>10000){
        qDebug()<<"地震波数据点数过多";
        return;
    }

    double yp[EARTHMAXDATACNT][2];//地震数据不应该超过10000个
    double w[EARTHMAXDATACNT];//频率=2*pi*f
    double znew[EARTHMAXDATACNT][2];//
    fft(N,X,yp);//求出acc的ifft----->znew
    for(int i=1;i<=(N-1)/2;i++){//计算前半部分的积分结果，注意不要把0计算进去
        w[i]=2*PI*(1.0*i*fs/N);
        znew[i][0]=yp[i][1]/w[i];
        znew[i][1]=-yp[i][0]/w[i];
    }

    for(int i=(N-1)/2+1;i<N;i++){
        znew[i][0]=znew[N-i][0];
        znew[i][1]=-znew[N-i][1];
    }
    ifft(N,znew,Y);
}
//注意地震波数据从1开始，一直到N
void SignalProcess::inteFD_All(int N, int fs, double Acc[], TRefData *data){
    data->refCnt=N;
    data->dataRefSampleT=1000/fs;
    double Acc_[10000];
    for(int i=0;i<=N;i++){
        data->ARef[i]=Acc[i];
        Acc_[i]=Acc[i]*9800;
    }
    //加速度积分得到速度
    inteFD(N,fs,Acc_,data->VRef);
    for(int i=1;i<=N;i++)
        refData.VRef[i]=refData.VRef[i]-refData.VRef[0];
    refData.VRef[0]=0;
    //速度积分得到位移
    inteFD(N,fs,data->VRef,data->SRef);
    for(int i=1;i<=N;i++)
        refData.SRef[i]=refData.SRef[i]-refData.SRef[0];
    refData.SRef[0]=0;
}

double SignalProcess::AutoCorrelation(double *data, int m, int N){
     double    r= 0.0f;
     for(int i = m; i <N;i++ )
          r +=data[i] * data[i-m];
     return  r ;
}

void SignalProcess::autoXcorr_func(double *in, double *out, int lenth){
    for (int i=0;i<=lenth;i++){
        out[i]=0;
        for (int j=0;j<=i;j++)
            out[i]+=in[j]*in[lenth-1-i+j];
    }
    for (int i=lenth;i<(lenth<<1)-1;i++)
        out[i]=out[(lenth<<1)-2-i];
}

void SignalProcess::crossXcorr_func(double *x, double *y, int N, double *r){
    double sxy;
    int delay,i,j;
    for(delay = -N + 1; delay < N; delay++) {
        //Calculate the numerator
        sxy = 0;
        for(i=0; i<N; i++) {
            j = i + delay;
            if((j < 0) || (j >= N)) continue;
            else sxy += (x[i] * y[j]);
        } //Calculate the correlation series at "delay"
        r[delay + N - 1] = sxy;
    }
}

double SignalProcess::varForArray(double *x, int count)
{
    int i;
    double result=0,xAvg=0;
    for (i=0;i<count;i++)
        xAvg+=x[i];
    xAvg/=count;
    for (i=0;i<count;i++)
        result+=(x[i]-xAvg)*(x[i]-xAvg);
    return result;
}

double SignalProcess::coeff(double *x, double *y, int count){
    int i;
    double xAvg=0,yAvg=0,cov=0,result=0;
    for (i=0;i<count;i++){
        xAvg+=x[i];
        yAvg+=y[i];
    }
    xAvg/=count;yAvg/=count;
    for(i=0;i<count;i++)
        cov+=(x[i]-xAvg)*(y[i]-yAvg);
    if(varForArray(x,count)==0||varForArray(y,count)==0)
        result=-2;
    else
        result=cov/(sqrt(varForArray(x,count))*sqrt(varForArray(y,count)));
    return result;
}

void SignalProcess::lagrangeInterpolation(int n, int originSampleT, double origin[], TRefData *newData, int sampleT){
    qDebug()<<"地震波插值开始";
    int interpolationCnt=originSampleT/sampleT;//向量两个点之间的插值数量；
    //如果原来是10ms的话，插值5个点，相邻两个点之间4个点
    int i=0,j=0;
    while(i+3<n){
        double g1=origin[i];
        double g2=origin[i+1];
        double g3=origin[i+2];
        double g4=origin[i+3];
        for(double t=-1;t<2;t+=1.0/interpolationCnt){
            double c1=t*(t-1)*(t-2)/-6;
            double c2=(t+1)*(t-1)*(t-2)/2;
            double c3=(t+1)*t*(t-2)/-2;
            double c4=(t+1)*(t-1)*t/6;
            newData->ARef[j++]=c1*g1+c2*g2+c3*g3+c4*g4;
        }
        i+=3;//下面4个点
    }

    //最后剩下的几个点直接用线性插值
    while(i<n-1){
        for(int k=0;k<interpolationCnt;k++)
            newData->ARef[j++]=origin[i]+\
                    (origin[i+1]-origin[i])/interpolationCnt*k;
        i++;
    }
    newData->ARef[j++]=origin[n-1];//最后一个数据
    newData->refCnt=j;
    newData->dataRefSampleT=sampleT;
    qDebug()<<"插值结束";
}

void SignalProcess::constTest(const int &n, const double *in, double *out){
    for(int i=0;i<n;i++)
        out[i]=in[i]*in[i];
}









