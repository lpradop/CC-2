#include <iostream>
#include <math.h>
using namespace std;

void printArr(int * arr,unsigned int n)
{
    for (unsigned int i = 0; i < n; ++i) 
    { 
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}
void invertirArrI(int * arr, unsigned int n)
{
    int m=ceil((double)n/2)-1;
    int temp=0;
    while (m>=0)
    {
        temp = *(arr+m);
        *(arr+m)=*(arr+n-m-1);
        *(arr+n-m-1)=temp;
        --m;
    }
}
void invertirArrR(int * arr, unsigned int n, int m =-2)
{
    m=m<-1?ceil((double)n/2)-1:m;
    if (n>=1 and m>=0)
    {
        int temp = *(arr+m);
        *(arr+m)=*(arr+n-m-1);
        *(arr+n-m-1)=temp;
        invertirArrR(arr, n, m-1);  
    }
}

int main ()
{
    unsigned int n=8;
    int * arr= new int [n]{0,1,2,3,4,5,10,7};
    invertirArrR(arr,n);
    printArr(arr,n);
    invertirArrI(arr,n);
    printArr(arr,n);
    delete [] arr;
    
}
