#include "computerrepository.h"
#include <iostream>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVariant>
#include <string>

ComputerRepository::ComputerRepository()
{
}

QSqlDatabase ComputerRepository::databaseConnect()
{
    QString connectionName = "ComputerConnection";

    QSqlDatabase db;

    if (QSqlDatabase::contains(connectionName))
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        db.setDatabaseName("Skil2.sqlite");
    }

    QSqlQuery query(db);
    db.open();
    query.prepare("PRAGMA foreign_keys ON");
    query.exec();
    query.clear();

    return db;
}

void ComputerRepository::add(Computer a)
{
//    std::replace(scientist.name.begin(),scientist.name.end(),delimiter,' ');
//    scientistList.push_back(scientist);
//    save();

    QSqlDatabase db = databaseConnect();
    QSqlQuery query(db);

    QVariant qstrName = QVariant(QString::fromStdString(a.name));
    QVariant qstrYearBuilt = QVariant(QString::fromStdString(a.yearBuilt));
    QVariant qstrType = QVariant(QString::fromStdString(a.type));
    QVariant qstrWas_Built = QVariant(a.was_built);


    query.prepare("INSERT INTO Computers ('Name', 'YearBuilt', 'Type', 'Was_Built')"
                              "VALUES(:Name, :YearBuilt, :Type, :Was_Built)");

        query.bindValue(":Name",qstrName);
        query.bindValue(":YearBuilt",qstrYearBuilt);
        query.bindValue(":Type",qstrType);
        query.bindValue(":Was_Built",qstrWas_Built);

        query.exec();
}
