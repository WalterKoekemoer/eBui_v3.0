#ifndef RESISTOR_H
#define RESISTOR_H

#include "component.h"

class Resistor: public ComponentClass
{
public:
    enum {TypeR = QGraphicsItem::UserType + 5 };
    int type() const
    {
        return TypeR;
    }
    Resistor(QString name, QString Magnitude);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void setMagnitude(double magnitude);
    void setName(QString name);
    double getMagnitude() ;
    void setConst(QString name);
    QString getConstName();
    QString getName();
    QPointF getPos();
    qreal getRot();
private:
    QString name;
    double Magnitude;
    QString ConstName;
};

#endif // RESISTOR_H
