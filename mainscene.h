#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>
#include "component.h"
#include "definecomponent.h"
#include "wire.h"

class MainScene : public QGraphicsScene
{
public:
    MainScene(QObject *parent = nullptr);
    ~MainScene();
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
#endif // MAINSCENE_H
