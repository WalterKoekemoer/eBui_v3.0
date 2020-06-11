#include "wire.h"

wire::wire(ComponentClass * compA, ComponentClass * compB, QPointF A, QPointF B)
{
    this->compA = compA;
    this->compB = compB;
    connection = compA->getConstName()+">"+compB->getConstName();
    //connection.insert(i,compA->getConstName()+"-"+compB->getConstName());
    //qDebug() << connection.first() << connection.last();
    if(compA->getRot() == 0)
    {
        if(compA->getPos().y() + 25 <= A.y())
        {
            this->A = true;
        }
        else if(compA->getPos().y() + 25  > A.y())
        {
            this->A = false;
        }
    }else {
        if(compA->getPos().x() - 25 >= A.x())
        {
            this->A = true;
        }
        else if(compA->getPos().x() - 25 < A.x())
        {
            this->A = false;

        }
    }
    if(compB->getRot() == 0)
    {
        if(compB->getPos().y() + 25 <= B.y())
        {
            this->B = true;
        }
        else if(compB->getPos().y() + 25  > B.y())
        {
            this->B = false;
        }
    }else {
        if(compB->getPos().x() - 25 >= B.x())
        {
            this->B = true;
        }
        else if(compB->getPos().x() - 25 < B.x())
        {
            this->B = false;
        }
    }

}

void wire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPointF p1;
    QPointF p2;
    QString TopBot;
    connection.clear();
    if(compA->getRot() == 0)
    {
        if(A)
        {
            p1 = QPointF(compA->getPos().x()  + 22.5,compA->getPos().y() + 50);
            TopBot = "T";
        }
        else
        {
            p1 = QPointF(compA->getPos().x()  + 22.5,compA->getPos().y() - 5);
            TopBot = "B";
        }
    }else {
        if(A)
        {
            p1 = QPointF(compA->getPos().x()  - 53,compA->getPos().y() + 22.5);
            TopBot = "T";
        }
        else
        {
            p1 = QPointF(compA->getPos().x()  + 3 ,compA->getPos().y() + 22.5);
            TopBot = "B";

        }
    }
    if(compB->getRot() == 0)
    {
        if(B)
        {
            p2  = QPointF(compB->getPos().x()  + 22.5,compB->getPos().y() + 50);
            TopBot = "T" + TopBot;
        }
        else
        {
            p2 = QPointF(compB->getPos().x()  + 22.5,compB->getPos().y() - 5);
            TopBot = "B" + TopBot;
        }
    }else {
        if(B)
        {
            p2 = QPointF(compB->getPos().x()  - 53.,compB->getPos().y() + 22.5);
            TopBot = "T" + TopBot;
        }
        else
        {
            p2 = QPointF(compB->getPos().x()  + 3 ,compB->getPos().y() + 22.5);
            TopBot = "B" + TopBot;
        }
    }
    connection = TopBot + compA->getConstName()+">"+compB->getConstName();
    //connection.insert(i, TopBot +compA->getConstName()+"-"+compB->getConstName());
    //qDebug() << connection[i];
    painter->drawLine(p1,p2);
}

QRectF wire::boundingRect() const
{
    return QRectF();
}

QString wire::connectedComponents()
{
    return connection;
}



