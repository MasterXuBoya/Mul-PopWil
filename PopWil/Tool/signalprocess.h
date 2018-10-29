#ifndef SIGNALPROCESS_H
#define SIGNALPROCESS_H

class SignalProcess
{
public:
    SignalProcess();
    //calculate the DFT of IN[] using FFT Algrithm,return complex array
    void fft(int N,double IN[],double OUT[][2]);
    //given a complex array,calculating the Amp and phase
    void fft_Amp_phase(int N,double OUT[][2],double Amp[],double phase[]);
    //return the power spectrum
    void power_spectrum(int N,double Amp[],double power[]);
};

#endif // SIGNALPROCESS_H
