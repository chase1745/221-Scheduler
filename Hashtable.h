#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "Node.h"

class Hashtable {
private:
    Node** htable;
public:

    Hashtable();  // default constructor
    ~Hashtable();  //destructor
    
    int hashFunc(int key);  // hash function
    
    void insert(int key, int value);  
    void remove(int key);
    int search(int key);
};

#endif
