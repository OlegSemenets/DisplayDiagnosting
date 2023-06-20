#include "displaydiagnostic.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DisplayDiagnostic w;
    w.show();
    return a.exec();
}
