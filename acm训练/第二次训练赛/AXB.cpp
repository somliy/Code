/*
A*B
 1000 ms       65536 KiB
Accepted/Submissions: 22/55 (40.00%)
   
Description
һ��С��������һ��ԼС�ڴ�ȥ�档�������˻���ľ���ں��ϵ�������
С��ͻȻ��С��˵��С�ڣ�����������"
��"����"
��"�����������������㡣������һ������n���������1~n�������Ӻ���ż���Ӻ͵ĳ˻�ô��"
��"������"
��ͨ����������С�ڳٳ�û�еõ��𰸣�С��˯�˹�ȥ����������ƽ�⡣�����С����Ȼ(����)���ˡ���
����ٸ�С��һ�λ��ᣬС�ڻᡭ���������㡣������ԵĻ������ܰ����ô?

Input
�������롣
������һ������T��ʾ��������֤������100000�顣
ÿ��һ������n(0 < n <= 10000)��

Output
����ÿ�����룬���һ����������ʾ�𰸡�

Sample
Input

3
1
2
3
Output

0
2
8
Hint
����ϴ�����long long����
%lld���
 

Source
��ʦ������ɽ������ѧ�ڰ˽�ACM������ƾ���
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long ll;
const ll MAXN = 100005;

ll a(ll n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	ll ans = 1;
	for(ll i = 2; i <= n; i ++) {
		ans *= (i-1+i);
	}
	return ans;
}

ll b(ll n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	ll ans = 0;
	for(ll i = 2; i <= n; i ++) {
		ans += (i-1)*(i);
	}
	return ans;
}

int main() {
	ll t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << a(n)+b(n) << endl;
	}
	return 0;
}
