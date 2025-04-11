#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string"
using namespace std;
int main(){
    const int n=5;
    int num[n]={};
    string name[n]={};
    float math_grade[n]={},cn_grade[n]={},cpp_grade[n]={};
    float grade[n]={};
    for (int i = 0; i < n; i++)
    {
        name[i].resize(30);
        scanf("%d %s %f %f %f", &num[i], &name[i][0], &math_grade[i], &cn_grade[i], &cpp_grade[i]);
        grade[i] = math_grade[i] + cn_grade[i] + cpp_grade[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d,%s,%.0f\n", num[i], name[i].c_str(), grade[i]);
    }
    
    





}