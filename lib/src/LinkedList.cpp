#include "LinkedList.h"
#include <iostream>
#include <sstream>

using namespace std;

LinkedList::LinkedList() {
    this->start = nullptr;
    this->end = nullptr;
    this->number_of_elements = 0;
}

LinkedList::~LinkedList() {

}

void LinkedList::insertElement(int index, int age) {
    node *newNode = new node;
    newNode->index = index;
    newNode->age = age;

    if(this->number_of_elements == 0) {
        newNode->prox = nullptr;
        this->start = newNode;
        this->end = newNode;
    } else {
        this->end->prox = newNode;
        newNode->prox = nullptr;
        this->end = newNode;
    }
    this->number_of_elements++;
}

void LinkedList::deleteElement(int index) {
    bool found = false;
    node *current = this->start;
    int i;
    for (i=0; i<this->number_of_elements; i++) {
        if (current->index == index) {
            found = true;
            break;
        }
        current = current->prox;
    }
    if(found) {
        if (current == this->start) {
            this->start = current->prox;
            current->prox = nullptr;
            delete current;
        } else if (current == this->end) {
            node *previous = this->start;
            for (int j=0; j< this->number_of_elements-1; j++) {
                previous = previous->prox;
            }
            this->end = previous;
            previous->prox = nullptr;
            delete current;
        } else {
            node *previous = this->start;
            for (int k=0; k<i-1; k++) {
                previous = previous->prox;
            }
            previous->prox = current->prox;
            current->prox = nullptr;
            delete current;
        }
        this->number_of_elements--;
    }
    
}

int LinkedList::youngest() {
    if (this->number_of_elements == 0)
        return -1;

    node *current = this->start;
    int youngest = current->age;
    for (int i=0;i<this->number_of_elements;i++) {
        
        if (current->age < youngest) {
            youngest = current->age;
        }
        current = current->prox;
    }
    return youngest;
}

void LinkedList::printList() {
    node *current = this->start;
    for (int i=0; i<this->number_of_elements; i++) {
        cout << current->index << " -> ";
        current = current->prox;
    }
}