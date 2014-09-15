#include "productshell.h"
#include "ui_productshell.h"

ProductShell::ProductShell(int inumber, PrincipalWindow *iprincipal, char iDebugLevel, QWidget *parent):
    QWidget(parent),
    ui(new Ui::ProductShell)
{
    testTimer = new QTimer(this);
    timer=new QTimer(this);


    principal = iprincipal;
    number=inumber;
    ui->setupUi(this);

    debugLevel = iDebugLevel;
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    connect(testTimer, SIGNAL(timeout()), this, SLOT(timeoutTestTimer()));

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
  delete testTimer;
    delete timer;
    delete ui;
}


void ProductShell::test()
{



    if (timer->isActive() || pauseFlag)
    {
        if (debugLevel==DEBUG_V)
        writeConsole("Попытка запуска тестирования, которое уже запущено");

        return;
    }

    numCycles = principal->getNumCycles();
//2 147 481 523
    numTime =principal->getNumTime(); //IN SECONDS


    //counting Timebreak
    timeBreak  = ((numTime*1000/numCycles)-(timeToMeasure*2+timeToSwitch*2))/2;
/*
Важный момент - дробные значения будут отсечены по принципу floor на каждом действии деления,
так как все переменные целого типа. Это, скорее всего, приведёт к тому, что система
всё же раньше справится с циклами, нежели положено по времени
и потребуется подержать реле в одном состоянии некоторое время.

*/

    if (timeBreak<minTimeBreak)
    {
        writeConsole("Ошибка 2.2 заданного времени не хватит для осуществления заданного числа циклов",MSG_ERROR);

        return;
    }

    if (debugLevel==DEBUG_V)
        {
        writeConsole("Параметры считаны успешно");
 writeConsole (tr ("Число циклов: %1 <br> Время общее: %2 мин <br> Timebreak=%3 msec").\
               arg(QString::number(numCycles))\
               .arg (QString::number (numTime))\
               .arg (QString::number (timeBreak)));



        //writeConsole(tr("Timebreak=%1 msec").arg(QString::number(timeBreak)));
        }
    counterCycles=0;
    counterTime=0;
    if (debugLevel==DEBUG_V)
    writeConsole("Запуск начала тестирования");
    timer->setSingleShot(1);
    timer->start(timeBreak); //first time start
    stage = 1;

    testTimer->start(1000);

    ui->labelCyclesPassedLeft->setText(tr("Циклов прошло/осталось: %1/%2").arg(QString::number(counterCycles)).arg(QString::number(numCycles-counterCycles)));


}

void ProductShell::pause(int val) //pause testing  0 - pause-resume, 1 - force pause 2 - force resume
{

if (val==1)
{
    testTimer->stop();
    remainingTimeHolder = timer->remainingTime();
    timer->stop();
    pauseFlag=1;
    ui->buttonPause_3->setText("Продолжить");
    writeConsole("Тестирование приостановлено");

    return;

}


    if (pauseFlag) //resume
    {
        timer->start(remainingTimeHolder);
        ui->buttonPause_3->setText("Пауза");
        writeConsole("Тестирование возобновлено");
        pauseFlag=0;
        testTimer->start(1000);
        timeout();

        return;


    }

    if ( timer->isActive())
    {

    testTimer->stop();
    remainingTimeHolder = timer->remainingTime();
    timer->stop();
    pauseFlag=1;
    ui->buttonPause_3->setText("Продолжить");
    writeConsole("Тестирование приостановлено");

    }


}


void ProductShell::reset()
{
writeConsole("Тестирование сброшено");
stage=1;
pauseFlag=0;
timer->stop();
testTimer->stop();

counterCycles=0;
counterTime=0;

ui->labelCyclesPassedLeft->setText(tr("Циклов прошло/осталось: %1/%2").arg(QString::number(counterCycles)).arg(QString::number(numCycles-counterCycles)));
ui->labelTimePassedLeft->setText(tr("Времени прошло/осталось: %1 сек/%2").arg(QString::number(counterTime)).arg(QString::number( 0)));

principal->deviceManager->nullLines();

}

void ProductShell::atFinish()
{
    writeConsole("Тестирование завершено", MSG_GOOD);
    stage=1;
    pauseFlag=0;
    timer->stop();
    testTimer->stop();

    counterCycles=0;
    counterTime=0;

    ui->labelCyclesPassedLeft->setText(tr("Циклов прошло/осталось: %1/%2").arg(QString::number(counterCycles)).arg(QString::number(numCycles-counterCycles)));
    ui->labelTimePassedLeft->setText(tr("Времени прошло/осталось: %1 сек/%2").arg(QString::number(counterTime)).arg(QString::number( 0)));

    principal->deviceManager->nullLines();


}

QString ProductShell::getConsoleText() //получить записанное в консоли
{
return ui->textEditShell->toHtml(); //а может и в plainText?? попробуем пока так


}


