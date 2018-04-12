#include<iostream>
#include<algorithm>

using namespace std;

int mark;

void a(int n) {
	for(int i = 1; i <= n; i++) {
		printf("sin(%d", i);
		if(i == n) continue;
		if(i%2) printf("-");
		else printf("+");
	}
	for(int i = 1; i <= n; i++) 
		printf(")");
}

void s(int n) {
	for(int i = 1; i < n; i++) 
		printf("(");
	for(int i = 1, j = n; i <=n, j >= 1; i++, j--) {
		a(i);
//		printf("a%d", i);
		if(j != 1) printf("+%d)", j);
		else printf("+%d\n", j);
	}
}

int main() {
	int n;
	cin >> n;
	s(n);
	return 0;
}
