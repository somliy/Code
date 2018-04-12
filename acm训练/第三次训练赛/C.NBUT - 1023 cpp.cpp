/*
Fans是个ACM程序设计迷。有时侯，他表现出很强烈的逆反心理，你往东，他往西，你往南，他偏往北。这一次，不知道又是谁惹着他了，好端端的一个个01串，到了他的手里，都变成10串了。请你编个程序来模仿他的行为，将01串（长度≤200），全变成10串吧。



Input
Output
Sample Input
0110100100100
1000000010000000000
Sample Output
1001011011011
0111111101111111111
Hint
无
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
	string s;
	while(cin >> s) {
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == '1') s[i] = '0';
			else s[i] = '1';
		}
		cout << s << endl;
	} 
	return 0;
} 
