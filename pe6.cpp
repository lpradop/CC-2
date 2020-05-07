#include <iostream>
using namespace std;
int main()
{
    unsigned long long int a=0;
    unsigned long long int b=0;
    for(unsigned int i=1;i<=100;++i)
    {
        a=a+(i*i);
    }
    for(unsigned int i=1;i<=100;++i)
    {
        b=b+i;
    }
    cout<<(b*b)-a<<endl;
    
    
}