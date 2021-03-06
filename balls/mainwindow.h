#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "field.h"
#include "displaywindow.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class
 *
 * MainWindow QWidget, creates a field and a DisplayWindow. Has all the buttons
 * for affecting the simulation.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_pushButton_3_clicked();

    void on_horizontalSlider_3_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    DisplayWindow * fWin;
    Field * fField;
};

#endif // MAINWINDOW_H
