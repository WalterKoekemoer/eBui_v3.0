#include "wire2.h"

Wire2::Wire2(QGraphicsItem *compA, QGraphicsItem *compB, QPointF A, QPointF B)
{
    if(compA->type() == QGraphicsItem::UserType + 6)
    {

    }else
    {
        this->compA = qgraphicsitem_cast<ComponentClass*>(compA);
        this->compB = qgraphicsitem_cast<ComponentClass*>(compB);
        connection = this->compA->getConstName()+">"+this->compB->getConstName();
        //connection.insert(i,compA->getConstName()+"-"+compB->getConstName());
        //qDebug() << connection.first() << connection.last();
        if(this->compA->getRot() == 0)
        {
            if(this->compA->getPos().y() + 25 <= A.y())
            {
                this->A = true;
            }
            else if(this->compA->getPos().y() + 25  > A.y())
            {
                this->A = false;
            }
        }else {
            if(this->compA->getPos().x() - 25 >= A.x())
            {
                this->A = true;
            }
            else if(this->compA->getPos().x() - 25 < A.x())
            {
                this->A = false;

            }
        }
        if(this->compB->getRot() == 0)
        {
            if(this->compB->getPos().y() + 25 <= B.y())
            {
                this->B = true;
            }
            else if(this->compB->getPos().y() + 25  > B.y())
            {
                this->B = false;
            }
        }else {
            if(this->compB->getPos().x() - 25 >= B.x())
            {
                this->B = true;
            }
            else if(this->compB->getPos().x() - 25 < B.x())
            {
                this->B = false;
            }
        }
    }

}

void Wire2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

QRectF Wire2::boundingRect() const
{
    return QRectF();
}

QString Wire2::connectedComponents()
{
    return connection;
}



