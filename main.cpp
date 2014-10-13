#include "mainwindow.h"
#include <QApplication>
#include "dbmanager.h"

int main(int argc, char *argv[])
{
    DBManager *objDbManager = new DBManager();
    objDbManager->checkAndCreateDb();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
