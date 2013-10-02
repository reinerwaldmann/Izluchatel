#ifndef DEVICEMANAGERIZLUCHATEL_H
#define DEVICEMANAGERIZLUCHATEL_H

#include <QObject>
#include "./principalwindow.h"


class PrincipalWindow;


class DeviceManagerIzluchatel : public QObject
{
    Q_OBJECT
public:
    explicit DeviceManagerIzluchatel(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // DEVICEMANAGERIZLUCHATEL_H
