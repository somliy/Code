/*
A+B
 1000 ms       65536 KiB
Accepted/Submissions: 16/26 (61.54%)
   
Description
����һ������n��

����AΪ1~n���������ּӺ͵ĳ˻���
����BΪ1~n���������ֳ˻��ļӺ͡�

��A+B��

Input
������һ������T��ʾ������
ÿ������һ������n(0 < n <= 10)��

Output
����ÿ�����룬���һ������������ʾ�����
��֤�����������int��Χ��

Sample
Input

2
1
3
Output

2
23
Hint
���ڵڶ��飬A = (1+2)*(2+3),B = 1*2+2*3��

Source
��ʦ������ɽ������ѧ�ڰ˽�ACM������ƾ��� ������
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long ll;
const ll MAXN = 100005;

ll solve(ll n) {
	int flag = 0;
	if(n == 0 || n == 1) return 0;
	if(n & 1) {
		n = n+1;
		flag = 1;
	}
	ll m = n/2;
	ll ans1 = ((1+n-1)*m)/2;
	ll ans2 = ((2+n)*m)/2;
	if(flag) ans2 -= n;
	return ans1*ans2;
}

int main() {
	ll t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}

