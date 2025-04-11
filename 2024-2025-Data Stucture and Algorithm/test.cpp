#include <iostream>
using namespace std;
void convert(int a) {
	if(a == 0) return 0;
	convert(a/2);
	cout << a % 2;
}
int main() {
    convert(77);
    return 0;
}