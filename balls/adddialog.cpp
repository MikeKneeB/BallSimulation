#include <memory>

#include "adddialog.h"
#include "ui_adddialog.h"
#include "field.h"
#include "ball.h"
#include "regularball.h"
#include "dragball.h"
#include "antiball.h"

AddDialog::AddDialog(Field * field, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    fField = field;
    ui->doubleSpinBox->setMaximum(500);
    ui->doubleSpinBox->setMinimum(0);
    ui->doubleSpinBox->setValue(250);
    ui->doubleSpinBox_2->setMaximum(500);
    ui->doubleSpinBox_2->setMinimum(0);
    ui->doubleSpinBox_2->setValue(250);
    ui->doubleSpinBox_3->setMaximum(500);
    ui->doubleSpinBox_3->setMinimum(-500);
    ui->doubleSpinBox_3->setValue(0);
    ui->doubleSpinBox_4->setMaximum(500);
    ui->doubleSpinBox_4->setMinimum(-500);
    ui->doubleSpinBox_4->setValue(0);
    ui->doubleSpinBox_5->setMaximum(100);
    ui->doubleSpinBox_5->setMinimum(0);
    ui->doubleSpinBox_5->setValue(10);
    ui->doubleSpinBox_6->setMaximum(50);
    ui->doubleSpinBox_6->setMinimum(1);
    ui->doubleSpinBox_6->setValue(10);

    this->setWindowTitle("Add Ball");

}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_buttonBox_accepted()
{
    if (ui->comboBox->currentIndex() == 0)
    {
        fField->AddBall(std::unique_ptr<Ball>(
                            new RegularBall(TwoVector(ui->doubleSpinBox->value(), ui->doubleSpinBox_2->value()),
                                            TwoVector(ui->doubleSpinBox_3->value(), ui->doubleSpinBox_4->value()),
                                            ui->doubleSpinBox_6->value(),
                                            ui->doubleSpinBox_5->value(),
                                            fField)));
    }
    else if (ui->comboBox->currentIndex() == 1)
    {
        fField->AddBall(std::unique_ptr<Ball>(
                            new AntiBall(TwoVector(ui->doubleSpinBox->value(), ui->doubleSpinBox_2->value()),
                                            TwoVector(ui->doubleSpinBox_3->value(), ui->doubleSpinBox_4->value()),
                                            ui->doubleSpinBox_6->value(),
                                            ui->doubleSpinBox_5->value(),
                                            fField)));
    }
    else if (ui->comboBox->currentIndex() == 2)
    {
        fField->AddBall(std::unique_ptr<Ball>(
                            new DragBall(TwoVector(ui->doubleSpinBox->value(), ui->doubleSpinBox_2->value()),
                                            TwoVector(ui->doubleSpinBox_3->value(), ui->doubleSpinBox_4->value()),
                                            ui->doubleSpinBox_6->value(),
                                            ui->doubleSpinBox_5->value(),
                                            fField)));
    }
}

void AddDialog::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if (ui->comboBox->currentIndex() == 0)
    {
        return;
    }
}
