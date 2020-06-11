#include "capacitor.h"

Capacitor::Capacitor(QString name, QString Magnitude)
{
    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptDrops(true);
    this->name = name;
    this->ConstName = name;
    bool *ok = nullptr;
    this->Magnitude = Magnitude.toDouble(ok);
}

void Capacitor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawEllipse(22.5,-5,5,5);

    painter->drawLine(25,0,25,22);

    painter->drawLine(20,22,30,22);
    painter->drawLine(20,28,30,28);

    painter->drawLine(25,28,25,50);

    painter->drawEllipse(22.5,50,5,5);

    char f = 'g';
    painter->drawText(50,20,name);
    painter->drawText(50,30,QString::number(Magnitude,f,6));
}

QRectF Capacitor::boundingRect() const
{
    return QRect(0,0,50,50);
}

void Capacitor::setMagnitude(double magnitude)
{
    this->Magnitude = magnitude;
}

void Capacitor::setConst(QString name)
{
    this->ConstName = name;
}

void Capacitor::setName(QString name)
{
    this->name = name;
}

double Capacitor::getMagnitude()
{
    return Magnitude;
}

QString Capacitor::getName()
{
    return name;
}

QString Capacitor::getConstName()
{
    return ConstName;
}

QPointF Capacitor::getPos()
{
    return pos();
}

qreal Capacitor::getRot()
{
    return rotation();
}


