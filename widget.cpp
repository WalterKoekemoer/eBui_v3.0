#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    view = ui->graphicsView;


    this->scene = new MainScene(ui->graphicsView->parent());
    view->setScene(scene);

    QMessageBox *msg = new QMessageBox();
    msg->information(this,"Program usage","Here follows basic instructions to use the program:\n\n"
                                          "1.Create your component\n"
                                          "2.Save the component to the component library\n"
                                          "3.Locate that directory and retrieve any saved item by selecting all files when in component directory\n"
                                          "4.Connect your components\n"
                                          "5.Add power source\n"
                                          "6.Simulate the circuit\n"
                                          "7.Save your work\n");
    VScount = 0;

}

Widget::~Widget()
{
    delete ui;

}

void Widget::on_AddComponent_clicked()
{
    scene->timer->stop();

    component = new AddComponent(this);
    component->setModal(true);
    component->exec();

    scene->timer->start();
}



void Widget::on_Open_clicked()
{
    QString Jason_filter = "JSON (*.json)";
    path = QFileDialog::getOpenFileName(this,tr("Open File"),"/eBui/Components",
                                        tr("Any file (*);;%1").arg(Jason_filter),
                                        &Jason_filter,
                                        QFileDialog::DontUseNativeDialog);

    OpenFile(path);

    addRoot(path);
}

