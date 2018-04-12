/*
1019 逆序数  
基准时间限制：1 秒 空间限制：131072 KB 分值: 0 难度：基础题 收藏  关注
在一个排列中，如果一对数的前后位置与大小顺序相反，即前面的数大于后面的数，那么它们就称为一个逆序。一个排列中逆序的总数就称为这个排列的逆序数。
如2 4 3 1中，2 1，4 3，4 1，3 1是逆序，逆序数是4。给出一个整数序列，求该序列的逆序数。
Input
第1行：N，N为序列的长度（n <= 50000)
第2 - N + 1行：序列中的元素（0 <= A[i] <= 10^9）
Output
输出逆序数
Input示例
4
2
4
3
1
Output示例
4
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;  

typedef long long ll;
const int maxn = 50010;

struct Node {
	int a, b;
}node[maxn]; 
int mp[maxn];
int p=1;
bool cmp1(Node x, Node y) {
	return x.a < y.a;
} 
bool cmp2(Node x, Node y) {
	return x.b < y.b;
} 
int lowbit(int x) {  
    return x&(-x);
}
void Update(int x) {  
    while(x <= p) {
        mp[x] += 1;
        x += lowbit(x);
    }
}

int Query(int x){  
    int sum = 0;
    while(x > 0) {
        sum += mp[x];
        x -= lowbit(x);
    }
    return sum;
}


int main () {
	int n, maxx = -1;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> node[i].a;
		node[i].b = i;
		
	} 
	sort(node,node+n,cmp1);
	node[n].a = -1;
	node[n].b = n;
	
	for(int i=0;i<n;i++){
		if(node[i].a == node[i+1].a){
			node[i].a = p;	
		}
		else{
			node[i].a = p++;	
		}
	}
	sort(node,node+n,cmp2);
	int sum=0;
	for(int i = 0; i < n; i++) {
		int x = node[i].a;
		sum += i - Query(x);
		Update(x);
	}
	cout<<sum;
	return 0;
} 
