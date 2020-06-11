#ifndef COMPONENT_H
#define COMPONENT_H

#include <QGraphicsItem>
#include <QPainter>
#include <QWidget>

class ComponentClass : public QGraphicsItem
{
public:
    virtual void setMagnitude(double magnitude) = 0;
    virtual void setName(QString name) = 0;
    virtual void setConst(QString name) = 0;
    virtual double getMagnitude() = 0;
    virtual QString getName() = 0;
    virtual QString getConstName() = 0;
    virtual QPointF getPos() = 0;
    virtual qreal getRot() = 0;

};


#endif // COMPONENT_H
