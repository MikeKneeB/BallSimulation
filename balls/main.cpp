#include <QApplication>
#include <iostream>
#include <memory>

#include "twovector.h"
#include "regularball.h"
#include "field.h"
#include "mainwindow.h"


using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

  //  TestField();

    return 0;
}


