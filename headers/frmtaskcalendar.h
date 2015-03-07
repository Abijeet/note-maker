#ifndef FRMTASKCALENDAR_H
#define FRMTASKCALENDAR_H

#include <QWidget>

namespace Ui {
class frmTaskCalendar;
}

class frmTaskCalendar : public QWidget
{
    Q_OBJECT

public:
    explicit frmTaskCalendar(QWidget *parent = 0);
    ~frmTaskCalendar();

private:
    Ui::frmTaskCalendar *ui;
};

#endif // FRMTASKCALENDAR_H
