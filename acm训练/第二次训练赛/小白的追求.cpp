/*
С�׵�׷��
 1000 ms       65536 KiB
Accepted/Submissions: 19/72 (26.39%)
   
Description
С�׺�С�ڵ�С�������Ժ�С�׾�ȥ׷����ȥ��������������֮������С�׹���10��Ŀ�꣬���0-9������С��ֻ��׷��һ��������С�׾�ȥ��С�������ν����С��ʲô��û��˵������ָ��һ��С�ף�С��˲���Ȼ���򣬡���������˳�ӱ����𣿣�����С��˵���������������Ĺ���ȥ������д���룬ûʱ������㡱������������������������Ҫ�����С�׾�����������������С����С���ģ����͵����һ����ʽΪ:(n^n)%10,����Ƕ��پ�ȥ׷��˭

Input
�������룬ÿ������һ������n��n<=10^9��

Output
���С��Ҫ׷������ӵı�š�

Sample
Input

1
2
3
4
Output

1
4
7
6
Source
��ʦ������ɽ������ѧ�ڰ˽�ACM������ƾ���
*/#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long ll;
 
ll pow_mod(ll a, ll n, ll mod) {
    if(!a) return 0;
    ll ans = 1;
    while(n) {
        if(n & 1) ans = (ans%mod) * (a%mod);
        n >>= 1;
		a *= a %= mod;
    }
    return ans % mod;
}

int main() {
	ll n;
	while(~scanf("%lld", &n)) {
		cout << pow_mod(n, n, 10) << endl;
	}
	return 0;
}
