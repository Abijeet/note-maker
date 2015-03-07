#ifndef FRMADDNOTE_H
#define FRMADDNOTE_H

#include <QWidget>

namespace Ui {
class FrmAddNote;
}

class FrmAddNote : public QWidget
{
    Q_OBJECT

public:
    explicit FrmAddNote(QWidget *parent = 0);
    ~FrmAddNote();

private:
    Ui::FrmAddNote *ui;
};

#endif // FRMADDNOTE_H
