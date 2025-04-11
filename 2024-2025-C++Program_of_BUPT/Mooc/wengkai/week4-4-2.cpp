#include <iostream>
using namespace std;
int main(){
    int sum=0,count=0;
    int number;
    do
    {


        scanf("%d",&number);
        sum+=number;
        count++;


    } while (number != -1);
    printf("%f\n",1.0*sum/count);
    system("pause");
    return 0;
    

}