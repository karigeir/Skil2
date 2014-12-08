#include "scienceservice.h"

ScienceService::ScienceService() {
    scientistRepository = ScientistRepository();
}

ScienceService::~ScienceService() {
}

void ScienceService::addScientist(Scientist scientist) {
    scientistRepository.add(scientist);
}

std::list<Scientist> ScienceService::getAllScientists() {
    return scientistRepository.list();
}

std::list<Scientist> ScienceService::getScientistsOrderedBy(std::string col, std::string mod) {
    return scientistRepository.list(col,mod);
}

Scientist* ScienceService::search(std::string searchTerm) {
    return scientistRepository.search(searchTerm);
}
