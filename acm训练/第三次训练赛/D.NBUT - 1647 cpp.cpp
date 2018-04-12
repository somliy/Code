/*
输入一个四个数字组成的整数 n,你的任务是数一数有多少种方法,恰好修改一个数字,把它 变成一个完全平方数(不能把首位修改成 0)。比如 n=7844,有两种方法:3844=62^2和 7744=88^2。


Input
输入第一行为整数 T (1<=T<=1000),即测试数据的组数,以后每行包含一个整数 n (1000<=n<=9999)。
Output
对于每组数据,输出恰好修改一个数字,把 n 变成完全平方数的方案数。
Sample Input
2
7844
9121
Sample Output
?Case 1: 2
Case 2: 0
Hint
无
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int j = 1; j <= t; j++) {
		int n, x, ans = 0, index;
		cin >> n;
		int a, b, c, d, a1, b1, c1, d1, sum;
		a = n / 1000;
		b = n % 1000 / 100;
		c = n % 100 / 10;
		d = n % 10;
//		printf("%d %d %d %d\n", a,b,c,d);
		for(int i = 32; i < 100; i ++) {
			sum = 0;
			x = i * i;
			a1 = x / 1000;
			b1 = x % 1000 / 100;
			c1 = x % 100 / 10;
			d1 = x % 10;
			if(a != a1) sum++;
			if(b != b1) sum++;
			if(c != c1) sum++;
			if(d != d1) sum++;
			if(sum == 1) ans++;
		}
		printf("Case %d: %d\n", j, ans);
//		cout << ans << endl;
	}
	return 0;
} 
