/********************************************************************************
** Form generated from reading UI file 'addcomponent.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOMPONENT_H
#define UI_ADDCOMPONENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddComponent
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_2;
    QPushButton *Btn_Inductor;
    QPushButton *Btn_Capacitor;
    QPushButton *Btn_Resistor;
    QPushButton *Btn_DepCrnt;
    QPushButton *Btn_DepVlt;
    QPushButton *pushButton;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddComponent)
    {
        if (AddComponent->objectName().isEmpty())
            AddComponent->setObjectName(QStringLiteral("AddComponent"));
        AddComponent->setEnabled(true);
        AddComponent->resize(800, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddComponent->sizePolicy().hasHeightForWidth());
        AddComponent->setSizePolicy(sizePolicy);
        AddComponent->setMinimumSize(QSize(800, 500));
        AddComponent->setMaximumSize(QSize(800, 500));
        verticalLayout_2 = new QVBoxLayout(AddComponent);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        graphicsView = new QGraphicsView(AddComponent);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        Btn_Inductor = new QPushButton(AddComponent);
        Btn_Inductor->setObjectName(QStringLiteral("Btn_Inductor"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Btn_Inductor->sizePolicy().hasHeightForWidth());
        Btn_Inductor->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/Icons/Inductor.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Inductor->setIcon(icon);
        Btn_Inductor->setIconSize(QSize(70, 24));

        gridLayout_2->addWidget(Btn_Inductor, 0, 0, 1, 1);

        Btn_Capacitor = new QPushButton(AddComponent);
        Btn_Capacitor->setObjectName(QStringLiteral("Btn_Capacitor"));
        sizePolicy1.setHeightForWidth(Btn_Capacitor->sizePolicy().hasHeightForWidth());
        Btn_Capacitor->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/Icons/Capacitor.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Capacitor->setIcon(icon1);
        Btn_Capacitor->setIconSize(QSize(70, 50));

        gridLayout_2->addWidget(Btn_Capacitor, 0, 1, 1, 1);

        Btn_Resistor = new QPushButton(AddComponent);
        Btn_Resistor->setObjectName(QStringLiteral("Btn_Resistor"));
        sizePolicy1.setHeightForWidth(Btn_Resistor->sizePolicy().hasHeightForWidth());
        Btn_Resistor->setSizePolicy(sizePolicy1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icons/Icons/Resistor.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Resistor->setIcon(icon2);
        Btn_Resistor->setIconSize(QSize(69, 20));

        gridLayout_2->addWidget(Btn_Resistor, 0, 2, 1, 1);

        Btn_DepCrnt = new QPushButton(AddComponent);
        Btn_DepCrnt->setObjectName(QStringLiteral("Btn_DepCrnt"));
        sizePolicy1.setHeightForWidth(Btn_DepCrnt->sizePolicy().hasHeightForWidth());
        Btn_DepCrnt->setSizePolicy(sizePolicy1);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icons/Icons/Current_Source_(Controlled).png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_DepCrnt->setIcon(icon3);
        Btn_DepCrnt->setIconSize(QSize(74, 62));

        gridLayout_2->addWidget(Btn_DepCrnt, 2, 1, 1, 1);

        Btn_DepVlt = new QPushButton(AddComponent);
        Btn_DepVlt->setObjectName(QStringLiteral("Btn_DepVlt"));
        sizePolicy1.setHeightForWidth(Btn_DepVlt->sizePolicy().hasHeightForWidth());
        Btn_DepVlt->setSizePolicy(sizePolicy1);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icons/Icons/Voltage_Source_(Controlled).png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_DepVlt->setIcon(icon4);
        Btn_DepVlt->setIconSize(QSize(61, 57));

        gridLayout_2->addWidget(Btn_DepVlt, 2, 0, 1, 1);

        pushButton = new QPushButton(AddComponent);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Icons/Icons/icons8-wire-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon5);
        pushButton->setIconSize(QSize(53, 53));
        pushButton->setCheckable(true);

        gridLayout_2->addWidget(pushButton, 2, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(1, 5);

        verticalLayout_2->addLayout(horizontalLayout);

        label_2 = new QLabel(AddComponent);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        buttonBox = new QDialogButtonBox(AddComponent);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(AddComponent);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddComponent, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddComponent, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddComponent);
    } // setupUi

    void retranslateUi(QDialog *AddComponent)
    {
        AddComponent->setWindowTitle(QApplication::translate("AddComponent", "Dialog", Q_NULLPTR));
        Btn_Inductor->setText(QString());
        Btn_Capacitor->setText(QString());
        Btn_Resistor->setText(QString());
        Btn_DepCrnt->setText(QString());
        Btn_DepVlt->setText(QString());
        pushButton->setText(QString());
        label_2->setText(QApplication::translate("AddComponent", "You can leave connectios open", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddComponent: public Ui_AddComponent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMPONENT_H
