#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/frmaddnote.h"
#include "headers/frmtaskcalendar.h"
#include "headers/constants.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tbwMain_tabCloseRequested(int index)
{
    delete this->ui->tbwMain->widget(index);
}

void MainWindow::on_actListNotes_triggered()
{
    frmTaskCalendar *taskCalendar = new frmTaskCalendar(this);
    this->ui->tbwMain->setCurrentIndex(this->ui->tbwMain->addTab(taskCalendar, "Your calendar"));
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    FrmAddNote *frmAddNote = new FrmAddNote(this);
    int currIndex = this->ui->tbwMain->addTab(frmAddNote, "Note for " + date.toString("ddd, d MMM yyyy"));
    this->ui->tbwMain->setCurrentIndex(currIndex);
}
