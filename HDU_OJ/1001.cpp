#include <iostream>
using namespace std;
int main(){
    int n = 0;
    int SUM = 0;
    while(cin>>n){
        for(int i = 1; i <= n; i++){
            SUM+=i;
        }
        cout<<SUM<<'\n'<<endl;
        SUM = 0;
    }
}