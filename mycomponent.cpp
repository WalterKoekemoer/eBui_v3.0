#include "mycomponent.h"



MyComponent::MyComponent(QJsonArray Components,QList <QPointF> EndComp,QList <QPointF> WirePoints)
{
    this->Components = Components;
    this->WirePoints = WirePoints;
    this->EndComp = EndComp;

}

void MyComponent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget, QString identity)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QJsonObject Component;
    QJsonArray ComponentData;

    for(int i = 0 ; i < this->Components.size() ; i++)
    {
        Component = Components[i].toObject();

        if(Component["Inductor"].isArray())
        {
            ComponentData = Component["Inductor"].toArray();
            QString Name = ComponentData[0].toString();
            QString ConstName = ComponentData[1].toString();
            QString Rotation = ComponentData[2].toString();
            QString XPos = ComponentData[3].toString();
            QString YPos = ComponentData[4].toString();
            QString Magnitude = ComponentData[5].toString();

            bool *ok = nullptr;
            Inductor(painter,Name,Magnitude,QPointF(XPos.toDouble(ok),YPos.toDouble(ok)),Rotation.toDouble(ok));


        }else if(Component["Dependent Current Source"].isArray())
        {
            ComponentData = Component["Dependent Current Source"].toArray();
            QString Name = ComponentData[0].toString();
            QString ConstName = ComponentData[1].toString();
            QString Rotation = ComponentData[2].toString();
            QString XPos = ComponentData[3].toString();
            QString YPos = ComponentData[4].toString();
            QString Magnitude = ComponentData[5].toString();

            Names.push_back(Name);
            ConstNames.push_back(ConstName);
            Rotations.push_back(Rotation.toDouble(ok));
            Pos.push_back(QPointF(XPos.toDouble(ok),YPos.toDouble(ok)));
            Magnitudes.push_back(Magnitude);

        }else if(Component["Dependent Voltage Source"].isArray())
        {
            ComponentData = Component["Dependent Voltage Source"].toArray();
            QString Name = ComponentData[0].toString();
            QString ConstName = ComponentData[1].toString();
            QString Rotation = ComponentData[2].toString();
            QString XPos = ComponentData[3].toString();
            QString YPos = ComponentData[4].toString();
            QString Magnitude = ComponentData[5].toString();

            Names.push_back(Name);
            ConstNames.push_back(ConstName);
            Rotations.push_back(Rotation.toDouble(ok));
            Pos.push_back(QPointF(XPos.toDouble(ok),YPos.toDouble(ok)));
            Magnitudes.push_back(Magnitude);

        }else if(Component["Resistor"].isArray())
        {
            ComponentData = Component["Resistor"].toArray();
            QString Name = ComponentData[0].toString();
            QString ConstName = ComponentData[1].toString();
            QString Rotation = ComponentData[2].toString();
            QString XPos = ComponentData[3].toString();
            QString YPos = ComponentData[4].toString();
            QString Magnitude = ComponentData[5].toString();

            Names.push_back(Name);
            ConstNames.push_back(ConstName);
            Rotations.push_back(Rotation.toDouble(ok));
            Pos.push_back(QPointF(XPos.toDouble(ok),YPos.toDouble(ok)));
            Magnitudes.push_back(Magnitude);


        }else if(Component["Capacitor"].isArray())
        {
            ComponentData = Component["Capacitor"].toArray();
            QString Name = ComponentData[0].toString();
            QString ConstName = ComponentData[1].toString();
            QString Rotation = ComponentData[2].toString();
            QString XPos = ComponentData[3].toString();
            QString YPos = ComponentData[4].toString();
            QString Magnitude = ComponentData[5].toString();

            Names.push_back(Name);
            ConstNames.push_back(ConstName);
            Rotations.push_back(Rotation.toDouble(ok));
            Pos.push_back(QPointF(XPos.toDouble(ok),YPos.toDouble(ok)));
            Magnitudes.push_back(Magnitude);

        }
    }
}

QRectF MyComponent::boundingRect() const
{
    return QRect();
}

void MyComponent::Resistor(QPainter *painter, QString name, QString Magnitude,QPointF pos,qreal rotation())
{
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

void MyComponent::Capacitor(QPainter *painter, QString name, QString Magnitude,QPointF pos,qreal rotation())
{
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

void MyComponent::Inductor(QPainter *painter, QString name, QString Magnitude,QPointF pos,qreal rotation())
{
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

void MyComponent::DVS(QPainter *painter, QString name, QString Magnitude,QPointF pos,qreal rotation())
{
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

void MyComponent::DCS(QPainter *painter, QString name, QString Magnitude,QPointF pos,qreal rotation())
{
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
