#include <iostream>
using namespace std;
  
  
void ordenar(int * arr,unsigned int n) {
  bool cambiado = true;
  unsigned int j = 0;
  int temp;
 
  while (cambiado) {
    cambiado = false;
    ++j;
    for (unsigned int i = 0; i < n - j; ++i) {
      if (arr[i] > arr[i + 1]) 
      {
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        cambiado = true;
      }
    }
  }
}
  
void printArr(int * arr,unsigned int n)
{
    for (unsigned int i = 0; i < n; ++i) 
    { 
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
} 
 
int main()  
{  
    unsigned int n=5;
    int * arr = new int[n]{4,25, 12, 2, 11};   
    ordenar(arr, n);  
    printArr(arr, n);    
}  