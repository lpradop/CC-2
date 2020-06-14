#pragma once
class Node
{
private:
    int elem_;
    Node *next_;
    friend class LinkedList;
    Node(int elem = 0, Node *next = nullptr);
    ~Node();
};