void ProductShell::writeConsole(QString msg, char type)
{
    /*
#define MSG_ERROR 1
#define MSG_NEUTRAL 0
#define MSG_GOOD 2
*/



msg=debugLevel==DEBUG_V?tr("Время %1 : ").arg(strtimex(counterTime)).append(msg):msg;



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



void ProductShell::receiveMeasData (int out, double value, QString type)
{
//подразумевается, что, если измерение пришло, оно верное


    double result = value;


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

void ProductShell::acceptResult(char slot, char out, char errCode, double result )
{
    if (errCode>0)
    {
        //возможно, вставить расшифровку ошибки
        writeConsole(tr("Ошибка при измерении №%1").arg(QString::number(errCode)), MSG_ERROR);
        pause();
        return;
    }


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



        writeConsole( "===Начало цикла===");

        stage++;
            timer->start(timeToSwitch);
            if (debugLevel==DEBUG_V) writeConsole("Включаем УПР1");
            switchController (1, 1);


        break;
    case 2:
        stage++;
        timer->start(timeToMeasure); //time to measure (2)
        if (debugLevel==DEBUG_V) writeConsole("Производим измерения, 1Вкл 2Выкл");
        if (principal->deviceManager->measure(number*10+1))
        {
            criticalError (tr ("Ошибка при измерении изделие %1 слот %2").arg(QString::number(number)).arg(QString::number(1)));

            //writeConsole(tr ("Ошибка при измерении изделие %1 слот %2").arg(QString::number(number)).arg(QString::number(1)));

        }
        if (principal->deviceManager->measure(number*10+2))
        {
            criticalError(tr ("Ошибка при измерении изделие %1 слот %2").arg(QString::number(number)).arg(QString::number(2)));
            //writeConsole(tr ("Ошибка при измерении изделие %1 слот %2").arg(QString::number(number)).arg(QString::number(2)));

        }

        break;
    case 3:
        stage++;
        timer->start(timeBreak); //(3)
        if (debugLevel==DEBUG_V) writeConsole("Выключаем УПР1");
        switchController (1, 0);
        break;

    case 4:
        stage++;
        timer->start(timeToSwitch); //(1)
        if (debugLevel==DEBUG_V) writeConsole("Включаем УПР2");
        switchController (2, 1);
        break;

    case 5:
        stage++;
        timer->start(timeToMeasure); //time to measure (2)
        if (debugLevel==DEBUG_V) writeConsole("Производим измерения, 1Выкл 2Вкл");

        if (principal->deviceManager->measure(number*10+1))
        {
            criticalError(tr ("Ошибка при измерении изделие %1 слот %2").arg(QString::number(number)).arg(QString::number(1)));
            //writeConsole(tr ("Ошибка при измерении изделие %1 слот %2").arg(QString::number(number)).arg(QString::number(1)));

        }
        if (principal->deviceManager->measure(number*10+2))
        {
            criticalError(tr ("Ошибка при измерении изделие %1 слот %2").arg(QString::number(number)).arg(QString::number(2)));
            //writeConsole(tr ("Ошибка при измерении изделие %1 слот %2").arg(QString::number(number)).arg(QString::number(2)));

        }
                break;
    case 6:
        stage=1;

        timer->start(timeBreak); //(3)
        switchController (2, 0);
        if (debugLevel==DEBUG_V) writeConsole("Выключаем УПР2");

        counterCycles++;
                writeConsole( "===Конец цикла===<br>");
ui->labelCyclesPassedLeft->setText(tr("Циклов прошло/осталось: %1/%2").arg(QString::number(counterCycles)).arg(QString::number(numCycles-counterCycles)));


   /*if (counterCycles>=numCycles)
        {atFinish();}
*/


        break;

    }





}
void ProductShell::timeoutTestTimer()
{
    counterTime++;
    ui->labelTimePassedLeft->setText(tr("Времени прошло/осталось: %1 /%2").arg(  strtimex(counterTime) ).arg(strtimex(numTime-counterTime)))  ;


    if (counterTime>=numTime) atFinish();
}

void ProductShell::on_buttonPause_2_clicked()
{

    ui->textEditShell->clear();

    //for debugging
//    reset();
}



void ProductShell::on_buttonReset_clicked()
{
 ui->textEditShell->clear();
    reset();


}

void ProductShell::on_buttonPause_3_clicked()
{

    pause();
}

void ProductShell::on_buttonTest_clicked()
{
     ui->textEditShell->clear();
test();
}


bool ProductShell::switchController (int out, bool state)
//Переключить контроллер
//out - выход, 1 или 2. State = состояние (1 вкл 0 выкл)
{
    int realout=out;
    switch (number)
    {
        case 1:

            break;
        case 2:
            realout+=2;
            break;
        case 3:
            realout+=4;
            break;

    }

    bool error=principal->deviceManager->wrLine(realout, state);
    if (error) criticalError("не удаётся связаться с контроллером");
}

void ProductShell::criticalError(QString msg) //запускает при критичной ошибке, требуещей постановки тестирования на паузу
{
    pause(1);
    writeConsole(tr ("Критичная ошибка: %1.").arg(msg) , MSG_ERROR );
    principal->deviceManager->nullLines();

}

