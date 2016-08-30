/********************************************************************************
** Form generated from reading UI file 'tadaily.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TADAILY_H
#define UI_TADAILY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaDailyClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *fileTbWidget;
    QPushButton *saveItemBt;
    QPushButton *newItemBt;
    QPushButton *deleteItemBt;
    QWidget *tab_2;
    QTableWidget *sendTbWid;
    QPushButton *otherCpBt;
    QLabel *timeLb;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QHBoxLayout *gHorizonLayout;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QLabel *totalLb;
    QLabel *label_6;
    QLabel *sendLb;
    QLabel *costLb;
    QLabel *label_4;
    QTextBrowser *logBrowser;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_send;
    QMenu *menu_other;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TaDailyClass)
    {
        if (TaDailyClass->objectName().isEmpty())
            TaDailyClass->setObjectName(QStringLiteral("TaDailyClass"));
        TaDailyClass->resize(918, 619);
        centralWidget = new QWidget(TaDailyClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(290, 10, 621, 551));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        fileTbWidget = new QTableWidget(tab);
        fileTbWidget->setObjectName(QStringLiteral("fileTbWidget"));
        fileTbWidget->setGeometry(QRect(0, 20, 611, 501));
        saveItemBt = new QPushButton(tab);
        saveItemBt->setObjectName(QStringLiteral("saveItemBt"));
        saveItemBt->setGeometry(QRect(380, 0, 51, 21));
        newItemBt = new QPushButton(tab);
        newItemBt->setObjectName(QStringLiteral("newItemBt"));
        newItemBt->setGeometry(QRect(440, 0, 51, 21));
        deleteItemBt = new QPushButton(tab);
        deleteItemBt->setObjectName(QStringLiteral("deleteItemBt"));
        deleteItemBt->setGeometry(QRect(500, 0, 51, 21));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        sendTbWid = new QTableWidget(tab_2);
        sendTbWid->setObjectName(QStringLiteral("sendTbWid"));
        sendTbWid->setGeometry(QRect(0, 20, 621, 511));
        otherCpBt = new QPushButton(tab_2);
        otherCpBt->setObjectName(QStringLiteral("otherCpBt"));
        otherCpBt->setGeometry(QRect(510, 0, 51, 21));
        tabWidget->addTab(tab_2, QString());
        timeLb = new QLabel(centralWidget);
        timeLb->setObjectName(QStringLiteral("timeLb"));
        timeLb->setGeometry(QRect(20, 520, 261, 31));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(11, 11, 271, 131));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        gHorizonLayout = new QHBoxLayout();
        gHorizonLayout->setSpacing(6);
        gHorizonLayout->setObjectName(QStringLiteral("gHorizonLayout"));

        verticalLayout->addLayout(gHorizonLayout);

        verticalSpacer = new QSpacerItem(20, 110, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(11, 140, 271, 351));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 20, 61, 21));
        totalLb = new QLabel(groupBox_2);
        totalLb->setObjectName(QStringLiteral("totalLb"));
        totalLb->setGeometry(QRect(110, 20, 54, 21));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 50, 81, 21));
        sendLb = new QLabel(groupBox_2);
        sendLb->setObjectName(QStringLiteral("sendLb"));
        sendLb->setGeometry(QRect(110, 50, 54, 21));
        costLb = new QLabel(groupBox_2);
        costLb->setObjectName(QStringLiteral("costLb"));
        costLb->setGeometry(QRect(110, 80, 51, 21));
        QFont font;
        font.setPointSize(11);
        costLb->setFont(font);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 80, 31, 20));
        logBrowser = new QTextBrowser(groupBox_2);
        logBrowser->setObjectName(QStringLiteral("logBrowser"));
        logBrowser->setGeometry(QRect(0, 110, 271, 241));
        TaDailyClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TaDailyClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 918, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_send = new QMenu(menuBar);
        menu_send->setObjectName(QStringLiteral("menu_send"));
        menu_other = new QMenu(menuBar);
        menu_other->setObjectName(QStringLiteral("menu_other"));
        TaDailyClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TaDailyClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TaDailyClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TaDailyClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TaDailyClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_send->menuAction());
        menuBar->addAction(menu_other->menuAction());

        retranslateUi(TaDailyClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TaDailyClass);
    } // setupUi

    void retranslateUi(QMainWindow *TaDailyClass)
    {
        TaDailyClass->setWindowTitle(QApplication::translate("TaDailyClass", "TaDaily", 0));
        saveItemBt->setText(QApplication::translate("TaDailyClass", "\344\277\235\345\255\230", 0));
        newItemBt->setText(QApplication::translate("TaDailyClass", "\346\226\260\345\242\236", 0));
        deleteItemBt->setText(QApplication::translate("TaDailyClass", "\345\210\240\351\231\244", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("TaDailyClass", "Tab 1", 0));
        otherCpBt->setText(QApplication::translate("TaDailyClass", "\346\213\267\350\264\235", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("TaDailyClass", "Tab 2", 0));
        timeLb->setText(QString());
        groupBox->setTitle(QApplication::translate("TaDailyClass", "\345\267\245\344\275\234\346\227\245\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("TaDailyClass", "\344\270\212\344\270\200\344\270\252\345\267\245\344\275\234\346\227\245", 0));
        label_2->setText(QApplication::translate("TaDailyClass", "\345\275\223\345\211\215\345\267\245\344\275\234\346\227\245", 0));
        groupBox_2->setTitle(QApplication::translate("TaDailyClass", "\345\217\221\351\200\201\347\212\266\346\200\201", 0));
        label_3->setText(QApplication::translate("TaDailyClass", "\346\200\273\346\226\207\344\273\266\346\225\260\357\274\232", 0));
        totalLb->setText(QString());
        label_6->setText(QApplication::translate("TaDailyClass", "\345\267\262\345\217\221\351\200\201\346\226\207\344\273\266\346\225\260\357\274\232", 0));
        sendLb->setText(QString());
        costLb->setText(QString());
        label_4->setText(QApplication::translate("TaDailyClass", "\350\200\227\346\227\266\357\274\232", 0));
        menu->setTitle(QApplication::translate("TaDailyClass", "\351\205\215\347\275\256", 0));
        menu_send->setTitle(QApplication::translate("TaDailyClass", "\346\225\260\346\215\256\345\217\221\351\200\201", 0));
        menu_other->setTitle(QApplication::translate("TaDailyClass", "\345\205\266\344\273\226\346\225\260\346\215\256", 0));
    } // retranslateUi

};

namespace Ui {
    class TaDailyClass: public Ui_TaDailyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TADAILY_H
