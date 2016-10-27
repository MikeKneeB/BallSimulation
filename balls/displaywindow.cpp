#include <QTimer>
#include <QPainter>
#include <QCloseEvent>
#include <iostream>

#include "displaywindow.h"
#include "ui_displaywindow.h"
#include "field.h"
#include "ball.h"
#include "twovector.h"

DisplayWindow::DisplayWindow(Field * field, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayWindow)
{

    fRunning = true;

    ui->setupUi(this);
    fField = field;

    fUpTimer = new QTimer(this);
    connect(fUpTimer, SIGNAL(timeout()), this, SLOT(updateEngine()));
    fUpTimer->start(10);

    fTimer = new QTimer(this);
    connect(fTimer, SIGNAL(timeout()), this, SLOT(update()));
    fTimer->start(10);

    show();

}

DisplayWindow::~DisplayWindow()
{
    delete ui;
    delete fField;
    delete fTimer;
    delete fUpTimer;
    std::cout << "Display window destructor called." << std::endl;
}

void DisplayWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setBrush(Qt::black);

    for (int i = 0; i != fField->GetSize(); i++)
    {
        painter.drawEllipse(fField->GetBall(i).GetPos().GetX(),
                            fField->GetBall(i).GetPos().GetY(),
                            fField->GetBall(i).GetRadius(),
                            fField->GetBall(i).GetRadius());
    }
}

void DisplayWindow::closeEvent(QCloseEvent *event)
{
    QWidget::closeEvent(event);
}

void DisplayWindow::updateEngine()
{
    fField->Update();
}

//void DisplayWindow::on_pushButton_clicked()
//{
//    if (fRunning)
//    {
//        fUpTimer->stop();
//        fTimer->stop();
//        fRunning = false;
//    }
//    else
//    {
//        fUpTimer->start(10);
//        fTimer->start(10);
//        ui->pushButton->setText("Pause");
//        fRunning = true;
//    }
//}
