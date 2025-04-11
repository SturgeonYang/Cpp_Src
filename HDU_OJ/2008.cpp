/*
@ time:	2025/02/10 
*/
#include <iostream>
using namespace std;
int main() {
    int n;
    while(cin >> n ) {
        if (n == 0) {
            break;
        }
        else{
            double m;
            double a = 0, b = 0, c = 0;
            for (int i = 0; i < n; i ++) {
                cin >> m;
                if (m < 0) {
                    a ++;
                }else if (m == 0) {
                    b ++;
                }else {
                    c ++;
                }
            }
            cout << a << ' ' << b << ' ' << c << endl;
        }   
    }
    return 0;
}