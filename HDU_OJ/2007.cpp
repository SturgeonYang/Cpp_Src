/*
@ time:	2025/02/10 
*/
#include <iostream>
using namespace std;
int main() {
    int m,n;
    int x = 0,y = 0;
    while (~scanf("%d %d",&m,&n)) {
        for (int i = m; i <= n; i++) {
            if (i % 2 == 0) {
                x += i*i;
            }
            else {
                y += i*i*i;
            }
        }
        cout << x << ' ' << y << endl;
        x = 0;
        y = 0;
    }
    return 0;
}