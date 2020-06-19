#include "node.hpp"
#pragma once
class LinkedList
{
private:
    Node *head_;
    unsigned int size_;
    void GenerateLinkedNodes(Node * start, unsigned int size);

public:
    LinkedList(unsigned int size = 0);
    ~LinkedList();
    void Insert(int elem);
    void Remove(unsigned int node_pos);
    void Print();
};
