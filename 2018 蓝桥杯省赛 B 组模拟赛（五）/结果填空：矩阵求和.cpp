#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main() {
	int sum = 0, x = 51;
	int a = 0;
	for(int i = 1; i <= 101; i++) {
		sum += a*2*x+x;
		x += 101; 
		i <= 50 ? a++ : a--;
	} 
	cout << sum << endl;
	return 0;
} 
