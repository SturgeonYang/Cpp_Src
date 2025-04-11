// 1 已知有n个整数的序列，查找指定数值key是否在该序列中，如果存在，找出该数值在序列中的位置。
//    int search(int a[], int n, int key)；
//    说明：a[] 待查找序列， n   待查找序列长度，  key  查找关键字



#include <iostream>
using namespace std;

int search(int a[], int n, int key) {
  for (int i = 1; i < n; ++i) {
    if (a[i] == key) {
      return i;
    }
  }
  return 0;
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


//迭代方法1：注意到耗时的地方在于有两次关系比较，计划优化成1次，哨兵模式
int search(int a[], int n, int key) {
  a[0] = key;
  int i;
  for(i = n; a[i] != key; i--);
  return i;
  }

  //功能迭代：把起始位置变量写进去，实现可以找多个key