/*
@ time:	2025/02/10 
*/
#include <iostream>
using namespace std;
int main() {
    int s;
    while(cin>>s){
        if(s >= 90 && s <= 100){
            cout<<'A'<<endl;
        }
        else if(s >= 80 && s < 90){
            cout<<'B'<<endl;
        }
        else if(s >= 70 && s < 80){
            cout<<'C'<<endl;
        }
        else if(s >= 60 && s < 70){
            cout<<'D'<<endl;
        }
        else if(s >= 0 && s < 60){
            cout<<'E'<<endl;
        }
        else cout<<"Score is error!";
    }
    return 0;
}