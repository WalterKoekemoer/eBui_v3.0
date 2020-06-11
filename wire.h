#ifndef WIRE_H
#define WIRE_H

#include "component.h"
#include "connections.h"
#include <QDebug>


class wire : public Connections
{
public:
    wire(ComponentClass *compA, ComponentClass *compB, QPointF A, QPointF B);
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

#endif // WIRE_H
