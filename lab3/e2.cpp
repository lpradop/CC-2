#include <iostream>
using namespace std;
void PrintArr(int *arr, size_t size)
{
    for (; size > 0; --size)
    {
        cout << *arr << " ";
        if (size != 1)
            ++arr;
    }
    cout << endl;
}

void InvertirArrI(int *arr, size_t size)
{

    while (size > 0)
    {
        for (size_t i = --size; i > 0; --i)
        {
            swap(*arr, *(arr + 1));
            ++arr;
        }
        arr -= size;
    }
}

void InvertirArrR(int *arr, size_t size)
{
    if (size > 0)
    {
        for (size_t i = --size; i > 0; --i)
        {
            swap(*arr, *(arr + 1));
            ++arr;
        }
        InvertirArrR(arr - size, size);
    }
    else
    {
    }
}

int main()
{
    size_t n = 8;
    int *arr = new int[n]{0, 1, 2, 3, 4, 5, 10, 7};
    InvertirArrI(arr, n);
    PrintArr(arr, n);
    InvertirArrR(arr, n);
    PrintArr(arr, n);
    delete[] arr;
}
