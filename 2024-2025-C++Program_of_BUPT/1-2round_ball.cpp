#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int r;
    cin>>r;
    const double pi = 3.1415926535;
    double a = pi*r*r;
    double b = 4.0/3.0*pi*r*r*r;
    cout<<fixed<<setprecision(2)<<a<<endl;
    cout<<fixed<<setprecision(2)<<b<<endl;
    return 0;


}