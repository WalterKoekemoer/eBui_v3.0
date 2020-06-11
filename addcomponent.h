#ifndef ADDCOMPONENT_H
#define ADDCOMPONENT_H

#include <QDialog>
#include "subcomponetsscene.h"
#include "capacitor.h"
#include "inductor.h"
#include "resistor.h"
#include "depcurrentsrc.h"
#include "depvoltagesrc.h"
#include <connections.h>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

namespace Ui {
class AddComponent;
}

class AddComponent : public QDialog
{
    Q_OBJECT

public:
    explicit AddComponent(QWidget *parent = 0);
    ~AddComponent();
    QString path;

protected:
    void closeEvent(QCloseEvent *e);

private slots:
    void on_Btn_Inductor_released();

    void on_Btn_Capacitor_released();

    void on_Btn_Resistor_released();

    void on_Btn_DepCrnt_released();

    void on_Btn_DepVlt_released();

    void on_pushButton_clicked(bool checked);

    void on_buttonBox_accepted();

    void createFile();

public slots:
    void Update();

private:
    QPoint CrntPos;
    Ui::AddComponent *ui;
    SubComponetsScene *scene;
    int C = 0;
    int I = 0;
    int R = 0;
    int Cs = 0;
    int Vs = 0;
};

#endif // ADDCOMPONENT_H
