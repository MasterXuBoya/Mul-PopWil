#include "ToolFromMatlab.h"

ToolFromMatlab::ToolFromMatlab(){

}

ToolFromMatlab::~ToolFromMatlab(){
    EarthPreprocessTerminate();
}

void ToolFromMatlab::init(){
    //---------------------------EarthPreprocess.dll------------------------------------------------
    QLibrary lib_EarthPreprocess("EarthPreprocess.dll");
    if(lib_EarthPreprocess.load())
           qDebug()<<"-----------EarthPreprocess.dll load success-----------------";
    EarthPreprocessInitialize();

    earthPreprocess=(EARTHPREPROCESS)lib_EarthPreprocess.resolve("?EarthPreprocess@@YAXHAAVmwArray@@00ABV1@1@Z");
    if(earthPreprocess)
        qDebug()<<"-----------function earthPreprocess load success---------------";
    //---------------------------WaveResample.dll------------------------------------------------
    QLibrary lib_WaveResample("WaveResample.dll");
    if(lib_WaveResample.load())
        qDebug()<<"-----------WaveResample.dll load success-----------------";
    WaveResampleInitialize();

    waveSample=(WAVERESAMPLE)lib_WaveResample.resolve("?WaveResample@@YAXHAAVmwArray@@ABV1@11@Z");
    if(waveSample)
        qDebug()<<"-----------function waveSample load success---------------";
    //---------------------------transformFunction.dll------------------------------------------------
    QLibrary lib_transformFunction("transformFunction.dll");
    if(lib_transformFunction.load())
        qDebug()<<"-----------transformFunction.dll load success-----------------";
    transformFunctionInitialize();

    transformFunction=(TRANSFORMFUNCTION)lib_transformFunction.resolve("?transformFunction@@YAXHAAVmwArray@@0ABV1@111@Z");

    if(transformFunction)
        qDebug()<<"-----------function transformFunction load success---------------";
    //---------------------------generateFirstDrive.dll------------------------------------------------
    QLibrary lib_generateFirstDrive("generateFirstDrive.dll");
    if(lib_generateFirstDrive.load())
        qDebug()<<"-----------generateFirstDrive.dll load success-----------------";
    generateFirstDriveInitialize();

    generateFirstDrive=(GENERATEFIRSTDRIVE)lib_generateFirstDrive.resolve("?generateFirstDrive@@YAXHAAVmwArray@@ABV1@1111@Z");
    if(generateFirstDrive)
        qDebug()<<"-----------function generateFirstDrive load success---------------";
    //---------------------------IterativeMode.dll------------------------------------------------
    QLibrary lib_IterativeMode("IterativeMode.dll");
    if(lib_IterativeMode.load())
        qDebug()<<"-----------IterativeMode.dll load success-----------------";
    IterativeModeInitialize();

    IterativeMode=(ITERATIVEMODE)lib_IterativeMode.resolve("?IterativeMode@@YAXHAAVmwArray@@ABV1@1111111@Z");
    if(IterativeMode)
        qDebug()<<"-----------function IterativeMode load success---------------";
}
