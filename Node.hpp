#ifndef NODE_HPP
#define NODE_HPP
#include "Rank.hpp"
using namespace std;

class Node {
private:

    Rank rank;
    Node* next;

public:

    Node() {
        this->rank = Rank();
        this->next = nullptr;
    }

    Node(Rank rank) {
        this->rank = rank;
        this->next = nullptr;
    }
    
    ~Node() {
        delete next;
    }

    Rank getRank() {
        return rank;
    }
    Node* getNext() {
        return next;
    }

    void setRank(Rank rank) {
        this->rank = rank;
    }
    void setNext(Node* next) {
        this->next = next;
    }
};


#endif