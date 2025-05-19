#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

// 二叉树节点结构体
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const string& preorder, int preL, int preR,
                    const string& inorder, int inL, int inR) {
    if (preL > preR) return nullptr;
    char rootVal = preorder[preL];
    int rootIdx = -1;
    for (int i = inL; i <= inR; ++i) {
        if (inorder[i] == rootVal) {
            rootIdx = i;
            break;
        }
    }
    if (rootIdx == -1) return nullptr; // 没找到，非法
    int leftLen = rootIdx - inL;
    int rightLen = inR - rootIdx;
    // 区间长度不一致，非法
    if (preL + leftLen > preR) return nullptr;
    if (preL + leftLen + rightLen != preR) return nullptr;

    TreeNode* root = new TreeNode(rootVal);
    root->left = buildTree(preorder, preL + 1, preL + leftLen, inorder, inL, rootIdx - 1);
    root->right = buildTree(preorder, preL + leftLen + 1, preR, inorder, rootIdx + 1, inR);

    // 如果左右子树有一侧构建失败，则整体失败
    if ((leftLen > 0 && !root->left) || (rightLen > 0 && !root->right)) {
        delete root;
        return nullptr;
    }
    return root;
}

// 检查输入是否合法
bool isValid(const string& preorder, const string& inorder) {
    if (preorder.size() != inorder.size() || preorder.empty()) return false;
    unordered_multiset<char> s1(preorder.begin(), preorder.end());
    unordered_multiset<char> s2(inorder.begin(), inorder.end());
    return s1 == s2;
}

// 后序遍历
void postOrder(TreeNode* root, string& res) {
    if (!root) return;
    postOrder(root->left, res);
    postOrder(root->right, res);
    res += root->val;
}

// 层序遍历
void levelOrder(TreeNode* root, string& res) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        res += node->val;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

// 释放内存
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    string preorder, inorder;
    cin >> preorder >> inorder;

    if (!isValid(preorder, inorder)) {
        cout << "error" << endl;
        return 0;
    }

    TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    if (!root) {
        cout << "error" << endl;
        return 0;
    }

    string post, level;
    postOrder(root, post);
    levelOrder(root, level);

    cout << post << endl;
    cout << level << endl;

    freeTree(root);
    return 0;
}