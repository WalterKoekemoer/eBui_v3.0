#ifndef MYCOMPONENT_H
#define MYCOMPONENT_H

#include <QGraphicsItem>
#include <QPainter>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

class MyComponent: public QGraphicsItem
{
public:
    MyComponent(QJsonArray Components, QList<QPointF> EndComp, QList<QPointF> WirePoints);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget, QString identity);
    QRectF boundingRect() const ;
    void Resistor(QPainter *painter, QString name, QString Magnitude,QPointF pos,qreal rotation());
    void Capacitor(QPainter *painter, QString name, QString Magnitude,QPointF pos,qreal rotation());
    void Inductor(QPainter *painter, QString name, QString Magnitude,QPointF pos,qreal rotation());
    void DVS(QPainter *painter, QString name, QString Magnitude,QPointF pos,qreal rotation());
    void DCS(QPainter *painter, QString name, QString Magnitude,QPointF pos,qreal rotation());

private:
    QJsonArray Components;
    QList<QPointF> EndComp;
    QList<QPointF> WirePoints;
};

#endif // MYCOMPONENT_H
