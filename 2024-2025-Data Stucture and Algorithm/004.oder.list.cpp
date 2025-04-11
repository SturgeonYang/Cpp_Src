#include <iostream>
using namespace std;
template<typename T, int N>
class SeqList {
private:
  T data[N];
  int length;
public:
  SeqList() {
    length = 0;
  }
  void Insert(int i, T x){
    for (int j = length; j >= i; j--) {
      data[j] = data[j - 1];
    }
    data[i - 1] = x;
    length++;
  }

  void Delete(int i) {
    for (int j = i; j < length; j++) {
      data[j - 1] = data[j];
    }
    length--;
  }

  void printlist() {
    if (length == 0) {
      cout << endl;
      return;
    }
    cout << data[0];
    for (int i = 1; i < length; i++) {
      cout << ' ' << data[i];
    }
    cout << endl;
  }

  int locate(T x) {
    for (int i = 0; i < length; i++) {
      if (data[i] == x) {
        return i + 1;
      }
    }
    return 0;
  }
};

int main() {
  SeqList<int, 100> a;
  SeqList<char, 100> b;
  SeqList<double, 100> c;
  char obj, oper;
  while (cin >> obj >> oper) {
    if (obj == 'a') {
      if (oper == 'i') {
        int pos, val;
        cin >> pos >> val;
        a.Insert(pos, val);
      } else if (oper == 'd') {
        int pos;
        cin >> pos;
        a.Delete(pos);
      } else if (oper == 'p') {
        a.printlist();
      } else if (oper == 'l') {
        int val;
        cin >> val;
        cout << a.locate(val) << endl;
      }
    } else if (obj == 'b') {
      if (oper == 'i') {
        int pos;
        char val;
        cin >> pos >> val;
        b.Insert(pos, val);
      } else if (oper == 'd') {
        int pos;
        cin >> pos;
        b.Delete(pos);
      } else if (oper == 'p') {
        b.printlist();
      } else if (oper == 'l') {
        char val;
        cin >> val;
        cout << b.locate(val) << endl;
      }
    } else if (obj == 'c') {
      if (oper == 'i') {
        int pos;
        double val;
        cin >> pos >> val;
        c.Insert(pos, val);
      } else if (oper == 'd') {
        int pos;
        cin >> pos;
        c.Delete(pos);
      } else if (oper == 'p') {
        c.printlist();
      } else if (oper == 'l') {
        double val;
        cin >> val;
        cout << c.locate(val) << endl;
      }
    }
  }
  return 0;
}