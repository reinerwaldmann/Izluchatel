/********************************************************************************
** Form generated from reading UI file 'productshell.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTSHELL_H
#define UI_PRODUCTSHELL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductShell
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelName;
    QLabel *labelSummary;
    QLabel *labelCyclesPassedLeft;
    QLabel *labelTimePassedLeft;
    QTextEdit *textEditShell;
    QPushButton *buttonPause_2;
    QPushButton *buttonTest;
    QPushButton *buttonReset;
    QPushButton *buttonPause_3;

    void setupUi(QWidget *ProductShell)
    {
        if (ProductShell->objectName().isEmpty())
            ProductShell->setObjectName(QStringLiteral("ProductShell"));
        ProductShell->resize(298, 509);
        verticalLayout = new QVBoxLayout(ProductShell);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelName = new QLabel(ProductShell);
        labelName->setObjectName(QStringLiteral("labelName"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        labelName->setFont(font);
        labelName->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelName);

        labelSummary = new QLabel(ProductShell);
        labelSummary->setObjectName(QStringLiteral("labelSummary"));

        verticalLayout->addWidget(labelSummary);

        labelCyclesPassedLeft = new QLabel(ProductShell);
        labelCyclesPassedLeft->setObjectName(QStringLiteral("labelCyclesPassedLeft"));

        verticalLayout->addWidget(labelCyclesPassedLeft);

        labelTimePassedLeft = new QLabel(ProductShell);
        labelTimePassedLeft->setObjectName(QStringLiteral("labelTimePassedLeft"));

        verticalLayout->addWidget(labelTimePassedLeft);

        textEditShell = new QTextEdit(ProductShell);
        textEditShell->setObjectName(QStringLiteral("textEditShell"));

        verticalLayout->addWidget(textEditShell);

        buttonPause_2 = new QPushButton(ProductShell);
        buttonPause_2->setObjectName(QStringLiteral("buttonPause_2"));

        verticalLayout->addWidget(buttonPause_2);

        buttonTest = new QPushButton(ProductShell);
        buttonTest->setObjectName(QStringLiteral("buttonTest"));

        verticalLayout->addWidget(buttonTest);

        buttonReset = new QPushButton(ProductShell);
        buttonReset->setObjectName(QStringLiteral("buttonReset"));

        verticalLayout->addWidget(buttonReset);

        buttonPause_3 = new QPushButton(ProductShell);
        buttonPause_3->setObjectName(QStringLiteral("buttonPause_3"));

        verticalLayout->addWidget(buttonPause_3);


        retranslateUi(ProductShell);

        QMetaObject::connectSlotsByName(ProductShell);
    } // setupUi

    void retranslateUi(QWidget *ProductShell)
    {
        ProductShell->setWindowTitle(QApplication::translate("ProductShell", "Form", 0));
        labelName->setText(QApplication::translate("ProductShell", "1", 0));
        labelSummary->setText(QApplication::translate("ProductShell", "\320\236\320\261\321\211\320\270\320\271 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", 0));
        labelCyclesPassedLeft->setText(QApplication::translate("ProductShell", "\320\246\320\270\320\272\320\273\320\276\320\262 \320\277\321\200\320\276\321\210\320\273\320\276/\320\276\321\201\321\202\320\260\320\273\320\276\321\201\321\214:", 0));
        labelTimePassedLeft->setText(QApplication::translate("ProductShell", "\320\222\321\200\320\265\320\274\320\265\320\275\320\270 \320\277\321\200\320\276\321\210\320\273\320\276/\320\276\321\201\321\202\320\260\320\273\320\276\321\201\321\214:", 0));
        buttonPause_2->setText(QApplication::translate("ProductShell", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\272\320\276\320\275\321\201\320\276\320\273\321\214", 0));
        buttonTest->setText(QApplication::translate("ProductShell", "\320\242\320\265\321\201\321\202", 0));
        buttonReset->setText(QApplication::translate("ProductShell", "\320\241\320\261\321\200\320\276\321\201", 0));
        buttonPause_3->setText(QApplication::translate("ProductShell", "\320\237\320\260\321\203\320\267\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class ProductShell: public Ui_ProductShell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTSHELL_H
