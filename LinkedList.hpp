#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "Node.hpp"
using namespace std;

class Linked {
private:

    Node* root;

    Node* recInsert(Node* newNode, Node* currentNode) {
        if (currentNode == nullptr) {
            return newNode;
        }

        Node* nextNode = recInsert(newNode, currentNode->getNext());
        currentNode->setNext(nextNode);
        return currentNode;
    }



public:

    Linked() {
        this->root = nullptr;
    }

    ~Linked() {
        delete root;
    }

    void insert(Rank rank) {
        Node* newNode = new Node(rank);
        root = recInsert(newNode, root);
    }

    void search(Rank rank) {
        
    }

};

#endif