#ifndef PRODUCTSHELL_H
#define PRODUCTSHELL_H

#include <QWidget>
#include "principalwindow.h"
#include <QTimer>

#define MSG_ERROR 1
#define MSG_NEUTRAL 0
#define MSG_GOOD 2

#define DEBUG_N 0
#define DEBUG_V 1



namespace Ui {
class ProductShell;
}

class PrincipalWindow;

class ProductShell : public QWidget
{
    Q_OBJECT
    
public:
    QTimer timer; //for testing process
    char debugLevel;
    bool flagWaitingAnswer;  //if we sent smf to the port, and waiting for answer,
    //for result, for example
    PrincipalWindow * principal;



    explicit ProductShell(char iDebugLevel=0, QWidget *parent = 0);
    ~ProductShell();
    void writeConsole (QString msg, char type=0);
    void test (); //begin testing
    void pause(); //pause testing

    void acceptResultSlot (char slot, char out, char errCode, double result );

    
private:
    Ui::ProductShell *ui;


private slots:
    void  timeout ();




};

#endif // PRODUCTSHELL_H
