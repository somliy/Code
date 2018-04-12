/*
生日蜡烛

某君从某年开始每年都举办一次生日party，并且每次都要吹熄与年龄相同根数的蜡烛。

现在算起来，他一共吹熄了236根蜡烛。

请问，他从多少岁开始过生日party的？

请填写他开始过生日party的年龄数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。


*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<vector> 

using namespace std;

typedef long long LL; 
const int MAXN = 10001;
const int inf = 0x3f3f3f3f;

int main() {
	for(int i = 1; i <= 130; i++) {
		for(int j = 1; j <= 130; j++) {
			if(i*(i+1)/2 - j*(j+1)/2 == 236) {
				printf("%d %d\n", j+1, i);
				getchar();
			}	
		}
	}
	return 0;
} 
