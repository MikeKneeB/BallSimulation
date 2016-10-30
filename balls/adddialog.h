#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

#include"field.h"

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(Field * field, QWidget *parent = 0);
    ~AddDialog();

private slots:
    void on_buttonBox_accepted();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::AddDialog *ui;
    Field * fField;
};

#endif // ADDDIALOG_H
