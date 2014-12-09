#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include "computer.h"
#include "computerrepository.h"

class ComputerService
{
public:
    ComputerService();
    void add(Computer additionalComputer);
private:
    ComputerRepository compRepository;
};

#endif // COMPUTERSERVICE_H
