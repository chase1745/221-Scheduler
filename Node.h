#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
private:
    int uin;  
    int grade;
    
    Node *next;
public:
    int getUin() const {return uin;}
    int getGrade() const {return grade;}
    Node* getNext() const {return next;}
    
    void setNext(Node *node) {this->next = node;}
        
    Node(int uin = 800000000, int grade=0) : uin(uin), grade(grade), next(nullptr) {};
};
    
std::ostream& operator<<(std::ostream& os, const Node& node)
{
    os << node.getUin() << " - " << node.getGrade();
}

#endif
