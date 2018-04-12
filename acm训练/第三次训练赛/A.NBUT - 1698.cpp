/*
������һ������������ֻ֪������ǰ��λ����֪��ĩβ��λ�����������ܱ���һ��������������ô��������ĩ��λ�ж��ٿ���
Input
���������������飬ÿ�����ݰ�����������a��b��0<a<10000,10<b<100) ,������0 0���������
Output
��Ӧÿ�����ݣ�������ܵ�������
Sample Input
200 40
1992 95
0 0
Sample Output
3
1
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
	int a, b;
	while(cin >> a >> b) {
		if(!a && !b) return 0;
		int ans = 0, index = a*100;
		for(int i = 0; i <= 99; i ++) {
			if((index + i)%b == 0)
				ans++;
		}
		cout << ans << endl;
	} 
	return 0;
} 
