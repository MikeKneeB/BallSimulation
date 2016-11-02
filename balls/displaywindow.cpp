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
    fUpTimer->start(5);

    fTimer = new QTimer(this);
    connect(fTimer, SIGNAL(timeout()), this, SLOT(update()));
    fTimer->start(5);

    show();

}

DisplayWindow::~DisplayWindow()
{
    delete ui;
    delete fTimer;
    delete fUpTimer;
}

void DisplayWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setBrush(Qt::black);

    double x, y, r;

    for (int i = 0; i != fField->GetSize(); i++)
    {
        r = fField->GetBall(i).GetRadius();
        x = fField->GetBall(i).GetPos().GetX();
        y = fField->GetBall(i).GetPos().GetY();
        painter.drawEllipse(x - r, y - r, 2*r, 2*r);
    }
}

void DisplayWindow::toggleSimulation()
{
    if (fRunning)
    {
        fUpTimer->stop();
        fTimer->stop();
        fRunning = false;
    }
    else
    {
        fUpTimer->start(5);
        fTimer->start(5);
        fRunning = true;
    }
}

bool DisplayWindow::running()
{
    return fRunning;
}

void DisplayWindow::closeEvent(QCloseEvent *event)
{
    QWidget::closeEvent(event);
}

void DisplayWindow::updateEngine()
{
    fField->Update();
}
