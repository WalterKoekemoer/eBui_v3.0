#ifndef WIRE2_H
#define WIRE2_H

#include "component.h"
#include "connections.h"
#include <QDebug>
#include "voltagesource.h"

class Wire2 : public Connections
{
public:
    Wire2(QGraphicsItem *compA, QGraphicsItem *compB, QPointF A, QPointF B);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QString connectedComponents();


private:
    QString connection;
    ComponentClass *compA;
    ComponentClass *compB;
    bool A;
    bool B;
    qreal distanceA;
    qreal distanceB;
};
#endif // WIRE2_H
