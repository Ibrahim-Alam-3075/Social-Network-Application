#include "project.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    project w;
    w.show();
    return a.exec();
}
