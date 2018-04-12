//�й�ʣ�ඨ�������ŵ��
//
//��Ϊn%3=2, n%5=3, n%7=2 �� 3��5��7����
//ʹ5 ��7 ��a�� 3 ���� 1����35 ��2 = 70����a = 2�� 
//ʹ3 ��7 ��b�� 5 ���� 1����21 ��1 = 21����b = 1�� 
//ʹ3 ��5 ��c�� 7 ���� 1����15 ��1 = 15����c = 1��
//mod = 3 ��5 ��7 = 21252��
//n =��70��x+21��y+15��z��% lcm(3,5,7) = 23 ����n����С��
 
 
//����С����
//modһ��Ϊ���� 
//a����������֮����5 ��7����nΪ������-2��3-2����modΪ3���˻�
//return ������Ҫ�˵�����res ��5 ��7 �� �����ϵ�� 
typedef long long ll;  

ll pow_mod(ll a, ll n, ll mod) {
	if(!a) return 0;  
    ll res = 1;  
    while(n > 0) {  
        if(n & 1) res = res * a % mod;  
        a = a * a % mod;  
        n >>= 1;  
    }  
    return res;  
} 

//��չŷ�����
//ax - by = d 
//ax - my = 1
//����x 

typedef  long long ll; 
 
void extgcd(ll a, ll b, ll& d, ll& x, ll& y) {  
    if(!b) {
		d = a;
		x = 1;
		y = 0;
	}else {
		extgcd(b, a%b, d, y, x); 
		y -= x * (a / b); 
	}  
}  
ll inverse(ll a, ll n) {  
    ll d, x, y;  
    extgcd(a, n, d, x, y);  
    return d == 1 ? (x + n) % n : -1;  
}  


//��Ԫ����ɸ ( PΪ���� )
//��1,2,...,N����P����Ԫ��PΪ������
//���Ӷȣ�O(N) 

typedef long long ll;

ll inv[N];  
void pre(int MOD) {  
    inv[0] = inv[1]=1;  
    for(int i=2;i<N;i++)
        inv[i]=((MOD-MOD/i)*inv[MOD%i])%MOD;  
}    
int main(){  
    int n,p;
    cin>>n>>p;
    pre(p);
    for(int i=1;i<=n;++i)
        printf("%d\n",inv[i]);
    return 0;  
}  


 
