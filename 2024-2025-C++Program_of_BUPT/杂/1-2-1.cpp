#include <iostream>
using namespace std;

int main()
{
    int a = 6, b, &r = a, &q = b;
    r = (b = 6, ++q, b + 5);
    cout << "r=" << r << endl;
}