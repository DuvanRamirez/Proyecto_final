#include "playing_in_dreams.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    playing_in_dreams w;
    w.show();
    return a.exec();
}
