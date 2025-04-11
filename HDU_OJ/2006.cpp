/*
@ time:	2025/02/10 
*/
#include <iostream>
using namespace std;
int main() {
    int n;
    while (cin >> n){
        int product = 1;
        for (int i = 0; i < n; i++){
            int num;
            cin >> num;
            if (num % 2 != 0) {
                product *= num;
            }
        }
        cout << product << endl;
    }
    return 0;
}