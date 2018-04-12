/*

标题：等差素数列

2,3,5,7,11,13,....是素数序列。
类似：7,37,67,97,127,157 这样完全由素数组成的等差数列，叫等差素数数列。
上边的数列公差为30，长度为6。

2004年，格林与华人陶哲轩合作证明了：存在任意长度的素数等差数列。
这是数论领域一项惊人的成果！

有这一理论为基础，请你借助手中的计算机，满怀信心地搜索：

长度为10的等差素数列，其公差最小值是多少？

注意：需要提交的是一个整数，不要填写任何多余的内容和说明文字。 


首先素数打表，枚举公差 ，从素数数组中利用公差 选出第一个长度为10的素数列，输出 


*/

 


#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

const int MAXN = 1000000;
int num = 1;
bool vis[MAXN];
int isprime[MAXN];

void getprime(int n) {
	memset(vis, true, sizeof(vis));
	for(int i = 2; i <= n; i++) {
		if(vis[i]) isprime[num++] = i;
		for(int j = 1; j < num; j++) {
			if(i*isprime[j] > n) break;
			vis[i*isprime[j]] = false;
			if(i%isprime[j] == 0) break; 
		}
	}
}

int main()  {
	int index;
	getprime(MAXN);
	for(int d = 2; d <= 1000; d++) {
		for(int i = 1; i <= num-11; i++) {
			index = isprime[i];
			for(int j = 1; j <= 10; j++) {
				if(!vis[index + d]) continue;
				if(j == 9) {
					printf("%d\n", d);
					getchar();
				}	
				index += d;
			}
		}
	}
	return 0;
}
