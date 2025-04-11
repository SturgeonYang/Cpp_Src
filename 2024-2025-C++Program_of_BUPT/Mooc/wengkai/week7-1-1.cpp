#include <iostream>

using namespace std;

int main()
{
    int a[10] = {[1]=1,[3]=3};
    int i;
    for (i=0;i<10;i++)
    {
        printf("%d\t",a[i]);
    }
    system("pause");
    return 0;
}