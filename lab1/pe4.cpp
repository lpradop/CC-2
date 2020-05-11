#include <iostream>
#include <string>
using namespace std;

bool esPalindromo(unsigned long int n)
{
    string m=to_string(n);
    unsigned int s=m.size();
    unsigned int b=s/2;
    for (unsigned int i=0; i<b;++i)
    {
        if(m[i]!=m[s-i-1])
        {
            return 0;
        }
    }
    return 1;
} 
int main()
{
    unsigned long int temp=0;
    unsigned long int p=0;
    for(unsigned int a=100;a<1000;++a)
    {
        for(unsigned int b = 100;b<1000;++b)
        {
            temp=a*b;
            p=(esPalindromo(temp)&&temp>p)?temp:p;
        }
    }
    
    cout<<p<<endl;

}