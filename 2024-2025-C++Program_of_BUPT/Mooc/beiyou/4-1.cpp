#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);


    int arr[N];
    double a = N-2;
    int n = 0;


    for (int i = 0; i < N; i++)
    {
        scanf("%d",&arr[i]);
    }


    sort(arr,arr+N);

    arr[0] = 0;
    arr[N-1] = 0;


    for(int i = 0; i < N; i++)
    {
        n += arr[i];
    }


    cout<<fixed<<setprecision(2)<<n/a<<endl;
    

    





}