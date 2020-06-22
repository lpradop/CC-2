#pragma once

template <class ElemType>
class Node
{
private:
    ElemType elem_;
    Node<ElemType> *next_;
    template <class T>
    friend class LinkedList;
    template <class T>
    friend class LinkedListIterator;
    Node(ElemType elem = ElemType(), Node<ElemType> *next = nullptr);
    ~Node();
};

template <class ElemType>
Node<ElemType>::Node(ElemType elem, Node *next) : elem_(elem), next_(next) {}

template <class ElemType>
Node<ElemType>::~Node() {}
