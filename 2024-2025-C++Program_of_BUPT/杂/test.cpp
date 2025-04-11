#include <iostream>
using namespace std;

int main()
{
char str[]="SSWLIA",c;
int k ;
for(k = 2;(c = str[k])!='\0';k++){
switch(c){
    case 'I':++k;break;
    case 'L':continue;
    default:cout<<c; continue;
}
cout<<"*";
}
}