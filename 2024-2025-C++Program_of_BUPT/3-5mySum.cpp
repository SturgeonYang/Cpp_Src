#include <iostream>
using namespace std;

int sumOdd = 0, sumEven = 0;
void mySum(int *p, int len, int &sumOdd, int &sumEven);
int main(){
    int N;
    cin>>N;
    int a[N];
    for(int i = 0; i<N; i++){
        cin>>a[i];
    }

    mySum(a, N, sumOdd, sumEven);
    cout<<sumOdd<<" "<<sumEven;
}

void mySum(int *p, int len, int &sumOdd, int &sumEven){
    for(int i = 0; i < len; i++){
        if(p[i] % 2 == 0 ){
            sumEven += p[i];
        }
        else{
            sumOdd += p[i];
        }
    }
}