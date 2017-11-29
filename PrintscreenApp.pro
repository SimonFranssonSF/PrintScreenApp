#-------------------------------------------------
#
# Project created by QtCreator 2017-11-26T04:22:46
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PrintscreenApp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

@CONFIG += qxt
QXT += core gui@
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    screenshotmanager.cpp \
    qcenteredbutton.cpp \
    keypressregister.cpp \
    keypressthread.cpp \
    mousepressregiters.cpp \
    qpaintlabel.cpp \
    specialrubberband.cpp

HEADERS += \
        mainwindow.h \
    screenshotmanager.h \
    qcenteredbutton.h \
    keypressregister.h \
    keypressthread.h \
    mousepressregiters.h \
    qpaintlabel.h \
    specialrubberband.h

FORMS += \
        mainwindow.ui


INCLUDEPATH += C:/Users/Frans/Desktop/curl-7.56.1/include
INCLUDEPATH += C:/Users/Frans/Desktop/curl-7.56.1/include/curl
INCLUDEPATH += C:/Users/Frans/Desktop/curl-7.56.1/lib
INCLUDEPATH += C:/Users/Frans/Desktop/cmake/lib
INCLUDEPATH += C:\Users\Frans\Desktop\cmake\lib\libcurl.dir




LIBS += -L/C:/Users/Frans/Desktop/libcurl/I386/ \
     -LIBCURLd \

LIBS += -L/C:/Users/Frans/Desktop/libcurl/I386/ \
     -LIBCURL \

LIBS += -L/C:/Users/Frans/Desktop/libcurl/IA64/ \
     -LIBCURL \

LIBS += -L/C:/Users/Frans/Desktop/cmake/lib/Debug/ \
     -FAN \


win32:CONFIG(release, debug|release): LIBS += -LC:/Users/Frans/Desktop/cmake/lib/release/ -lFAN
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/Users/Frans/Desktop/cmake/lib/debug/ -lFAN
else:unix: LIBS += -LC:/Users/Frans/Desktop/cmake/lib/ -lFAN

INCLUDEPATH += C:/Users/Frans/Desktop/curl-7.56.1/include/curl
DEPENDPATH += C:/Users/Frans/Desktop/curl-7.56.1/include/curl

RESOURCES += \
    resources.qrc




