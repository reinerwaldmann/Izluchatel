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



void ProductShell::writeConsole(QString msg, char type)
{

    switch (type)
    {

    case MSG_ERROR:
        ui->textEditShell->append(tr( "<font color-red> %1 </font>" ).arg(msg)  );
        break;
    case MSG_GOOD:
        ui->textEditShell->append(tr( "<font color-green> %1 </font>" ).arg(msg)  );
        break;
    case MSG_NEUTRAL:
        ui->textEditShell->append(tr( " %1" ).arg(msg)  );
        break;

    }

}



void ProductShell::acceptResult(char slot, char out, char errCode, double result )
{}

void ProductShell::timeout()
{
ui->labelCyclesPassedLeft->setText(tr("Циклов прошло/осталось: %1/%2").arg(QString::number(counterCycles)).arg(QString::number(numCycles-counterCycles)));
ui->labelTimePassedLeft->setText(tr("Времени прошло/осталось: %1/%2").arg(QString::number(counterCycles)).arg(QString::number(numTime-counterTime)));

    switch (stage)
    {
    case 1:
        stage++;
            timer.start(500);
            if (debugLevel==DEBUG_V) writeConsole("Включаем УПР1");

        break;
    case 2:
        stage++;
        timer.start(1000); //time to measure (2)
        if (debugLevel==DEBUG_V) writeConsole("Производим измерения, 1Вкл 2Выкл");
        break;
    case 3:
        stage++;
        timer.start(timeBreak); //(3)
        if (debugLevel==DEBUG_V) writeConsole("Выключаем УПР1");
        break;

    case 4:
        stage++;
        timer.start(500); //(1)
        if (debugLevel==DEBUG_V) writeConsole("Включаем УПР2");
        break;

    case 5:
        stage++;
        timer.start(1000); //time to measure (2)
        if (debugLevel==DEBUG_V) writeConsole("Производим измерения, 1Выкл 2Вкл");
                break;
    case 6:
        stage=1;
        timer.start(timeBreak); //(3)
        if (debugLevel==DEBUG_V) writeConsole("Выключаем УПР2");
        break;

    }


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
