#include <iostream>
using namespace std;
unsigned int sumaMultiplos(unsigned int m, unsigned int k)
{
    unsigned int p = k/m;
    return m*p*(p+1)/2;

}
int main ()
{
    cout<<sumaMultiplos(3,999)+sumaMultiplos(5,999)-sumaMultiplos(15,999);
}