#include "GraDigwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraDigwindow GD;
    GD.show();
    return a.exec();
}
