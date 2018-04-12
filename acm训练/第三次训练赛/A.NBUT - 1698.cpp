/*
现在有一个整数，我们只知道它的前几位，不知道末尾两位，若该整数能被另一个整数除尽，那么该整数的末两位有多少可能
Input
输入数据有若干组，每组数据包含两个整数a，b（0<a<10000,10<b<100) ,若遇到0 0，则处理结束
Output
对应每组数据，输出可能的数量。
Sample Input
200 40
1992 95
0 0
Sample Output
3
1
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
	int a, b;
	while(cin >> a >> b) {
		if(!a && !b) return 0;
		int ans = 0, index = a*100;
		for(int i = 0; i <= 99; i ++) {
			if((index + i)%b == 0)
				ans++;
		}
		cout << ans << endl;
	} 
	return 0;
} 
