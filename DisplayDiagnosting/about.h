
#ifndef ABOUT_H
#define ABOUT_H

#include <QMainWindow>
#include "ui_about.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class about;
} // namespace Ui
QT_END_NAMESPACE

class About : public QMainWindow
{
    Q_OBJECT

public:
    About(QWidget *parent = nullptr);
    ~About();

private:
    // Private class members
    Ui::about *ui;
};

#endif // ABOUT_H
