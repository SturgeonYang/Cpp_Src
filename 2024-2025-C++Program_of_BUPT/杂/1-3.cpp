/***************
 * 内容：内存模型理解
 * 时间：2024/09/09
****************/




#include <iostream>
using namespace std;
int a=10;
int main()
{
    int b=20,c=30;
    cout<<"全局变量a的地址："<<&a<<endl;
    cout<<"全局变量b的地址："<<&b<<endl;
    cout<<"全局变量c的地址："<<&c<<endl;
    return 0;
} 