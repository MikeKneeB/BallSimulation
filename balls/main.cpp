#include <QApplication>
#include <iostream>
#include <memory>

#include "twovector.h"
#include "regularball.h"
#include "field.h"
#include "mainwindow.h"


using namespace std;

void TestVector();
void TestField();

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

    TestField();

    return 0;
}

void TestVector()
{
    TwoVector vec_1;
    vec_1.SetX(3.5);
    vec_1.SetY(-0.5);

    TwoVector vec_2(2.1, 0);

    vec_1.Print();
    vec_2.Print();
    cout << endl;

    TwoVector vec_3;

    vec_3 = vec_1;
    vec_3.Print();
    cout << endl;

    vec_3 = vec_1 + vec_2;
    vec_3.Print();
    cout << endl;

    vec_3 = -vec_1;
    vec_3.Print();
    cout << endl;

    vec_3 = vec_2 - vec_1;
    vec_3.Print();
    cout << endl;

//    vec_3 = 3*vec_1;
//    vec_3.Print();
//    cout << endl;

    vec_3 = vec_1*3;
    vec_3.Print();
    cout << endl;

    cout << vec_2.Modulus() << ", " << vec_1.Modulus() << endl;

    cout << vec_2.Argument() << ", " << vec_1.Argument() << endl;

    cout << vec_1.Dot(vec_2) << endl;

}

void TestField()
{
    TwoVector vec_1(1, 1);

    Field field(20, 20, 0.0001, vec_1);

    field.Print();

    unique_ptr<Ball> refBall(new RegularBall(vec_1, vec_1, 1, 1, &field));

    field.AddBall(move(refBall));

    field.Print();

    field.GetBall(0).Print();

}


