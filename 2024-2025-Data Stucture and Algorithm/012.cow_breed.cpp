
#include <iostream>
#include <vector>
using namespace std;

// 动态规划方法计算第 N 年的母牛数量
int countCows(int N) {
    if (N <= 3) {
        return 1; // 前 3 年母牛数量均为 1
    }

    vector<int> dp(N + 1, 0); // dp[i] 表示第 i 年的母牛数量
    dp[1] = dp[2] = dp[3] = 1;

    for (int i = 4; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 3]; // 递推公式
    }

    return dp[N];
}

int main() {
    int N;
    cin >> N;

    if (N < 1 || N > 50) {
        return 1;
    }

    int result = countCows(N);
    cout << result << endl;

    return 0;
}