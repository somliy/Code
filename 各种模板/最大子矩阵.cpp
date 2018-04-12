#include<iostream>
#include<cstring> 

using namespace std;

const int maxn = 200;
int n;

int maxarray(int *a, int n) {
	int each = a[0];
	int maxx = a[0];
	for(int i = 1; i < n; i++) {
		if(each >= 0) each += a[i];
		else each = a[i];
		if(each > maxx) maxx = each;
	}
	return maxx;
}

int maxdoulearray(int (*a)[maxn], int n) {
	int max1, max2, each[maxn];
	memset(each, 0, sizeof each); 
	max1 = max2 = a[0][0];
	for(int i = 0; i < n; i++) {
		memset(each, 0, sizeof each);
		for(int j = i; j < n; j++) {
			for(int k = 0; k < n; k++) {
				each[k] += a[j][k];
			}
			max1 = maxarray(each, n);
			if(max1 > max2) max2 = max1;
		}
	}
	return max2;
}

int main() {
	int a[maxn][maxn];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	cout << maxdoulearray(a, n) << endl;
	return 0;
}
