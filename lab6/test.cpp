#include "linked_list.hpp"
#include <iostream>
int main()
{
    LinkedList<int> test{};
    test.Insert(2);
    test.Insert(3);
    test.Insert(4);
    test.Insert(5);
    LinkedList<int>::iterator test_it = test.Begin();
    test.Print();

    std::cout << *(test_it++) << "\n";

    std::cout << *test_it << "\n";
    test.Print();
    for (LinkedList<int>::iterator i = test.Begin(); i != test.End(); ++i)
    {
        std::cout << *i << "\n";
    }
    return 0;
}