#include "ui_principalwindow.h"
#include "principalwindow.h"




PrincipalWindow::PrincipalWindow(int iDebugLevel, QWidget *parent):
QMainWindow(parent),
ui(new Ui::PrincipalWindow)
{
debugLevel = iDebugLevel;
ui->setupUi(this);
ы
ui->spinBoxNumProducts->hide();
ui->label->hide();


addShell();
addShell();
addShell();

deviceManager = new DeviceManagerIzluchatel(1720, this);
QObject::connect(deviceManager, SIGNAL( fireTransitMeasData(int, double , QString ) ), this, SLOT(receiveMeasDataAndTransit (int , double , QString )));
numCycles=0;

QSettings settings("SKTB", "Izluchatel");
restoreGeometry(settings.value("PrincipalWindow-geometry").toByteArray());
restoreState(settings.value("PrincipalWindow-state").toByteArray());

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
return ui->radioMins->isChecked()?ui->spinBoxNumMins->value()*60:ui->spinBoxNumMins->value()*60*60;





}
int PrincipalWindow::getNumCycles()
{
return ui->spinBoxNumCycles->value();
}
void PrincipalWindow::on_spinBoxNumProducts_valueChanged(int arg1)
{
 if ((shellList.size()>arg1)&&(!shellList.at(arg1)->isTestGoingOn()))     removeShell();

if (shellList.size()<arg1) addShell();
}
void PrincipalWindow::on_pushButtonTest_clicked()
{
    if (validateInputData()) return; //error in input data
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
        if (deviceManager->UI!=NULL)
        {
            deviceManager->UI->close();
            on_pushButtonReset_clicked();

        }
    }

    QSettings settings("SKTB", "Izluchatel");
    settings.setValue("PrincipalWindow-geometry", saveGeometry());
    settings.setValue("PrincipalWindow-state", saveState());

    QWidget::closeEvent(ce);

}
void PrincipalWindow::receiveMeasDataAndTransit (int id, double value, QString type)
{
    int shellid=(int)id/10; //идентификатор шелла, ведь устройства имеют двухцифренный идентификатор шелл - девайс (1 или 2)
    if (shellList.size()>=shellid)
    //если есть такой шелл, ассоциированный с данным устройством
    //есть сомнения, а всегда ли будет сохраняться соответствие
    {
        qDebug()<< "Received "+QString::number(id)+"\t"+QString::number(value)+"\t"+type+"\t"+QString::number(shellid);
        shellList[shellid-1]->receiveMeasData (id%10, value, type);
    }
}


void PrincipalWindow::on_pushButtonReset_clicked()
{
    QListIterator<ProductShell * > i(shellList);
    while (i.hasNext())
    i.next()->reset();

}

void PrincipalWindow::on_pushButtonSaveReports_clicked()
{

    QString dir = QFileDialog::getExistingDirectory(this, tr("Выбор папки сохранения отчётов"), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (dir.isEmpty())
        return;

    QListIterator<ProductShell * > i(shellList);
    int j(0);
    while (i.hasNext())
    {
        j++;
        QString filename = dir+"/"+QDateTime::currentDateTime().toString("dd-mm-yyyy_hh-mm-ss")+"_slot"+QString::number(j)+".html";
        QFile f (filename);

        if(!f.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Ошибка при записи файлов отчётов"));
            return;
        }
        QTextStream out (&f);
        out<<i.next()->getConsoleText();

        f.close();

        //i.next()->reset();

    }

}

void PrincipalWindow::blockButtons(int state)
/*Блокировка кнопок в зависимости от состояния
1 - дефолтное
2 - в процессе тестирования
*/
{



}

double PrincipalWindow::getThresholdOn()
{
    return ui->spinBoxThresON->value();

}

double PrincipalWindow::getThresholdOff()
{
    return ui->spinBoxThresOFF->value();

}

void PrincipalWindow::on_pushButtonReset_2_clicked()
{
deviceManager->UI->show();
}

