//测试cmath库
#include <iostream>
#include <cmath>
int main()
{
    using namespace std;
    double area;
    cout << "Enter the floor area, in square feet, of your home\n";
    cin >> area;
    double side;
    side = sqrt(area);
    printf("that's the equivalent of a square","%f",side," feet to the side.");
    cout <<"That's the equivalent of a square "<<side<<" feet to the side."<<endl;//xx feet to the side 表示“正方形的边长为xx”作为后置定语
    system("pause");//这里的cout 不需要占位符，当然也可以用prinf(%f,side)
    return 0;
}