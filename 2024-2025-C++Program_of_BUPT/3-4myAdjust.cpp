#include <iostream>
using namespace std;



void myAdjust(int *p, int n, int m);

int main(){
    int N,M;
    cin>>N>>M;
    int a[N] = {};
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    myAdjust(a,N,M);
}

void myAdjust(int *p, int n, int m){
    int b[n] = {};
    for(int i = 0; i < m; i++){
        b[i] = p[i+(n-m)];
    }
    for(int i = 0; i < n-m; i++){
        b[i+m] = p[i];
    }
    for(int i = 0; i < n; i++) {
        cout<< b[i] << " ";
    }
}