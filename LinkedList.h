#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <vector>


class Node {
private:
    int uin;  
    int grade;
    
public:
    Node *next;
    
    int getUin() const {return uin;}
    int getGrade() const {return grade;}
    
    Node(int uin = 800000000, int grade=0) : uin(uin), grade(grade), next(nullptr) {};
};




class LinkedList {
private:
    Node* head;
    int size;
public:
    LinkedList() : head(nullptr), size(0) {}
    ~LinkedList()
    {
        while (head != nullptr) {
            Node* prev = head;
            head = head->next;
            size--;
            delete prev;
        }
    }
    
    
    bool isEmpty() const {(head == nullptr) ? true : false;}
    
    
    void insertFirst(Node* node)
    {
        node->next = head;
        head = node;
        size++;
    }
    
    
    void removeFirst()
    {
        Node* cur = head;
        head = head->next;
        delete cur;
        size--;
    }

    
    
    int search(int uin)  // searches for the node in the linked list who's uin matches inputted uin and returns the grade
    {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->getUin() == uin) return curr->getGrade();
            else curr = curr->next;
        }

        return 0;
    }
    
    
    int getSize() const {return size;}
};

#endif /* LinkedList_h */


