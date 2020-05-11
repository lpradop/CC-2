#include <iostream>
using namespace std;

int sumaArrR(int * arr, int n)
{
  if (n==0){
    return 0;
    
  }
  else {
    return arr[n-1]+sumaArrR(arr,n-1);
  }
    
}
int sumaArrI(int * arr, int n)
{
  int s=0;
  for(int i=0;i<n;++i)
  {
    s+=arr[i];
    
  }
  return s;
  
}

int main()
{
    int arr[]={1,2,3,1};
    cout << sumaArrI(arr,4)<<endl;
    cout << sumaArrR(arr,4)<<endl;
}