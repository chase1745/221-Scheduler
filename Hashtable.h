#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include "LinkedList.h"

class Hashtable {
private:
    std::vector<LinkedList> htable;
public:

    Hashtable();  // default constructor
    
    int hashFunc(int key);  // hash function
    
    void insert(int key, int value);  
    void remove(int key);
    int search(int key);
    
    void hashStats();
};

#endif
