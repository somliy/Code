/*
链接：https://www.nowcoder.com/acm/contest/89/M
来源：牛客网

题目描述 
There are N cups of water which are numbered from 1 to N. The ith cup contains Ai liters of water, and the magical value of the ith cup is Bi.
The 1st operation will pour B1 liters of water from the 1st cup to the 2nd cup.

The 2nd operation will pour B2 liters of water from the 2nd cup to the 3rd cup.
......

The Nth operation will pour BN liters of water from the Nth cup to the 1st cup.
The (N + 1)th operation will pour B1 liters of water from the 1st cup to the 2nd cup.
......
If the water in the cup is not enough to perform the operation, the game will stop immediately. The question is if this game will keep running forever? If not, how many times will it be operated?

输入描述:
The first line contains an integer T, where T is the number of test cases. T test cases follow.
For each test case, the first line contains one integer N, where N is the number of cups.

The second line contains N integers A1, A2, ... , AN, where Ai is the volume of water in the ith cup.
The third line contains N integers B1, B2, ... , BN, where Bi is the magical value of the ith cup.
输出描述:
For each test case, output one line containing “Case #x: y”, where x is the test case number (startingfrom 1). If the game will keep running forever, y is “INF”. Otherwise, y is the operation times.
? 1 ≤ T ≤ 102.?
? 2 ≤ N ≤ 102.?
? 0 ≤ Ai ≤ 109.?
? 1 ≤ Bi ≤ 109.
示例1
输入
2
3
4 5 6
1 3 6
3
2 0 1
1 1 1
输出
Case #1: 7
Case #2: INF
备注:
For the first case, this game’s operation times is 7.
[4,5,6] ? [3,6,6] ? [3,3,9] ? [9,3,3] ? [8,4,3] ? [8,1,6] ? [14,1,0] ? [13,2,0]
For the second case, this game will keep running forever.

*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn = 1000;
int main() {
	int t;
	cin >> t;
	for(int ca = 1; ca <= t; ca++) {
		int n, k, a[maxn], b[maxn];
		long long ans = -1; 
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cin >> b[i];
		if(a[1] < b[1]) {
			ans = 0; k = 1;
		} 
		else {
			if(b[n] < b[1])
                ans = (a[1]-b[1])/(b[1]-b[n])+1, k=1;
            for(int i = 2; i <= n; i++) {
                if(b[i-1] - b[i] >= 0) continue;
                if(a[i]/(b[i]-b[i-1])<ans || ans==-1) {
                    ans = a[i]/(b[i]-b[i-1]);
                    k = i;
                }
            }
		}
		printf("Case #%d: ", ca);
        if (ans != -1) cout << ans*n+k-1 << endl;
        else cout << "INF" << endl;
	}
	return 0;
} 
