#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include <QTimer>

#include "field.h"

namespace Ui {
class DisplayWindow;
}

/**
 * @brief The DisplayWindow class
 *
 * DisplayWindow QWidget, periodically updates and draws the field on the
 * screen.
 */
class DisplayWindow : public QWidget
{
    Q_OBJECT

public:
    //Explicit constructor, created by QT
    explicit DisplayWindow(Field * field, QWidget *parent = 0);
    ~DisplayWindow();

    //Play/pause simulation.
    void toggleSimulation();

    //Returns whether the simulation is running or not.
    bool running();

private slots:
    //Overwritten paint method, draws the simulation state.
    void paintEvent(QPaintEvent *);
    //updateEngine() simply calls the field's Update() method.
    void updateEngine();
    void closeEvent(QCloseEvent *);

private:
    Ui::DisplayWindow *ui;
    Field * fField;
    QTimer * fTimer;
    QTimer * fUpTimer;
    bool fRunning;
};

#endif // DISPLAYWINDOW_H
