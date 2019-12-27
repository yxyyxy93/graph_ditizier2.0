#include "GraDigwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraDigwindow GD;
    GD.show();
    try {
        int ret;
        ret = a.exec();
        return ret;
    } catch (...) {
        return EXIT_FAILURE; // exit the application
    }
}
