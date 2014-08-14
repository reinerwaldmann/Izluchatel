#ifndef PRODUCTSHELL_H
#define PRODUCTSHELL_H

#include <QWidget>
#include "principalwindow.h"
#include <QTimer>
#include "timestuff.h"

#define MSG_ERROR 1
#define MSG_NEUTRAL 0
#define MSG_GOOD 2

#define DEBUG_N 0
#define DEBUG_V 1


const int timeToSwitch = 500; //ms
const int timeToMeasure = 2000; //ms
const int minTimeBreak=500; //ms

namespace Ui {
class ProductShell;
}

class PrincipalWindow;

class ProductShell : public QWidget
{
    Q_OBJECT
    
public:






    QTimer  * timer; //for testing process
    QTimer *  testTimer; //for indicating time elapsed


    char debugLevel;
    bool flagWaitingAnswer;  //if we sent smf to the port, and waiting for answer,
    //for result, for example
    PrincipalWindow * principal;
    int number;

    int timeBreak; //counted interval between two switches
    char stage; //number of an event, that comes 1 2 3 4 5 6

    int numCycles;
    int counterCycles;

    long  numTime;
    long counterTime;//in secs, increased by testTimer

    int remainingTimeHolder; //holds remaining time when testing paused
    bool pauseFlag; //rasises as pause is triggered

//2 147 483 647
    //3 600 000

    explicit ProductShell(int inumber, PrincipalWindow * iprincipal,  char iDebugLevel=0, QWidget *parent = 0);
    ~ProductShell();
    void writeConsole (QString msg, char type=0);
    void test (); //begin testing
    void atFinish(); //fired at finish of testing process
    void pause(); //pause testing
    void reset(); //reset testing


    void acceptResult (char slot, char out, char errCode, double result );

    void receiveMeasData (int out, double value, QString type);

    
private:
    Ui::ProductShell *ui;


private slots:
    void  timeout ();
    void  timeoutTestTimer ();




    void on_buttonPause_2_clicked();
     void on_buttonReset_clicked();
    void on_buttonPause_3_clicked();
    void on_buttonTest_clicked();
};

#endif // PRODUCTSHELL_H
