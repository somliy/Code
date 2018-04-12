/*
标题：包子凑数

小明几乎每天早晨都会在一家包子铺吃早餐。他发现这家包子铺有N种蒸笼，其中第i种蒸笼恰好能放Ai个包子。每种蒸笼都有非常多笼，可以认为是无限笼。

每当有顾客想买X个包子，卖包子的大叔就会迅速选出若干笼包子来，使得这若干笼中恰好一共有X个包子。比如一共有3种蒸笼，分别能放3、4和5个包子。当顾客想买11个包子时，大叔就会选2笼3个的再加1笼5个的（也可能选出1笼3个的再加2笼4个的）。

当然有时包子大叔无论如何也凑不出顾客想买的数量。比如一共有3种蒸笼，分别能放4、5和6个包子。而顾客想买7个包子时，大叔就凑不出来了。

小明想知道一共有多少种数目是包子大叔凑不出来的。

输入
----
第一行包含一个整数N。(1 <= N <= 100)
以下N行每行包含一个整数Ai。(1 <= Ai <= 100)  

输出
----
一个整数代表答案。如果凑不出的数目有无限多个，输出INF。

例如，
输入：
2  
4  
5   

程序应该输出：
6  

再例如，
输入：
2  
4  
6    

程序应该输出：
INF

样例解释：
对于样例1，凑不出的数目包括：1, 2, 3, 6, 7, 11。  
对于样例2，所有奇数都凑不出来，所以有无限多个。  

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。
----------------------------------------------------------


扩展欧几里得变形，利用求最小公倍数得知不为1的，为inf种

为1的，使用完全背包算法，假设背包很大，从历史背包中排出能够凑出的个数，剩下的就是凑不出来的 

*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<set>

using namespace std;

typedef long long LL; 
const int MAXN = 10000;
const int maxn = 10500;
int a[maxn];
bool f[maxn];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main () {
	int n, index;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	index = a[0];
	for(int i = 1; i < n; i++) 
		index = gcd(index, a[i]);
	if(index != 1) {
		printf("INF\n");
		return 0;
	}else {
		f[0] = true;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j+a[i] < maxn; j++) {
				if(f[j]) f[j+a[i]] = true;
			}
		}
		int ans = 0;
		for(int i = 0; i < maxn; i++) {
			if(false == f[i]) {
				ans++;
			}
 		}
 		cout << ans << endl;
	}
	return 0;
}
