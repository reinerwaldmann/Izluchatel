#ifndef PRINCIPALWINDOW_H
#define PRINCIPALWINDOW_H

#include <QMainWindow>
#include <QList>

#include "DeviceManagerIzluchatel/devicemanagerizluchatel.h"
#include "productshell.h"

namespace Ui {
class PrincipalWindow;
}

class DeviceManagerIzluchatel;
class ProductShell;



class PrincipalWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit PrincipalWindow(int iDebugLevel, QWidget *parent = 0);
    ~PrincipalWindow();
    
    QList <ProductShell * > shellList;

    void addShell();
    void removeShell();

    char debugLevel;



private slots:
    void on_spinBoxNumProducts_valueChanged(int arg1);

    void on_pushButtonTest_clicked();

private:
    Ui::PrincipalWindow *ui;
};

#endif // PRINCIPALWINDOW_H
