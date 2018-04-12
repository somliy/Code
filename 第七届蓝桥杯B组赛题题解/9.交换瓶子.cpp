/*
��N��ƿ�ӣ���� 1 ~ N�����ڼ����ϡ�

������5��ƿ�ӣ�
2 1 3 5 4

Ҫ��ÿ������2��ƿ�ӣ��������ǵ�λ�á�
�������ɴκ�ʹ��ƿ�ӵ����Ϊ��
1 2 3 4 5

������ô�򵥵��������Ȼ��������Ҫ����2�ξͿ��Ը�λ��

���ƿ�Ӹ����أ������ͨ������������

�����ʽΪ���У�
��һ��: һ��������N��N<10000��, ��ʾƿ�ӵ���Ŀ
�ڶ��У�N�����������ÿո�ֿ�����ʾƿ��Ŀǰ�����������

�������Ϊһ��һ������������ʾ���ٽ������ٴΣ������������

���磬���룺
5
3 1 2 5 4

����Ӧ�������
3

�����磬���룺
5
5 4 3 2 1

����Ӧ�������
2

��ԴԼ����
��ֵ�ڴ����� < 256M
CPU���� < 1000ms

���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

���д������ͬһ��Դ�ļ��У�����ͨ���󣬿����ύ��Դ�롣


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

typedef long long LL; 
const int MAXN = 10001;
const int inf = 0x3f3f3f3f;
int a[MAXN];

void swap(int x, int y) {
	int t = a[x];
	a[x] = a[y];
	a[y] = t;
}

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] != i) {
			swap(i, a[i]);
			ans++;
		}
	}
	cout << ans << endl;
	
	return 0;
} 
