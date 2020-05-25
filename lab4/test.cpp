#include <iostream>
#include "persona.cpp"
#include "arreglo-de-personas.cpp"
using namespace std;

int main (){
    Persona a=Persona("lucho","postigos",19);
    Persona arr_p[]={Persona("pedro","perez",39),Persona("maria","juana",35),Persona("Luigi","El de verde",31)};
    ArregloDePersonas arr=ArregloDePersonas();
    ArregloDePersonas arr2=ArregloDePersonas(arr_p,3);
    arr.PushBack(a);
    arr.Resize(30);
    cout<<arr.GetSize()<<endl;
    cout<<arr2.GetSize()<<endl;

    arr.Clear();
}