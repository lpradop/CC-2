#include <iostream>
using namespace std;
void raizC(int n);

int main()
{
    raizC(16);
}
void raizC(int n)
{
    int raiz = n;
    while (true)
    {
        if (raiz * raiz > n)
        {
            --raiz;
        }
        else if (raiz * raiz == n)

        {
            cout << "la raiz exacta es: " << raiz << endl;
            break;
        }
        else
        {
            cout << "la raiz aproximada es: " << raiz << endl;

            break;

        }



        
    }
}