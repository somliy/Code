/*

���⣺�Ȳ�������

2,3,5,7,11,13,....���������С�
���ƣ�7,37,67,97,127,157 ������ȫ��������ɵĵȲ����У��еȲ��������С�
�ϱߵ����й���Ϊ30������Ϊ6��

2004�꣬�����뻪������������֤���ˣ��������ⳤ�ȵ������Ȳ����С�
������������һ��˵ĳɹ���

����һ����Ϊ����������������еļ�������������ĵ�������

����Ϊ10�ĵȲ������У��乫����Сֵ�Ƕ��٣�

ע�⣺��Ҫ�ύ����һ����������Ҫ��д�κζ�������ݺ�˵�����֡� 


�����������ö�ٹ��� �����������������ù��� ѡ����һ������Ϊ10�������У���� 


*/

 


#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

const int MAXN = 1000000;
int num = 1;
bool vis[MAXN];
int isprime[MAXN];

void getprime(int n) {
	memset(vis, true, sizeof(vis));
	for(int i = 2; i <= n; i++) {
		if(vis[i]) isprime[num++] = i;
		for(int j = 1; j < num; j++) {
			if(i*isprime[j] > n) break;
			vis[i*isprime[j]] = false;
			if(i%isprime[j] == 0) break; 
		}
	}
}

int main()  {
	int index;
	getprime(MAXN);
	for(int d = 2; d <= 1000; d++) {
		for(int i = 1; i <= num-11; i++) {
			index = isprime[i];
			for(int j = 1; j <= 10; j++) {
				if(!vis[index + d]) continue;
				if(j == 9) {
					printf("%d\n", d);
					getchar();
				}	
				index += d;
			}
		}
	}
	return 0;
}
