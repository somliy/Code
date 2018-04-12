/*


标题：方格分割

6x6的方格，沿着格子的边线剪开成两部分。
要求这两部分的形状完全相同。

如图：p1.png, p2.png, p3.png 就是可行的分割法。

试计算：
包括这3种分法在内，一共有多少种不同的分割方法。
注意：旋转对称的属于同一种分割法。

请提交该整数，不要填写任何多余的内容或说明文字。

--------------------------------------------------------

从图片上看并不是一笔画，即不是dfs，bfs也不行

那么仔细看图发现，图是以3,3点中心对称

所以，以3,3点为起点，dfs，每次标记两个，即对应的两个点，如果到达边界，就是一次分割

最后结果/4，因为可以旋转 



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
