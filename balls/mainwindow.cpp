#include <memory>
#include <cmath>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "displaywindow.h"
#include "adddialog.h"
#include "twovector.h"
#include "regularball.h"
#include "field.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fField = new Field();
    fField->SetX(500);
    fField->SetY(500);
    fField->SetResistance(1);
    fField->SetGrav(TwoVector(0,0));
    fField->SetTime(0.01);

    fWin = new DisplayWindow(fField, this);
    fWin->move(10, 10);

    ui->horizontalSlider->setRange(-30, 30);
    ui->horizontalSlider_2->setRange(-30, 30);

    ui->horizontalSlider_3->setRange(0, 100);

    this->setWindowTitle("Ball Simulation");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete fField;
}

void MainWindow::on_pushButton_clicked()
{
    AddDialog * dialog = new AddDialog(fField, this);
    dialog->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    fWin->toggleSimulation();
    if (fWin->running())
    {
        ui->pushButton_2->setText("Pause");
    }
    else
    {
        ui->pushButton_2->setText("Play");
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    fField->SetGrav(TwoVector(ui->horizontalSlider->value(), ui->horizontalSlider_2->value()));
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    fField->SetGrav(TwoVector(ui->horizontalSlider->value(), ui->horizontalSlider_2->value()));
}

void MainWindow::on_pushButton_3_clicked()
{
    fField->ClearBalls();
    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider_2->setValue(0);
    fField->SetGrav(TwoVector(0,0));

}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    fField->SetResistance(std::pow(10,-0.1*ui->horizontalSlider_3->value()));
}
