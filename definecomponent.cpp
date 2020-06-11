#include "definecomponent.h"
#include "ui_definecomponent.h"
#include <QDebug>

DefineComponent::DefineComponent(QList<QGraphicsItem *> components, QGraphicsItem *item) :
    ui(new Ui::DefineComponent)
{
    ui->setupUi(this);

    this->item = item;
    this->components = components;
    ComponentClass *comp = qgraphicsitem_cast<ComponentClass*>(item);
    ui->groupBox->setTitle(comp->getName());

    if(item->type() == QGraphicsItem::UserType + 1)
    {
       ui->lineEdit_3->setEnabled(false);
    }
    else if(item->type() == QGraphicsItem::UserType + 4)
    {
        ui->lineEdit_3->setEnabled(false);
    }
    else if(item->type() == QGraphicsItem::UserType + 5)
    {
        ui->lineEdit_3->setEnabled(false);
    }else if(item->type() == QGraphicsItem::UserType + 6)
    {
        ui->lineEdit_3->setEnabled(false);
        ui->lineEdit->setEnabled(false);
    }

}

DefineComponent::~DefineComponent()
{
    delete ui;
}

void DefineComponent::on_buttonBox_accepted()
{
    bool create = true;
    QString text = ui->lineEdit_2->text();
    if(!ui->lineEdit_2->text().isEmpty())
    {
        double multiplier;
        if(ui->lineEdit_2->text().data()[ui->lineEdit_2->text().size() - 1] == 'M')
            multiplier = pow(10,6);
        else if(ui->lineEdit_2->text().data()[ui->lineEdit_2->text().size() - 1] == 'k')
            multiplier = pow(10,3);
        else if(ui->lineEdit_2->text().data()[ui->lineEdit_2->text().size() - 1] == 'm')
            multiplier = pow(10,-3);
        else if(ui->lineEdit_2->text().data()[ui->lineEdit_2->text().size() - 1] == 'u')
            multiplier = pow(10,-6);
        else if(ui->lineEdit_2->text().data()[ui->lineEdit_2->text().size() - 1] == 'n')
            multiplier = pow(10,-9);
        else if(ui->lineEdit_2->text().data()[ui->lineEdit_2->text().size() - 1] == 'p')
            multiplier = pow(10,-12);
        else if(ui->lineEdit_2->text().data()[ui->lineEdit_2->text().size() - 1] == 'f')
            multiplier = pow(10,-15);
        else if(ui->lineEdit_2->text().data()[ui->lineEdit_2->text().size() - 1].isLetter())
        {
            multiplier = 1;
            text.chop(1);
        }
        else multiplier = 1;

        if(multiplier != 1)
            text.chop(1);

        for(int j = 0; j < text.size();j++)
        {
            if(text.data()[j].isLetter())
            {
                create = false;
                break;
            }
        }
        if(create)
        {

            if(item->type() == QGraphicsItem::UserType + 1)
            {
                Capacitor *capacitor = qgraphicsitem_cast<Capacitor*>(item);
                if(!ui->lineEdit->text().isEmpty())
                    capacitor->setName(ui->lineEdit->text());
                bool *ok = nullptr;
                capacitor->setMagnitude(text.toDouble(ok) * multiplier);
            }
            else if(item->type() == QGraphicsItem::UserType + 4)
            {
                Inductor *inductor = qgraphicsitem_cast<Inductor*>(item);
                if(!ui->lineEdit->text().isEmpty())
                    inductor->setName(ui->lineEdit->text());
                bool *ok = nullptr;
                inductor->setMagnitude(text.toDouble(ok) * multiplier);
            }
            else if(item->type() == QGraphicsItem::UserType + 5)
            {
                Resistor *resistor = qgraphicsitem_cast<Resistor*>(item);
                if(!ui->lineEdit->text().isEmpty())
                    resistor->setName(ui->lineEdit->text());
                bool *ok = nullptr;
                resistor->setMagnitude(text.toDouble(ok) * multiplier);
            }else if(item->type() == QGraphicsItem::UserType + 2)
            {
                bool found = false;
                depCurrentSrc *DCS = qgraphicsitem_cast<depCurrentSrc*>(item);
                for(int i = 0; i < components.size() ; i++)
                {
                    if(components[i]->type() == QGraphicsItem::UserType + 1)
                    {
                        Capacitor * comp = qgraphicsitem_cast<Capacitor*>(components[i]);
                        if(comp->getName() == ui->lineEdit_3->text())
                        {
                            found = true;
                            if(!ui->lineEdit->text().isEmpty())
                                DCS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                            else
                            {
                                QString sourceName = DCS->getName();
                                sourceName.chop(sourceName.indexOf('(',1));
                                DCS->setName(sourceName + "(" + comp->getName() + ")");
                            }
                            bool *ok = nullptr;
                            DCS->setMagnitude(text.toDouble(ok) * multiplier);
                            break;
                        }
                    }
                    else if(components[i]->type() == QGraphicsItem::UserType + 4)
                    {
                        Inductor * comp = qgraphicsitem_cast<Inductor*>(components[i]);
                        if(comp->getName() == ui->lineEdit_3->text())
                        {
                            found = true;
                            if(!ui->lineEdit->text().isEmpty())
                                DCS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                            else
                            {
                                QString sourceName = DCS->getName();
                                sourceName.chop(sourceName.indexOf('(',1));
                                DCS->setName(sourceName + "(" + comp->getName() + ")");
                            }
                            bool *ok = nullptr;
                            DCS->setMagnitude(text.toDouble(ok) * multiplier);
                            break;
                        }
                    }else if(components[i]->type() == QGraphicsItem::UserType + 5)
                    {
                        Resistor * comp = qgraphicsitem_cast<Resistor*>(components[i]);
                        if(comp->getName() == ui->lineEdit_3->text())
                        {
                            found = true;
                            if(!ui->lineEdit->text().isEmpty())
                                DCS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                            else
                            {
                                QString sourceName = DCS->getName();
                                sourceName.chop(sourceName.indexOf('(',1));
                                DCS->setName(sourceName + "(" + comp->getName() + ")");
                            }
                            bool *ok = nullptr;
                            DCS->setMagnitude(text.toDouble(ok) * multiplier);
                            break;
                        }
                    }
                }
                if(!found)
                {
                    QMessageBox::information(this,"Error!",ui->label_3->text() + " not found...");
                    create = false;
                }
            }else if(item->type() == QGraphicsItem::UserType + 3)
            {
                bool found = false;
                depVoltageSrc *DVS = qgraphicsitem_cast<depVoltageSrc*>(item);
                for(int i = 0; i < components.size() ; i++)
                {
                    if(components[i]->type() == QGraphicsItem::UserType + 1)
                    {
                        Capacitor * comp = qgraphicsitem_cast<Capacitor*>(components[i]);
                        if(comp->getName() == ui->lineEdit_3->text())
                        {
                            found = true;
                            if(!ui->lineEdit->text().isEmpty())
                                DVS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                            else
                            {
                                QString sourceName = DVS->getName();
                                sourceName.chop(sourceName.indexOf('(',1));
                                DVS->setName(sourceName + "(" + comp->getName() + ")");
                            }
                            bool *ok = nullptr;
                            DVS->setMagnitude(text.toDouble(ok) * multiplier);
                            break;
                        }
                    }
                    else if(components[i]->type() == QGraphicsItem::UserType + 4)
                    {
                        Inductor * comp = qgraphicsitem_cast<Inductor*>(components[i]);
                        if(comp->getName() == ui->lineEdit_3->text())
                        {
                            found = true;
                            if(!ui->lineEdit->text().isEmpty())
                                DVS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                            else
                            {
                                QString sourceName = DVS->getName();
                                sourceName.chop(sourceName.indexOf('(',1));
                                DVS->setName(sourceName + "(" + comp->getName() + ")");
                            }
                            bool *ok = nullptr;
                            DVS->setMagnitude(text.toDouble(ok) * multiplier);
                            break;
                        }
                    }else if(components[i]->type() == QGraphicsItem::UserType + 5)
                    {
                        Resistor * comp = qgraphicsitem_cast<Resistor*>(components[i]);
                        if(comp->getName() == ui->lineEdit_3->text() )
                        {
                            found = true;
                            if(!ui->lineEdit->text().isEmpty())
                                DVS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                            else
                            {
                                QString sourceName = DVS->getName();
                                sourceName.chop(sourceName.indexOf('(',1));
                                DVS->setName(sourceName + "(" + comp->getName() + ")");
                            }
                            bool *ok = nullptr;
                            DVS->setMagnitude(text.toDouble(ok) * multiplier);
                            break;
                        }
                    }
                }
                if(!found)
                {
                    QMessageBox::information(this,"Error!",ui->lineEdit_3->text() + " not found...");
                    create = false;
                }
            }else if(item->type() == QGraphicsItem::UserType + 6)
            {
                bool *ok = nullptr;
                VoltageSource *VS = qgraphicsitem_cast<VoltageSource*>(item);
                VS->setMagnitude(text.toDouble(ok));

            }
        }
    }
}
        /*
        if(create)
        {
            if(components.size() == 1)
            {
                if(item->type() == QGraphicsItem::UserType + 1)
                {
                    Capacitor *capacitor = qgraphicsitem_cast<Capacitor*>(item);
                    capacitor->setName(ui->lineEdit->text());
                    bool *ok = nullptr;
                    capacitor->setMagnitude(text.toDouble(ok) * multiplier);
                }
                else if(item->type() == QGraphicsItem::UserType + 4)
                {
                    Inductor *inductor = qgraphicsitem_cast<Inductor*>(item);
                    inductor->setName(ui->lineEdit->text());
                    bool *ok = nullptr;
                    inductor->setMagnitude(text.toDouble(ok) * multiplier);
                }
                else if(item->type() == QGraphicsItem::UserType + 5)
                {
                    Resistor *resistor = qgraphicsitem_cast<Resistor*>(item);
                    resistor->setName(ui->lineEdit->text());
                    bool *ok = nullptr;
                    resistor->setMagnitude(text.toDouble(ok) * multiplier);
                }
            }else
            {

                for(int i = 0; i < components.size() ; i++)
                {
                    if(components[i]->type() == QGraphicsItem::UserType + 1)
                    {
                        Capacitor * comp = qgraphicsitem_cast<Capacitor*>(components[i]);
                        if(comp->getName() == ui->label->text())
                        {
                            create = false;
                            break;
                        }
                    }
                    else if(components[i]->type() == QGraphicsItem::UserType + 2)
                    {
                        depCurrentSrc * comp = qgraphicsitem_cast<depCurrentSrc*>(components[i]);
                        if(comp->getName() == ui->label->text())
                        {
                            create = false;
                            break;
                        }
                    }
                    else if(components[i]->type() == QGraphicsItem::UserType + 3)
                    {
                        depVoltageSrc * comp = qgraphicsitem_cast<depVoltageSrc*>(components[i]);
                        if(comp->getName() == ui->label->text())
                        {
                            create = false;
                            break;
                        }
                    }else if(components[i]->type() == QGraphicsItem::UserType + 4)
                    {
                        Inductor * comp = qgraphicsitem_cast<Inductor*>(components[i]);
                        if(comp->getName() == ui->label->text())
                        {
                            create = false;
                            break;
                        }
                    }else if(components[i]->type() == QGraphicsItem::UserType + 5)
                    {
                        Resistor * comp = qgraphicsitem_cast<Resistor*>(components[i]);
                        if(comp->getName() == ui->label->text())
                        {
                            create = false;
                            break;
                        }
                    }
                }
                if(!create)
                {
                    QMessageBox::information(this,"Error!",ui->label->text() + " already exists...");
                }else
                {

                    if(item->type() == QGraphicsItem::UserType + 1)
                    {
                        Capacitor *capacitor = qgraphicsitem_cast<Capacitor*>(item);
                        capacitor->setName(ui->lineEdit->text());
                        bool *ok = nullptr;
                        capacitor->setMagnitude(text.toDouble(ok) * multiplier);
                    }
                    else if(item->type() == QGraphicsItem::UserType + 4)
                    {
                        Inductor *inductor = qgraphicsitem_cast<Inductor*>(item);
                        inductor->setName(ui->lineEdit->text());
                        bool *ok = nullptr;
                        inductor->setMagnitude(text.toDouble(ok) * multiplier);
                    }
                    else if(item->type() == QGraphicsItem::UserType + 5)
                    {
                        Resistor *resistor = qgraphicsitem_cast<Resistor*>(item);
                        resistor->setName(ui->lineEdit->text());
                        bool *ok = nullptr;
                        resistor->setMagnitude(text.toDouble(ok) * multiplier);
                    }else if(item->type() == QGraphicsItem::UserType + 2)
                    {
                        bool found = false;
                        depCurrentSrc *DCS = qgraphicsitem_cast<depCurrentSrc*>(item);
                        for(int i = 0; i < components.size() ; i++)
                        {
                            if(components[i]->type() == QGraphicsItem::UserType + 1)
                            {
                                Capacitor * comp = qgraphicsitem_cast<Capacitor*>(components[i]);
                                if(comp->getName() == ui->lineEdit_3->text())
                                {
                                    found = true;
                                    DCS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                                    bool *ok = nullptr;
                                    DCS->setMagnitude(text.toDouble(ok) * multiplier);
                                    break;
                                }
                            }
                            else if(components[i]->type() == QGraphicsItem::UserType + 2)
                            {
                                depCurrentSrc * comp = qgraphicsitem_cast<depCurrentSrc*>(components[i]);
                                if(comp->getName() == ui->lineEdit_3->text())
                                {
                                    found = true;
                                    DCS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                                    bool *ok = nullptr;
                                    DCS->setMagnitude(text.toDouble(ok) * multiplier);
                                    break;
                                }
                            }
                            else if(components[i]->type() == QGraphicsItem::UserType + 3)
                            {
                                depVoltageSrc * comp = qgraphicsitem_cast<depVoltageSrc*>(components[i]);
                                if(comp->getName() == ui->lineEdit_3->text())
                                {
                                    found = true;
                                    DCS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                                    bool *ok = nullptr;
                                    DCS->setMagnitude(text.toDouble(ok) * multiplier);
                                    break;
                                }
                            }else if(components[i]->type() == QGraphicsItem::UserType + 4)
                            {
                                Inductor * comp = qgraphicsitem_cast<Inductor*>(components[i]);
                                if(comp->getName() == ui->lineEdit_3->text())
                                {
                                    found = true;
                                    DCS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                                    bool *ok = nullptr;
                                    DCS->setMagnitude(text.toDouble(ok) * multiplier);
                                    break;
                                }
                            }else if(components[i]->type() == QGraphicsItem::UserType + 5)
                            {
                                Resistor * comp = qgraphicsitem_cast<Resistor*>(components[i]);
                                if(comp->getName() == ui->lineEdit_3->text())
                                {
                                    found = true;
                                    DCS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                                    bool *ok = nullptr;
                                    DCS->setMagnitude(text.toDouble(ok) * multiplier);
                                    break;
                                }
                            }
                        }
                        if(!found)
                        {
                            QMessageBox::information(this,"Error!",ui->label_3->text() + " not found...");
                            create = false;
                        }
                    }else
                    {
                        bool found = false;
                        depVoltageSrc *DVS = qgraphicsitem_cast<depVoltageSrc*>(item);
                        for(int i = 0; i < components.size() ; i++)
                        {
                            if(components[i]->type() == QGraphicsItem::UserType + 1)
                            {
                                Capacitor * comp = qgraphicsitem_cast<Capacitor*>(components[i]);
                                if(comp->getName() == ui->lineEdit_3->text())
                                {
                                    found = true;
                                    DVS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                                    bool *ok = nullptr;
                                    DVS->setMagnitude(text.toDouble(ok) * multiplier);
                                    break;
                                }
                            }
                            else if(components[i]->type() == QGraphicsItem::UserType + 2)
                            {
                                depCurrentSrc * comp = qgraphicsitem_cast<depCurrentSrc*>(components[i]);
                                if(comp->getName() == ui->lineEdit_3->text())
                                {
                                    found = true;
                                    DVS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                                    bool *ok = nullptr;
                                    DVS->setMagnitude(text.toDouble(ok) * multiplier);
                                    break;
                                }
                            }
                            else if(components[i]->type() == QGraphicsItem::UserType + 3)
                            {
                                depVoltageSrc * comp = qgraphicsitem_cast<depVoltageSrc*>(components[i]);
                                if(comp->getName() == ui->lineEdit_3->text())
                                {
                                    found = true;
                                    DVS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                                    bool *ok = nullptr;
                                    DVS->setMagnitude(text.toDouble(ok) * multiplier);
                                    break;
                                }
                            }else if(components[i]->type() == QGraphicsItem::UserType + 4)
                            {
                                Inductor * comp = qgraphicsitem_cast<Inductor*>(components[i]);
                                if(comp->getName() == ui->lineEdit_3->text())
                                {
                                    found = true;
                                    DVS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                                    bool *ok = nullptr;
                                    DVS->setMagnitude(text.toDouble(ok) * multiplier);
                                    break;
                                }
                            }else if(components[i]->type() == QGraphicsItem::UserType + 5)
                            {
                                Resistor * comp = qgraphicsitem_cast<Resistor*>(components[i]);
                                if(comp->getName() == ui->lineEdit_3->text() )
                                {
                                    found = true;
                                    DVS->setName(ui->lineEdit->text() + "(" + comp->getName() + ")");
                                    bool *ok = nullptr;
                                    DVS->setMagnitude(text.toDouble(ok) * multiplier);
                                    break;
                                }
                            }
                        }
                        if(!found)
                        {
                            QMessageBox::information(this,"Error!",ui->lineEdit_3->text() + " not found...");
                            create = false;
                        }
                    }
                }
            }
        }
    }
}
*/

