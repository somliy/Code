/*
1174 区间中最大的数
基准时间限制：1 秒 空间限制：131072 KB 分值: 0 难度：基础题 收藏  关注
给出一个有N个数的序列，编号0 - N - 1。进行Q次查询，查询编号i至j的所有数中，最大的数是多少。
例如: 1 7 6 3 1。i = 1, j = 3，对应的数为7 6 3，最大的数为7。（该问题也被称为RMQ问题）
Input
第1行：1个数N，表示序列的长度。(2 <= N <= 10000)
第2 - N + 1行：每行1个数，对应序列中的元素。(0 <= S[i] <= 10^9)
第N + 2行：1个数Q，表示查询的数量。(2 <= Q <= 10000)
第N + 3 - N + Q + 2行：每行2个数，对应查询的起始编号i和结束编号j。(0 <= i <= j <= N - 1)
Output
共Q行，对应每一个查询区间的最大值。
Input示例
5
1
7
6
3
1
3
0 1
1 3
3 4
Output示例
7
7
3

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

typedef long long ll; 
const int maxn = 100;
const int inf = 0x3f3f3f3f;
const int MAXN = 10006;

int arr[MAXN];
int main() {
	int n, m;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	cin >> m;
	while(m--) {
		int a, b, ans = -10000;
		cin >> a >> b;
		for(int i = a; i <= b; i++) {
			ans = max(ans, arr[i]);
		}
		cout << ans << endl;
	}
    return 0; 
} 
