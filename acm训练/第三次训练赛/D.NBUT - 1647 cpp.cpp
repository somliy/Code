/*
����һ���ĸ�������ɵ����� n,�����������һ���ж����ַ���,ǡ���޸�һ������,���� ���һ����ȫƽ����(���ܰ���λ�޸ĳ� 0)������ n=7844,�����ַ���:3844=62^2�� 7744=88^2��


Input
�����һ��Ϊ���� T (1<=T<=1000),���������ݵ�����,�Ժ�ÿ�а���һ������ n (1000<=n<=9999)��
Output
����ÿ������,���ǡ���޸�һ������,�� n �����ȫƽ�����ķ�������
Sample Input
2
7844
9121
Sample Output
?Case 1: 2
Case 2: 0
Hint
��
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int j = 1; j <= t; j++) {
		int n, x, ans = 0, index;
		cin >> n;
		int a, b, c, d, a1, b1, c1, d1, sum;
		a = n / 1000;
		b = n % 1000 / 100;
		c = n % 100 / 10;
		d = n % 10;
//		printf("%d %d %d %d\n", a,b,c,d);
		for(int i = 32; i < 100; i ++) {
			sum = 0;
			x = i * i;
			a1 = x / 1000;
			b1 = x % 1000 / 100;
			c1 = x % 100 / 10;
			d1 = x % 10;
			if(a != a1) sum++;
			if(b != b1) sum++;
			if(c != c1) sum++;
			if(d != d1) sum++;
			if(sum == 1) ans++;
		}
		printf("Case %d: %d\n", j, ans);
//		cout << ans << endl;
	}
	return 0;
} 
