#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <iostream>
#include <sstream>

struct node {
    int index;
    int age;

    node *prox;
};

class LinkedList  {
    private:
        node *start;
        node *end;
        int number_of_elements;

    public:
        LinkedList();
        ~LinkedList();
        void insertElement(int index, int age);
        void deleteElement(int index);
        int youngest();
        int size();
        int getByPosition(int position);
        bool deleteForSwap(int index);
        void printList();
};




#endif