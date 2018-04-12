/*
四平方和定理，又称为拉格朗日定理：
每个正整数都可以表示为至多4个正整数的平方和。
如果把0包括进去，就正好可以表示为4个数的平方和。
比如：
5 = 0^2 + 0^2 + 1^2 + 2^2
7 = 1^2 + 1^2 + 1^2 + 2^2
（^符号表示乘方的意思）

对于一个给定的正整数，可能存在多种平方和的表示法。
要求你对4个数排序：
0 <= a <= b <= c <= d
并对所有的可能表示法按 a,b,c,d 为联合主键升序排列，最后输出第一个表示法


程序输入为一个正整数N (N<5000000)
要求输出4个非负整数，按从小到大排序，中间用空格分开


例如，输入：
5
则程序应该输出：
0 0 1 2


再例如，输入：
12
则程序应该输出：
0 2 2 2


再例如，输入：
773535
则程序应该输出：
1 1 267 838


资源约定：
峰值内存消耗 < 256M
CPU消耗  < 3000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

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
