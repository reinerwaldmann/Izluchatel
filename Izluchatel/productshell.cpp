#include "productshell.h"
#include "ui_productshell.h"

ProductShell::ProductShell(int inumber, PrincipalWindow *iprincipal, char iDebugLevel, QWidget *parent):
    QWidget(parent),
    ui(new Ui::ProductShell)
{

    principal = iprincipal;
    number=inumber;
    ui->setupUi(this);

    debugLevel = iDebugLevel;
    connect(&timer, SIGNAL(timeout()), this, SLOT(timeout()));
    ui->labelName->setText(tr("Изделие №%1").arg(QString::number(number)));


    counterCycles=0;
    counterTime=0;

    numCycles=0;
    numTime=0;

    pauseFlag=0;
    remainingTimeHolder=0;

    stage = 1;



}

ProductShell::~ProductShell()
{
    delete ui;
}


void ProductShell::test()
{


    if (timer.isActive() || pauseFlag)
    {
        if (debugLevel==DEBUG_V)
        writeConsole("Попытка запуска тестирования, которое уже запущено");

        return;
    }

    numCycles = principal->numCycles;
    //numTime
    //counting Timebreak
    counterCycles=0;
    counterTime=0;



    if (debugLevel==DEBUG_V)
    writeConsole("Запуск начала тестирования");




//debugging
    timeBreak = 3;
    timer.setSingleShot(1);
    timer.start(timeBreak); //first time start
    stage = 1;





}

void ProductShell::pause()
{

    if (pauseFlag) //resume
    {
        timer.start(remainingTimeHolder);
        ui->buttonPause_3->setText("Пауза");
        writeConsole("Тестирование возобновлено");
        pauseFlag=0;
        return;


    }

    if ( timer.isActive())
    {

    remainingTimeHolder = timer.remainingTime();
    timer.stop();
    pauseFlag=1;
    ui->buttonPause_3->setText("Продолжить");
    writeConsole("Тестирование приостановлено");

    }


}


void ProductShell::reset()
{
stage=1;
pauseFlag=0;
timer.stop();


}

void ProductShell::atFinish()
{
    timer.stop();
    stage=1;


    writeConsole("Тестирование завершено", MSG_GOOD);
}

void ProductShell::writeConsole(QString msg, char type)
{
    /*
#define MSG_ERROR 1
#define MSG_NEUTRAL 0
#define MSG_GOOD 2
*/

    switch (type)
    {

    case MSG_ERROR:
        ui->textEditShell->append(tr( "<font color=red> %1 </font>" ).arg(msg)  );
        break;
    case MSG_GOOD:
        ui->textEditShell->append(tr( "<font color=green> %1 </font>" ).arg(msg)  );
        break;
    case MSG_NEUTRAL:
        ui->textEditShell->append(tr( " %1" ).arg(msg)  );
        break;

    }

}



