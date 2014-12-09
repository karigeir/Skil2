#include "computerservice.h"
#include "computerrepository.h"
#include <iostream>

ComputerService::ComputerService()
{
}

void ComputerService::add(Computer additionalComputer)
{
    compRepository.add(additionalComputer);
}
