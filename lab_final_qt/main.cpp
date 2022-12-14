#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //clase llamada QApplication, "a" es el objeto de la clase
                                //esa clase está definida en un constructor
    MainWindow w;
    w.show();                   //es un metodo que está en la clase MainWindow
    return a.exec();
}
