#include<iostream>
#include<cmath>

using namespace std;

const int maxn = 0x3f3f3f3f;
double a[10005];
int n, k;

bool C(double mid) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i] / mid;
	}
	return sum >= k;
}

int main () {
	double l = 0, r = maxn;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	while(r - l > 1e-10) {
		double mid = (l + r) / 2;
		if(C(mid)) l = mid;
		else r = mid;
	}
	printf("%.2lf", floor(r*100)/100);
} 
