#ifndef TIMESTUFF_H
#define TIMESTUFF_H

#include <QString>
#include <QObject>

struct m_time {int secs; int mins; int hours;};
m_time ot (unsigned long in);
QString strtimex (m_time in);
QString strtimex (unsigned long in);






#endif // TIMESTUFF_H
