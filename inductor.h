#ifndef INDUCTOR_H
#define INDUCTOR_H

#include "component.h"

class Inductor: public ComponentClass
{
public:
    enum {TypeI = QGraphicsItem::UserType + 4 };
    int type() const
    {
        return TypeI;
    }
    Inductor(QString name, QString Magnitude);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void setMagnitude(double magnitude);
    void setName(QString name);
    void setConst(QString name);
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

#endif // INDUCTOR_H
