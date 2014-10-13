#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "frmaddnote.h"
#include "constants.h"

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

void MainWindow::on_actAddNote_triggered()
{
    int hasExistingTab = checkifTabExists(ADD_NOTE_FORM_NAME);

    // Check if a tab with the objectName exists, if it does, don't add another tab
    // and set the add new tab as the active tab.
    if(hasExistingTab != -1) {
        this->ui->tbwMain->setCurrentIndex(hasExistingTab);
        return;
    }

    FrmAddNote *addNoteTab = new FrmAddNote(this->ui->tbwMain);
    addNoteTab->setObjectName(ADD_NOTE_FORM_NAME);
    addNoteTab->setToolTip("Add a note...");

    // Add a tab and set it as the current index.
    this->ui->tbwMain->setCurrentIndex(this->ui->tbwMain->addTab(addNoteTab, "Add a note..."));
}

int MainWindow::checkifTabExists(QString strTabName) {
    QTabWidget *qTab = this->ui->tbwMain;
    int tabCount = qTab->count();
    QWidget *qTempTab;
    for(int i = 0; i < tabCount; ++i) {
        qTempTab = qTab->widget(i);
        if(qTempTab->objectName() == strTabName) {
            return i;
        }
    }
    return -1;
}

void MainWindow::on_tbwMain_tabCloseRequested(int index)
{
    delete this->ui->tbwMain->widget(index);
}

QString MainWindow::getTabNameById(int index) {
    return this->ui->tbwMain->widget(index)->objectName();
}
