/********************************************************************************
** Form generated from reading UI file 'adddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOG_H
#define UI_ADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AddDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_6;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_7;
    QLabel *label_5;

    void setupUi(QDialog *AddDialog)
    {
        if (AddDialog->objectName().isEmpty())
            AddDialog->setObjectName(QStringLiteral("AddDialog"));
        AddDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(AddDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 91, 22));
        doubleSpinBox = new QDoubleSpinBox(AddDialog);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(60, 60, 62, 22));
        doubleSpinBox_2 = new QDoubleSpinBox(AddDialog);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(130, 60, 62, 22));
        doubleSpinBox_3 = new QDoubleSpinBox(AddDialog);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(60, 90, 62, 22));
        doubleSpinBox_4 = new QDoubleSpinBox(AddDialog);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(130, 90, 62, 22));
        label = new QLabel(AddDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 47, 13));
        label_2 = new QLabel(AddDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 47, 13));
        doubleSpinBox_5 = new QDoubleSpinBox(AddDialog);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setGeometry(QRect(60, 120, 62, 22));
        label_3 = new QLabel(AddDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 47, 13));
        doubleSpinBox_6 = new QDoubleSpinBox(AddDialog);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setGeometry(QRect(60, 150, 62, 22));
        label_4 = new QLabel(AddDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 150, 47, 13));
        doubleSpinBox_7 = new QDoubleSpinBox(AddDialog);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setGeometry(QRect(60, 180, 62, 22));
        label_5 = new QLabel(AddDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 180, 47, 13));

        retranslateUi(AddDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDialog)
    {
        AddDialog->setWindowTitle(QApplication::translate("AddDialog", "Dialog", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("AddDialog", "Regular ball", 0)
         << QApplication::translate("AddDialog", "Inelastic Ball", 0)
        );
        label->setText(QApplication::translate("AddDialog", "Position", 0));
        label_2->setText(QApplication::translate("AddDialog", "Velocity", 0));
        label_3->setText(QApplication::translate("AddDialog", "Mass", 0));
        label_4->setText(QApplication::translate("AddDialog", "Radius", 0));
        label_5->setText(QApplication::translate("AddDialog", "Elasticity", 0));
    } // retranslateUi

};

namespace Ui {
    class AddDialog: public Ui_AddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
