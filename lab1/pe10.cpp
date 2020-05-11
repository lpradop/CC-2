#include <iostream>
#include <math.h>
using namespace std;
bool esPrimo(unsigned long long int n)
{
    unsigned long long int b = floor(sqrt(n));
    bool t = 1;
    unsigned long long int i=5;
    if (n==2 or n==3 or n==1 or n == 5)
    {
        return 1;
    }
    else
    {
        if(n%2==0 or n%3==0 or n%5==0)
        {
            return 0;
        }
        else 
        {
            while (i<=b)
            {
                i=t?i+2:i+4;
                t=!t;
                if (n%i==0)
                {
                    return 0;
                }

            }
            return 1;
        }
    }
}

int main()
{
    unsigned long long int s=0;
    for(unsigned int n=2;n<=2000000;++n)
    {
        s=esPrimo(n)?s+n:s;
    }
    cout<<s<<endl;
}