#include "principalwindow.h"
#include "ui_principalwindow.h"

PrincipalWindow::PrincipalWindow(int iDebugLevel, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::PrincipalWindow)
{

    debugLevel = iDebugLevel;
    ui->setupUi(this);

    addShell();

    deviceManager = new DeviceManagerIzluchatel(1720, this);

    QObject::connect(deviceManager, SIGNAL( fireTransitMeasData(int id,  double value, QString type) ), this, SLOT(receiveMeasDataAndTransit (int id, double value, QString type)));


    numCycles=0;
}

PrincipalWindow::~PrincipalWindow()
{
    delete ui;
}


void PrincipalWindow::addShell()
{
    ProductShell * pr = new ProductShell (shellList.size()+1, this, debugLevel, this);
    ui->horizontalLayoutShells->addWidget(pr);
    shellList.append(pr);

}

void PrincipalWindow::removeShell()
{
    ProductShell * pr = shellList.last();
    shellList.removeLast();
    ui->horizontalLayoutShells->removeWidget(pr);
    delete pr;


}

bool PrincipalWindow::validateInputData ()
{
    return 0;

}


int PrincipalWindow::getNumTime()
{
return ui->spinBoxNumMins->value()*60;
}

int PrincipalWindow::getNumCycles()
{
return ui->spinBoxNumCycles->value();
}



void PrincipalWindow::on_spinBoxNumProducts_valueChanged(int arg1)
{
    if (shellList.size()>arg1) removeShell();
    if (shellList.size()<arg1) addShell();


}

void PrincipalWindow::on_pushButtonTest_clicked()
{
    if  (validateInputData()) return; //error in input data

    numCycles = ui->spinBoxNumCycles->value();

    //debugging
    numTime = ui->spinBoxNumMins->value()*60; //in sec
    //in production must be value in hours value_in_h*60*60

    QListIterator<ProductShell * > i(shellList);
    while (i.hasNext())
    i.next()->test();


}

void PrincipalWindow::closeEvent(QCloseEvent *ce)
{

    if (deviceManager!=NULL)
    {
        if  (deviceManager->UI!=NULL)
        {

             deviceManager->UI->close();
        }

    }


}

void PrincipalWindow::receiveMeasDataAndTransit (int id, double value, QString type)
{

    int shellid=(int)id/10; //идентификатор шелла, ведь устройства имеют двухцифренный идентификатор шелл - девайс (1 или 2)

    if (shellList.size()>id)
        //если есть такой шелл, ассоциированный с данным устройством
        //есть сомнения, а всегда ли будет сохраняться соответствие

    {
        shellList[shellid]->receiveMeasData (id%10, value, type);

    }



}
