#include <iostream>
using namespace std;

void Ordenar(int *arr, size_t size)
{
    if (size > 0)
    {
        int *min = arr;
        const int kSize = size - 1;
        for (--size; size > 0; --size)
        {
            if (*(++arr) < *min)
                swap(*min, *arr);
        }

        Ordenar(++min, kSize);
    }
    else
    {
    }
}

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

int main()
{
    size_t n = 5;
    int *arr = new int[n]{4, 25, 12, 23, 110};
    Ordenar(arr, n);
    PrintArr(arr, n);
}