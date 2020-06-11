#ifndef DEPCURRENTSRC_H
#define DEPCURRENTSRC_H

#include "component.h"

class depCurrentSrc: public ComponentClass
{
public:
    enum {TypeDCS = UserType + 2 };
    int type() const
    {
        return TypeDCS;
    }

    depCurrentSrc(QString name, QString Magnitude);
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

#endif // DEPCURRENTSRC_H
