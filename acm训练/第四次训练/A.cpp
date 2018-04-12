/*
51Nod - 1088 
回文串是指aba、abba、cccbccc、aaaa这种左右对称的字符串。
输入一个字符串Str，输出Str里最长回文子串的长度。
Input
输入Str（Str的长度 <= 1000)
Output
输出最长回文子串的长度L。
Sample Input
daabaac
Sample Output
5
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
const int MAXN = 100000;


int main() {
	char str[1005];
	int ans = -1;
	scanf("%s", str); 
	int len = strlen(str);
	for(int i = 0; i < len-1 ;i++) {
		for(int j = i+1; j < len; j++) {
			for(int l = i, r = j; l <= r;) {
				if(str[l] != str[r]) break;
				if(str[l] == str[r]) l++,r--;
				if(l >= r) {
					ans = max(ans, j-i+1);	
				}
			}
		}
	}
	cout << ans << endl;
    return 0; 
} 
