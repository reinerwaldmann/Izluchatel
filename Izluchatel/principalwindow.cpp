#include "principalwindow.h"
#include "ui_principalwindow.h"

PrincipalWindow::PrincipalWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PrincipalWindow)
{
    ui->setupUi(this);
}

PrincipalWindow::~PrincipalWindow()
{
    delete ui;
}
