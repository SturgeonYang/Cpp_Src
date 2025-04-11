#include <iostream>
#include <string.h>
int main(void) {
    int n;
    int i=1;
    printf("请输入一个小于二十的正奇数：\n");
    scanf("%d",&n);

    label:
    if (n%2!=1||n<=0||n>=20)
    {
        printf("请输入一个小于二十的正奇数：\n");
        scanf("%d",&n);
        goto label;
    }
    else
    {
        for(;i<=n;i=i+2)
        {
            for(int count=1;count<=i;count++)
            {
                printf("*");
                
            }
            printf("\n");
            
            
            
            
            
        }

    }
    
    

    system("pause");
    return 0;
}