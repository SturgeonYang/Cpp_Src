/*
@ time:	2025/02/13 
*/



// #include <iostream>
// #include <cstdio>
// #include <cstring>
// using namespace std;

// int main() {
//     char a;
//     int n = 1;
//     while((a = getchar()) != '#'){
//         if(a == ' ') n++;
//         else if(a == '\n'){
//             cout<<n;
//             n=1;
//         }

//         else continue;
//     }

//     return 0;

// }错误！题目要的是“不同单词的总数”


//写法一
#include <iostream>
#include <set>
#include <sstream>
using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    if (line == "#") {
      break;
    }

    set<string> unique_words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
      unique_words.insert(word);
    }

    cout << unique_words.size() << endl;
  }
  return 0;
}