#include "voltagesource.h"


VoltageSource::VoltageSource(QString name,QString Magnitude)
{
    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptDrops(true);
    this->name = name;
    bool *ok = nullptr;
    this->Magnitude = Magnitude.toDouble(ok);
}

void VoltageSource::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawEllipse(22.5,-5,5,5);

    painter->drawLine(25,0,25,5);

    painter->drawLine(25,10,25,18);
    painter->drawLine(21,14,29,14);

    painter->drawEllipse(5,5,40,40);

    painter->drawLine(21,32,29,32);

    painter->drawLine(25,45,25,50);

    painter->drawEllipse(22.5,50,5,5);

    char f = 'g';
    painter->drawText(50,20,name);
    painter->drawText(50,30,QString::number(Magnitude,f,6));

}

QRectF VoltageSource::boundingRect() const
{
    return QRect(0,0,50,50);
}

void VoltageSource::setMagnitude(double magnitude)
{
    this->Magnitude = magnitude;
}

void VoltageSource::setConst(QString name)
{
    this->ConstName = name;
}

void VoltageSource::setName(QString name)
{
    this->name = name;
}

double VoltageSource::getMagnitude()
{
    return Magnitude;
}

QString VoltageSource::getName()
{
    return name;
}

QString VoltageSource::getConstName()
{
    return ConstName;
}

QPointF VoltageSource::getPos()
{
    return pos();
}

qreal VoltageSource::getRot()
{
    return rotation();
}
