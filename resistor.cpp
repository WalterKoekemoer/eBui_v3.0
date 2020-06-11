#include "resistor.h"

Resistor::Resistor(QString name, QString Magnitude)
{
    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptDrops(true);
    setAcceptDrops(true);
    this->name = name;
    bool *ok = nullptr;
    this->Magnitude = Magnitude.toDouble(ok);
    ConstName = name;
}

void Resistor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawEllipse(22.5,-5,5,5);

    painter->drawLine(25,0,25,5);

    painter->drawLine(25,5,35,15);
    painter->drawLine(35,15,15,25);
    painter->drawLine(15,25,35,35);
    painter->drawLine(35,35,25,45);

    painter->drawLine(25,45, 25,50);

    painter->drawEllipse(22.5,50,5,5);

    char f = 'g';
    painter->drawText(50,20,name);
    painter->drawText(50,30,QString::number(Magnitude,f,6));
}

QRectF Resistor::boundingRect() const
{
    return QRect(0,0,50,50);
}

void Resistor::setMagnitude(double magnitude)
{
    this->Magnitude = magnitude;
}

void Resistor::setName(QString name)
{
    this->name = name;
}

double Resistor::getMagnitude()
{
    return Magnitude;
}

void Resistor::setConst(QString name)
{
    this->ConstName = name;
}

QString Resistor::getConstName()
{
    return ConstName;
}

QString Resistor::getName()
{
    return name;
}

QPointF Resistor::getPos()
{
    return pos();
}

qreal Resistor::getRot()
{
    return rotation();
}



