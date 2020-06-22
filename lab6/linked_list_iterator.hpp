#pragma once
#include "node.hpp"
template <class ElemType>
class LinkedListIterator
{
private:
    Node<ElemType> *node_;

    template <class T>
    friend class LinkedList;

    LinkedListIterator(Node<ElemType> *node = nullptr);

public:
    LinkedListIterator<ElemType> operator++()
    {
        if (node_ != nullptr)
        {
            node_ = node_->next_;
        }
        return *this;
    }
    LinkedListIterator<ElemType> operator++(int)
    {
        if (node_ != nullptr)
        {
            LinkedListIterator<ElemType> temp(*this);
            operator++();
            return temp;
        }
        else
        {
            return *this;
        }
    }
    ElemType operator*()
    {
        return (this->node_)->elem_;
    }
    bool operator==(const LinkedListIterator &obj)
    {
        return this->node_ == obj.node_;
    }
    bool operator!=(const LinkedListIterator &obj)
    {
        return !(*this == obj);
    }
};

template <class ElemType>
LinkedListIterator<ElemType>::LinkedListIterator(Node<ElemType> *node) : node_(node) {}
