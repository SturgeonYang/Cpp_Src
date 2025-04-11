//Version 1
// #include <iostream>
// using namespace std;
// int main(){
//     int a = 0, b = 0;
//     cin>>a>>b;
//     cout<<a+b;
// }
//错误在于，题目要求"Process to end of file"




//Version 2
#include <iostream>
using namespace std;

int main() {
    int a, b;
    // 使用 while 循环读取输入，直到文件结束或读取失败
    while (cin >> a >> b) {
        cout << a + b << endl;
    }
    return 0;
}