#ifndef PRODUCTSHELL_H
#define PRODUCTSHELL_H

#include <QWidget>

namespace Ui {
class ProductShell;
}

class ProductShell : public QWidget
{
    Q_OBJECT
    
public:
    explicit ProductShell(QWidget *parent = 0);
    ~ProductShell();
    
private:
    Ui::ProductShell *ui;
};

#endif // PRODUCTSHELL_H
