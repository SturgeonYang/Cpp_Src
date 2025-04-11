/*
@ time:	2025/02/11 
@ problem: 给定三条边，请你判断一下能不能组成一个三角形。
@ note: 注意输入的数值类型，使用 double 以确保处理小数。
*/
#include <iostream>
using namespace std;
int main() {
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        double A, B, C; // 使用 double 以确保处理小数
        cin >> A >> B >> C;
        if (A + B > C && A + C > B && B + C > A){
            cout << "YES" << endl; // 确保每个输出都在单独的一行
        }else{
            cout << "NO" << endl; // 确保每个输出都在单独的一行
        }
    }
    return 0;
}