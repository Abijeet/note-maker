#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QStandardPaths>
#include <QFile>

#include "headers/dbmanager.h"
#include "headers/constants.h"

DBManager::DBManager() {
    this->dbLocation = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/" + APPLICATION_DB;
}

bool DBManager::checkAndCreateDb() {
    if(!QFile::exists(this->dbLocation)) {
        this->db = QSqlDatabase::addDatabase(DB_TYPE);
        this->db.setDatabaseName(this->dbLocation);
        return this->initializeDatabase();
    }
    if(!this->db.open()) {
        return false;
    }
    this->db.close();
    return true;
}

bool DBManager::checkAndOpenConnection() {
    if(this->db.isOpen()) {
        return true;
    } else {
        return this->db.open();
    }
}

bool DBManager::initializeDatabase() {
    if(!this->checkAndOpenConnection()) {
        // TODO :: Error, do something here.
        return false;
    }
    QString notesTypeTable = "CREATE TABLE " + NOTES_TYPE_TABLE +
            "(id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "name VARCHAR(200), "
            "created_on DATETIME NOT NULL, "
            "modified_on DATETIME NOT NULL)";
    QString notesTable = "CREATE TABLE " + NOTES_TABLE +
            "(id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "type_id INTEGER NOT NULL, "
            "title VARCHAR(250), "
            "content TEXT, "
            "created_on DATETIME NOT NULL, "
            "modified_on DATETIME NOT NULL, "
            "FOREIGN KEY(type_id) REFERENCES " + NOTES_TYPE_TABLE + "(id));";

    this->db.transaction();
    QSqlQuery query;
    bool blNotesTypeResult, blNotesResult;
    blNotesTypeResult = query.exec(notesTypeTable);
    blNotesResult = query.exec(notesTable);
    if(blNotesResult && blNotesTypeResult) {
        if(this->db.commit()) {
            return true;
        }
        return false;
    }
    this->db.rollback();
    return false;
}



