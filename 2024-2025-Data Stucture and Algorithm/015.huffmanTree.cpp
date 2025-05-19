#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 哈夫曼树节点
struct Node {
    int weight;
    Node(int w) : weight(w) {}
    // 小根堆需要重载>
    bool operator>(const Node& other) const {
        return weight > other.weight;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> freq(n);
    for (int i = 0; i < n; ++i) {
        cin >> freq[i];
    }

    // 小根堆
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push(freq[i]);
    }

    int total = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int sum = a + b;
        total += sum;
        pq.push(sum);
    }

    cout << total << endl;
    return 0;
}