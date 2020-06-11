#include "inductor.h"

Inductor::Inductor(QString name, QString Magnitude)
{
    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptDrops(true);
    this->name = name;
    bool *ok = nullptr;
    this->Magnitude = Magnitude.toDouble(ok);
    ConstName = name;
}

void Inductor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawEllipse(22.5,-5,5,5);

    painter->drawLine(25,0,25,5);

    painter->drawArc(QRectF(18.33,31.66, 13.33, 13.33), 270 * 16, 180 * 16);
    painter->drawArc(QRectF(18.33,18.33, 13.33, 13.33), 270 * 16, 180 * 16);
    painter->drawArc(QRectF(18.33,5, 13.33, 13.33), 270 * 16, 180 * 16);

    painter->drawLine(25,45,25,50);

    painter->drawEllipse(22.5,50,5,5);

    char f = 'g';
    painter->drawText(50,20,name);
    painter->drawText(50,30,QString::number(Magnitude,f,6));
}

QRectF Inductor::boundingRect() const
{
    return QRect(0,0,50,50);
}

void Inductor::setMagnitude(double magnitude)
{
    this->Magnitude = magnitude;
}

void Inductor::setName(QString name)
{
    this->name = name;
}

void Inductor::setConst(QString name)
{
    this->ConstName = name;
}

double Inductor::getMagnitude()
{
    return Magnitude;
}

QString Inductor::getName()
{
    return name;
}

QString Inductor::getConstName()
{
    return ConstName;
}

QPointF Inductor::getPos()
{
    return pos();
}

qreal Inductor::getRot()
{
    return rotation();
}

