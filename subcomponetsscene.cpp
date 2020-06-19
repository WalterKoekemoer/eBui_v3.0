#include "subcomponetsscene.h"
#include <Qt>

SubComponetsScene::SubComponetsScene(QObject *parent)
    : QGraphicsScene(parent)
{
    this->timer = new QTimer(parent);
    connect(timer,SIGNAL(timeout()),parent,SLOT(Update()));
    timer->start();

    connectComp = nullptr;
    addWire = false;
}

SubComponetsScene::~SubComponetsScene()
{

}

void SubComponetsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    if(!selectedItems().isEmpty() && !addWire)
    {
        item = selectedItems().first();
        DefineComponent thisComp(items(),item);
        thisComp.setModal(true);
        thisComp.exec();
    }else if(!selectedItems().isEmpty() && addWire)
    {
        if(connectComp == nullptr)
        {
            item = selectedItems().first();
            connectComp = qgraphicsitem_cast<ComponentClass*>(item);
            A = CrntPos;
        }else if(item != selectedItems().first())
        {
            item = selectedItems().first();
            Wire = new wire(connectComp,qgraphicsitem_cast<ComponentClass*>(item),A,CrntPos);
            addItem(Wire);
            connectionList.push_back(Wire);
            WireA.push_back(A);
            WireB.push_back(CrntPos);


            connectComp = nullptr;
        }
    }
}


void SubComponetsScene::keyPressEvent(QKeyEvent *keyEvent)
{

    QGraphicsItem * items = selectedItems().front();
    if(keyEvent->key() == Qt::Key_R && !selectedItems().isEmpty())
    {
        if(items->type() == QGraphicsItem::UserType + 1)
        {
            Capacitor *cap = qgraphicsitem_cast<Capacitor*>(items);
            cap->rotation() == 0 ? cap->setRotation(90):cap->setRotation(0);
        }
        else if(items->type() == QGraphicsItem::UserType + 2)
        {
            depCurrentSrc *DCS = qgraphicsitem_cast<depCurrentSrc*>(items);
            DCS->rotation() == 0 ? DCS->setRotation(90):DCS->setRotation(0);
        }
        else if(items->type() == QGraphicsItem::UserType + 3)
        {
            depVoltageSrc *DVS = qgraphicsitem_cast<depVoltageSrc*>(items);
            DVS->rotation() == 0 ? DVS->setRotation(90):DVS->setRotation(0);
        }
        else if(items->type() == QGraphicsItem::UserType + 4)
        {
            Inductor *inductor = qgraphicsitem_cast<Inductor*>(items);
            inductor->rotation() == 0 ? inductor->setRotation(90):inductor->setRotation(0);
        }
        else if(items->type() == QGraphicsItem::UserType + 5)
        {
            Resistor *resistor = qgraphicsitem_cast<Resistor*>(items);
            resistor->rotation() == 0 ? resistor->setRotation(90):resistor->setRotation(0);
        }
    }
}






