#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;

const int maxn = 35;

int main() {
	int l, r, n, a[maxn] = {1};
	cin >> n;
	for(int i = 0; i < n; i++) {
		l = 0;
		for(int j = 0; j <= i; j++) {
			r = a[j];
			a[j] = l + r;
			l = r;
			printf("%d ", a[j]);
		}
		printf("\n");
	}
	return 0;
}
