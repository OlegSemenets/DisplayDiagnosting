
#include "GUI/Headers/autotestsettings.h"
#include "ui_autotestsettings.h"

#include <QMessageBox>

AutoTestSettings::AutoTestSettings(size_t &delay, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Налаштування");
    m_Delay = &delay;
    ui->spinBox->setRange(1, 20);
    ui->spinBox->setValue(delay);
    setFixedSize(QSize(357, 222));
}

AutoTestSettings::~AutoTestSettings()
{
    delete quitAction;
    delete ui;
}

void AutoTestSettings::SetCurrentDelay()
{
    ui->spinBox->setValue(*m_Delay);
}

void AutoTestSettings::on_pushButton_clicked()
{
    *m_Delay = ui->spinBox->value();
    QMessageBox messageBox;
    messageBox.setStyleSheet("background-color: white;");
    messageBox.setWindowTitle("Примітка!");
    messageBox.setText("Інформація збережена!");
    messageBox.exec();
}
