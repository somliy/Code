/*

ú����Ŀ

��һ��ú�򣬶ѳ�������׶�Ρ����壺
��һ���1����
�ڶ���3�������г������Σ���
������6�������г������Σ���
���Ĳ�10�������г������Σ���
....
���һ����100�㣬���ж��ٸ�ú��


�����ʾú������Ŀ�����֡�
ע�⣺���ύ��Ӧ����һ����������Ҫ��д�κζ�������ݻ�˵�������֡�

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

int main() {
	int sum = 0, s = 1;
	for(int i = 1; i <= 100; i++) {
		sum += s;
		s += i+1;
	}
	printf("%d\n", sum);
	return 0;
} 
