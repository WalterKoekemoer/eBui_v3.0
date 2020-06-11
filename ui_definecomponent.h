/********************************************************************************
** Form generated from reading UI file 'definecomponent.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFINECOMPONENT_H
#define UI_DEFINECOMPONENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DefineComponent
{
public:
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *DefineComponent)
    {
        if (DefineComponent->objectName().isEmpty())
            DefineComponent->setObjectName(QStringLiteral("DefineComponent"));
        DefineComponent->resize(430, 235);
        groupBox = new QGroupBox(DefineComponent);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 391, 201));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 110, 111, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 160, 111, 16));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 110, 113, 22));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(true);
        lineEdit_3->setGeometry(QRect(140, 160, 113, 22));
        lineEdit_3->setAcceptDrops(true);
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 110, 81, 71));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 60, 113, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 55, 16));

        retranslateUi(DefineComponent);
        QObject::connect(buttonBox, SIGNAL(accepted()), DefineComponent, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DefineComponent, SLOT(reject()));

        QMetaObject::connectSlotsByName(DefineComponent);
    } // setupUi

    void retranslateUi(QDialog *DefineComponent)
    {
        DefineComponent->setWindowTitle(QApplication::translate("DefineComponent", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DefineComponent", "GroupBox", Q_NULLPTR));
        label_2->setText(QApplication::translate("DefineComponent", "Magnitude:", Q_NULLPTR));
        label_3->setText(QApplication::translate("DefineComponent", "Dependent on:", Q_NULLPTR));
        lineEdit_2->setInputMask(QString());
        label->setText(QApplication::translate("DefineComponent", "Name", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DefineComponent: public Ui_DefineComponent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFINECOMPONENT_H
