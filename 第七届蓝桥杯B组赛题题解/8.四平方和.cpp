/*
��ƽ���Ͷ����ֳ�Ϊ�������ն���
ÿ�������������Ա�ʾΪ����4����������ƽ���͡�
�����0������ȥ�������ÿ��Ա�ʾΪ4������ƽ���͡�
���磺
5 = 0^2 + 0^2 + 1^2 + 2^2
7 = 1^2 + 1^2 + 1^2 + 2^2
��^���ű�ʾ�˷�����˼��

����һ�������������������ܴ��ڶ���ƽ���͵ı�ʾ����
Ҫ�����4��������
0 <= a <= b <= c <= d
�������еĿ��ܱ�ʾ���� a,b,c,d Ϊ���������������У���������һ����ʾ��


��������Ϊһ��������N (N<5000000)
Ҫ�����4���Ǹ�����������С���������м��ÿո�ֿ�


���磬���룺
5
�����Ӧ�������
0 0 1 2


�����磬���룺
12
�����Ӧ�������
0 2 2 2


�����磬���룺
773535
�����Ӧ�������
1 1 267 838


��ԴԼ����
��ֵ�ڴ����� < 256M
CPU����  < 3000ms


���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

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
const double MAXN = 10001;
const int inf = 0x3f3f3f3f;

int main() {
	int a, b, c, n;  
    scanf("%d", &n);  
    double maxn = sqrt(n);
    for(int a = 0; a <= maxn; a ++){  
        for(int b = a; b <= maxn; b ++){  
            for(int c = b; c <= maxn; c ++){  
                double d = sqrt(n-a*a-b*b-c*c);  
                if(d == (int)d){  
                    printf("%d %d %d %d\n", a, b, c, (int)d);  
                    return 0;
                }  
            }  
        }  
    }  
    return 0;  
} 
