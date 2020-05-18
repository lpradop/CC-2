#include <iostream>
using namespace std;

int SumaArrR(int *arr, size_t size)
{
  if (size == 0)
  {
    return 0;
  }
  else
  {
    return *arr + SumaArrR(++arr, size - 1);
  }
}
int SumaArrI(int *arr, size_t size)
{
  int sum = 0;
  for (;size >0 ; --size)
  {
    s +=*( arr++);
  }
  return sum;
}

int main()
{
  size_t n = 5;
  int *arr = new int[n]{1, 2, 3, 1, 9};
  cout << SumaArrI(arr, n) << endl;
  cout << SumaArrR(arr, n) << endl;
}