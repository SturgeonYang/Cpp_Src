#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// 哈夫曼树节点
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;
    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    HuffmanNode(int f, HuffmanNode* l, HuffmanNode* r) : ch(0), freq(f), left(l), right(r) {}
};

// 比较器
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

class HuffmanTree {
public:
    HuffmanTree() : root(nullptr) {}

    // 1. 初始化
    void Init(const string& s) {
        freqMap.clear();
        for (char c : s) freqMap[c]++;
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
        for (auto& p : freqMap)
            pq.push(new HuffmanNode(p.first, p.second));
        while (pq.size() > 1) {
            HuffmanNode* l = pq.top(); pq.pop();
            HuffmanNode* r = pq.top(); pq.pop();
            pq.push(new HuffmanNode(l->freq + r->freq, l, r));
        }
        root = pq.empty() ? nullptr : pq.top();
        codeTable.clear();
        if (root) CreateTable(root, "");
    }

    // 2. 建立编码表
    void CreateTable(HuffmanNode* node, string code) {
        if (!node) return;
        if (!node->left && !node->right) codeTable[node->ch] = code.empty() ? "0" : code;
        CreateTable(node->left, code + "0");
        CreateTable(node->right, code + "1");
    }

    void PrintTable() {
        cout << "字符\t频度\t编码\n";
        for (auto& p : codeTable)
            cout << (p.first == ' ' ? "[space]" : string(1, p.first)) << "\t" << freqMap[p.first] << "\t" << p.second << endl;
    }

    // 3. 编码
    string Encoding(const string& s) {
        string res;
        for (char c : s) res += codeTable[c];
        return res;
    }

    // 4. 解码
    string Decoding(const string& code) {
        string res;
        HuffmanNode* node = root;
        for (char bit : code) {
            node = (bit == '0') ? node->left : node->right;
            if (!node->left && !node->right) {
                res += node->ch;
                node = root;
            }
        }
        return res;
    }

    // 5. 打印哈夫曼树（选作，简单版）
    void PrintTree(HuffmanNode* node, string prefix = "") {
        if (!node) return;
        if (!node->left && !node->right)
            cout << prefix << (node->ch == ' ' ? "[space]" : string(1, node->ch)) << " (" << node->freq << ")\n";
        else {
            PrintTree(node->left, prefix + "0");
            PrintTree(node->right, prefix + "1");
        }
    }
    void PrintTree() { PrintTree(root); }

    // 6. 压缩效果分析
    void Analyze(const string& s, const string& encoded) {
        int before = s.size() * 8;
        int after = encoded.size();
        cout << "编码前长度: " << before << " bit\n";
        cout << "编码后长度: " << after << " bit\n";
        cout << "压缩率: " << fixed << setprecision(2) << (1.0 - after * 1.0 / before) * 100 << "%\n";
    }

private:
    HuffmanNode* root;
    unordered_map<char, int> freqMap;
    unordered_map<char, string> codeTable;
};

int main() {
    HuffmanTree ht;
    string s, encoded, decoded;
    int choice;
    cout << "请输入要编码的字符串（可包含空格和标点）：\n";
    getline(cin, s);

    while (true) {
        cout << "\n菜单：\n";
        cout << "1. 初始化并建立哈夫曼树\n";
        cout << "2. 输出编码表\n";
        cout << "3. 编码\n";
        cout << "4. 解码\n";
        cout << "5. 打印哈夫曼树\n";
        cout << "6. 压缩效果分析\n";
        cout << "0. 退出\n";
        cout << "请选择操作：";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            ht.Init(s);
            cout << "哈夫曼树已建立。\n";
        } else if (choice == 2) {
            ht.PrintTable();
        } else if (choice == 3) {
            encoded = ht.Encoding(s);
            cout << "编码结果：\n" << encoded << endl;
        } else if (choice == 4) {
            if (encoded.empty()) {
                cout << "请先进行编码！\n";
            } else {
                decoded = ht.Decoding(encoded);
                cout << "解码结果：\n" << decoded << endl;
            }
        } else if (choice == 5) {
            ht.PrintTree();
        } else if (choice == 6) {
            if (encoded.empty()) {
                cout << "请先进行编码！\n";
            } else {
                ht.Analyze(s, encoded);
            }
        } else if (choice == 0) {
            break;
        } else {
            cout << "无效选择，请重新输入。\n";
        }
    }
    return 0;
}