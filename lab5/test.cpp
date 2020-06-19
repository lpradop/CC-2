#include "linked-list.hpp"
int main()
{
    LinkedList test = LinkedList(4);
    LinkedList test_null = LinkedList();
    test.Print();
    test_null.Print();
    
    test.Insert(2);
    test.Insert(-1);
    test.Insert(-1);
    test.Insert(0);
    test.Insert(3);

    test_null.Insert(6);
    test.Print();
    test_null.Print();
}
