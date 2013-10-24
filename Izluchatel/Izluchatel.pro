#-------------------------------------------------
#
# Project created by QtCreator 2013-09-27T16:42:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Izluchatel
TEMPLATE = app


SOURCES += main.cpp\
        principalwindow.cpp \
    productshell.cpp \
    DeviceManagerIzluchatel/devicemanagerizluchatel.cpp \
    timestuff.cpp \
    DeviceManagerIzluchatel/devicemanagerizluchatelui.cpp \
    DeviceManagerIzluchatel/devicewidget.cpp

HEADERS  += principalwindow.h \
    productshell.h \
    DeviceManagerIzluchatel/devicemanagerizluchatel.h \
    timestuff.h \
    DeviceManagerIzluchatel/devicemanagerizluchatelui.h \
    DeviceManagerIzluchatel/devicewidget.h

FORMS    += principalwindow.ui \
    productshell.ui \
    DeviceManagerIzluchatel/devicemanagerizluchatelui.ui \
    DeviceManagerIzluchatel/devicewidget.ui
