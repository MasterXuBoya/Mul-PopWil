#-------------------------------------------------
#
# Project created by QtCreator 2018-03-25T13:17:26
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#the extern header file
INCLUDEPATH += ../include

#ע�� 1��-L ����ָ�� .lib/.a �ļ���λ��
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
#Pay attention to the '&' sign
  QMAKE_POST_LINK += copy /Y ..\\lib32\\chartdir60.dll $(DESTDIR) &
  QMAKE_POST_LINK += copy /Y ..\\lib32\\Enc7480.dll $(DESTDIR)
}

TARGET = PopWil
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qchartviewer.cpp \
    performancetimer.cpp \
    iohelper.cpp \
    constvar.cpp \
    inihelper.cpp \
    randomwalk.cpp \
    testwindow.cpp \
    aboutform.cpp

HEADERS  += mainwindow.h \
    qchartviewer.h \
    qdoublebufferedqueue.h \
    performancetimer.h \
    iohelper.h \
    constvar.h \
    inihelper.h \
    randomwalk.h \
    testwindow.h \
    aboutform.h

FORMS    += mainwindow.ui \
    testwindow.ui \
    aboutform.ui


QMAKE_CXXFLAGS += -Wno-unused-variable
QMAKE_CXXFLAGS += -Wno-unused-parameter


RESOURCES += \
    resource.qrc

