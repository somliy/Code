/*
Fans�Ǹ�ACM��������ԡ���ʱ������ֳ���ǿ�ҵ��淴�������������������������ϣ���ƫ��������һ�Σ���֪������˭�������ˣ��ö˶˵�һ����01��������������������10���ˡ�������������ģ��������Ϊ����01�������ȡ�200����ȫ���10���ɡ�



Input
Output
Sample Input
0110100100100
1000000010000000000
Sample Output
1001011011011
0111111101111111111
Hint
��
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
