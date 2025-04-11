#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int num[3] = {};
    scanf("%d %d %d",&num[0],&num[1],&num[2]);
	sort(num,num+3);
	for(int i=0;i<3;i++){
		cout<<num[i];
        if (i < 2)
        {
            printf(",");
        }
        else
        {
            continue;
        }

        
	}
	
	return 0;
	
} 