#include "signalprocess.h"
#include"fftw3.h"
#include<qdebug.h>
#include<math.h>

SignalProcess::SignalProcess()
{

}

void SignalProcess::fft(int N, double IN[],double OUT[][2])
{
    int i;
    fftw_complex *din,*out;
    fftw_plan p;

    din  = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    if((din==NULL)||(out==NULL))
    {
        qDebug()<<"Error:insufficient available memory\n";
    }
    else
    {
        for(i=0; i<N; i++)/*²âÊÔÊý¾Ý*/
        {
            din[i][0] = IN[i];
            din[i][1] = 0;
        }
    }
    p = fftw_plan_dft_1d(N, din, out, FFTW_FORWARD,FFTW_ESTIMATE);
    fftw_execute(p); /* repeat as needed */
    fftw_destroy_plan(p);
    fftw_cleanup();
    if(din!=NULL) fftw_free(din);
    if(out!=NULL) fftw_free(out);

    /*
    for(i=0;i<N;i++)
        qDebug()<<din[i][0]<<"  "<<din[i][1];
    qDebug()<<endl;
    for(i=0;i<N;i++)
        qDebug()<<out[i][0]<<"  "<<out[i][1];
    */
    for(i=0;i<N;i++)
        OUT[i][0]=out[i][0],OUT[i][1]=out[i][1];
}

void SignalProcess::fft_Amp_phase(int N, double OUT[][2], double Amp[], double phase[])
{
    int i;
    for(i=0;i<N;i++)
    {
        Amp[i]=sqrt(pow(OUT[i][0],2)+pow(OUT[i][1],2));
        phase[i]=atan2(OUT[i][1],OUT[i][0]);
    }
}

void SignalProcess::power_spectrum (int N, double Amp[], double power[])
{
    int i;
    for(i=0;i<N;i++)
        power[i]=Amp[i]*Amp[i]/N;
}
