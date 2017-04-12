// hashtable functions

#include <iostream>
#include <vector>
#include "Hashtable.h"
#include "LinkedList.h"

using namespace std;

int TABLESIZE = 100;

Hashtable::Hashtable() 
{
    for (int i = 0; i < TABLESIZE; i++) {  // create 100 (# of students) empty linked lists
        htable.push_back(LinkedList());
    }
}



// inserts a key, value pair into a node in the hashtable
void Hashtable::insert(int key, int value) 
{
    int newKey = hashFunc(key);
    Node* node = new Node(key, value);
    htable.at(newKey).insertFirst(node);
}



// searches for and returns a value with a matching key
int Hashtable::search(int key)
{
    int newKey = hashFunc(key);
    // returns the grade of the student with the uin searched for
    return htable.at(newKey).search(key); 
}



// hash function that returns the hash value from the given key
// h = key mod size_of_hashtable
int Hashtable::hashFunc(int key)
{
    return key % TABLESIZE;
}


void Hashtable::hashStats()  // outputs the min, max, and average size of linked lists in hash table
{
    int min = htable[0].getSize();
    int max = htable[0].getSize();
    double sum = 0;
    for (int i = 0; i < TABLESIZE; i++) {
        sum += htable[i].getSize();
        if (htable[i].getSize() < min) min = htable[i].getSize(); 
        else if (htable[i].getSize() > max) max = htable[i].getSize(); 
    }
    cout << "Minimum Linked List size: " << min << endl;
    cout << "Maximum Linked List size: " << max << endl;
    cout << "Average Linked List size: " << sum/static_cast<double>(TABLESIZE) << endl;
}
