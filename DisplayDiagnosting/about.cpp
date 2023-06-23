
#include "GUI/Headers/about.h"
#include "ui_about.h"

About::About(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::about)
{
    ui->setupUi(this);
    setFixedSize(QSize(400, 400));
}

About::~About()
{
    delete ui;
}
