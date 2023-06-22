#ifndef DISPLAYDIAGNOSTIC_H
#define DISPLAYDIAGNOSTIC_H

#include <QColor>
#include <QList>
#include <QMainWindow>

#include "calibraiontests.h"
#include "focustests.h"
#include "gradienttests.h"
#include "gridtests.h"
#include "readingtests.h"
#include "solidtests.h"

#include "about.h"
#include "autotestsettings.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class DisplayDiagnostic;
} // namespace Ui
QT_END_NAMESPACE

enum TestType { NONE = -1, SOLID = 0, CALIBRATION, WHITEGRID, READ, GRADIENT, FOCUS, BLACKGRID };
enum RunType { NONE_, AUTO, DEFAULT };

class DisplayDiagnostic : public QMainWindow
{
    Q_OBJECT

public:
    DisplayDiagnostic(QWidget *parent = nullptr);
    ~DisplayDiagnostic();

private slots:

    void on_pushButton_3_clicked();
    void on_comboBox_currentIndexChanged(int index);
    void on_pushButton_4_clicked();
    void on_comboBox_3_currentIndexChanged(int index);
    void on_pushButton_2_clicked();
    void on_comboBox_2_currentIndexChanged(int index);
    void on_pushButton_1_clicked();
    void on_pushButton_6_clicked();
    void on_action_2_triggered();
    void on_action_triggered();

    void on_settings_close();

    void on_pushButton_5_clicked();

    void on_action_3_triggered();

private:
    // приватні функції класу які відповідають за зміну вікон тестування
    void HideAllLabels();
    void ShowColorTest(int index);
    void ShowCaliberTest(int index);
    void ShowGridTest(int index);

    // функції які відповідають за запуск солід тесту
    void CheckSelectedSolidTests();
    void RunSolidTests(bool AutoTest = false);

    // функції які відповідають за тестування гардієнтом
    void CheckSelectedGradientTests();
    void RunGradientTests(bool AutoTest = false);

    // функції які відповідають за тестування читабильності
    void CheckSelectedReadingTests();
    void RunReadingTests(bool AutoTest = false);

    // функції які відповідають за калібрувальні тести
    void CheckSelectedCalibrationTests();
    void RunCalibrationTests(bool AutoTest = false);

    // функції які відповідають за фокусувальні тести
    void CheckFocusTests();
    void RunFocusTests(bool AutoTest = false);

    // функції які відповідають за сіткові тести
    void CheckGridTests();
    void RunGridTests(bool AutoTest = false);

private:
    // приватні поля класу
    Ui::DisplayDiagnostic *ui;
    TestType m_TestType;
    QList<QColor> m_ColorsList;
    QList<int> m_CodeList;
    size_t m_Delay;

private:
    // приватні поля класу які відповідають за тести
    SolidTests *solid;
    GradientTests *gradient;
    ReadingTests *reading;
    CalibraionTests *calibration;
    FocusTests *focus;
    GridTests *grid;
};

#endif // DISPLAYDIAGNOSTIC_H
