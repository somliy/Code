#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

bool prime(int x) {
	for(int i = 2; i <= sqrt(x+1); i++) {
		if(x % i == 0) return false;
	}
	return true;
}

int main() {
	int a[9], ans = 0;
	for(int i = 0; i < 8; i++) 
		a[i] = i;
	do{
		if(a[0] == 0) continue;
		if(a[7] % 2 == 0) continue;
		int x = 0;
		for(int i = 0; i < 8; i++) {
			x = x*10 + a[i];
		}
//		cout << x << endl;
		if(prime(x)) ans++;
		
	}while(next_permutation(a, a+8));
	cout << ans << endl;
	return 0;
}
