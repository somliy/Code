/*

WCѧ����ǰ��һ�ŷ��ţ�ÿ�����Ŵ�С��һ����Ϊ����ǿ��֢����������Ҫ�������Ұ�˳��һ����һ���سԣ�����ѡ��Ի򲻳ԣ�������ÿ�γԵķ��ű��벻С����һ�γԵķ��ţ�������һ����WCѧ���ַǳ�̰�ԣ�����Ҫ���Կ��ܶ�ķ��ţ���������������������Ҫ��������֪��������ܳԼ������ţ����ܰ������

Input
�����ж������ݡ� 
��һ������n��ʾ��n�����ţ�n<=1000�� 
�ڶ�����n������a1~an��0=<ai<=10000����ai��ʾ������������i�����ŵ����
Output
�����ԳԵ��ķ�������
Sample Input
10
10 9 8 7 6 5 4 3 4 5
Sample Output
3
Hint
��
*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn = 1010;
int a[maxn];
int dp[maxn];

int main () {
	int n;
	while(cin >> n) {
		for(int i = 1; i <= n; i++) 
			cin >> a[i], dp[i] = 1;
		for(int i = 2; i <= n; i++) {
			for(int j = 1; j < i; j++) {
				if(a[i] > a[j]) {
					dp[i] = max(dp[i], dp[j]+1);
				} 
			}
		}
		int ans = 1;
		for(int i = 1; i <= n; i++) {
			if(ans < dp[i])
				ans = dp[i];
		}
		cout << ans << endl;
	}
	return 0;
}
