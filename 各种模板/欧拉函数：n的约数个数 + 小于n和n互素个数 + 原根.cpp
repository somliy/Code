/******
*	���ڻ����n��������n���ʵ�������Ŀ�� 
*
*	��nԼ���ĸ��� 
*
*	ԭ��= n-1 
*
*	ŷ�����������ʣ���������n�ϵ�ֵ���ڶ�n���������ӷֽ�����е��������ϵ�ŷ������֮����
*
*	https://www.cnblogs.com/handsomecui/p/4755455.html
*
*	ŷ�����������ʣ�
*
*		(1)p^k��ŷ������:
*	
*			��N������p(��N=p), ��(n)= ��(p)=p-p^(k-1)=p-1��
*	
*			��N������p��k����(��N=p^k)����(n)=p^k-p^(k-1)=(p-1)p^(k-1)��
*	
*		(2)mn��ŷ������
*	
*			��nΪ���������Ԧ�(n)��ʾ������n����n���ص��������ĸ�������Ϊn��ŷ������ֵ����m,n���ʣ���(mn)=(m-1)(n-1)=��(m)��(n)��
*	
*		(3)��������:
*	
*			��nΪ����ʱ����(2n)=��(n)��
*		
*			�����κ��������� ��������a,n(n>2)��:a^��(n)=1 mod n (�����)�˹�ʽ�� ŷ������
*	
*			��n=p �� a������p����(��:gcd(a,p)=1)����ʽ��: a^(p-1)=1 mod n (�����)�˹�ʽ�� ����С����
*		
*	С�ڻ����n�����У���n���ʵ������ܺ�Ϊ����(x) * x / 2  (n>1)��
*/


//�������� 
typedef long long ll;

ll euler_phi(ll n) {
	ll m = (ll)sqrt(n + 0.5);
	ll ans = n;
	for(ll i = 2; i <= m; i++) if(n % i == 0) {
		ans = ans / i * (i - 1);
		while(n % i == 0) n /= i;
	} 
	if(n > 1) ans = ans / n * (n - 1);
	return ans;
}


//��� 
typedef long long ll;
const ll MAXN = 1000000;
ll phi[MAXN];

void phi_table(ll n, ll* phi) {
	for(ll i = 2; i <= n; i++)  phi[i] = 0;
	phi[1] = 1;
	for(ll i = 2; i <= n; i++) if(!phi[i]) 
	for(ll j = i; j <= n; j += i) {
		if(!phi[j]) phi[j] = j;
		phi[j] = phi[j] / i * (i - 1);
	}
}

/** 
*	����С����
*	
*	����p����������gcd(a,p)=1
*
*	a^(p-1)=1(mod p)
*
*	f(p) = p - 1;
*
*/






/**
*	ͬ�ඨ��
*
*    		��� a mod b = c ����(a+kb) mod b =c(kΪ��0����)
*
*    		��� a mod b = c ����(ka) mod b =kc (kΪ������)
*
*    		(a+b) mod c =((a mod c)+(b mod c )) mod c;
*
*    		(a*b) mod c=((a mod c)*(b mod c)) mod c
*
*/








 
