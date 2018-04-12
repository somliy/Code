/*
如下的10个格子

（如果显示有问题，也可以参看【图1.jpg】）

填入0~9的数字。要求：连续的两个数字不能相邻。
（左右、上下、对角都算相邻）

一共有多少种可能的填数方案？

请填写表示方案数目的整数。
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
const int flag = 1000;
const int inf = 0x3f3f3f3f;
int a[10] = {0,1,2,3,4,5,6,7,8,9};
int b[10][10];

void init() {
	int kase = -1;
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 4; j++) {
			if(i == 1 && j == 1) continue;
			if(i == 3 && j == 4) continue;
			b[i][j] = a[++kase];
		}
	}
}

int f(int x, int y) {
	for(int i = -1; i <= 1; i++) {
		for(int j = -1; j <= 1; j++) {
			if(i == 1 && j == 1) continue;
			if(abs(b[x+i][y+j] - b[x][y]) == 1)
				return 0;
		}
	}
	return 1;
}

bool check() {
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 4; j++) {
			if(!f(i, j))
				return false;
		}
	}
	return true;
}

int main() {
	int sum = 0;init();
	do{
		memset(b, flag, sizeof b);
		b[1][1] = b[3][4] = flag;
		
		if(check()) {
			sum ++;
		}
	}while(next_permutation(a, a+10));
	printf("%d\n", sum);
	return 0;
} 
















