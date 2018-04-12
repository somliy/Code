#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			printf("%c",'A'+abs(i-j));
		}
		printf("\n");
	}
	return 0;
}
