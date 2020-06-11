#ifndef DEPVOLTAGESRC_H
#define DEPVOLTAGESRC_H

#include "component.h"
class depVoltageSrc: public ComponentClass
{
public:
    enum {DVS = UserType + 3 };
    int type() const
    {
        return DVS;
    }
    depVoltageSrc(QString name, QString Magnitude);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void setMagnitude(double magnitude);
    void setName(QString name);
    double getMagnitude() ;
    void setConst(QString name);
    QString getName();
    QString getConstName();
    QPointF getPos();
    qreal getRot();
private:
    QString name;
    double Magnitude;
    QString ConstName;
};

#endif // DEPVOLTAGESRC_H
