#include <iostream>
using namespace std;

unsigned int tamStr(const char * arr, unsigned int i=0)
{
    return *(arr+i)=='\0'?0:1+tamStr(arr,i+1);
}

const char * concatenar(const char * a, const char * b)
{
    char * temp =new char[tamStr(a)+tamStr(b)];
    for (unsigned int i =0 ; i <tamStr(a);++i)
    {
        temp[i]=*(a+i);
    }
    for (unsigned int i =0 ;i <tamStr(b);++i)
    {
        
        temp[i+tamStr(a)]=*(b+i);
    }
    const char * c = temp;
    return c;

}
int main()
{
    const char * a="ya no ";
    const char * b="lo soporto";
    cout<<concatenar(a,b)<<endl;

}