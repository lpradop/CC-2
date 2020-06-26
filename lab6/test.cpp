#include "linked_list.hpp"
#include "natural_number.hpp"
#include <iostream>
#include <string>
int main()
{
    LinkedList<std::string> test{};
    test.Insert("hutne");
    test.Insert("ue");
    test.Insert("teoa");
    test.Insert("uantr");
    LinkedList<std::string>::iterator test_it = test.Begin();
    test.Print();

    std::cout << *(test_it++) << "\n";

    std::cout << *test_it << "\n";
    test.Print();
    for (LinkedList<std::string>::iterator i = test.Begin(); i != test.End(); ++i)
    {
        std::cout << *i << "\n";
    }

    ///////------------------
    LinkedList<NaturalNumber> test_class{};
    test_class.Insert(NaturalNumber(2));
    test_class.Insert(NaturalNumber(6));
    test_class.Insert(NaturalNumber(-1));
    test_class.Print();
    LinkedList<NaturalNumber>::iterator test_class_it = test_class.Begin();

    std::cout << *(test_class_it++) << "\n";
    std::cout << *test_class_it << "\n";
    test_class.Print();
    for (LinkedList<NaturalNumber>::iterator i = test_class.Begin(); i != test_class.End(); ++i)
    {
        std::cout << *i << "\n";
    }
    return 0;
}