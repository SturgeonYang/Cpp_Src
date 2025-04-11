/*
@ time:	2025/02/10 
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double a;
    while(cin>>a){
        if(a >= 0){
            cout<<fixed<<setprecision(2)<<a<<endl;
        }
        else{
            a = 0 - a;
            cout<<fixed<<setprecision(2)<<a<<endl;
        }
    }
    return 0;
}