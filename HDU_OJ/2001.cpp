#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double dis(double a,double b,double c,double d){
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));

}
int main() {
    double x1,y1,x2,y2,distance;
    while(~scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)){
        distance = dis(x1,y1,x2,y2);
        cout<<fixed<<setprecision(2)<<distance;
    }
    
    return 0;
}