#include "timestuff.h"




m_time ot (unsigned long in)
{
m_time res;
res.hours=in/3600;
res.mins=(in-res.hours*3600)/60;
res.secs=in-res.hours*3600-res.mins*60;
return res;
}


QString strtimex (m_time in)
{


QString res;

if (in.hours!=0) res.append(QObject::tr(" %1 ч. ").arg(QString::number(in.hours)) );
if (in.mins!=0) res.append(QObject::tr(" %1 мин. ").arg(QString::number(in.mins)) );
res.append(QObject::tr(" %1 сек. ").arg(QString::number(in.secs)) );

return res;

//ну и для упоротых

/*return in.hours!=0?QObject::tr(" %1 ч. ").arg(QString::number(in.hours)):" "+\
                in.mins!=0?QObject::tr(" %1 мин. ").arg(QString::number(in.mins)):" "+\
                 QObject::tr(" %1 сек. ").arg(QString::number(in.secs)) ;

*/
}

QString strtimex (unsigned long in)
{
    return strtimex(ot (in));

}

