#include "principalwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PrincipalWindow w(DEBUG_V);
    w.show();
    
    return a.exec();
}
