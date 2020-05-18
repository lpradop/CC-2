#include <iostream>
using namespace std;

size_t TamStrR(const char *p_arr, size_t i = 0)
{
    return *p_arr == '\0' ? 0 : 1 + TamStrR(++p_arr, ++i);
}
size_t TamStrI(const char *p_arr)
{
    size_t size = 0;
    while (*p_arr != '\0')
    {
        ++p_arr;
        ++size;
    }
    return size;
}

int main()
{
    const char *p_arr = "aoeuiE";
    cout << TamStrR(p_arr) << endl;
    cout << TamStrI(p_arr) << endl;
}