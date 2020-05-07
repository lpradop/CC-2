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
    bool numeros[20];
    unsigned long long int n=1;

    for(unsigned int i=0;i<20;++i)
    {
        numeros[i]=esPrimo(i+1)?1:0;
        n=esPrimo(i+1)?n*(i+1):n;
    }
    for(unsigned int i=3;i<20;++i)
    {
        if(!numeros[i])
        {
            
            unsigned int p =1;
            while (p<=i)
            {
                if((i+1)%(p+1)==0)
                {
                    
                    while (n%(i+1)!=0)
                    {
                        n=(p+1)*n;
                    }
                }
                ++p;
            } 
            
        }
    }
    cout<<n<<endl;
    

}