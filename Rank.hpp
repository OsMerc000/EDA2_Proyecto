#ifndef RANK_HPP
#define RANK_HPP
#include <string>
using namespace std;

class Rank {
private:
    
    string name;
    int totalNum;
    int totalPrio;

public:

    Rank() {
        this->name = "";
        this->totalNum = 1;
        this->totalPrio = 0;
    }

    Rank(string name) {
        this->name = name;
        this->totalNum = 1;
        this->totalPrio = 0;
    }

    Rank(string name, int totalNum, int totalPrio) {
        this->name = name;
        this->totalNum = totalNum;
        this->totalPrio = totalPrio;
    }

    ~Rank() {}

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
        1  -> This is greater than the other
        0  -> this is equal to the other
        -1 -> This is less than the other
    */
    int comparePrio(Rank other) {
        if (totalPrio > other.totalPrio) {
            return 1;
        } else if (totalPrio < other.totalPrio) {
            return -1;
        } else {
            if (name < other.name) {
                return 1;
            } else if (name > other.name) {
                return -1;
            } else {
                return 0;
            }
        }
    }

    string toString() {
        string rankString = "Incident: " + name
            + "\ttotalNum: " + to_string(totalNum) 
            + "\ttotalPrio: " + to_string(totalPrio)
        ;
        return rankString;
    }
};

#endif