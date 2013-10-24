#-------------------------------------------------
#
# Project created by QtCreator 2013-09-27T16:42:29
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Izluchatel
TEMPLATE = app


SOURCES += main.cpp\
        principalwindow.cpp \
    productshell.cpp \
    DeviceManagerIzluchatel/devicemanagerizluchatel.cpp \
    timestuff.cpp \
    DeviceManagerIzluchatel/devicemanagerizluchatelui.cpp \
    DeviceManagerIzluchatel/devicewidget.cpp \
    DeviceManagerIzluchatel/device.cpp \
    DeviceManagerIzluchatel/devicelan.cpp

HEADERS  += principalwindow.h \
    productshell.h \
    DeviceManagerIzluchatel/devicemanagerizluchatel.h \
    timestuff.h \
    DeviceManagerIzluchatel/devicemanagerizluchatelui.h \
    DeviceManagerIzluchatel/devicewidget.h \
    DeviceManagerIzluchatel/device.h \
    DeviceManagerIzluchatel/devicelan.h

FORMS    += principalwindow.ui \
    productshell.ui \
    DeviceManagerIzluchatel/devicemanagerizluchatelui.ui \
    DeviceManagerIzluchatel/devicewidget.ui
