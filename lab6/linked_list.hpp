#pragma once
#include "node.hpp"
#include <iostream>
#include "linked_list_iterator.hpp"
using Size = unsigned int;
using Position = unsigned int;

template <class ElemType>
class LinkedList
{
private:
    Node<ElemType> *head_;
    Size size_;
    void GenerateLinkedNodes(Node<ElemType> *start, Size size);
    template <class T>
    friend class LinkedListIterator;

public:
    using iterator = LinkedListIterator<ElemType>;
    LinkedList(Size size = 0);
    ~LinkedList();
    void Insert(ElemType elem, Position node_pos = 0);
    void Remove(Position node_pos);
    void Print();
    iterator Begin();
    iterator End();
};

template <class ElemType>
LinkedList<ElemType>::LinkedList(Size size)
{
    if (size == 0)
    {
        head_ = nullptr;
        size_ = 0;
    }
    else
    {
        head_ = new Node<ElemType>();
        size_ = size;
        GenerateLinkedNodes(head_, size_ - 1);
    }
}

template <class ElemType>
void LinkedList<ElemType>::GenerateLinkedNodes(Node<ElemType> *start, Size size)
{
    for (Size i = 0; i < size; ++i)
    {
        start->next_ = new Node<ElemType>();
        start = start->next_;
    }
}

template <class ElemType>
LinkedList<ElemType>::~LinkedList()
{
    Node<ElemType> *temp;
    while (head_ != nullptr)
    {
        temp = head_->next_;
        delete head_;
        head_ = temp;
    }
}

template <class ElemType>
void LinkedList<ElemType>::Insert(ElemType elem, Position node_pos)
{
    if (node_pos <= size_)
    {
        if (node_pos == 0)
        {
            head_ = new Node<ElemType>(elem, head_);
        }
        else
        {
            Node<ElemType> *previous_node = head_;
            for (Position i = 1; i < node_pos; ++i)
            {
                previous_node = previous_node->next_;
            }
            previous_node->next_ = new Node<ElemType>(elem, previous_node->next_);
        }

        ++size_;
    }
}
template <class ElemType>
void LinkedList<ElemType>::Remove(Position node_pos)
{
    if (node_pos < size_)
    {
        Node<ElemType> *temp;
        if (node_pos == 0)
        {
            temp = head_->next_;
            delete head_;
            head_ = temp;
        }
        else
        {
            Node<ElemType> *previous_node = head_;
            for (Position i = 1; i < node_pos; ++i)
            {
                previous_node = previous_node->next_;
            }
            temp = (previous_node->next_)->next_;
            delete previous_node->next_;
            previous_node->next_ = temp;
        }
        --size_;
    }
}

template <class ElemType>
void LinkedList<ElemType>::Print()
{
    Node<ElemType> *node = head_;
    for (Position i = 0; i <= size_; ++i)
    {
        if (node == nullptr)
        {
            std::cout << "null\n";
        }
        else
        {
            std::cout << node->elem_ << " -> ";
            node = node->next_;
        }
    }
}

template <class ElemType>
typename LinkedList<ElemType>::iterator LinkedList<ElemType>::Begin()
{
    return iterator(head_);
}

template <class ElemType>
typename LinkedList<ElemType>::iterator LinkedList<ElemType>::End()
{
    return iterator();
}