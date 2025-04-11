#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int n = 10;
    char* pc = (char*)&n;
    int* pi = &n;
    printf("n的地址：%p\n", &n);
    printf("pc的值：%p\n", pc);
    printf("pi的值：%p\n", pi);
    printf("pc+1的值：%p\n", pc+1);
    printf("pi+1的值：%p\n", pi+1);
    //地址+1会自动跳过一个自身类型的空间
    printf("解引用*pc：%d\n", *pc);
    printf("解引用*pi：%d\n", *pi);
    //解引用会取出指针指向的值
    *pc = *pc+1;
    printf("解引用*pc：%d\n", *pc);
    printf("(char*)&n：%p", (char*)&n);

    cout<<sizeof(char*)<<endl;
    cout<<sizeof(int*)<<endl;

    char b[] = "lemon";//创建于栈区
    char *qq = &b[1];
    printf("qq3=%c\n", *qq);
    }