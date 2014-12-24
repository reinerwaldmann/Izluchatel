/********************************************************************************
** Form generated from reading UI file 'devicewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEWIDGET_H
#define UI_DEVICEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *Connect;

    void setupUi(QWidget *DeviceWidget)
    {
        if (DeviceWidget->objectName().isEmpty())
            DeviceWidget->setObjectName(QStringLiteral("DeviceWidget"));
        DeviceWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(DeviceWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DeviceWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        verticalLayout->addWidget(label);

        Connect = new QPushButton(DeviceWidget);
        Connect->setObjectName(QStringLiteral("Connect"));
        Connect->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(Connect);


        retranslateUi(DeviceWidget);

        QMetaObject::connectSlotsByName(DeviceWidget);
    } // setupUi

    void retranslateUi(QWidget *DeviceWidget)
    {
        DeviceWidget->setWindowTitle(QApplication::translate("DeviceWidget", "Form", 0));
        label->setText(QApplication::translate("DeviceWidget", "\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", 0));
        Connect->setText(QApplication::translate("DeviceWidget", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class DeviceWidget: public Ui_DeviceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEWIDGET_H
