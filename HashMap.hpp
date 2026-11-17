#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include "Rank.hpp"

class HashMap {
private:

    Rank* table;
    int cap;
    int len;

    int hash(string key) {
        int num = 0;
        for (int i = 0; i < key.length(); i++) {
            num += key[i];
        }
        int index = num % cap;
        return index;
    }

    float chargeFactor() {
        return (float) len / (float) cap;
    }

    void reFactor() {
        int newCap;
        
        if (cap == 1) {
            newCap = 2;
        } else {
            newCap = cap * 1.5;
        }

        HashMap newMap = HashMap(newCap);
        for(int i = 0; i < cap; i++) {
            if (table[i].getName() != "") {
                string name = table[i].getName();
                int totalPrio = table[i].getTotalPrio();
                int totalNum = table[i].getTotalNum();
                newMap.secInsert(name, totalNum, totalPrio);
            }
        }

        delete[] table;
        table = newMap.table;
        cap = newMap.cap;

        return;
    }

    void secInsert(string name, int totalNum, int totalPrio) {
        int index = hash(name);
        int i = index;
        
        do {
            i %= cap;
            
            if (table[i].getName() == "") {
                Rank rank = Rank(name, totalNum, totalPrio);
                table[i] = rank;
                return;
            }

            i += 1;
        } while (i != index);

        return;    
    }

public:

    HashMap() {
        this->len = 0;
        this->cap = 5;
        this->table = new Rank[cap];
        for (int i = 0; i < cap; i++) {
            table[i] = Rank();
        }
    }

    //Cap debe ser mayor que 0
    HashMap(int cap) {
        this->len = 0;
        this->cap = cap;
        this->table = new Rank[cap];
        for (int i = 0; i < cap; i++) {
            table[i] = Rank();
        }
    }

    ~HashMap() {
        delete[] table;
    }

    int getLen() {
        return len;
    }
    int getCap() {
        return cap;
    }

    void insert(string name, int sev) {
        if (chargeFactor() >= 0.75) {
            reFactor();
        }

        int index = hash(name);
        int i = index;
        
        do {
            i %= cap;
            
            if (table[i].getName() == "") {
                Rank rank = Rank(name);
                table[i] = rank;
                len += 1;
                return;
            }

            if (table[i].getName() == name) {
                table[i].incTotalNum();
                table[i].incTotalPrio(sev);
                return;
            }

            i += 1;
        } while (i != index);

        return;
    }

    string toString() {
        string mapString = "";
        for(int i = 0; i < cap; i++) {
            mapString += table[i].toString() + "\n";
        }
        return mapString;
    }
};

#endif