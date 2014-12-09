#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H
#include "computer.h"
#include <QSqlDatabase>

class ComputerRepository
{
public:
    ComputerRepository();
    void add(Computer a);
    QSqlDatabase databaseConnect();
};

#endif // COMPUTERREPOSITORY_H
