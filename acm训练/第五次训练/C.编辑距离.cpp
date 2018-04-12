/*
1183 编辑距离  
基准时间限制：1 秒 空间限制：131072 KB 分值: 0 难度：基础题 收藏  关注
编辑距离，又称Levenshtein距离（也叫做Edit Distance），是指两个字串之间，由一个转成另一个所需的最少编辑操作次数。许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。
例如将kitten一字转成sitting：
sitten （k->s）
sittin （e->i）
sitting （->g）
所以kitten和sitting的编辑距离是3。俄罗斯科学家Vladimir Levenshtein在1965年提出这个概念。
给出两个字符串a,b，求a和b的编辑距离。
Input
第1行：字符串a(a的长度 <= 1000)。
第2行：字符串b(b的长度 <= 1000)。
Output
输出a和b的编辑距离
Input示例
kitten
sitting
Output示例
3
*/

#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1010;
char s[maxn], t[maxn];
int dp[maxn][maxn];
int main() {
	int n, m;
	while(~scanf("%s %s", s, t)) {
		n = strlen(s), m = strlen(t); 
		for(int i=0;i<=n;i++) dp[i][0] = i;
		for(int j=0;j<=m;j++) dp[0][j] = j;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
				dp[i][j] = min(dp[i][j],dp[i-1][j-1]+(s[i-1] != t[j-1]));
			}
		}
		cout << dp[n][m] << endl;
	}
	return 0;
} 
