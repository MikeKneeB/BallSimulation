#include <memory>

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
    fField->SetResistance(0);
    fField->SetGrav(TwoVector(0,0));
    fField->SetTime(0.01);

    Win = new DisplayWindow(fField, this);
    Win->move(10, 10);

    ui->horizontalSlider->setRange(-30, 30);
    ui->horizontalSlider_2->setRange(-30, 30);

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
    Win->toggleSimulation();
    if (Win->running())
    {
        ui->pushButton_2->setText("Pause");
    }
    else
    {
        ui->pushButton_2->setText("Play");
    }
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    fField->SetGrav(TwoVector(ui->horizontalSlider->value(), ui->horizontalSlider_2->value()));
}

void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
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
