#include <iostream>
using namespace std;

unsigned int tamStrR(const char arr[], unsigned int i=0)
{
    return arr[i]=='\0'?0:1+tamStrR(arr,i+1);
}
unsigned int tamStrI(const char * arr)
{
    unsigned int c=0;
    for(unsigned int i=0;*(arr+i)!='\0';++i)
    {
        ++c;
    }
    return c;
}

int main()
{
    const char arr[]="aoeui";
    cout<<tamStrR(arr)<<endl;
    cout<<tamStrI(arr)<<endl;
}