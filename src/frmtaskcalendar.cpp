#include "headers/frmtaskcalendar.h"
#include "ui_frmtaskcalendar.h"
#include "headers/frmaddnote.h"

frmTaskCalendar::frmTaskCalendar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmTaskCalendar)
{    
    ui->setupUi(this);
    connect( this->ui->calendarWidget, SIGNAL(clicked(QDate)), parent, SLOT(on_calendarWidget_clicked(QDate)) );
}

frmTaskCalendar::~frmTaskCalendar()
{
    delete ui;
}
