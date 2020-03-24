#-------------------------------------------------
#
# Project created by QtCreator 2018-03-25T13:17:26
#
#-------------------------------------------------

QT       += core gui
#QT += xlsx
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
               Draw

#ע��     1��-L ����ָ�� .lib/.a �ļ���λ��
#        2��-l  ����ָ��������ļ���(��Ҫ����չ��)
#        3�����⣬������ļ���·���У���б���õ���������б��
#        4��QtҪ��ʽ����DLL�Ļ������dll�ļ����ڳ�������Ŀ¼�У�lib����ŵ��ļ�·����㣬������������.pro�ļ��е�LIBSָ�����ָ���������ļ��У�.h�ļ����ڳ���ǰĿ¼�¼��ɡ�

LIBS += -lwinmm  #PerformanceTimer required
#Add the chartDirector .dll and .lib file.
win32:contains(QMAKE_HOST.arch, x86_64) {
  LIBS += ../lib64/chartdir60.lib#../../��ʾ�ӵ�ǰ�ļ�Ŀ¼��������
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
    UI/rbf.cpp \
    Draw/mychartviewer.cpp \
    Draw/qchartviewer.cpp \
    Tool/inihelper.cpp \
    Tool/logger.cpp \
    UI/sinesweepmodule.cpp \
    Controller/TVController.cpp \
    Controller/PID3Controller.cpp \
    Tool/Oscilator.cpp \
    Draw/DisplayBuffer.cpp \
    UI/DisplayBufferForm.cpp

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
    UI/rbf.h \
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
    UI/DisplayBufferForm.h

FORMS    += mainwindow.ui \
    testwindow.ui \
    aboutform.ui \
    configuredialog.ui \
    ctrldialog.ui \
    rbf.ui \
    systemsettings.ui \
    sinesweepmodule.ui \
    DisplayBufferForm.ui


QMAKE_CXXFLAGS += -Wno-unused-variable
QMAKE_CXXFLAGS += -Wno-unused-parameter
QMAKE_CXXFLAGS += -Wcomment


RESOURCES += \
    resource.qrc


