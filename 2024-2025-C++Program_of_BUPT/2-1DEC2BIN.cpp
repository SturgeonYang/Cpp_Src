#include <iostream>
#include <bitset>
using namespace std;
int main(){


    int bit,num;

    cin>>num;

    int a=num;

    int b=num;


    for (bit = 1; num>=2; bit++)
    {
        num=num*1.0;
        num/=2.0;

    }



    for (; bit>0 ; bit--)
    {
        a>>=(bit-1);
        a=a&1;
        if(a==1)
        {
            cout<<1;
            a=b;
        }
        else
        {
            cout<<0;
            a=b;
        }


    }

}