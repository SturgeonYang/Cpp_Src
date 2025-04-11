/*
@ time: 2025/02/10
@ knowledge: 使用 new 和 delete 动态分配变长数组
@ description: 在 C++ 中，如果编译器或在线判题系统不支持在数组初始化时使用变量描述数组大小，可以使用 new 运算符来动态分配数组。使用完动态分配的数组后，需要使用 delete[] 运算符释放内存，以避免内存泄漏。
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int m;
  cin >> m;
  int* n = new int[m];

  for (int i = 0; i < m; i++) {
    cin >> n[i];
  }

  for (int p = 0; p < m; p++) {
    double s = 0.0, current;
    for (int i = 0; i < n[p]; i++) {
      if (i % 2 == 0) {
        current = 1.0 / (i + 1);
      } else {
        current = -(1.0 / (i + 1));
      }
      s += current;
    }
    cout << fixed << setprecision(2) << s << endl;
  }

  delete[] n;
  return 0;
}