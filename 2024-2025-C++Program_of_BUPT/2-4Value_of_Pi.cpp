#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main(){
    double pi_quarter = 0.0;
    double a = -1.0;
    for (int i = 1; a*pow(-1,i) > 1.0e-6 ; i++)
    {
        a = pow(-1,i+1)*1/(2*ia-1);
        pi_quarter += a;
    }
    pi_quarter -= a;
    cout<<fixed<<setprecision(8)<<pi_quarter*4<<endl;
    system("pause");



}