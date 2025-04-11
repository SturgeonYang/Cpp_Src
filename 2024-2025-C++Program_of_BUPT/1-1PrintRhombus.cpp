#include <iostream>
using namespace std;

int main()
{
    int n=0;
    cin>>n;
    if (n<20&&n%2==1)
    {
        for(int i = 0; i < (n+1)/2; i++ )
        {
            for (int j = 0; j < (n-(2*i+1))/2; j++)//
            {
                cout<<" ";
            }
            for (int j = 0; j < 2*i+1; j++)//j=2i+1(其中i为行数-1，j从0到2i-1的循环次数为该行的星号数)
            {
                cout<<"*";
            }


            cout<<endl;

        }
        
        for (int i = (n-1)/2; i > 0; i--)//
        {
            for (int j = 0; j < (n-(2*(i-1)+1))/2; j++)//
            {
                cout<<" ";
            }
            for (int j = 0; j < 2*(i-1)+1; j++)//
            {
                cout<<"*";
            }

            cout<<endl;
        }
    }
    return 0;

}