#include "productshell.h"
#include "ui_productshell.h"

ProductShell::ProductShell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductShell)
{
    ui->setupUi(this);
}

ProductShell::~ProductShell()
{
    delete ui;
}
