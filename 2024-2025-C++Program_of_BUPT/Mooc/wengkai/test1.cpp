#include <iostream>
using namespace std;
int main(){
    int x;
    scanf("%d", &x);
    int n[[gnu::unused]] = x * x * x + 3;
    cout<<n<<endl;
    system("pause");
    return 0;
}