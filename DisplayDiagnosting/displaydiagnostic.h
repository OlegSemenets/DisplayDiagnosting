#ifndef DISPLAYDIAGNOSTIC_H
#define DISPLAYDIAGNOSTIC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DisplayDiagnostic; }
QT_END_NAMESPACE

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

private:

    Ui::DisplayDiagnostic *ui;
    void HideAllLabels();
    void ShowColorTest(int index);
    void ShowCaliberTest(int index);
    void ShowGridTest(int index);

};
#endif // DISPLAYDIAGNOSTIC_H
