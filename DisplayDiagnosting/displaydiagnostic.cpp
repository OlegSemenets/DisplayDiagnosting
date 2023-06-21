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
    ui -> pushButton_5 -> hide();
    ui -> pushButton_6 -> hide();
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
    ui -> pushButton_5 -> show();
    ui -> pushButton_6 -> show();
    if(index == 0)
    {
        ui -> groupBox_8 -> hide();
        ui -> groupBox_7 ->setGeometry(410,170,361,271);
        ui -> groupBox_7 -> show();
    }
    else if(index == 1)
    {
        ui -> groupBox_7 -> hide();
        ui -> groupBox_8 ->setGeometry(410,170,361,271);
        ui -> groupBox_8 -> show();

    }
}

void DisplayDiagnostic::ShowCaliberTest(int index)
{
    ui -> pushButton_5 -> show();
    ui -> pushButton_6 -> show();
    if(index == 0)
    {
        ui -> groupBox_3 -> hide();
        ui -> groupBox_2 ->setGeometry(410,170,361,271);
        ui -> groupBox_2 -> show();
    }
    else if(index == 1)
    {
        ui -> groupBox_2 -> hide();
        ui -> groupBox_3 ->setGeometry(410,170,361,271);
        ui -> groupBox_3 -> show();

    }
}

void DisplayDiagnostic::ShowGridTest(int index)
{
    ui -> pushButton_5 -> show();
    ui -> pushButton_6 -> show();
    if(index == 0)
    {
        ui -> groupBox_6 -> hide();
        ui -> groupBox_5 ->setGeometry(410,170,361,271);
        ui -> groupBox_5 -> show();
    }
    else if(index == 1)
    {
        ui -> groupBox_5 -> hide();
        ui -> groupBox_6 ->setGeometry(410,170,361,271);
        ui -> groupBox_6 -> show();

    }
}



void DisplayDiagnostic::on_pushButton_3_clicked()
{
    HideAllLabels();
    ui -> comboBox -> show();
    ui -> comboBox -> setGeometry(450,110,291,51);
    ShowColorTest(ui -> comboBox -> currentIndex());
}


void DisplayDiagnostic::on_comboBox_currentIndexChanged(int index)
{
    ShowColorTest(index);
}


void DisplayDiagnostic::on_pushButton_4_clicked()
{
    HideAllLabels();
    ui -> comboBox_3 -> show();
    ui -> comboBox_3 -> setGeometry(450,110,291,51);
    ShowCaliberTest(ui -> comboBox_3 -> currentIndex());
}


void DisplayDiagnostic::on_comboBox_3_currentIndexChanged(int index)
{
    ShowCaliberTest(index);
}


void DisplayDiagnostic::on_pushButton_2_clicked()
{
    HideAllLabels();
    ui -> comboBox_2 -> show();
    ui -> comboBox_2 -> setGeometry(450,110,291,51);
    ShowGridTest(ui -> comboBox_2 -> currentIndex());
}


void DisplayDiagnostic::on_comboBox_2_currentIndexChanged(int index)
{
    ShowGridTest(index);
}


void DisplayDiagnostic::on_pushButton_1_clicked()
{
    HideAllLabels();
    ui -> pushButton_5 -> show();
    ui -> pushButton_6 -> show();
    ui -> groupBox_4 ->setGeometry(390,110,421,331);
    ui -> groupBox_4 -> show();

}

