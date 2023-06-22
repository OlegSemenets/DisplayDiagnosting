#include "GUI/Headers/displaydiagnostic.h"
#include <QMessageBox>
#include "ui_displaydiagnostic.h"
#include <windows.h>

DisplayDiagnostic::DisplayDiagnostic(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DisplayDiagnostic)
    , m_Delay{4}
{
    ui->setupUi(this);
    settings_ui = nullptr;
    about = nullptr;
    solid = nullptr;
    gradient = nullptr;
    reading = nullptr;
    calibration = nullptr;
    focus = nullptr;
    grid = nullptr;
    HideAllLabels();
    m_TestType = NONE;
    setFixedSize(QSize(840, 568));
}

DisplayDiagnostic::~DisplayDiagnostic()
{
    if (solid != nullptr)
        delete solid;
    if (gradient != nullptr)
        delete gradient;
    if (reading != nullptr)
        delete reading;
    if (calibration != nullptr)
        delete calibration;
    if (focus != nullptr)
        delete focus;
    if (grid != nullptr)
        delete grid;
    if (settings_ui != nullptr)
        delete settings_ui;
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
        m_TestType = SOLID;
        ui -> groupBox_8 -> hide();
        ui -> groupBox_7 ->setGeometry(410,170,361,271);
        ui -> groupBox_7 -> show();
    }
    else if(index == 1)
    {
        m_TestType = GRADIENT;
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
        m_TestType = CALIBRATION;
        ui -> groupBox_3 -> hide();
        ui -> groupBox_2 ->setGeometry(410,170,361,271);
        ui -> groupBox_2 -> show();
    }
    else if(index == 1)
    {
        m_TestType = FOCUS;
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
        m_TestType = WHITEGRID;
        ui -> groupBox_6 -> hide();
        ui -> groupBox_5 ->setGeometry(410,170,361,271);
        ui -> groupBox_5 -> show();
    } else if (index == 1) {
        m_TestType = BLACKGRID;
        ui->groupBox_5->hide();
        ui->groupBox_6->setGeometry(410, 170, 361, 271);
        ui->groupBox_6->show();
    }
}

void DisplayDiagnostic::CheckSelectedSolidTests()
{
    if (!m_ColorsList.empty())
        m_ColorsList.clear();

    if (ui->checkBox_20->isChecked()) {
        m_ColorsList.push_back(QColor(255, 165, 0));
    }
    if (ui->checkBox_21->isChecked()) {
        m_ColorsList.push_back(QColor(Qt::white));
    }
    if (ui->checkBox_22->isChecked()) {
        m_ColorsList.push_back(QColor(Qt::red));
    }
    if (ui->checkBox_23->isChecked()) {
        m_ColorsList.push_back(QColor(Qt::black));
    }
}

void DisplayDiagnostic::RunSolidTests(bool AutoTest)
{
    CheckSelectedSolidTests();
    if (m_ColorsList.isEmpty()) {
        QMessageBox messageBox;
        messageBox.setStyleSheet("background-color: white;");
        messageBox.setWindowTitle("Помилка!");
        messageBox.setText("Ви не вибрали тест!");
        messageBox.exec();
        return;
    }

    solid = new SolidTests(AutoTest, m_Delay);
    solid->SetColorList(m_ColorsList);
    solid->showFullScreen();
    solid->MakeTest(0);
}

void DisplayDiagnostic::CheckSelectedGradientTests()
{
    if (!m_ColorsList.empty())
        m_ColorsList.clear();

    if (ui->checkBox_27->isChecked()) {
        m_ColorsList.push_back(QColor(Qt::yellow));
    }
    if (ui->checkBox_28->isChecked()) {
        m_ColorsList.push_back(QColor(Qt::green));
    }
    if (ui->checkBox_29->isChecked()) {
        m_ColorsList.push_back(QColor(Qt::blue));
    }
}
void DisplayDiagnostic::RunGradientTests(bool AutoTest)
{
    CheckSelectedGradientTests();
    if (m_ColorsList.isEmpty()) {
        QMessageBox messageBox;
        messageBox.setStyleSheet("background-color: white;");
        messageBox.setWindowTitle("Помилка!");
        messageBox.setText("Ви не вибрали тест!");
        messageBox.exec();
        return;
    }

    gradient = new GradientTests(AutoTest, m_Delay);
    gradient->SetGradientList(m_ColorsList);
    gradient->showFullScreen();
    gradient->MakeTest(0);
}

