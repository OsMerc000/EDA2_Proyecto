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

class MaxHeap {
private:

    Incident* tree;
    int cap;
    int len;

    void recInsert(int indexSon) {
        if (indexSon == 0) {
            return;
        }

        int indexFather = getIndexFather(indexSon);

        if (tree[indexFather].comparePrio(tree[indexSon]) == -1) {
            Incident tmp = tree[indexFather];
            tree[indexFather] = tree[indexSon];
            tree[indexSon] = tmp;
            recInsert(indexFather);
        } else {
            return;
        }
    }

    inline int getIndexFather(int indexSon) {
        return (indexSon - 1) / 2;
    }

    inline int getIndexLeft(int indexFather) {
        return indexFather * 2 + 1;
    }

    inline int getIndexRight(int indexFather) {
        return indexFather * 2 + 2;
    }

public:

    MaxHeap(int cap) {
        this->tree = new Incident[cap];
        this->cap = cap;
        this-> len = 0;
    }

    ~MaxHeap() {
        delete[] tree;
    }

    void insert(Incident incident) {
        tree[len] = incident;
        recInsert(len);
        len += 1;
    }

    string toString() {
        string stringMaxHeap = "";
        for (int i = 0; i < len; i++) {
            stringMaxHeap += tree[i].toString() + "\n";
        }
        return stringMaxHeap;
    }

    // Incident pop() {

    // }

};

#endif