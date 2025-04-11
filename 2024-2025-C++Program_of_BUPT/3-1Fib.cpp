#include <iostream>
using namespace std;

int fib(int n);


int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
}


int fib(int n){
    int i;
    if (n == 0){
        i = 0;
    }
    else if (n == 1){
        i = 1;
    }
    else{
        i = fib(n-1) + fib(n-2);
    }
    return i;
}