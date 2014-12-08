#include "scientistrepository.h"


ScientistRepository::ScientistRepository(std::string fname) {
    filename = fname;
    delimiter = '\t';
    std::ifstream scientistFile;

    try {
        scientistFile.open(filename.c_str(),std::ios::in);
    } catch(...) {
        // Ignore the error, the file is non existent and will be created next time we save.
    }

    scientistList = std::list<Scientist>();

    if(scientistFile.is_open()) {
        std::string lineToRead = "";

        // Load all records into memory
        while(std::getline(scientistFile,lineToRead)) {
            Scientist scientist = Scientist();
            std::vector<std::string> fields = util::split(lineToRead,delimiter);
            scientist.name = fields.at(0);
            scientist.dateOfBirth = fields.at(1);
            scientist.dateOfDeath = fields.at(2);
            scientist.gender = fields.at(3);
            scientistList.push_back(scientist);
        }
        scientistFile.close();
    }
}

ScientistRepository::~ScientistRepository() {
}

void ScientistRepository::add(Scientist scientist) {
    // Replace our chosen delimiter with space to avoid breaking the delimited format of the file
    std::replace(scientist.name.begin(),scientist.name.end(),delimiter,' ');
    scientistList.push_back(scientist);
    save();
}


std::list<Scientist> ScientistRepository::list() {
    return deepCopy();
}

std::list<Scientist> ScientistRepository::list(std::string col, std::string mod) {
    std::list<Scientist> outList = std::list<Scientist>();
    outList = deepCopy();
    Comparer comp = Comparer(col,mod);
    outList.sort(comp);
    return outList;
}

std::list<Scientist> ScientistRepository::deepCopy() {
    std::list<Scientist> outList = std::list<Scientist>();
    for(std::list<Scientist>::iterator iter = scientistList.begin(); iter != scientistList.end(); iter++) {
        outList.push_back(Scientist(*iter));
    }
    return outList;
}

void ScientistRepository::save() {
    std::ofstream scientistFile;
    scientistFile.open(filename.c_str());

    if(!scientistFile.is_open()) {
        throw std::runtime_error("Failed to open " + filename);
    }

    for(std::list<Scientist>::iterator iter = scientistList.begin(); iter != scientistList.end(); iter++) {
        scientistFile << (*iter).name << delimiter << (*iter).dateOfBirth << delimiter << (*iter).dateOfDeath << delimiter << (*iter).gender << std::endl;
    }
    scientistFile.flush();
    scientistFile.close();
}

Scientist* ScientistRepository::search(std::string searchTerm) {
    // Naive search implementation, finds the case sensitive substring in the name and returns first match
    for(std::list<Scientist>::iterator iter = scientistList.begin(); iter != scientistList.end(); iter++) {
        if(iter->name.find(searchTerm) != std::string::npos) {
            return new Scientist(*iter);
        }
    }
    return NULL;
}
