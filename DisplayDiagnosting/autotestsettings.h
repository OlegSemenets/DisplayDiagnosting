
#ifndef AUTOTESTSETTINGS_H
#define AUTOTESTSETTINGS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
} // namespace Ui
QT_END_NAMESPACE

class AutoTestSettings : public QMainWindow
{
    Q_OBJECT

public:
    AutoTestSettings(size_t &delay, QWidget *parent = nullptr);
    ~AutoTestSettings();
    void SetCurrentDelay();

private slots:
    void on_pushButton_clicked();

private:
    // Private class members
    Ui::MainWindow *ui;
    size_t *m_Delay;
    QAction *quitAction{};
};

#endif // AUTOTESTSETTINGS_H
