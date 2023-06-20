#include "displaydiagnostic.h"
#include "ui_displaydiagnostic.h"

DisplayDiagnostic::DisplayDiagnostic(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DisplayDiagnostic)
{
    ui->setupUi(this);
    HideAllLabels();
}

DisplayDiagnostic::~DisplayDiagnostic()
{
    delete ui;
}

void DisplayDiagnostic::HideAllLabels()
{
    ui -> comboBox_3 -> hide();
    ui -> comboBox_2 -> hide();
    ui -> comboBox -> hide();
    ui -> groupBox_8 -> hide();
    ui -> groupBox_7 -> hide();
    ui -> groupBox_6 -> hide();
    ui -> groupBox_5 -> hide();
    ui -> groupBox_4 -> hide();
    ui -> groupBox_3 -> hide();
    ui -> groupBox_2 -> hide();
}

void DisplayDiagnostic::ShowColorTest(int index)
{
    if(index == 0)
    {
        ui -> groupBox_8 -> hide();
        ui -> groupBox_7 ->setGeometry(460,140,181,151);
        ui -> groupBox_7 -> show();
        ui -> groupBox_7 -> setcolor(green);
    }
    else if(index == 1)
    {
        ui -> groupBox_7 -> hide();
        ui -> groupBox_8 ->setGeometry(460,140,231,121);
        ui -> groupBox_8 -> show();

    }
}



void DisplayDiagnostic::on_pushButton_3_clicked()
{
    HideAllLabels();
    ui -> comboBox -> show();
    ui -> comboBox -> setGeometry(510,90,281,41);
    ShowColorTest(ui -> comboBox -> currentIndex());
}


void DisplayDiagnostic::on_comboBox_currentIndexChanged(int index)
{
    ShowColorTest(index);
}

