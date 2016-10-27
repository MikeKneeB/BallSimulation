#include <memory>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "displaywindow.h"
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
    fField->SetGrav(TwoVector(10,10));
    fField->SetTime(0.1);

    Win = new DisplayWindow(fField, this);

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    fField->AddBall(std::unique_ptr<Ball>(new RegularBall(TwoVector(300,200),TwoVector(10,0), 20, 0.4, fField)));
}
