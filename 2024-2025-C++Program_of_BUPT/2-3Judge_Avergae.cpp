#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
    int arr[10];
    const double a = 8.0;
    int n = 0;

    scanf("%d %d %d %d %d %d %d %d %d %d",
        &arr[0],&arr[1],&arr[2],&arr[3],&arr[4],
        &arr[5],&arr[6],&arr[7],&arr[8],&arr[9]);
    sort(arr,arr+10);
    arr[0] = 0;
    arr[9] = 0;
    for(int i = 0; i<10; i++)
    {
        n += arr[i];
    }
    cout<<fixed<<setprecision(3)<<n/a<<endl;
    

    





}