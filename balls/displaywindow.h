#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include <QTimer>

#include "field.h"

namespace Ui {
class DisplayWindow;
}

class DisplayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayWindow(Field * field, QWidget *parent = 0);
    ~DisplayWindow();

private slots:
    void paintEvent(QPaintEvent *);
    void updateEngine();
    void closeEvent(QCloseEvent *);

    void on_pushButton_clicked();

private:
    Ui::DisplayWindow *ui;
    Field * fField;
    QTimer * fTimer;
    QTimer * fUpTimer;
    bool fRunning;
};

#endif // DISPLAYWINDOW_H
