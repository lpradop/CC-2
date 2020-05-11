#include <iostream>
using namespace std;
void printStr(const char * arr,unsigned int n)
{
    for (unsigned int i = 0; i < n; ++i) 
    { 
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}

void printArr(int * arr,unsigned int n)
{
    for (unsigned int i = 0; i < n; ++i) 
    { 
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}