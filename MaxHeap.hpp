#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP
#include "HashMap.hpp"

struct Rank {
    int position;
    Incident Incident;

    string toString() {
        string stringRank = "Position: " + to_string(position)
            + "\t" + Incident.toString()
        ;
        return stringRank;
    }
};

#endif