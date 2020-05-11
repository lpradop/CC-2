#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    unsigned int a=0;
    unsigned int b=0;
    unsigned int c=1;
    auto f=[&a,&b,&c]()->int
    {
        while (a<500)
        {
            ++a;
            while(b<500)
            {
                ++b;
                if (a*(b+1) ==500)
                {
                    c=floor(sqrt(a*a+b*b));
                    return 1;
                }

            }
        }
    }();
    cout<<a<<endl;
    cout<<b<<endl;

    
}