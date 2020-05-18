#include <iostream>
using namespace std;

size_t TamStr(const char *p_arr)
{
    size_t size = 0;
    while (*p_arr != '\0')
    {
        ++p_arr;
        ++size;
    }
    return size;
}
void Copiar (char *p_a, char *p_b)
{
    for (size_t size_a = TamStr(p_a); size_a > 0; --size_a)
    {
        *p_b++ = *p_a++;
    }
}
int main()
{
    char a[] = "khe";
    char b[] = "que fue?";
    char *p_a = &a[0];
    char *p_b = &b[0];
    Copiar(p_a,p_b);
    cout<<b<<endl;

}