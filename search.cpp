#include <iostream>
using namespace std;

int search(int a[], int n, int key) {
  for (int i = 1; i < n; ++i) {
    if (a[i] == key) {
      return i; // 返回找到的索引位置
    }
  }
  return 0; // 如果未找到，返回-1
}

int main() {
  int a[] = {2, 2, 3, 4, 5};
  int n = sizeof(a) / sizeof(a[1]);
  int key = 4;
  int result = search(a, n, key);
  if (result != 0) {
    cout << "Found " << key << " at index " << result << endl;
  } else {
    cout << key << " not found in the array" << endl;
  }
  return 1;
}
