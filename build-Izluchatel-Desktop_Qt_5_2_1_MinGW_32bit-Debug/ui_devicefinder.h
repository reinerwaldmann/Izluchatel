/********************************************************************************
** Form generated from reading UI file 'devicefinder.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEFINDER_H
#define UI_DEVICEFINDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DeviceFinder
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBoxNumberOfSets;
    QPushButton *pushSetQuantity;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboDevices;
    QPushButton *pushSearch;
    QTextEdit *textEditConsole;

    void setupUi(QDialog *DeviceFinder)
    {
        if (DeviceFinder->objectName().isEmpty())
            DeviceFinder->setObjectName(QStringLiteral("DeviceFinder"));
        DeviceFinder->resize(699, 387);
        verticalLayout = new QVBoxLayout(DeviceFinder);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DeviceFinder);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        doubleSpinBoxNumberOfSets = new QDoubleSpinBox(DeviceFinder);
        doubleSpinBoxNumberOfSets->setObjectName(QStringLiteral("doubleSpinBoxNumberOfSets"));
        doubleSpinBoxNumberOfSets->setDecimals(0);
        doubleSpinBoxNumberOfSets->setMinimum(1);
        doubleSpinBoxNumberOfSets->setValue(1);

        horizontalLayout->addWidget(doubleSpinBoxNumberOfSets);

        pushSetQuantity = new QPushButton(DeviceFinder);
        pushSetQuantity->setObjectName(QStringLiteral("pushSetQuantity"));
        pushSetQuantity->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(pushSetQuantity);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(DeviceFinder);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboDevices = new QComboBox(DeviceFinder);
        comboDevices->setObjectName(QStringLiteral("comboDevices"));
        comboDevices->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(comboDevices);

        pushSearch = new QPushButton(DeviceFinder);
        pushSearch->setObjectName(QStringLiteral("pushSearch"));
        pushSearch->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(pushSearch);


        verticalLayout->addLayout(horizontalLayout_2);

        textEditConsole = new QTextEdit(DeviceFinder);
        textEditConsole->setObjectName(QStringLiteral("textEditConsole"));

        verticalLayout->addWidget(textEditConsole);


        retranslateUi(DeviceFinder);

        QMetaObject::connectSlotsByName(DeviceFinder);
    } // setupUi

    void retranslateUi(QDialog *DeviceFinder)
    {
        DeviceFinder->setWindowTitle(QApplication::translate("DeviceFinder", "Dialog", 0));
        label->setText(QApplication::translate("DeviceFinder", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\275\320\260\320\261\320\276\321\200\320\276\320\262 \320\276\320\261\320\276\321\200\321\203\320\264\320\276\320\262\320\260\320\275\320\270\321\217", 0));
        pushSetQuantity->setText(QApplication::translate("DeviceFinder", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", 0));
        label_2->setText(QApplication::translate("DeviceFinder", "\320\237\320\276\320\270\321\201\320\272 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262", 0));
        pushSearch->setText(QApplication::translate("DeviceFinder", "\320\230\321\201\320\272\320\260\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class DeviceFinder: public Ui_DeviceFinder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEFINDER_H
