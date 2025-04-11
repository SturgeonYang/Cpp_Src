/*
@ time:	2025/02/10 
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    int n, m;
    double c, sum = 0;
    while ( cin >> n >> m) {
        sum = n;
        for (int i = 0; i < m-1; i ++) {
            c = sqrt(n);
            sum += c;
            n = c;
        }
        cout << fixed << setprecision(2) << sum <<endl;
    }
    return 0;
}