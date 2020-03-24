#-------------------------------------------------
#
# Project created by QtCreator 2018-03-25T13:17:26
#
#-------------------------------------------------

QT       += core gui
QT += xlsx
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


#the extern header file
INCLUDEPATH += ../include
INCLUDEPATH += ../Inc
INCLUDEPATH += Controller\
               Test\
               UI\
               Tool\
               Communication\
               Filter\
               Draw\
               MatlabDLL

#注：     1、-L 参数指定 .lib/.a 文件的位置
#        2、-l  参数指定导入库文件名(不要加扩展名)
#        3、另外，导入库文件的路径中，反斜杠用的是向右倾斜的
#        4、Qt要隐式调用DLL的话，须把dll文件放在程序的输出目录中，lib所存放的文件路径随便，但是须由上述.pro文件中的LIBS指定语句指定其所在文件夹，.h文件放在程序当前目录下即可。

LIBS += -lwinmm  #PerformanceTimer required
#Add the chartDirector .dll and .lib file.
win32:contains(QMAKE_HOST.arch, x86_64) {
  LIBS += ../lib64/chartdir60.lib#../../表示从当前文件目录向上两级
  LIBS += ../lib64/Enc7480.lib
  QMAKE_POST_LINK += copy /Y ..\\lib64\\chartdir60.dll $(DESTDIR) &
  QMAKE_POST_LINK = copy /Y ..\\lib64\\Enc7480.dll $(DESTDIR)
} else {
  LIBS += ../lib32/chartdir60.lib
  LIBS += ../lib32/Enc7480.lib
  LIBS += ../lib32/libfftw3-3.lib
  LIBS += ../lib32/libfftw3f-3.lib
  LIBS += ../lib32/libfftw3l-3.lib
#Pay attention to the '&' sign
  QMAKE_POST_LINK += copy /Y ..\\lib32\\chartdir60.dll $(DESTDIR) &
  QMAKE_POST_LINK += copy /Y ..\\lib32\\Enc7480.dll $(DESTDIR) &
  QMAKE_POST_LINK += copy /Y ..\\lib32\\libfftw3-3.dll $(DESTDIR) &
  QMAKE_POST_LINK += copy /Y ..\\lib32\\libfftw3f-3.dll $(DESTDIR) &
  QMAKE_POST_LINK += copy /Y ..\\lib32\\libfftw3l-3.dll $(DESTDIR)
}
#---------------------lib for Matlab--------------------------------------------------
#----------general-----------
DEFINES += __MW_STDINT_H__

INCLUDEPATH += ../includeForMatlab
INCLUDEPATH += ../includeForMatlab/win32

LIBS+= -L../libForMatlab -llibeng
LIBS+= -L../libForMatlab -llibmat
LIBS+= -L../libForMatlab -llibmex
LIBS+= -L../libForMatlab -llibmx
LIBS+= -L../libForMatlab -lmclmcr
LIBS+= -L../libForMatlab -lmclmcrrt
#-----------every--------------
LIBS += ../lib32/fftForMatlab.lib
LIBS += ../lib32/tfeFun.lib
LIBS += ../lib32/dotMul.lib
LIBS += ../lib32/addMul.lib
LIBS += ../lib32/plotTest.lib
LIBS += ../lib32/EarthPreprocess.lib
LIBS += ../lib32/WaveResample.lib
LIBS += ../lib32/transformFunction.lib
LIBS += ../lib32/generateFirstDrive.lib
LIBS += ../lib32/IterativeMode.lib
LIBS += ../lib32/pcidll.lib



QMAKE_POST_LINK += copy /Y ..\\lib32\\dotMul.dll $(DESTDIR)&
QMAKE_POST_LINK += copy /Y ..\\lib32\\fftForMatlab.dll $(DESTDIR)&
QMAKE_POST_LINK += copy /Y ..\\lib32\\tfeFun.dll $(DESTDIR)&
QMAKE_POST_LINK += copy /Y ..\\lib32\\addMul.dll $(DESTDIR)&
QMAKE_POST_LINK += copy /Y ..\\lib32\\plotTest.dll $(DESTDIR)&
QMAKE_POST_LINK += copy /Y ..\\lib32\\EarthPreprocess.dll $(DESTDIR)&
QMAKE_POST_LINK += copy /Y ..\\lib32\\WaveResample.dll $(DESTDIR)&
QMAKE_POST_LINK += copy /Y ..\\lib32\\transformFunction.dll $(DESTDIR)&
QMAKE_POST_LINK += copy /Y ..\\lib32\\generateFirstDrive.dll $(DESTDIR)&
QMAKE_POST_LINK += copy /Y ..\\lib32\\IterativeMode.dll $(DESTDIR)&
QMAKE_POST_LINK += copy /Y ..\\lib32\\pcidll.dll $(DESTDIR)
#-----------------------------------------------------------------------

