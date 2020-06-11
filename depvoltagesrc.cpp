#include "depvoltagesrc.h"

depVoltageSrc::depVoltageSrc(QString name, QString Magnitude)
{
    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptDrops(true);
    this->name = name;
    bool *ok = nullptr;
    this->Magnitude = Magnitude.toDouble(ok);
    ConstName = name;
}

void depVoltageSrc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawEllipse(22.5,-5,5,5);

    painter->drawLine(25,0,25,5);

    painter->drawLine(25,10,25,18);
    painter->drawLine(21,14,29,14);

    painter->drawLine(0,25,25,5);
    painter->drawLine(50,25,25,5);
    painter->drawLine(50,25,25,45);
    painter->drawLine(0,25,25,45);

    painter->drawLine(21,32,29,32);

    painter->drawLine(25,45,25,50);

    painter->drawEllipse(22.5,50,5,5);

    char f = 'g';
    painter->drawText(50,50,QString::number(Magnitude,f,6) + name);
}

QRectF depVoltageSrc::boundingRect() const
{
    return QRect(0,0,50,50);
}

void depVoltageSrc::setMagnitude(double magnitude)
{
    this->Magnitude = magnitude;
}

void depVoltageSrc::setName(QString name)
{
    this->name = name;
}

double depVoltageSrc::getMagnitude()
{
    return Magnitude;
}

void depVoltageSrc::setConst(QString name)
{
    this->ConstName = name;
}

QString depVoltageSrc::getName()
{
    return name;
}

QString depVoltageSrc::getConstName()
{
    return ConstName;
}

QPointF depVoltageSrc::getPos()
{
    return pos();
}

qreal depVoltageSrc::getRot()
{
    return rotation();
}

