#include "productshell.h"
#include "ui_productshell.h"

ProductShell::ProductShell(char iDebugLevel, QWidget *parent):
    QWidget(parent),
    ui(new Ui::ProductShell),
    timer (this)
{
    ui->setupUi(this);
    debugLevel = iDebugLevel;
    connect(&timer, SIGNAL(timeout()), this, SLOT(timeout()));
}

ProductShell::~ProductShell()
{
    delete ui;
}


void ProductShell::test()
{}

void ProductShell::pause()
{}

void ProductShell::writeConsole(QString msg, char type)
{

    switch (type)
    {

    case MSG_ERROR:
        ui->textEditShell->append(tr( "<font color-red> %1 </font> <br>" ).arg(msg)  );
        break;
    case MSG_GOOD:
        ui->textEditShell->append(tr( "<font color-green> %1 </font> <br>" ).arg(msg)  );
        break;
    case MSG_NEUTRAL:
        ui->textEditShell->append(tr( " %1 <br> " ).arg(msg)  );
        break;

    }

}



void ProductShell::acceptResultSlot(char slot, char out, char errCode, double result )
{}

void timeout()
{

}
