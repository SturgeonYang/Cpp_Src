#include <iostream>
#include <cstring>
using namespace std;

#define N 1000
int s[N][30];
int sum0, sum1, sum2;//分别指向S0,S1,S2三个集合
//每行存储一个简单析取式，第二维下标0~25代表命题变项a~z
//取值 0: 该变项没有出现，1: 该变项出现，2: 该变项出现且为否定
void convert(char str[]) {//转换函数，把输入的字符串str先储存到二维数组s里
    memset(s, 0, sizeof(s));
    sum0 = sum1 = -1;
    sum2 = 0;
    int len = strlen(str);
    int i =0;
    while (i <= len) {
        if (str[i] >= 'a' && str[i] <= 'z')//判断属于26个字母——表示命题变项
        {
            s[sum2][str[i] - 'a'] = 1;
        } else if (str[i] == '&') {//跳过合取运算符
                sum2++;
        } else if (str[i] == '!') {//对否定符的特殊处理
                s[sum2][str[++i] - 'a'] = 2;
        }
        i++;
    }
}
bool same(int a[], int b[]) {//判断两个简单析取式是否相同
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
    
}

bool check(int c[]) {//检查S0,S1,S2是否有重复
    for (int i = 0; i <= sum2; i++) {
        if (same(s[i], c)) {
            return false;
        }
    }
    return true;
}

bool res(int a[], int b[]) {//实现消解算法
    int single = 0;//记录不能消解的变项个数
    int couple = 0;//记录能消解的变项个数

    for (int i = 0; i < 26; i++) {
        if (!a[i] && !b[i]) {
            continue;
        }
        if ((a[i == 1 && b[i] == 2]) || (a[i] == 2 && b[i] == 1)) {
            couple++;
        } else {
            single ++;
        }
    }

    if (couple != 1) {//不能消解或有多对可以消解
        return true;
    }

    if (!single) {//只有一对可消解且没有不能消解的变项，得到空子句
        return false;
    }

    int c[30];
    //储存消解结果
    for (int i = 0; i < 26; i ++) {
        if ((!a[i] && !b[i]) || (a[i] + b[i] == 3)) {
            c[i] = 0;
        } else if (a[i] == 1 || b[i] == 1) {
            c[i] = 1;
        } else {
            c[i] = 2;
        }
    }
    if (check(c)) {//检查c在S0,S1,S2是否出现过
        sum2++;
        for (int i = 0; i < 26; i++)//将c加入S2
        {
            s[sum2][i] = c[i];
        }
    }
    return true;
}



int main() {
    char str[N];
    scanf("%s", str);
    convert(str);
    do//将S1并到S0中，令S1等于S2，清空S2
    {
        sum0 = sum1;
        sum1 = sum2;
        for (int i = 0; i < sum0; i++) {
            for (int j = sum0 +1; j <= sum1; j++) {
                if (!res(s[i], s[j])) {
                    printf("NO\n");
                    return 0;
                }
            }
        }
        for (int i = sum0 + 1; i <= sum1; i++) {
            for (int j = i + 1; j <= sum1; j++) {
                if (!res(s[i], s[j])) {
                    printf("NO\n");
                    return 0;
                }
            }
        }
    } while (sum2 > sum1);
    printf("YES\n");
    return 0;
}