#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <addcomponent.h>
#include <QTimer>
#include <QDebug>
#include <resistor.h>
#include <inductor.h>
#include <capacitor.h>
#include <depcurrentsrc.h>
#include <depvoltagesrc.h>
#include "mainscene.h"
#include <wire.h>
#include <component.h>
#include <Qt>
#include <QTimer>
#include <voltagesource.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_AddComponent_clicked();

    void on_Open_clicked();

    void OpenFile(QString path);

    void on_treeWidget_activated(const QModelIndex &index);

    void addRoot(QString name);

    void on_Simulate_clicked();


    void on_Wire_clicked(bool checked);

public slots:
    void Update();

private:
    Ui::Widget *ui;
    wire *Wire;
    AddComponent * component;
    QGraphicsView *view;
    Capacitor *cap;
    Resistor *resistor;
    Inductor *inductor;
    depCurrentSrc *DCS;
    depVoltageSrc *DVS;
    MainScene *scene;
    QString path;
    QDir dir;
    QList <QString> ConnectionsList;
    QList <VoltageSource*> VS;
    VoltageSource *Vcc;
    int VScount;
};

#endif // WIDGET_H
