#include "signalprocess.h"
#include"fftw3.h"
#include<qdebug.h>
#include<math.h>

#define EARTHMAXDATACNT 10000

SignalProcess::SignalProcess()
{

}

void SignalProcess::fft(int N, double input[], double output[][2])
{
    int i;
    fftw_complex *din=NULL,*out=NULL;
    fftw_plan p;
    qDebug()<<"fft start:N="<<N;
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
    fftw_destroy_plan(p);
    fftw_cleanup();
    if(din!=NULL) fftw_free(din);
    if(out!=NULL) fftw_free(out);

//    qDebug()<<N<<"haha";
//    for(i=0;i<N;i++)
//        qDebug()<<i<<"  "<<din[i][0]<<"  "<<din[i][1];
//    qDebug()<<endl;
    for(i=0;i<N;i++)
        qDebug()<<out[i][0]<<"  "<<out[i][1];


    for(i=0;i<N;i++){
        output[i][0]=out[i][0];
        output[i][1]=out[i][1];
    }
    qDebug()<<"fft end";
}

void SignalProcess::ifft(int N, double input[][2], double output[]){
    int i;
    fftw_complex *din,*out;
    fftw_plan p;

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
    fftw_destroy_plan(p);
    fftw_cleanup();
    if(din!=NULL) fftw_free(din);
    if(out!=NULL) fftw_free(out);


//    for(i=0;i<N;i++)
//        qDebug()<<din[i][0]<<"  "<<din[i][1];
//    qDebug()<<endl;
//    for(i=0;i<N;i++)
//        qDebug()<<out[i][0]<<"  "<<out[i][1];

    for(i=0;i<N;i++)
        output[i]=out[i][0]/N;
}

void SignalProcess::fft_Amp_phase(int N, double output[][2], double Amp[], double phase[])
{
    int i;
    for(i=0;i<N;i++)
    {
        Amp[i]=sqrt(pow(output[i][0],2)+pow(output[i][1],2));
        phase[i]=atan2(output[i][1],output[i][0]);
    }
}

void SignalProcess::power_spectrum (int N, double Amp[], double power[])
{
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
    qDebug()<<"haha";
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