void DisplayDiagnostic::CheckSelectedReadingTests()
{
    if (!m_CodeList.empty())
        m_CodeList.clear();

    if (ui->checkBox_45->isChecked()) {
        m_CodeList.push_back(WhiteOnBlack);
    }
    if (ui->checkBox_46->isChecked()) {
        m_CodeList.push_back(BlackOnWhite);
    }
    if (ui->checkBox_47->isChecked()) {
        m_CodeList.push_back(BlueOnGreen);
    }
    if (ui->checkBox_48->isChecked()) {
        m_CodeList.push_back(YellowOnBlue);
    }
}
void DisplayDiagnostic::RunReadingTests(bool AutoTest)
{
    CheckSelectedReadingTests();
    if (m_CodeList.isEmpty()) {
        QMessageBox messageBox;
        messageBox.setStyleSheet("background-color: white;");
        messageBox.setWindowTitle("Помилка!");
        messageBox.setText("Ви не вибрали тест!");
        messageBox.exec();
        return;
    }

    reading = new ReadingTests(AutoTest, m_Delay);
    reading->SetReadingList(m_CodeList);
    reading->showFullScreen();
    reading->MakeTest(m_CodeList[0]);
}

void DisplayDiagnostic::CheckSelectedCalibrationTests()
{
    if (!m_CodeList.empty())
        m_CodeList.clear();

    if (ui->checkBox_30->isChecked()) {
        m_CodeList.push_back(LCD_);
    }
    if (ui->checkBox_31->isChecked()) {
        m_CodeList.push_back(SCOPE_);
    }
    if (ui->checkBox_32->isChecked()) {
        m_CodeList.push_back(BRIGHTNES_);
    }
}
void DisplayDiagnostic::RunCalibrationTests(bool AutoTest)
{
    CheckSelectedCalibrationTests();
    if (m_CodeList.isEmpty()) {
        QMessageBox messageBox;
        messageBox.setStyleSheet("background-color: white;");
        messageBox.setWindowTitle("Помилка!");
        messageBox.setText("Ви не вибрали тест!");
        messageBox.exec();
        return;
    }

    calibration = new CalibraionTests(AutoTest, m_Delay);
    calibration->SetCalibrationList(m_CodeList);
    calibration->showFullScreen();
    calibration->MakeTest(m_CodeList[0]);
}

void DisplayDiagnostic::CheckFocusTests()
{
    if (!m_CodeList.empty())
        m_CodeList.clear();

    if (ui->checkBox_33->isChecked()) {
        m_CodeList.push_back(WHITEPATTERN);
    }
    if (ui->checkBox_34->isChecked()) {
        m_CodeList.push_back(BLACKPATTERN);
    }
    if (ui->checkBox_35->isChecked()) {
        m_CodeList.push_back(SHARPNES);
    }
}

void DisplayDiagnostic::RunFocusTests(bool AutoTest)
{
    CheckFocusTests();
    if (m_CodeList.isEmpty()) {
        QMessageBox messageBox;
        messageBox.setStyleSheet("background-color: white;");
        messageBox.setWindowTitle("Помилка!");
        messageBox.setText("Ви не вибрали тест!");
        messageBox.exec();
        return;
    }

    focus = new FocusTests(AutoTest, m_Delay);
    focus->SetFocusList(m_CodeList);
    focus->showFullScreen();
    focus->MakeTest(m_CodeList[0]);
}

