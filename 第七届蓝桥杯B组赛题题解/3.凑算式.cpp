/*
����ʽ

       B      DEF
A + �� + -������ = 10
       C       GHI

�������ʾ�����⣬���Բμ���ͼ1.jpg����

�����ʽ��A~I����1~9�����֣���ͬ����ĸ����ͬ�����֡�

���磺
6+8/3+952/714 ����һ�ֽⷨ��
5+3/1+972/486 ����һ�ֽⷨ��

�����ʽһ���ж����ֽⷨ��

ע�⣺���ύӦ���Ǹ���������Ҫ��д�κζ�������ݻ�˵�������֡�

*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<vector> 

using namespace std;

typedef long long LL; 
const int MAXN = 10001;
const int inf = 0x3f3f3f3f;

int main() {
	int sum = 0;
	int a[9] = {1,2,3,4,5,6,7,8,9};
	do{
		if((double)a[0] + (double)a[1]/a[2] + (double)(a[3]*100+a[4]*10+a[5]) / (a[6]*100+a[7]*10+a[8]) == 10)
			sum ++;
	}while(next_permutation(a, a+9));
	printf("%d\n", sum);
	return 0;
} 