TARGET = PopWil
TEMPLATE = app


SOURCES += main.cpp\
    constvar.cpp \
    Controller/PIDController.cpp \
    Test/testwindow.cpp \
    Controller/staticpositioncontroller.cpp \
    Filter/AvgFilter.cpp \
    Filter/ButtorFilter.cpp \
    Communication/aiinstant.cpp \
    Communication/aistreaming.cpp \
    Communication/aoinstant.cpp \
    Communication/doinstant.cpp \
    Tool/common.cpp \
    Tool/mathtool.cpp \
    Tool/signalprocess.cpp \
    UI/aboutform.cpp \
    UI/configuredialog.cpp \
    UI/ctrldialog.cpp \
    UI/systemsettings.cpp \
    Tool/performancetimer.cpp \
    UI/mainwindow.cpp \
    Draw/mychartviewer.cpp \
    Draw/qchartviewer.cpp \
    Tool/inihelper.cpp \
    Tool/logger.cpp \
    UI/sinesweepmodule.cpp \
    Controller/TVController.cpp \
    Controller/PID3Controller.cpp \
    Tool/Oscilator.cpp \
    Draw/DisplayBuffer.cpp \
    UI/DisplayBufferForm.cpp \
    Filter/HMAFilter.cpp \
    Test/testfornothing.cpp \
    Communication/ssitool.cpp \
    MatlabDLL/ToolFromMatlab.cpp \
    UI/calibration.cpp \
    UI/IterativeControlMainWindow.cpp

HEADERS  += \
    constvar.h \
    Controller/PIDController.h \
    Test/testwindow.h \
    Controller/staticpositioncontroller.h \
    Filter/AVGFilter.h \
    Filter/ButtorFilter.h \
    Communication/aistreaming.h \
    Communication/aoinstant.h \
    Communication/aiinstant.h \
    Tool/mathtool.h \
    Communication/doinstant.h \
    Tool/common.h \
    Tool/signalprocess.h \
    UI/aboutform.h \
    UI/configuredialog.h \
    UI/ctrldialog.h \
    UI/systemsettings.h \
    Tool/performancetimer.h \
    UI/mainwindow.h \
    Draw/bchartdir.h \
    Draw/chartdir.h \
    Draw/memblock.h \
    Draw/mychartviewer.h \
    Draw/qchartviewer.h \
    Draw/qdoublebufferedqueue.h \
    Tool/FinanceChart.h \
    Tool/inihelper.h \
    Tool/logger.h \
    UI/sinesweepmodule.h \
    Controller/TVController.h \
    Controller/PID3Controller.h \
    UI/popwilheader.h \
    Tool/Oscilator.h \
    Draw/DisplayBuffer.h \
    UI/DisplayBufferForm.h \
    Filter/HMAFilter.h \
    Test/testfornothing.h \
    Communication/ssitool.h \
    MatlabDLL/ToolFromMatlab.h \
    UI/calibration.h \
    UI/IterativeControlMainWindow.h \
    MatlabDLL/addMul.h \
    MatlabDLL/dotMul.h \
    MatlabDLL/EarthPreprocess.h \
    MatlabDLL/fftForMatlab.h \
    MatlabDLL/generateFirstDrive.h \
    MatlabDLL/IterativeMode.h \
    MatlabDLL/plotTest.h \
    MatlabDLL/tfeFun.h \
    MatlabDLL/transformFunction.h \
    MatlabDLL/WaveResample.h

FORMS    += mainwindow.ui \
    testwindow.ui \
    aboutform.ui \
    configuredialog.ui \
    ctrldialog.ui \
    systemsettings.ui \
    sinesweepmodule.ui \
    DisplayBufferForm.ui \
    IterativeControlMainWindow.ui \
    calibration.ui


QMAKE_CXXFLAGS += -Wno-unused-variable
QMAKE_CXXFLAGS +=  -Wno-unused-parameter
QMAKE_CXXFLAGS += -Wcomment


RESOURCES += \
    resource.qrc

DISTFILES += \
    mainicon.rc

RC_FILE += mainicon.rc

TRANSLATIONS += lang_English.ts

