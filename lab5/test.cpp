#include "linked-list.hpp"
int main()
{
    LinkedList test = LinkedList(4);
    LinkedList test_null = LinkedList();
    test.Print();
    test_null.Print();

    test_null.Insert(-2, 0);
    test.Insert(-5, 2);
    test.Insert(-3, 0);
    test_null.Print();
    test.Print();

    test.Remove(3);
    test_null.Remove(0);
    test_null.Print();
    test.Print();
}
