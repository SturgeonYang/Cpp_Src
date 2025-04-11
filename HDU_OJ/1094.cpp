#include <iostream>
using namespace std;

int main() {

    int n;

    while(cin>>n){

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


    return 0;
  
}