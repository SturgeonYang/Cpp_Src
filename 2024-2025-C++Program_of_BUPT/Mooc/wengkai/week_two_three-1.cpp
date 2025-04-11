#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a;
    int b;
    int c;
    cin>>a>>b>>c;
    cout<<max(a,max(b,c));
    return 0;
}