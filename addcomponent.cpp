#include "addcomponent.h"
#include "ui_addcomponent.h"
#include <QDebug>

AddComponent::AddComponent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComponent)
{
    ui->setupUi(this);

    this->scene = new SubComponetsScene(ui->graphicsView->parent());
    ui->graphicsView->setScene(scene);
}

AddComponent::~AddComponent()
{
    delete ui;
    scene->timer->stop();
    scene->~QGraphicsScene();
}


void AddComponent::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);
    scene->~SubComponetsScene();
}


void AddComponent::on_Btn_Inductor_released()
{
    scene->addItem(new Inductor("I" + QString::number(I++,10),"0"));
}


void AddComponent::on_Btn_Capacitor_released()
{
    scene->addItem(new Capacitor("C" + QString::number(C++,10),"0"));
}

void AddComponent::on_Btn_Resistor_released()
{
    scene->addItem(new Resistor("R" + QString::number(R++,10),"0"));

}

void AddComponent::on_Btn_DepCrnt_released()
{
    scene->addItem(new depCurrentSrc("Vx" + QString::number(Cs++,10),"0"));
}

void AddComponent::on_Btn_DepVlt_released()
{
    scene->addItem(new depVoltageSrc("Ix" + QString::number(Vs++,10),"0"));

}

void AddComponent::Update()
{
    scene->update();
    if(scene->addWire)
        scene->CrntPos = ui->graphicsView->mapToScene(ui->graphicsView->mapFromGlobal(cursor().pos()));
}

void AddComponent::on_pushButton_clicked(bool checked)
{
    checked ? scene->addWire = true: scene->addWire = false;
}

void AddComponent::on_buttonBox_accepted()
{
    createFile();
}


