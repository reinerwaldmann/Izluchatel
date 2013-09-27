#ifndef PRINCIPALWINDOW_H
#define PRINCIPALWINDOW_H

#include <QMainWindow>

namespace Ui {
class PrincipalWindow;
}

class PrincipalWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit PrincipalWindow(QWidget *parent = 0);
    ~PrincipalWindow();
    
private:
    Ui::PrincipalWindow *ui;
};

#endif // PRINCIPALWINDOW_H
