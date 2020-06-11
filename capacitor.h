#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "component.h"

class Capacitor : public ComponentClass
{
public:
    enum {TypeC = QGraphicsItem::UserType + 1 };
    int type() const
    {
        return TypeC;
    }
    Capacitor(QString name, QString Magnitude);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void setMagnitude(double magnitude);
    void setConst(QString name);
    void setName(QString name);
    double getMagnitude() ;
    QString getName();
    QString getConstName();
    QPointF getPos();
    qreal getRot();

private:
    QString name;
    double Magnitude;
    QString ConstName;
};

#endif // CAPACITOR_H
