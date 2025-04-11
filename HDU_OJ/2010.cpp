/*
@ time: 2025/02/10
@ version: 1 By Sturgeon
@ result: WA
@ reason: the variable "num" not been set 0 when a loop ends.
*/

// 问题：变量 "num" 在每次循环结束时没有被重置为 0。
// 问题：使用 pow 函数进行浮点运算可能导致精度问题。
// #include <iostream>
// #include <cmath>
// using namespace std;
// int main() {
//     int m,n;
//     int num = 0;
//     while (cin >> m >> n)
//     {
//         for (int i = m; i <= n; i++)
//         {
//             int a,b,c;
//             a = i / 100;
//             b = i % 100 / 10;
//             c = i % 10;
//             if (i == pow(a, 3) + pow(b , 3) + pow(c, 3))
//             {
//                 num ++;
//                 if (num == 1)
//                 {
//                     cout << i;
//                 }else{
//                     cout << ' ' << i;
//                 }
//             }else continue;
//         }
//         if (num == 0)
//         {
//             cout << "no";
//         }
//         cout << endl;
//         num = 0;
//     }
//     return 0;
// }

#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int m, n;
  while (cin >> m >> n) {
    bool found = false;
    for (int i = m; i <= n; i++) {
      int a = i / 100;
      int b = (i / 10) % 10;
      int c = i % 10;
      if (i == static_cast<int>(pow(a, 3)) + static_cast<int>(pow(b, 3)) +
                     static_cast<int>(pow(c, 3))) {
        if (found) {
          cout << ' ';
        }
        cout << i;
        found = true;
      }
    }
    if (!found) {
      cout << "no";
    }
    cout << endl;
  }
  return 0;
}