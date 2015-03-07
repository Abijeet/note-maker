#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QtSql/QSqlDatabase>

class DBManager : public QObject
{
    Q_OBJECT
public:
    explicit DBManager();
    bool checkAndCreateDb();

private:
    QString dbLocation;
    QSqlDatabase db;
    bool checkAndOpenConnection();
    bool initializeDatabase();

signals:

public slots:

};

#endif // DBMANAGER_H
