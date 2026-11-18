#ifndef MAXHEAP_HPP
#ifndef RANK_HPP
#define RANK_HPP
#define MAXHEAP_HPP
#include "HashMap.hpp"

struct Rank {
    int position;
    Incident incident;

    Rank() {
        this->position = 0;
        this->incident = Incident();
    }

    Rank(int position, Incident incident) {
        this->position = position;
        this->incident = incident;
    }

    string toString() {
        string stringRank = "Position: " + to_string(position)
            + "\t" + incident.toString()
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
            swap(tree[indexFather], tree[indexSon]);
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

    void heapifyDown(int indexFather) {
        while(true) {
            int indexSon = indexFather;
            int indexLeft = getIndexLeft(indexFather);
            int indexRight = getIndexRight(indexFather);

            if (indexLeft < len && tree[indexSon].comparePrio(tree[indexLeft]) == -1) {
                indexSon = indexLeft;
            }

            if (indexRight < len && tree[indexSon].comparePrio(tree[indexRight]) == -1) {
                indexSon = indexRight;
            }

            if (indexSon == indexFather) {
                break;
            }

            swap(tree[indexFather], tree[indexSon]);
            indexFather = indexSon;
        }
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

    Incident pop() {
        Incident max = tree[0];
        
        tree[0] = tree[len - 1];
        len -= 1;

        heapifyDown(0);
        return max;
    }

    Rank* ranking(int top) {
        Rank* ranking = new Rank[top];
        for(int i = 0; i < top; i++) {
            Rank rank = Rank(i + 1, pop());
            ranking[i] = rank;
        }
        return ranking;
    }

    Rank* ranking() {
        return ranking(len);
    }

    int getLen() {
        return len;
    }
    int getCap() {
        return cap;
    }
};

#endif
#endif