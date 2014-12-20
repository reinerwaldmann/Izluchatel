#ifndef PRINCIPALWINDOW_H
#define PRINCIPALWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QFileDialog>
#include <QDateTime>
#include <QMessageBox>
#include <QSettings>

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
    DeviceManagerIzluchatel * deviceManager;


    //data from user interface
    int numCycles;
    unsigned long numTime; //IN SECONDS!

    char debugLevel;




    bool validateInputData ();


    void addShell();
    void removeShell();

    void closeEvent(QCloseEvent *ce);

    void blockButtons(int state);


    int getNumTime();
    int getNumCycles();

    double getThresholdOn();
    double getThresholdOff();






private slots:
    void on_spinBoxNumProducts_valueChanged(int arg1);

    void on_pushButtonTest_clicked();


    void receiveMeasDataAndTransit (int id, double value, QString type);






    void on_pushButtonReset_clicked();

    void on_pushButtonSaveReports_clicked();

    void on_pushButtonReset_2_clicked();

private:
    Ui::PrincipalWindow *ui;
};

#endif // PRINCIPALWINDOW_H




