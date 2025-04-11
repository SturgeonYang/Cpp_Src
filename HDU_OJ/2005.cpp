/*
@ time:	2025/02/10 
*/
#include <iostream>
using namespace std;
int main() {
    int y,m,d,n = 0;
    int s[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    while(scanf("%d/%d/%d",&y,&m,&d)!=EOF){
        for(int i = 0; i < m-1; i++){
            n += s[i];
        }

        n += d;

        if (((y%4 == 0 && y%100 != 0) || y%400 == 0) && m >= 3){
            n += 1;
        }

        cout<<n<<endl;

        n = 0;
    }
    return 0;
}