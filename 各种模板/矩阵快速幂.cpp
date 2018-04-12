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

const int maxn = 100;
int tmp[maxn][maxn], res[maxn][maxn];
int n, m;

void solve(int a[][maxn], int b[][maxn]) {
	memset(tmp, 0, sizeof tmp);
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++)
			for(int l = 0; l < n; l++) 
				tmp[i][j] += a[i][l]*b[l][j];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			a[i][j] = tmp[i][j];
		}
	}			
}

void Pow(int a[][maxn], int k) {
	memset(res, 0, sizeof res);
	for(int i = 0; i < n; i++) res[i][i] = 1;
	while(k) {
//		printf("--------------k = %d\n", k); 
		if(k & 1) solve(res, a);
		else solve(a, a);
		k >>= 1;
//		for(int i = 0; i < n; i++) {
//			for(int j = 0; j < n; j++) {
//				printf("%d ", a[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");			
	}
} 

int main() {
	int arr[maxn][maxn];
	cin >> n >> m;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) 
			cin >> arr[i][j];
	Pow(arr, m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
