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
    unsigned long int n=600851475143;
    unsigned int b = sqrt(n);
    bool t = 1;
    unsigned int i=3;
    unsigned int f=0;
    while (i<=b)
    {
        i=t?i+2:i+4;
        f=(n%i==0 && esPrimo(i))?i:f;
        t=!t;

    }
    cout << f<<endl;
}