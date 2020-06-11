#ifndef DEFINECOMPONENT_H
#define DEFINECOMPONENT_H

#include <QGraphicsItem>
#include <QMessageBox>
#include <QDialog>
#include <QList>
#include "component.h"
#include "capacitor.h"
#include "inductor.h"
#include "resistor.h"
#include "depcurrentsrc.h"
#include "depvoltagesrc.h"
#include "voltagesource.h"

namespace Ui {
class DefineComponent;
}

class DefineComponent : public QDialog
{
    Q_OBJECT

public:
    explicit DefineComponent(QList<QGraphicsItem*> components, QGraphicsItem *item);

    ~DefineComponent();
private slots:
    void on_buttonBox_accepted();

private:
    Ui::DefineComponent *ui;
    QList <QGraphicsItem *> components;
    QGraphicsItem *item;
};

#endif // DEFINECOMPONENT_H
