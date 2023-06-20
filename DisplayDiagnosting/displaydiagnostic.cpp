#include "displaydiagnostic.h"
#include "ui_displaydiagnostic.h"

DisplayDiagnostic::DisplayDiagnostic(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DisplayDiagnostic)
{
    ui->setupUi(this);
}

DisplayDiagnostic::~DisplayDiagnostic()
{
    delete ui;
}

