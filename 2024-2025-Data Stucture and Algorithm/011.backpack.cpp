#include <iostream>
#include <vector>
using namespace std;

// 动态规划方法计算解的个数
int countSolutionsDP(int S, const vector<int>& weights) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(S + 1, 0));

    // 初始化：容量为 0 时只有一种解（不选任何物品）
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // 填充 DP 表
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= S; j++) {
            dp[i][j] = dp[i - 1][j]; // 不选第 i 件物品
            if (j >= weights[i - 1]) {
                dp[i][j] += dp[i - 1][j - weights[i - 1]]; // 选第 i 件物品
            }
        }
    }

    return dp[n][S];
}

int main() {
    // 输入背包容量和物品数量
    int S, n;
    cin >> S >> n;

    // 输入物品质量
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    // 动态规划法
    int dpCount = countSolutionsDP(S, weights);
    cout << dpCount << endl;

    return 0;
}