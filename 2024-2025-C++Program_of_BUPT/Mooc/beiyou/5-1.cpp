#include <iostream>
using namespace std;


int func(int i);

int main(){

    int n,x;

    scanf("%d",&x);
    
    n = func(x);

    printf("%d",n);



}


int func(int i)
{
    int fn;

    if (i == 1)
    {

        fn = 10;


    }


    else
    {

        fn = func(i-1)+2;

    }

    return fn;


}