void AddComponent::createFile()
{
    QString Jason_filter = "JSON (*.json)";
    this->path = QFileDialog::getSaveFileName(this,tr("Save File"),"/",
                                              tr("Any file (*);;%1").arg(Jason_filter),
                                              &Jason_filter,
                                              QFileDialog::DontUseNativeDialog);

    if(path.isEmpty());
    else
    {
        QGraphicsView * view = ui->graphicsView;
        QJsonDocument doc;
        QJsonArray Components;

        char format = 'g';
        for(QGraphicsItem *item: view->scene()->items())
        {
            ComponentClass *comp = qgraphicsitem_cast<ComponentClass*>(item);


            if(item->type() == QGraphicsItem::UserType + 1)
            {
                QString Name = comp->getName();
                QString ConstName = comp->getConstName();
                QString Rotation = QString::number (comp->getRot() , format, 6 );
                QString XPos = QString::number (comp->getPos().x() , format, 6 );
                QString YPos = QString::number (comp->getPos().y() , format, 6 ) ;
                QString Magnitude = QString::number (comp->getMagnitude() , format, 15 );

                QJsonArray ComponentData;
                QJsonObject Component;

                ComponentData.push_back(Name);
                ComponentData.push_back(ConstName);
                ComponentData.push_back(Rotation);
                ComponentData.push_back(XPos);
                ComponentData.push_back(YPos);
                ComponentData.push_back(Magnitude);

                Component.insert("Capacitor", ComponentData);

                Components.push_back(Component);

            }else if(item->type() == QGraphicsItem::UserType + 2)
            {
                QString Name = comp->getName();
                QString ConstName = comp->getConstName();
                QString Rotation = QString::number (comp->getRot() , format, 6 );
                QString XPos = QString::number (comp->getPos().x() , format, 6 );
                QString YPos = QString::number (comp->getPos().y() , format, 6 ) ;
                QString Magnitude = QString::number (comp->getMagnitude() , format, 15 );

                QJsonArray ComponentData;
                QJsonObject Component;

                ComponentData.push_back(Name);
                ComponentData.push_back(ConstName);
                ComponentData.push_back(Rotation);
                ComponentData.push_back(XPos);
                ComponentData.push_back(YPos);
                ComponentData.push_back(Magnitude);

                Component.insert("Dependent Current Source", ComponentData);

                Components.push_back(Component);
            }else if(item->type() == QGraphicsItem::UserType + 3)
            {
                QString Name = comp->getName();
                QString ConstName = comp->getConstName();
                QString Rotation = QString::number (comp->getRot() , format, 6 );
                QString XPos = QString::number (comp->getPos().x() , format, 6 );
                QString YPos = QString::number (comp->getPos().y() , format, 6 ) ;
                QString Magnitude = QString::number (comp->getMagnitude() , format, 15 );

                QJsonArray ComponentData;
                QJsonObject Component;

                ComponentData.push_back(Name);
                ComponentData.push_back(ConstName);
                ComponentData.push_back(Rotation);
                ComponentData.push_back(XPos);
                ComponentData.push_back(YPos);
                ComponentData.push_back(Magnitude);

                Component.insert("Dependent Voltage Source", ComponentData);

                Components.push_back(Component);

            }else if(item->type() == QGraphicsItem::UserType + 4)
            {
                QString Name = comp->getName();
                QString ConstName = comp->getConstName();
                QString Rotation = QString::number (comp->getRot() , format, 6 );
                QString XPos = QString::number (comp->getPos().x() , format, 6 );
                QString YPos = QString::number (comp->getPos().y() , format, 6 ) ;
                QString Magnitude = QString::number (comp->getMagnitude() , format, 15 );

                QJsonArray ComponentData;
                QJsonObject Component;

                ComponentData.push_back(Name);
                ComponentData.push_back(ConstName);
                ComponentData.push_back(Rotation);
                ComponentData.push_back(XPos);
                ComponentData.push_back(YPos);
                ComponentData.push_back(Magnitude);

                Component.insert("Inductor", ComponentData);

                Components.push_back(Component);

            }else if(item->type() == QGraphicsItem::UserType + 5)
            {
                QString Name = comp->getName();
                QString ConstName = comp->getConstName();
                QString Rotation = QString::number (comp->getRot() , format, 6 );
                QString XPos = QString::number (comp->getPos().x() , format, 6 );
                QString YPos = QString::number (comp->getPos().y() , format, 6 ) ;
                QString Magnitude = QString::number (comp->getMagnitude() , format, 15 );

                QJsonArray ComponentData;
                QJsonObject Component;

                ComponentData.push_back(Name);
                ComponentData.push_back(ConstName);
                ComponentData.push_back(Rotation);
                ComponentData.push_back(XPos);
                ComponentData.push_back(YPos);
                ComponentData.push_back(Magnitude);

                Component.insert("Resistor", ComponentData);

                Components.push_back(Component);
            }

        }

        QJsonArray ConnectionsItems;
        for(Connections *item : scene->connectionList)
        {
            QString connection = item->connectedComponents();
            ConnectionsItems.push_back(connection);
        }
        QJsonObject Component;
        Component.insert("Connections", ConnectionsItems);
        Components.push_back(Component);

        QJsonArray WireAx;
        for(QPointF A : scene->WireA)
        {
            WireAx.push_back(A.x());
        }
        QJsonObject Ax;
        Ax.insert("Ax", WireAx);
        Components.push_back(Ax);

        QJsonArray WireAy;
        for(QPointF A : scene->WireA)
        {
            WireAy.push_back(A.y());
        }
        QJsonObject Ay;
        Ay.insert("Ay", WireAy);
        Components.push_back(Ay);

        QJsonArray WireBx;
        for(QPointF B : scene->WireB)
        {
            WireBx.push_back(B.x());
        }
        QJsonObject Bx;
        Bx.insert("Bx", WireBx);
        Components.push_back(Bx);

        QJsonArray WireBy;
        for(QPointF B : scene->WireB)
        {
            WireBy.push_back(B.y());
        }
        QJsonObject By;
        By.insert("By", WireBy);
        Components.push_back(By);

        doc.setArray(Components);
        QByteArray data_json = doc.toJson();
        qDebug() << doc.toJson();
        QFile out(path);

        if(out.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            out.write(data_json);
            out.close();
            QMessageBox::information(this,"Message:","Component Saved");
        }else
        {
            QMessageBox::warning(this,"Message:","Error, Not saved");
        }
    }
}
