#include "depcurrentsrc.h"

depCurrentSrc::depCurrentSrc(QString name, QString Magnitude)
{
    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptDrops(true);
    this->name = name;
    bool *ok = nullptr;
    this->Magnitude = Magnitude.toDouble(ok);
    ConstName = name;
}

void depCurrentSrc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawEllipse(22.5,-5,5,5);

    painter->drawLine(25,0,25,5);

    painter->drawLine(25,10,25,40);
    painter->drawLine(25,10,29,15);
    painter->drawLine(25,10,21,15);

    painter->drawLine(0,25,25,5);
    painter->drawLine(50,25,25,5);
    painter->drawLine(50,25,25,45);
    painter->drawLine(0,25,25,45);

    painter->drawLine(25,45,25,50);

    painter->drawEllipse(22.5,50,5,5);

    char f = 'g';
    painter->drawText(50,50,QString::number(Magnitude,f,6) + name);
}

QRectF depCurrentSrc::boundingRect() const
{
    return QRect(0,0,50,50);
}

void depCurrentSrc::setMagnitude(double magnitude)
{
    this->Magnitude = magnitude;
}

void depCurrentSrc::setName(QString name)
{
    this->name = name;
}

void depCurrentSrc::setConst(QString name)
{
    this->ConstName = name;
}

double depCurrentSrc::getMagnitude()
{
    return Magnitude;
}

QString depCurrentSrc::getName()
{
    return name;
}

QString depCurrentSrc::getConstName()
{
    return ConstName;
}

QPointF depCurrentSrc::getPos()
{
    return pos();
}

qreal depCurrentSrc::getRot()
{
    return rotation();
}
