#include <iostream>
using namespace std;
int main()
{
    unsigned int f1=1;
    unsigned int f2=1;
    unsigned int k =4E6;
    unsigned int temp;
    unsigned int s=0;
    while(f2<= k)
    {
        temp=f2;
        f2=f1+f2;
        f1=temp;
        if (f2%2==0)
        {
            s=s+f2;
        }


    }
    cout << s<<endl;
}