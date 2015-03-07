#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QDate>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots :
    void on_calendarWidget_clicked(const QDate &date);

private slots:
    void on_tbwMain_tabCloseRequested(int index);

    void on_actListNotes_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
