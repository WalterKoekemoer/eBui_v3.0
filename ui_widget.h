/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *Open;
    QPushButton *New;
    QPushButton *Simulate;
    QPushButton *Wire;
    QPushButton *Save;
    QPushButton *AddComponent;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QTreeWidget *treeWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setEnabled(true);
        Widget->resize(800, 500);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setMinimumSize(QSize(800, 500));
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_2->setContentsMargins(-1, -1, 8, 19);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(116);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, 0, -1);
        Open = new QPushButton(Widget);
        Open->setObjectName(QStringLiteral("Open"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/Icons/icons8-folder-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        Open->setIcon(icon);

        horizontalLayout_4->addWidget(Open);

        New = new QPushButton(Widget);
        New->setObjectName(QStringLiteral("New"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/Icons/icons8-add-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        New->setIcon(icon1);

        horizontalLayout_4->addWidget(New);

        Simulate = new QPushButton(Widget);
        Simulate->setObjectName(QStringLiteral("Simulate"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icons/Icons/icons8-electronics-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        Simulate->setIcon(icon2);

        horizontalLayout_4->addWidget(Simulate);

        Wire = new QPushButton(Widget);
        Wire->setObjectName(QStringLiteral("Wire"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icons/Icons/icons8-wire-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        Wire->setIcon(icon3);
        Wire->setCheckable(true);

        horizontalLayout_4->addWidget(Wire);

        Save = new QPushButton(Widget);
        Save->setObjectName(QStringLiteral("Save"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icons/Icons/icons8-save-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        Save->setIcon(icon4);

        horizontalLayout_4->addWidget(Save);

        AddComponent = new QPushButton(Widget);
        AddComponent->setObjectName(QStringLiteral("AddComponent"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Icons/Icons/icons8-heater-resistor-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddComponent->setIcon(icon5);

        horizontalLayout_4->addWidget(AddComponent);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(7);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        treeWidget = new QTreeWidget(Widget);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(0, font);
        __qtreewidgetitem->setIcon(0, icon);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Icons/Icons/Voltage.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font1;
        font1.setPointSize(8);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem1->setFont(0, font1);
        __qtreewidgetitem1->setIcon(0, icon6);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setUniformRowHeights(false);
        treeWidget->setSortingEnabled(true);
        treeWidget->setAnimated(false);
        treeWidget->setAllColumnsShowFocus(false);
        treeWidget->setWordWrap(false);
        treeWidget->setHeaderHidden(false);

        horizontalLayout_5->addWidget(treeWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new QGraphicsView(Widget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout->addWidget(graphicsView);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 4);

        horizontalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_2->setStretch(0, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_4->addWidget(label);


        verticalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_2->setStretch(1, 15);
        verticalLayout_2->setStretch(2, 1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "eBui", Q_NULLPTR));
        Open->setText(QString());
        New->setText(QString());
        Simulate->setText(QString());
        Wire->setText(QString());
        Save->setText(QString());
        AddComponent->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("Widget", "My Components", Q_NULLPTR));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("Widget", "->Voltage Source", Q_NULLPTR));
        treeWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("Widget", "x:0     y:0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
