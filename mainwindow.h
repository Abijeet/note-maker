#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actAddNote_triggered();
    void on_tbwMain_tabCloseRequested(int index);

private:
    Ui::MainWindow *ui;
    int checkifTabExists(QString);
    QString getTabNameById(int);
};

#endif // MAINWINDOW_H
