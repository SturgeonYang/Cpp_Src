// 题目描述
// 设计一个算法检查算数表达式的圆括号是否匹配。

// 输入
// 算数表达式

// 输出
// 圆括号匹配：OK

// 圆括号不匹配：Error

// 样例输入
// (a+b)
// 样例输出
// OK

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 检查圆括号是否匹配的函数
string checkBrackets(const string& expression) {
    stack<char> s;

    for (char ch : expression) {
        if (ch == '(') {
            s.push(ch); // 遇到左括号，入栈
        } else if (ch == ')') {
            if (s.empty()) {
                return "Error"; // 栈为空，说明右括号多余
            }
            s.pop(); // 遇到右括号，弹出栈顶左括号
        }
    }

    // 检查栈是否为空
    if (s.empty()) {
        return "OK"; // 所有括号匹配
    } else {
        return "Error"; // 栈不为空，说明左括号多余
    }
}

int main() {
    string expression;
    cin >> expression; // 输入算数表达式

    cout << checkBrackets(expression) << endl; // 输出检查结果

    return 0;
}