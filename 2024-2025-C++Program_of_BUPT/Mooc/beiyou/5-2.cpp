#include <iostream>
using namespace std;
#define k 20
void encryption(char* arr, int N)
{
        for(int i = 0; i < k; i++)
        {
            if (arr[i] >= 'A' && arr[i] <= 'Z')
            {
                arr[i] = (arr[i] - 'A' + N) % 26 + 'A';
            }
            else if (arr[i] >= 'a' && arr[i] <= 'z')
            {
                arr[i] = (arr[i] - 'a' + N) % 26 + 'a';
            }
            else
            {
                continue;
            }
            
            
        }
}
int main()
{
    int N = 0;
    cin >> N;
    char arr[k] = {};
    cin >> arr;
    encryption(arr, N);
    cout << arr << endl;
    return 0;
}