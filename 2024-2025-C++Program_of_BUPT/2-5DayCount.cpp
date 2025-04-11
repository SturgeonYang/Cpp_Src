#include <iostream>
using namespace std;
int main(){
    int y,m,d;
    scanf("%d %d %d",&y,&m,&d);
    int arr[12] = {31,29,31,30,31,30,31,30,31,30,31,30};
    int n=0;
    if (y%4==0)
    {
        for (int i = 0; i < m-1; i++)
        {
            n+=arr[i];
        }
        n+=d;
        
    }

    else
    {
        for (int i = 0; i < m-1; i++)
        {
            n+=arr[i];
        }
        n+=d;
        n-=1;
        
    }
    
    cout<<n;

}