void DisplayDiagnostic::CheckGridTests()
{
    if (!m_ColorsList.empty())
        m_ColorsList.clear();
    if (m_TestType == WHITEGRID) {
        if (ui->checkBox_24->isChecked()) {
            m_ColorsList.push_back(QColor(Qt::red));
        }
        if (ui->checkBox_25->isChecked()) {
            m_ColorsList.push_back(QColor(Qt::yellow));
        }
        if (ui->checkBox_26->isChecked()) {
            m_ColorsList.push_back(QColor(Qt::green));
        }
        if (ui->checkBox_36->isChecked()) {
            m_ColorsList.push_back(QColor(Qt::black));
        }
    } else {
        if (ui->checkBox_37->isChecked()) {
            m_ColorsList.push_back(QColor(Qt::white));
        }
        if (ui->checkBox_38->isChecked()) {
            m_ColorsList.push_back(QColor(Qt::red));
        }
        if (ui->checkBox_39->isChecked()) {
            m_ColorsList.push_back(QColor(Qt::blue));
        }
        if (ui->checkBox_40->isChecked()) {
            m_ColorsList.push_back(QColor(Qt::green));
        }
    }
}
void DisplayDiagnostic::RunGridTests(bool AutoTest)
{
    CheckGridTests();
    if (m_ColorsList.isEmpty()) {
        QMessageBox messageBox;
        messageBox.setStyleSheet("background-color: white;");
        messageBox.setWindowTitle("Помилка!");
        messageBox.setText("Ви не вибрали тест!");
        messageBox.exec();
        return;
    }

    if (m_TestType == WHITEGRID)
        grid = new GridTests(AutoTest, m_Delay, QColor(Qt::white));
    else
        grid = new GridTests(AutoTest, m_Delay, QColor(Qt::black));
    grid->SetGridColorList(m_ColorsList);
    grid->showFullScreen();
    grid->MakeTest(0);
}

void DisplayDiagnostic::on_pushButton_3_clicked()
{
    m_TestType = SOLID;
    HideAllLabels();
    ui -> comboBox -> show();
    ui->comboBox->setCurrentIndex(0);
    ui -> comboBox -> setGeometry(450,110,291,51);
    ShowColorTest(ui -> comboBox -> currentIndex());
}


void DisplayDiagnostic::on_comboBox_currentIndexChanged(int index)
{
    ShowColorTest(index);
}

void DisplayDiagnostic::on_pushButton_4_clicked()
{
    m_TestType = CALIBRATION;
    HideAllLabels();
    ui -> comboBox_3 -> show();
    ui->comboBox_3->setCurrentIndex(0);
    ui -> comboBox_3 -> setGeometry(450,110,291,51);
    ShowCaliberTest(ui -> comboBox_3 -> currentIndex());
}

void DisplayDiagnostic::on_comboBox_3_currentIndexChanged(int index)
{
    ShowCaliberTest(index);
}

void DisplayDiagnostic::on_pushButton_2_clicked()
{
    m_TestType = WHITEGRID;
    HideAllLabels();
    ui -> comboBox_2 -> show();
    ui->comboBox_2->setCurrentIndex(0);
    ui -> comboBox_2 -> setGeometry(450,110,291,51);
    ShowGridTest(ui -> comboBox_2 -> currentIndex());
}

void DisplayDiagnostic::on_comboBox_2_currentIndexChanged(int index)
{
    ShowGridTest(index);
}

void DisplayDiagnostic::on_pushButton_1_clicked()
{
    m_TestType = READ;
    HideAllLabels();
    ui->pushButton_5->show();
    ui->pushButton_6->show();
    ui->groupBox_4->setGeometry(390, 110, 421, 331);
    ui -> groupBox_4 -> show();
}

void DisplayDiagnostic::on_pushButton_6_clicked()
{
    if (m_TestType == NONE)
        return;
    else if (m_TestType == SOLID) {
        RunSolidTests();
    } else if (m_TestType == GRADIENT) {
        RunGradientTests();
    } else if (m_TestType == READ) {
        RunReadingTests();
    } else if (m_TestType == CALIBRATION) {
        RunCalibrationTests();
    } else if (m_TestType == FOCUS) {
        RunFocusTests();
    } else {
        RunGridTests();
    }
}

void DisplayDiagnostic::on_action_2_triggered()
{
    this->close();
}

void DisplayDiagnostic::on_pushButton_5_clicked()
{
    if (m_TestType == NONE)
        return;
    else if (m_TestType == SOLID) {
        RunSolidTests(true);
    } else if (m_TestType == GRADIENT) {
        RunGradientTests(true);
    } else if (m_TestType == READ) {
        RunReadingTests(true);
    } else if (m_TestType == CALIBRATION) {
        RunCalibrationTests(true);
    } else if (m_TestType == FOCUS) {
        RunFocusTests(true);
    } else {
        RunGridTests(true);
    }
}


