#include<iostream>
using namespace std;
int main(){


    int sum,mul;
    int a1,a2,a3;

    for(int i=10; i<1000; i++)
    {


        if (i==23)
        {
            a2 = i/10;
            a3 = i%10;

            sum = a2+a3;
            mul = a2*a3;
            if (mul>sum)
            {
                printf("%d",i);
            }
            else{}

        }


        else if (i<=99)
        {
            a2 = i/10;
            a3 = i%10;

            sum = a2+a3;
            mul = a2*a3;
            if (mul>sum)
            {
                printf(" %d",i);
            }
            else{}
        }
        
        
        else
        {
            a1 = i/100;
            a2 = i%100/10;
            a3 = i%100%10;

            sum = a1+a2+a3;
            mul = a1*a2*a3;
            if (mul>sum)
            {
                printf(" %d",i);
            }
            else
            {}


        }
        

    }

    return 0;


}