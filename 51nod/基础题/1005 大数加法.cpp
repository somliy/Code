#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main() {
	string a, b, c;
	cin >> a >> b;
	int lena = a.length();
	int lenb = b.length();
	int temp = 0;
	for(int i=lena-1, j=lenb-1; i>=0 || j>=0; i--,j--) {
		temp = (a[i]-'0')+(b[j]-'0')+temp;
		a[i] = temp % 10 + '0';
		temp /= 10; 
	}
	if(temp) cout << temp;
	for(int i = 0; i <= lena-1; i++) 
		cout << a[i];
	cout << endl;
	return 0;
} 
