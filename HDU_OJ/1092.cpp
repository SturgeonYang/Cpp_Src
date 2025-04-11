//Problem - 1092
//涉及变长数组，C99之前的标准用不了。杭电OJ恰好用不了
//所以这里索性用100为大小
//！！或许有更好的解法，以后探索



#include <iostream>
using namespace std;

int main() {

    int n;

    while(true){

        cin>>n;

        if(n == 0)
            break;

        else{
            int num[100]={};

            for(int i = 0; i < n; i++){
                cin>>num[i];
            }

            int sum = 0;

            for(int i = 0; i < n; i++){
                sum += num[i];
            }

            cout<<sum<<endl;
        }

    
    }


    return 0;
  
}



//Copilot优化后
#include <iostream>
#include <numeric>  // for std::accumulate
using namespace std;

int main() {
  int n;
  while (true) {
    cin >> n;
    if (n == 0) {
      break;
    }

    int num[100] = {};
    for (int i = 0; i < n; ++i) {
      cin >> num[i];
    }

    int sum = accumulate(num, num + n, 0);
    cout << sum << endl;
  }
  return 0;
}