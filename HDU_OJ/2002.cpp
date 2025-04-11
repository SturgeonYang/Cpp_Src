#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.1415927
using namespace std;

int main() {
    double r,volume;
    while(~scanf("%lf",&r)){
        volume = PI*4/3.0*r*r*r;
        cout<<fixed<<setprecision(3)<<volume;
    }
    
    return 0;
}