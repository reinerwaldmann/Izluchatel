#ifndef DEVICEMANAGERIZLUCHATEL_H
#define DEVICEMANAGERIZLUCHATEL_H

#include <QObject>
#include "./principalwindow.h"


class PrincipalWindow;


class DeviceManagerIzluchatel : public QObject
{
    Q_OBJECT
public:
    explicit DeviceManagerIzluchatel(PrincipalWindow * iprincipal,  QObject *parent = 0);
    char measure (char slt, char out); //returns 0 if OK, 1 if device is known to be offline

    PrincipalWindow * principal;

signals:
    
public slots:
    
};

#endif // DEVICEMANAGERIZLUCHATEL_H