void ProductShell::acceptResult(char slot, char out, char errCode, double result )
{

    bool isGood=0;

    if (errCode>0)
    {
        //возможно, вставить расшифровку ошибки
        writeConsole(tr("Ошибка при измерении №%1").arg(QString::number(errCode)), MSG_ERROR);
        pause();
        return;
    }

    char resgood = MSG_GOOD;

    if (stage-1==2)
//1st up 2nd down
    {
        if (out==1)
        {
        if (result<=8)
    { writeConsole( tr ("Измерение по выходу 1: в норме, значение потерь %1 dB при норме не более 8dB").arg (QString::number(result)), MSG_GOOD); }
     else
    { writeConsole( tr ("Измерение по выходу 1: вне диапазона, значение потерь %1 dB при норме не более 8dB").arg (QString::number(result)), MSG_ERROR); }

         }

        if (out==2)
        {
        if (result>=50)
    { writeConsole( tr ("Измерение по выходу 2: в норме, значение потерь %1 dB при норме не менее 50dB").arg (QString::number(result)), MSG_GOOD); }
     else
    { writeConsole( tr ("Измерение по выходу 2: вне диапазона, значение потерь %1 dB при норме не менее 50dB").arg (QString::number(result)), MSG_ERROR); }
         }



    }

    if (stage-1==5)
//1st down 2nd up
//1 включен 2 отключен
    {

        if (out==2)
        {
        if (result<=8)
    { writeConsole( tr ("Измерение по выходу 2: в норме, значение потерь %1 dB при норме не более 8dB").arg (QString::number(result)), MSG_GOOD); }
     else
    { writeConsole( tr ("Измерение по выходу 2: вне диапазона, значение потерь %1 dB при норме не менее 8dB").arg (QString::number(result)), MSG_ERROR); }

         }

        if (out==1)
        {
        if (result>=50)
    { writeConsole( tr ("Измерение по выходу 1: в норме, значение потерь %1 dB при норме не менее 50dB").arg (QString::number(result)), MSG_GOOD); }
     else
    { writeConsole( tr ("Измерение по выходу 1: вне диапазона, значение потерь %1 dB при норме не менее 50dB").arg (QString::number(result)), MSG_ERROR); }
         }

    }


}

void ProductShell::timeout()
{



    switch (stage)
    {
    case 1:
           stage++;
            timer.start(timeToSwitch);
            if (debugLevel==DEBUG_V) writeConsole("Включаем УПР1");

        break;
    case 2:
        stage++;
        timer.start(timeToMeasure); //time to measure (2)
        if (debugLevel==DEBUG_V) writeConsole("Производим измерения, 1Вкл 2Выкл");
        if (principal->deviceManager->measure(number, 1))
        {
            writeConsole(tr ("Ошибка при измерении изделие %1 слот %2").arg(QString::number(number)).arg(QString::number(1)));

        }
        if (principal->deviceManager->measure(number, 2))
        {
            writeConsole(tr ("Ошибка при измерении изделие %1 слот %2").arg(QString::number(number)).arg(QString::number(2)));

        }

        break;
    case 3:
        stage++;
        timer.start(timeBreak); //(3)
        if (debugLevel==DEBUG_V) writeConsole("Выключаем УПР1");
        break;

    case 4:
        stage++;
        timer.start(timeToSwitch); //(1)
        if (debugLevel==DEBUG_V) writeConsole("Включаем УПР2");
        break;

    case 5:
        stage++;
        timer.start(timeToMeasure); //time to measure (2)
        if (debugLevel==DEBUG_V) writeConsole("Производим измерения, 1Выкл 2Вкл");

        if (principal->deviceManager->measure(number, 1))
        {
            writeConsole(tr ("Ошибка при измерении изделие %1 слот %2").arg(QString::number(number)).arg(QString::number(1)));

        }
        if (principal->deviceManager->measure(number, 2))
        {
            writeConsole(tr ("Ошибка при измерении изделие %1 слот %2").arg(QString::number(number)).arg(QString::number(2)));

        }
                break;
    case 6:
        stage=1;

        timer.start(timeBreak); //(3)
        if (debugLevel==DEBUG_V) writeConsole("Выключаем УПР2");

        counterCycles++;

        if (counterCycles>=numCycles)
        {atFinish();}

        break;

    }
    ui->labelCyclesPassedLeft->setText(tr("Циклов прошло/осталось: %1/%2").arg(QString::number(counterCycles)).arg(QString::number(numCycles-counterCycles)));
    ui->labelTimePassedLeft->setText(tr("Времени прошло/осталось: %1/%2").arg(QString::number(counterCycles)).arg(QString::number(numTime-counterTime)));


}

void ProductShell::on_buttonPause_2_clicked()
{
    ui->textEditShell->clear();

    //for debugging
    reset();
}



void ProductShell::on_buttonReset_clicked()
{
reset();
writeConsole("Тестирование сброшено");

}

void ProductShell::on_buttonPause_3_clicked()
{

    pause();
}

void ProductShell::on_buttonTest_clicked()
{
test();
}
