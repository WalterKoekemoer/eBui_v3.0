#ifndef VOLTAGESOURCE_H
#define VOLTAGESOURCE_H

#include "component.h"

class VoltageSource : public ComponentClass
{
public:
    enum {TypeC = QGraphicsItem::UserType + 6 };
    int type() const
    {
        return TypeC;
    }
    VoltageSource(QString name,QString Magnitude);
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

#endif // VOLTAGESOURCE_H
