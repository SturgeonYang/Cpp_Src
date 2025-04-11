#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    cout<<setw(2)<<setfill('0')<<hex<<a<<setw(2)<<b<<setw(2)<<c<<setw(2)<<d;
    return 0;


}