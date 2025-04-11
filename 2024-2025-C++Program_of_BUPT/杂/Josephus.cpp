// #include <iostream>
// using namespace std;

// int main(){

//     const int max = 10;
//     int i,k,m,n,people[max],*p;
//     cout<<"请输入当前的总人数(小于100)：";
//     cin>>n;
//     p = people;
//     for(i = 0; i < n; i++)
//         p[i] = i+1;
//     i=0;
//     k=0;
//     m=0;
//     for(k = 1; m < n-1 ; k++)
//     {
//         if(p[i] == 0)
//             i++;
//         if(k == 3)
//         {
//             *(p+i) = 0;
//             k = 0;
//             m++;
//         }
//         i++;
//         if(i ==n )
//         {   
//             i = 0;
//             k = 1;
//         }
//     }
//     while (*p == 0)
//         *p = *(p+(++i));
//     cout<<"最后退出的是原序号为"<<*p<<"的人";
//     return 0;


// }
// 以上为第一次写，错误：无法在某一轮结束后重置k值

#include <iostream>
using namespace std;

int main(){

    const int max = 100;
    int i,k,m,n,people[max],*p;
    cout<<"请输入当前的总人数(小于100)：";
    cin>>n;
    p = people;
    for(i = 0; i < n; i++)
        p[i] = i+1;
    i=0;
    k=0;
    m=0;
    while(m<n-1)
    {
        if(p[i] != 0)
            k++;
        if(k == 3)
        {
            *(p+i) = 0;
            k = 0;
            m++;
        }
        i++;
        if(i ==n )
        {   
            i = 0;
        }
    }
    while (*p == 0)
        p++;
    cout<<"最后退出的是原序号为"<<*p<<"的人";
    return 0;


}