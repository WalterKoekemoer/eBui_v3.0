ifndef GROUND_H
#define GROUND_H

#include <QGraphicsItem>
#include <QPainter>
#include <QWidget>

class Ground : public QGraphicsItem
{
public:
    enum {TypeG = QGraphicsItem::UserType + 6 };
    int type() const
    {
        return TypeG;
    }
    Ground();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;


};

#endif // GROUND_H
