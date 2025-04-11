#include <iostream>
using namespace std;
int main(){
    int k;
    int num_10;
    int num_1;
    int num_100;
    scanf("%d",&k);
    for(int i = 100; i<501; i++){
            num_100 = i/100;
            num_10 = i%100/10;
            num_1 = i%10;
            if (num_1 + num_10 + num_100 == k)
            {
                printf("%d\n",i);
            }

    }

    system("pause");


}