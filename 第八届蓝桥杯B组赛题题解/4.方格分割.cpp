/*


���⣺����ָ�

6x6�ķ������Ÿ��ӵı��߼����������֡�
Ҫ���������ֵ���״��ȫ��ͬ��

��ͼ��p1.png, p2.png, p3.png ���ǿ��еķָ��

�Լ��㣺
������3�ַַ����ڣ�һ���ж����ֲ�ͬ�ķָ����
ע�⣺��ת�ԳƵ�����ͬһ�ַָ��

���ύ����������Ҫ��д�κζ�������ݻ�˵�����֡�

--------------------------------------------------------

��ͼƬ�Ͽ�������һ�ʻ���������dfs��bfsҲ����

��ô��ϸ��ͼ���֣�ͼ����3,3�����ĶԳ�

���ԣ���3,3��Ϊ��㣬dfs��ÿ�α������������Ӧ�������㣬�������߽磬����һ�ηָ�

�����/4����Ϊ������ת 



*/ 

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

const int MAXN = 10000;
const int maxn = 10;
int a[maxn][maxn], b[maxn][maxn];
int ans = 0;

int d[4][2] = {0,1,1,0,0,-1,-1,0};

void dfs(int x, int y) {
	if(x==0||y==0||x==6||y==6) {
		ans++;
		return;
	}
	for(int i = 0; i < 4; i++) {
		int xx = x + d[i][0];
		int yy = y + d[i][1];
		if(b[xx][yy]) continue;
		b[xx][yy] = 1;
		b[6-xx][6-yy] = 1;
		dfs(xx, yy);
		b[xx][yy] = 0;
		b[6-xx][6-yy] = 0;
	}
}

int main() {
	memset(b, 0, sizeof b);
	b[3][3] = 1;
	dfs(3, 3);
	printf("%d\n", ans/4);
	
	return 0;
}
