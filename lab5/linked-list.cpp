#include "linked-list.hpp"
#include <iostream>
LinkedList::LinkedList(unsigned int size)
{
    if (size == 0)
    {
        head_ = nullptr;
        size_ = 0;
    }
    else
    {
        head_ = new Node();
        size_ = size;
        GenerateLinkedNodes(head_, size_ - 1);
    }
}
void LinkedList::GenerateLinkedNodes(Node *start, unsigned int size)
{
    for (unsigned int i = 0; i < size; ++i)
    {
        start->next_ = new Node();
        start = start->next_;
    }
}
LinkedList::~LinkedList()
{
    Node *temp;
    while (head_ != nullptr)
    {
        temp = head_->next_;
        delete head_;
        head_ = temp;
    }
}
void LinkedList::Insert(int elem)
{
    if (head_ == nullptr)
    {
        head_ = new Node(elem);
    }
    else
    {
        if (elem <= head_->elem_)
        {
            head_ = new Node(elem, head_);
        }
        else
        {
            Node *previous_node = head_;
            while (previous_node->next_ != nullptr)
            {
                if ((previous_node->next_)->elem_ < elem)
                {
                    previous_node = previous_node->next_;
                }
                else
                {
                    break;
                }
                
            }
            previous_node->next_=new Node(elem,previous_node->next_);
        }
    }
    ++size_;
}
void LinkedList::Remove(unsigned int node_pos)
{
    if (node_pos < size_)
    {
        Node *temp;
        if (node_pos == 0)
        {
            temp = head_->next_;
            delete head_;
            head_ = temp;
        }
        else
        {
            Node *previous_node = head_;
            for (unsigned int i = 1; i < node_pos; ++i)
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
void LinkedList::Print()
{
    Node *node = head_;
    for (unsigned int i = 0; i <= size_; ++i)
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
