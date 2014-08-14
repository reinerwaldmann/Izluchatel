#-------------------------------------------------
#
# Project created by QtCreator 2013-09-27T16:42:29
#
#-------------------------------------------------

include(qextserialport-1.2beta2/src/qextserialport.pri)
QT       += core gui network xml

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
    DeviceManagerIzluchatel/devicelan.cpp \
    DeviceManagerIzluchatel/controller.cpp \
    DeviceManagerIzluchatel/devicefinder.cpp \
    DeviceManagerIzluchatel/devicelanjerome.cpp \
    DeviceManagerIzluchatel/devicers232.cpp \
    DeviceManagerIzluchatel/devicers232rubin201.cpp \
    DeviceManagerIzluchatel/measurer.cpp

HEADERS  += principalwindow.h \
    productshell.h \
    DeviceManagerIzluchatel/devicemanagerizluchatel.h \
    timestuff.h \
    DeviceManagerIzluchatel/devicemanagerizluchatelui.h \
    DeviceManagerIzluchatel/devicewidget.h \
    DeviceManagerIzluchatel/device.h \
    DeviceManagerIzluchatel/devicelan.h \
    DeviceManagerIzluchatel/controller.h \
    DeviceManagerIzluchatel/devicefinder.h \
    DeviceManagerIzluchatel/devicelanjerome.h \
    DeviceManagerIzluchatel/devicers232.h \
    DeviceManagerIzluchatel/devicers232rubin201.h \
    DeviceManagerIzluchatel/measurer.h

FORMS    += principalwindow.ui \
    productshell.ui \
    DeviceManagerIzluchatel/devicemanagerizluchatelui.ui \
    DeviceManagerIzluchatel/devicewidget.ui \
    DeviceManagerIzluchatel/devicefinder.ui
