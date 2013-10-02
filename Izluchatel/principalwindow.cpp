#include "principalwindow.h"
#include "ui_principalwindow.h"

PrincipalWindow::PrincipalWindow(int iDebugLevel, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::PrincipalWindow)
{

    debugLevel = iDebugLevel;
    ui->setupUi(this);
    addShell();
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

void PrincipalWindow::on_spinBoxNumProducts_valueChanged(int arg1)
{
    if (shellList.size()>arg1) removeShell();
    if (shellList.size()<arg1) addShell();


}

void PrincipalWindow::on_pushButtonTest_clicked()
{
     QListIterator<ProductShell * > i(shellList);
    while (i.hasNext())
    i.next()->test();


}
