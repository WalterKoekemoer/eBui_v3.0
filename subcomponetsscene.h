#ifndef SUBCOMPONETSSCENE_H
#define SUBCOMPONETSSCENE_H

#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>
#include "component.h"
#include "definecomponent.h"
#include "wire.h"

class SubComponetsScene : public QGraphicsScene
{
public:
    SubComponetsScene(QObject *parent = nullptr);
    ~SubComponetsScene();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *keyEvent);
    QList <Connections*> connectionList;
    QList <QPointF> WireA;
    QList <QPointF> WireB;
    QTimer *timer;
    bool addWire;
    QPointF CrntPos;
    wire *Wire;
private:
    QGraphicsItem *item;
    ComponentClass *connectComp;
    QPointF A;

};

#endif // SUBCOMPONETSSCENE_H