void Widget::OpenFile(QString path)
{
    if(path.isEmpty())
    {

    }else
    {
        QJsonDocument doc;
        QJsonArray Components;
        QByteArray data_jason;
        QJsonObject Component;
        QJsonArray ComponentData;
        QFile input(path);
        if(input.open(QIODevice::ReadOnly) | QIODevice::Text)
        {
            data_jason = input.readAll();
            doc = doc.fromJson(data_jason);
            Components = doc.array();
            int Avalx = 0;
            int Avaly = 0;
            int Bvalx = 0;
            int Bvaly = 0;
            int linkNum = 0;
            for(int i = 0; i < Components.size();i++)
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
                    this->inductor = new Inductor(Name,Magnitude);
                    inductor->setPos(XPos.toDouble(ok),YPos.toDouble(ok));
                    inductor->setRotation(Rotation.toDouble(ok));
                    inductor->setConst(ConstName);

                    scene->addItem(inductor);

                }else if(Component["Dependent Current Source"].isArray())
                {
                    ComponentData = Component["Dependent Current Source"].toArray();
                    QString Name = ComponentData[0].toString();
                    QString ConstName = ComponentData[1].toString();
                    QString Rotation = ComponentData[2].toString();
                    QString XPos = ComponentData[3].toString();
                    QString YPos = ComponentData[4].toString();
                    QString Magnitude = ComponentData[5].toString();

                    bool *ok = nullptr;
                    this->DCS = new depCurrentSrc(Name,Magnitude);
                    DCS->setPos(XPos.toDouble(ok),YPos.toDouble(ok));
                    DCS->setRotation(Rotation.toDouble(ok));
                    DCS->setConst(ConstName);

                    scene->addItem(DCS);

                }else if(Component["Dependent Voltage Source"].isArray())
                {
                    ComponentData = Component["Dependent Voltage Source"].toArray();
                    QString Name = ComponentData[0].toString();
                    QString ConstName = ComponentData[1].toString();
                    QString Rotation = ComponentData[2].toString();
                    QString XPos = ComponentData[3].toString();
                    QString YPos = ComponentData[4].toString();
                    QString Magnitude = ComponentData[5].toString();

                    bool *ok = nullptr;
                    this->DVS = new depVoltageSrc(Name,Magnitude);
                    DVS->setPos(XPos.toDouble(ok),YPos.toDouble(ok));
                    DVS->setRotation(Rotation.toDouble(ok));
                    DVS->setConst(ConstName);

                    scene->addItem(DVS);

                }else if(Component["Resistor"].isArray())
                {
                    ComponentData = Component["Resistor"].toArray();
                    QString Name = ComponentData[0].toString();
                    QString ConstName = ComponentData[1].toString();
                    QString Rotation = ComponentData[2].toString();
                    QString XPos = ComponentData[3].toString();
                    QString YPos = ComponentData[4].toString();
                    QString Magnitude = ComponentData[5].toString();

                    bool *ok = nullptr;
                    this->resistor = new Resistor(Name,Magnitude);
                    resistor->setPos(XPos.toDouble(ok),YPos.toDouble(ok));
                    resistor->setRotation(Rotation.toDouble(ok));
                    resistor->setConst(ConstName);

                    scene->addItem(resistor);

                }else if(Component["Capacitor"].isArray())
                {
                    ComponentData = Component["Capacitor"].toArray();
                    QString Name = ComponentData[0].toString();
                    QString ConstName = ComponentData[1].toString();
                    QString Rotation = ComponentData[2].toString();
                    QString XPos = ComponentData[3].toString();
                    QString YPos = ComponentData[4].toString();
                    QString Magnitude = ComponentData[5].toString();

                    bool *ok = nullptr;
                    this->cap = new Capacitor(Name,Magnitude);
                    cap->setPos(XPos.toDouble(ok),YPos.toDouble(ok));
                    cap->setRotation(Rotation.toDouble(ok));
                    cap->setConst(ConstName);

                    scene->addItem(cap);

                }else if(Component["Ax"].isArray())
                {
                    Avalx = i;
                }else if(Component["Ay"].isArray())
                {
                    Avaly = i ;
                }else if(Component["By"].isArray())
                {
                    Bvaly = i ;
                }else if(Component["Bx"].isArray())
                {
                    Bvalx = i ;
                }else if(Component["Connections"].isArray())
                {
                    linkNum = i;
                }
            }
            QJsonObject links = Components[linkNum].toObject();
            QJsonObject Axx = Components[Avalx].toObject();
            QJsonObject Ayy = Components[Avaly].toObject();
            QJsonObject Bxx = Components[Bvalx].toObject();
            QJsonObject Byy = Components[Bvaly].toObject();

            QJsonArray linkList = links["Connections"].toArray();
            QJsonArray Ax = Axx["Ax"].toArray();
            QJsonArray Ay = Ayy["Ay"].toArray();
            QJsonArray Bx = Bxx["Bx"].toArray();
            QJsonArray By = Byy["By"].toArray();

            for(int i = 0 ; i < linkList.size(); i++)
            {
                QString link = linkList[i].toString();
                ConnectionsList.push_back(link);
                if(link.at(0) == 'T' && link.at(1) == 'T')
                {
                    ComponentClass *AA = qgraphicsitem_cast<ComponentClass*>(scene->itemAt(Ax[i].toDouble(6) ,Ay[i].toDouble(6),QTransform()));
                    ComponentClass *BB = qgraphicsitem_cast<ComponentClass*>(scene->itemAt(Bx[i].toDouble(6) ,By[i].toDouble(6),QTransform()));
                    if(AA != nullptr && BB != nullptr)
                        scene->addItem(new wire(AA,BB,QPointF(Ax[i].toDouble(6),Ay[i].toDouble(6)),QPointF(Bx[i].toDouble(6) ,By[i].toDouble(6))));
                    else
                        qDebug() << "1" << QPointF(Ax[i].toDouble(6),Ay[i].toDouble(6)) << "B" << QPointF(Bx[i].toDouble(6) ,By[i].toDouble(6));
                }
                else if(link.at(0) == 'B' && link.at(1) == 'B')
                {
                    ComponentClass *AA = qgraphicsitem_cast<ComponentClass*>(scene->itemAt(Ax[i].toDouble(6) ,Ay[i].toDouble(6),QTransform()));
                    ComponentClass *BB = qgraphicsitem_cast<ComponentClass*>(scene->itemAt(Bx[i].toDouble(6) ,By[i].toDouble(6),QTransform()));
                    if(AA != nullptr && BB != nullptr)
                        scene->addItem(new wire(AA,BB,QPointF(Ax[i].toDouble(6),Ay[i].toDouble(6) + 30),QPointF(Bx[i].toDouble(6) ,By[i].toDouble(6) + 30)));
                    else
                        qDebug() << "2" << QPointF(Ax[i].toDouble(6),Ay[i].toDouble(6)) << "B" << QPointF(Bx[i].toDouble(6) ,By[i].toDouble(6));
                }
                else if(link.at(0) == 'B' && link.at(1) == 'T')
                {
                    ComponentClass *AA = qgraphicsitem_cast<ComponentClass*>(scene->itemAt(Ax[i].toDouble(6) ,Ay[i].toDouble(6),QTransform()));
                    ComponentClass *BB = qgraphicsitem_cast<ComponentClass*>(scene->itemAt(Bx[i].toDouble(6) ,By[i].toDouble(6),QTransform()));
                    if(AA != nullptr && BB != nullptr)
                        scene->addItem(new wire(AA,BB,QPointF(Ax[i].toDouble(6),Ay[i].toDouble(6) + 30),QPointF(Bx[i].toDouble(6) ,By[i].toDouble(6))));
                    else
                        qDebug() << "3" << QPointF(Ax[i].toDouble(6),Ay[i].toDouble(6)) << "B" << QPointF(Bx[i].toDouble(6) ,By[i].toDouble(6));
                }
                else if(link.at(0) == 'T' && link.at(1) == 'B')
                {
                    ComponentClass *AA = qgraphicsitem_cast<ComponentClass*>(scene->itemAt(Ax[i].toDouble(6) ,Ay[i].toDouble(6),QTransform()));
                    ComponentClass *BB = qgraphicsitem_cast<ComponentClass*>(scene->itemAt(Bx[i].toDouble(6) ,By[i].toDouble(6),QTransform()));
                    if(AA != nullptr && BB != nullptr)
                        scene->addItem(new wire(AA,BB,QPointF(Ax[i].toDouble(6),Ay[i].toDouble(6)),QPointF(Bx[i].toDouble(6) ,By[i].toDouble(6) + 30)));
                    else
                        qDebug() << "4" << QPointF(Ax[i].toDouble(6),Ay[i].toDouble(6)) << "B" << QPointF(Bx[i].toDouble(6) ,By[i].toDouble(6));
                }
            }
        }else{
            QMessageBox::critical(this,tr("Error"),input.errorString());
        }
    }

}

