#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    const int MAX = 20;
    int heights[MAX];
    int dp[MAX];
    int n = 0;

    while (cin >> heights[n]) {
        n++;
        if (cin.get() == '\n') {
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (heights[j] >= heights[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxInt = 0;
    for (int i = 0; i < n; i++) {
        maxInt = max(maxInt, dp[i]);
    }
    cout << maxInt << endl;
    return 0;
}