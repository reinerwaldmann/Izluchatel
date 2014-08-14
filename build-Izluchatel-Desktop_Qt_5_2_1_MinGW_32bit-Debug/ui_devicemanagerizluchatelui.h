/********************************************************************************
** Form generated from reading UI file 'devicemanagerizluchatelui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEMANAGERIZLUCHATELUI_H
#define UI_DEVICEMANAGERIZLUCHATELUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceManagerIzluchatelUI
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboListOfDevices;
    QPushButton *searchDevice;
    QPushButton *searchDevice_2;
    QTextEdit *console;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboLevelOfOutput;

    void setupUi(QWidget *DeviceManagerIzluchatelUI)
    {
        if (DeviceManagerIzluchatelUI->objectName().isEmpty())
            DeviceManagerIzluchatelUI->setObjectName(QStringLiteral("DeviceManagerIzluchatelUI"));
        DeviceManagerIzluchatelUI->resize(461, 478);
        verticalLayout = new QVBoxLayout(DeviceManagerIzluchatelUI);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(DeviceManagerIzluchatelUI);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        tableWidget = new QTableWidget(DeviceManagerIzluchatelUI);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(DeviceManagerIzluchatelUI);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboListOfDevices = new QComboBox(DeviceManagerIzluchatelUI);
        comboListOfDevices->setObjectName(QStringLiteral("comboListOfDevices"));
        comboListOfDevices->setMinimumSize(QSize(150, 0));

        horizontalLayout_2->addWidget(comboListOfDevices);

        searchDevice = new QPushButton(DeviceManagerIzluchatelUI);
        searchDevice->setObjectName(QStringLiteral("searchDevice"));

        horizontalLayout_2->addWidget(searchDevice);


        verticalLayout->addLayout(horizontalLayout_2);

        searchDevice_2 = new QPushButton(DeviceManagerIzluchatelUI);
        searchDevice_2->setObjectName(QStringLiteral("searchDevice_2"));

        verticalLayout->addWidget(searchDevice_2);

        console = new QTextEdit(DeviceManagerIzluchatelUI);
        console->setObjectName(QStringLiteral("console"));

        verticalLayout->addWidget(console);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DeviceManagerIzluchatelUI);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboLevelOfOutput = new QComboBox(DeviceManagerIzluchatelUI);
        comboLevelOfOutput->setObjectName(QStringLiteral("comboLevelOfOutput"));
        comboLevelOfOutput->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(comboLevelOfOutput);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DeviceManagerIzluchatelUI);

        QMetaObject::connectSlotsByName(DeviceManagerIzluchatelUI);
    } // setupUi

    void retranslateUi(QWidget *DeviceManagerIzluchatelUI)
    {
        DeviceManagerIzluchatelUI->setWindowTitle(QApplication::translate("DeviceManagerIzluchatelUI", "\320\234\320\265\320\275\320\265\320\264\320\266\320\265\321\200 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262", 0));
        label_3->setText(QApplication::translate("DeviceManagerIzluchatelUI", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\275\321\213\320\265 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0));
        label_2->setText(QApplication::translate("DeviceManagerIzluchatelUI", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\275\320\265\320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\275\321\213\321\205 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262", 0));
        searchDevice->setText(QApplication::translate("DeviceManagerIzluchatelUI", "\320\230\321\201\320\272\320\260\321\202\321\214", 0));
        searchDevice_2->setText(QString());
        label->setText(QApplication::translate("DeviceManagerIzluchatelUI", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\262\321\213\320\262\320\276\320\264\320\260 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\271", 0));
        comboLevelOfOutput->clear();
        comboLevelOfOutput->insertItems(0, QStringList()
         << QApplication::translate("DeviceManagerIzluchatelUI", "\320\242\320\276\320\273\321\214\320\272\320\276 \320\276\321\210\320\270\320\261\320\272\320\270", 0)
         << QApplication::translate("DeviceManagerIzluchatelUI", "\320\236\321\210\320\270\320\261\320\272\320\270 \320\270 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", 0)
         << QApplication::translate("DeviceManagerIzluchatelUI", "\320\222\321\201\321\221", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class DeviceManagerIzluchatelUI: public Ui_DeviceManagerIzluchatelUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEMANAGERIZLUCHATELUI_H
