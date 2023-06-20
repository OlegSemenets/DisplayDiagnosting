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

private:
    Ui::DisplayDiagnostic *ui;
};
#endif // DISPLAYDIAGNOSTIC_H
