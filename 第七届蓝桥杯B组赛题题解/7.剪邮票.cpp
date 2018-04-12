/*
�硾ͼ1.jpg��, ��12������һ���12��Ф����Ʊ��
������Ҫ���м���5������Ҫ����������ŵġ�
����������һ���ǲ���������
���磬��ͼ2.jpg������ͼ3.jpg���У��ۺ�ɫ��ʾ���־��Ǻϸ�ļ�ȡ��

������㣬һ���ж����ֲ�ͬ�ļ�ȡ������

����д��ʾ������Ŀ��������
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
const int MAXN = 5;
const int inf = 0x3f3f3f3f;
int arr[MAXN], vis[MAXN];
int mp[12] = {1,2,3,4,6,7,8,9,11,12,13,14};
int d[4] = {-1,1,5,-5};

void dfs(int x) {
	for(int i = 0; i < 4; i++) {
		int t = arr[x] + d[i];
		if(t<1||t==5||t==10||t==15) 
			continue;
		for(int j = 0; j < 5; j++) {
			if(!vis[j] && arr[j]==t) {
				vis[j] = 1;
				dfs(j);
			}
		}
	}
}

int main() {
	int ans = 0;
	for(int a=0; a<8; a++)  
    for(int b=a+1; b<9; b++)  
    for(int c=b+1; c<10; c++)  
    for(int d=c+1; d<11; d++)  
    for(int e=d+1; e<12; e++) {
    	arr[0] = mp[a], arr[1] = mp[b], 
		arr[2] = mp[c], arr[3] = mp[d], 
		arr[4] = mp[e];
    	memset(vis, 0, sizeof vis);
    	vis[0] = 1;
    	dfs(0);
    	int index = 0;
    	for(int i = 0; i < 5; i++) {
    		if(vis[i])
    			index++;
		}
		if(index == 5) ans++;
	}
	printf("%d\n", ans);
	return 0;
} 
