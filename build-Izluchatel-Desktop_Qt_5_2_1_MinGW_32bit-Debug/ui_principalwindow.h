/********************************************************************************
** Form generated from reading UI file 'principalwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINCIPALWINDOW_H
#define UI_PRINCIPALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrincipalWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxTesting;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpinBox *spinBoxNumProducts;
    QLabel *label_2;
    QSpinBox *spinBoxNumCycles;
    QLabel *label_3;
    QSpinBox *spinBoxNumMins;
    QLabel *label_11;
    QComboBox *comboBoxTime;
    QLabel *label_10;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpinBox *spinBoxThresON;
    QLabel *label_8;
    QLabel *label_6;
    QSpinBox *spinBoxThresOFF;
    QLabel *label_9;
    QHBoxLayout *horizontalLayoutShells;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonSaveReports;
    QPushButton *pushButtonTest;
    QPushButton *pushButtonReset;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PrincipalWindow)
    {
        if (PrincipalWindow->objectName().isEmpty())
            PrincipalWindow->setObjectName(QStringLiteral("PrincipalWindow"));
        PrincipalWindow->resize(688, 549);
        QFont font;
        font.setPointSize(10);
        PrincipalWindow->setFont(font);
        PrincipalWindow->setWindowOpacity(1);
        centralWidget = new QWidget(PrincipalWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBoxTesting = new QGroupBox(centralWidget);
        groupBoxTesting->setObjectName(QStringLiteral("groupBoxTesting"));
        groupBoxTesting->setMinimumSize(QSize(0, 60));
        groupBoxTesting->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_3 = new QHBoxLayout(groupBoxTesting);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 2, -1, 9);
        label = new QLabel(groupBoxTesting);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        spinBoxNumProducts = new QSpinBox(groupBoxTesting);
        spinBoxNumProducts->setObjectName(QStringLiteral("spinBoxNumProducts"));
        spinBoxNumProducts->setMinimumSize(QSize(0, 30));
        spinBoxNumProducts->setMinimum(1);
        spinBoxNumProducts->setMaximum(3);

        horizontalLayout_3->addWidget(spinBoxNumProducts);

        label_2 = new QLabel(groupBoxTesting);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        spinBoxNumCycles = new QSpinBox(groupBoxTesting);
        spinBoxNumCycles->setObjectName(QStringLiteral("spinBoxNumCycles"));
        spinBoxNumCycles->setMinimumSize(QSize(0, 30));
        spinBoxNumCycles->setMinimum(1);
        spinBoxNumCycles->setMaximum(1000000000);

        horizontalLayout_3->addWidget(spinBoxNumCycles);

        label_3 = new QLabel(groupBoxTesting);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBoxNumMins = new QSpinBox(groupBoxTesting);
        spinBoxNumMins->setObjectName(QStringLiteral("spinBoxNumMins"));
        spinBoxNumMins->setMinimumSize(QSize(0, 30));
        spinBoxNumMins->setMinimum(1);
        spinBoxNumMins->setMaximum(1000000000);

        horizontalLayout_3->addWidget(spinBoxNumMins);

        label_11 = new QLabel(groupBoxTesting);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_3->addWidget(label_11);

        comboBoxTime = new QComboBox(groupBoxTesting);
        comboBoxTime->setObjectName(QStringLiteral("comboBoxTime"));
        comboBoxTime->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(comboBoxTime);

        label_10 = new QLabel(groupBoxTesting);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_3->addWidget(label_10);


        verticalLayout->addWidget(groupBoxTesting);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 60));
        groupBox_2->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 2, -1, 9);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        spinBoxThresON = new QSpinBox(groupBox_2);
        spinBoxThresON->setObjectName(QStringLiteral("spinBoxThresON"));
        spinBoxThresON->setMinimumSize(QSize(0, 30));
        spinBoxThresON->setMaximum(1000000000);

        horizontalLayout_4->addWidget(spinBoxThresON);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        spinBoxThresOFF = new QSpinBox(groupBox_2);
        spinBoxThresOFF->setObjectName(QStringLiteral("spinBoxThresOFF"));
        spinBoxThresOFF->setMinimumSize(QSize(0, 30));
        spinBoxThresOFF->setMaximum(1000000000);

        horizontalLayout_4->addWidget(spinBoxThresOFF);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayoutShells = new QHBoxLayout();
        horizontalLayoutShells->setSpacing(6);
        horizontalLayoutShells->setObjectName(QStringLiteral("horizontalLayoutShells"));

        verticalLayout->addLayout(horizontalLayoutShells);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonSaveReports = new QPushButton(centralWidget);
        pushButtonSaveReports->setObjectName(QStringLiteral("pushButtonSaveReports"));
        pushButtonSaveReports->setMinimumSize(QSize(1, 30));

        horizontalLayout_2->addWidget(pushButtonSaveReports);

        pushButtonTest = new QPushButton(centralWidget);
        pushButtonTest->setObjectName(QStringLiteral("pushButtonTest"));
        pushButtonTest->setMinimumSize(QSize(1, 30));

        horizontalLayout_2->addWidget(pushButtonTest);

        pushButtonReset = new QPushButton(centralWidget);
        pushButtonReset->setObjectName(QStringLiteral("pushButtonReset"));
        pushButtonReset->setMinimumSize(QSize(1, 30));

        horizontalLayout_2->addWidget(pushButtonReset);


        verticalLayout->addLayout(horizontalLayout_2);

        PrincipalWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PrincipalWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 688, 21));
        PrincipalWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PrincipalWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PrincipalWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PrincipalWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PrincipalWindow->setStatusBar(statusBar);

        retranslateUi(PrincipalWindow);

        QMetaObject::connectSlotsByName(PrincipalWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PrincipalWindow)
    {
        PrincipalWindow->setWindowTitle(QApplication::translate("PrincipalWindow", "\320\223\320\273\320\260\320\262\320\275\320\276\320\265 \320\276\320\272\320\275\320\276", 0));
        groupBoxTesting->setTitle(QApplication::translate("PrincipalWindow", "\320\230\321\201\320\277\321\213\321\202\320\260\320\275\320\270\321\217", 0));
        label->setText(QApplication::translate("PrincipalWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\276\320\261\321\200\320\260\320\267\321\206\320\276\320\262", 0));
        label_2->setText(QApplication::translate("PrincipalWindow", "\320\232\320\276\320\273-\320\262\320\276 \321\206\320\270\320\272\320\273\320\276\320\262", 0));
        label_3->setText(QApplication::translate("PrincipalWindow", "\320\222\321\200\320\265\320\274\321\217", 0));
        label_11->setText(QApplication::translate("PrincipalWindow", "\320\274\320\270\320\275 (test)", 0));
        comboBoxTime->clear();
        comboBoxTime->insertItems(0, QStringList()
         << QApplication::translate("PrincipalWindow", "96", 0)
         << QApplication::translate("PrincipalWindow", "168", 0)
         << QApplication::translate("PrincipalWindow", "200", 0)
         << QApplication::translate("PrincipalWindow", "500", 0)
         << QApplication::translate("PrincipalWindow", "1000", 0)
        );
        label_10->setText(QApplication::translate("PrincipalWindow", "\321\207.", 0));
        groupBox_2->setTitle(QApplication::translate("PrincipalWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0));
        label_5->setText(QApplication::translate("PrincipalWindow", "\320\237\320\276\321\200\320\276\320\263 \320\262\320\272\320\273.", 0));
        label_8->setText(QApplication::translate("PrincipalWindow", "dB", 0));
        label_6->setText(QApplication::translate("PrincipalWindow", "\320\237\320\276\321\200\320\276\320\263 \320\262\321\213\320\272\320\273.", 0));
        label_9->setText(QApplication::translate("PrincipalWindow", "dB", 0));
        pushButtonSaveReports->setText(QApplication::translate("PrincipalWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\276\321\202\321\207\321\221\321\202\321\213", 0));
        pushButtonTest->setText(QApplication::translate("PrincipalWindow", "\320\242\320\265\321\201\321\202", 0));
        pushButtonReset->setText(QApplication::translate("PrincipalWindow", "\320\241\320\261\321\200\320\276\321\201", 0));
    } // retranslateUi

};

namespace Ui {
    class PrincipalWindow: public Ui_PrincipalWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPALWINDOW_H