void Widget::on_treeWidget_activated(const QModelIndex &index)
{
    QString ComponentName = index.data(Qt::DisplayRole).toString();
    if(ComponentName != "->Voltage Source")
    {
        OpenFile(ComponentName);
    }else
    {
        char f = 'g';
        QString count = QString::number(VScount++,f,6);
        this->Vcc = new VoltageSource("V" + count,"0");
        VS.push_back(Vcc);
        scene->addItem(Vcc);
    }
}

void Widget::addRoot(QString name)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
    item->setText(0,name);
    ui->treeWidget->addTopLevelItem(item);
}

void Widget::Update()
{
    scene->update();
    scene->CrntPos = ui->graphicsView->mapToScene(ui->graphicsView->mapFromGlobal(cursor().pos()));
    char f = 'g';
    if(abs(scene->CrntPos.x()) < view->rect().width()/2 && abs(scene->CrntPos.y()) < view->rect().height()/2)
        ui->label->setText("x: " + QString::number(scene->CrntPos.x(),f,6) + "  y: " + QString::number(scene->CrntPos.y(),f,6));
    else
        ui->label->setText("x:-- y:--");

}

void Widget::on_Simulate_clicked()
{
    for(int i = 0; i < scene->connectionList.size() ; i++)
    {
        ConnectionsList.push_back(scene->connectionList[i]->connectedComponents());
    }

    for(int i = 0; i < ConnectionsList.size(); i++)
    {
        qDebug() << ConnectionsList[i];
    }
}

void Widget::on_Wire_clicked(bool checked)
{
    checked ? scene->addWire = true: scene->addWire = false;
}
