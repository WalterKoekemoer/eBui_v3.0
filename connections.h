#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include <QGraphicsItem>
#include <QPainter>
#include <QString>
#include <QMap>

class Connections : public QGraphicsItem
{
public:
    virtual QString connectedComponents() = 0;
};

#endif // CONNECTIONS_H
