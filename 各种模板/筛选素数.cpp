#include<iostream>
#include<cstring> 
#include<cmath>
#define MAXN 100000

using namespace std;

//�����sqrt ʹ�ò�����
 
 
 //ɸѡ�� ���ٴ�� 
const int MAXN = 100000;
bool vis[MAXN];

int getprime(int n) {
	int m = sqrt(n+0.5);
	memset(vis, true, sizeof(vis));
	vis[0] = vis[1] = false;
	for(int i = 2; i <= m; i++) {
		if(vis[i]) {
			for(int j = i*i; j <= n; j+=i) {
				vis[j] = false;
			}
		}
	}
}


//ŷ��ɸ�� o(n) 
const int MAXN = 100000;
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
 
 
 
 

//һ��
bool isprime[MAXN];
int prime[1000];
int num = 0;
int n;
//�������飬�ʹ�� ��ΪҪ�棬���Բ���sqrt��
//��Ϊû��sqrt����j����i*i��ʼ 
int getprime(int n) {
	memset(isprime, true, sizeof(isprime));
	prime[num++] = 2;
	isprime[0] = isprime[1] = false;
	for(int i = 3; i <= n; i+=2) {
		if(isprime[i]) {
			prime[num++] = i;
			for(int j=i+i; j <= n; j+=i) {
				isprime[j] = false;
			}
		}
	}
}

//���ٴ�� 
void getprime(int) {
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for(int i = 3; i <= n; i+=2) {
		if(isprime[i]) {
			for(int j=i+i; j <= n; j+=i) {
				isprime[j] = false;
			}
		}
	}
}



//���ɸ �෴ 

int num = 0 
bool vis[MANX];
int prime[MAXN/2];
void getprime(int n) {  
	//memset(visit, false, sizeof(vis));  
	for(int i = 2; i <= n; i++) {  
		if(!vis[i]) prime[++num] = i;  
		for(int j = 1; j <= num && i*prime[j] <= n; j++) {  
			vis[i*prime[j]] = true;  
			if(i % prime[j] == 0) break;   
		}  
	}  
}  


