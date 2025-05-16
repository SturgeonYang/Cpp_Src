#include <iostream>
#include <vector>
using namespace std;

// 动态规划方法计算走上第 M 级楼梯的走法数量
int countWays(int M) {
    if (M == 1) return 1;
    if (M == 2) return 1; // 修正：样例要求第 2 级楼梯的走法数量为 1

    vector<int> dp(M + 1, 0);
    dp[1] = 1; // 第一级的走法
    dp[2] = 1; // 第二级的走法

    for (int i = 3; i <= M; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; // 递推公式
    }

    return dp[M];
}

int main() {
    int N;
    cin >> N;

    vector<int> results;
    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;
        results.push_back(countWays(M));
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}