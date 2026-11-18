#ifndef INCIDENT_HPP
#define INCIDENT_HPP
#include <string>
using namespace std;

class Incident {
private:
    
    string name;
    int totalNum;
    int totalPrio;

    int compareNamesSimple(string otherName) {
        if (name < otherName) {
            return 1;
        } else if (name > otherName) {
            return -1;
        } else {
            return 0;
        }
    }
    
    int compareNamesComplex(string otherName) {
        int thisCode = stoi(name.substr(4));
        int otherCode = stoi(otherName.substr(4));
        if (thisCode < otherCode) {
            return 1;
        } else if (thisCode > otherCode) {
            return -1;
        } else {
            return 0;
        }
    }

public:

    Incident() {
        this->name = "";
        this->totalNum = 0;
        this->totalPrio = 0;
    }

    Incident(string name) {
        this->name = name;
        this->totalNum = 1;
        this->totalPrio = 0;
    }

    Incident(string name, int sevInicial) {
        this->name = name;
        this->totalNum = 1;
        this->totalPrio = sevInicial;
    }

    Incident(string name, int totalNum, int totalPrio) {
        this->name = name;
        this->totalNum = totalNum;
        this->totalPrio = totalPrio;
    }

    ~Incident() {}

    string getName() {
        return name;
    }
    int getTotalNum() {
        return totalNum;
    }
    int getTotalPrio() {
        return totalPrio;
    }

    void incTotalNum() {
        totalNum += 1;
    }
    void incTotalPrio(int prio) {
        totalPrio += prio;
    }

    /*
        1  -> This > Other
        -1 -> This < Other
        0  -> This == Other
    */
    int comparePrio(Incident other) {
        if (totalPrio > other.totalPrio) {
            return 1;
        } else if (totalPrio < other.totalPrio) {
            return -1;
        } else {
            return compareNames(other.getName());
        }
    }

    string toString() {
        string stringIncident = "Incident: " + name
            + "\ttotalNum: " + to_string(totalNum) 
            + "\ttotalPrio: " + to_string(totalPrio)
        ;
        return stringIncident;
    }
    
    int compareNames(string otherName) {
        if (name.length() == otherName.length()) {
            return compareNamesSimple(otherName);
        } else {
            return compareNamesComplex(otherName);
        }
    }
};

#endif