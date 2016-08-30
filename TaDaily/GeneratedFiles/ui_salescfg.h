/********************************************************************************
** Form generated from reading UI file 'salescfg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALESCFG_H
#define UI_SALESCFG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_id;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_name;
    QLineEdit *lineEdit_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_ser;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineTo;
    QPushButton *toBt;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineTo_2;
    QPushButton *toBt_2;
    QPushButton *configueBt;
    QLabel *errorLb;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(444, 286);
        layoutWidget = new QWidget(Form);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 19, 421, 211));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_id = new QLabel(layoutWidget);
        label_id->setObjectName(QStringLiteral("label_id"));

        verticalLayout->addWidget(label_id);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_name = new QLabel(layoutWidget);
        label_name->setObjectName(QStringLiteral("label_name"));

        verticalLayout_2->addWidget(label_name);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_ser = new QLabel(layoutWidget);
        label_ser->setObjectName(QStringLiteral("label_ser"));

        verticalLayout_3->addWidget(label_ser);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout_3->addWidget(lineEdit_3);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_4->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineTo = new QLineEdit(layoutWidget);
        lineTo->setObjectName(QStringLiteral("lineTo"));
        lineTo->setMaximumSize(QSize(350, 20));

        horizontalLayout_2->addWidget(lineTo);

        toBt = new QPushButton(layoutWidget);
        toBt->setObjectName(QStringLiteral("toBt"));
        toBt->setMaximumSize(QSize(21, 20));
        QFont font;
        font.setPointSize(11);
        toBt->setFont(font);

        horizontalLayout_2->addWidget(toBt);


        verticalLayout_4->addLayout(horizontalLayout_2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_4->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineTo_2 = new QLineEdit(layoutWidget);
        lineTo_2->setObjectName(QStringLiteral("lineTo_2"));
        lineTo_2->setMaximumSize(QSize(350, 20));

        horizontalLayout_3->addWidget(lineTo_2);

        toBt_2 = new QPushButton(layoutWidget);
        toBt_2->setObjectName(QStringLiteral("toBt_2"));
        toBt_2->setMaximumSize(QSize(21, 20));
        toBt_2->setFont(font);

        horizontalLayout_3->addWidget(toBt_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        configueBt = new QPushButton(Form);
        configueBt->setObjectName(QStringLiteral("configueBt"));
        configueBt->setGeometry(QRect(350, 250, 75, 23));
        errorLb = new QLabel(Form);
        errorLb->setObjectName(QStringLiteral("errorLb"));
        errorLb->setGeometry(QRect(13, 252, 181, 20));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        label_id->setText(QApplication::translate("Form", "\351\224\200\345\224\256\345\225\206ID", 0));
        label_name->setText(QApplication::translate("Form", "\351\224\200\345\224\256\345\225\206\345\220\215\347\247\260", 0));
        label_ser->setText(QApplication::translate("Form", "\346\267\261\350\257\201\351\200\232\345\217\267", 0));
        label->setText(QApplication::translate("Form", "From:", 0));
        toBt->setText(QApplication::translate("Form", "..", 0));
        label_2->setText(QApplication::translate("Form", "To:", 0));
        toBt_2->setText(QApplication::translate("Form", "..", 0));
        configueBt->setText(QApplication::translate("Form", "\347\241\256\345\256\232", 0));
        errorLb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALESCFG_H
