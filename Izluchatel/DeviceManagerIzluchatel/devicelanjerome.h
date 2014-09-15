#ifndef DEVICELANJEROME_H
#define DEVICELANJEROME_H
#include "devicelan.h"
#include "controller.h"


class DeviceLANJerome : public DeviceLAN, public Controller
{
    Q_OBJECT

public:
    DeviceLANJerome();
     int ping ();

    //Джеромоспецифичное
     //устанавливает уровень на линии, команда $KE,WR, <line>, <state>
     int wrLine(int numline, bool state=1);
     int sendToPort(QString msg);

     int nullLines();//зануляет все линии, команда $KE, WRA, 0000000000000000000000



public slots:
    void readyRead ();


};

#endif // DEVICELANJEROME_H


