#include "headers/frmaddnote.h"
#include "ui_frmaddnote.h"

FrmAddNote::FrmAddNote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmAddNote)
{
    ui->setupUi(this);
}

FrmAddNote::~FrmAddNote()
{
    delete ui;
}
