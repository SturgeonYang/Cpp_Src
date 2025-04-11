#include <iostream>
using namespace std;
int main() {
    char a[4];
    while(cin>>a){
        if(a[0] > a[1]) swap(a[0],a[1]);
        if(a[0] > a[2]) swap(a[0],a[2]);
        if(a[1] > a[2]) swap(a[1],a[2]);
        for(int i = 0; i<3; i++){
            cout<<a[i]<<' ';
        }
    }
    cout<<'\n';
    return 0;
}