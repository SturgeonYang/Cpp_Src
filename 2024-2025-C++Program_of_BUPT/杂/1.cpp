#include <iostream>
#include <sstream> // 引入stringstream库
using namespace std;

int main() {
    int a, b;
    string input;
    cout << "请输入两个整数，用逗号分隔：" << endl;
    getline(cin, input); // 读取整行输入
    stringstream ss(input);
    char comma; // 用于读取逗号
    ss >> a >> comma >> b;
    cout << "第一个整数是：" << a << endl;
    cout << "第二个整数是：" << b << endl;
    return 0;
}