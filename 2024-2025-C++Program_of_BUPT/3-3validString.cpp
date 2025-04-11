#include <iostream>
using namespace std;

int strcheck(int N, char* a);

int main(){
    int N;
    cin>>N;
    char a[N];
    cin>>a;
    cout << strcheck(N,a);
}

int strcheck(int N, char* a){
    int m = 0;
    int re;
    char v[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 
    's', 't','u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 
    'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
    'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 
    'W', 'X', 'Y', 'Z'};
    for(int i = 0; i < N; i++){
        for(int p = 0; p < 52; p++){
            if (a[i] == v[p])
                m++;
            else
                continue;
        }
    }

    if(m == N)
        re = 1;
    else re = 0;

    return re;
        
}