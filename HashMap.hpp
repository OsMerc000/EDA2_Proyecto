#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include "Incident.hpp"

class HashMap {
private:

    Incident* table;
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
        table = newMap.getTable();
        cap = newMap.getCap();
        newMap.setTable(nullptr);
    }

    void secInsert(string name, int totalNum, int totalPrio) {
        int index = hash(name);
        int i = index;
        
        do {
            
            if (table[i].getName() == "") {
                Incident incident = Incident(name, totalNum, totalPrio);
                table[i] = incident;
                return;
            }

            i = (i + 1) % cap;
        } while (i != index);
    }

    Incident* getTable() {
        return table;
    }

    void setTable(Incident* table) {
        this->table = table;
    }

public:

    HashMap() {
        this->len = 0;
        this->cap = 5;
        this->table = new Incident[cap];
        for (int i = 0; i < cap; i++) {
            table[i] = Incident();
        }
    }

    //Cap debe ser mayor que 0
    HashMap(int cap) {
        this->len = 0;
        this->cap = cap;
        this->table = new Incident[cap];
        for (int i = 0; i < cap; i++) {
            table[i] = Incident();
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
        int index = hash(name);
        int i = index;
        
        do {
            if (table[i].getName() == "") {
                if (chargeFactor() >= 0.75) {
                    reFactor();
                    insert(name, sev);
                } else {
                    Incident incident = Incident(name, sev);
                    table[i] = incident;
                    len += 1;
                }
                return;
            }

            if (table[i].getName() == name) {
                table[i].incTotalNum();
                table[i].incTotalPrio(sev);
                return;
            }

            i = (i + 1) % cap;
        } while (i != index);

        return;
    }

    string toString() {
        string stringMap = "";
        for(int i = 0; i < cap; i++) {
            if (table[i].getName() != "") {
                stringMap += table[i].toString() + "\n";
            }
        }
        return stringMap;
    }

    Incident* getIncidents() {
        Incident* incidents = new Incident[len];
        int i = 0;
        for(int j = 0; j < cap; j++) {
            if (table[j].getName() != "") {
                incidents[i] = table[j];
                i += 1;
            }
        }
        return incidents;
    }
};

#endif