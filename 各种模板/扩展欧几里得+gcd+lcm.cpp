

//���Լ��  շת����� 
typedef long long LL; 
const LL MAXN = 1000000; 

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a%b);
}

//���ֱ��a%b==0,˵��a=bxһ������������Ǵӱ���ʼ��С�ģ����仰˵�Ǵӳ��Լ���ʼ�ģ�
//����ֻ��Խ��Խ��С���ж�����������ô��������ʱ���˵����a���Ա�b������b���Ա�b������
//b�������Լ��
//�������һ�εõ�a%b==0����ô���ǰ�a�в��ܱ������Ĳ����õ���a%b����Ϊ�ⲿ�ֲ�����ô�仯��
//ʼ�վ���һ�����ܱ������Ĳ��֣���һ���������������Ĵη������һ����
//ȥ����һ���֣������Ƚ��Ƿ���Ա�������������Ծ���������˵��Ҫ˵����һ���ǣ��������һ�εõ���a��b��ֵ�Ѿ����ǵ�����ֵ�ˣ���
//��������ˣ���ôb����Ҫ���ֵ�����Ǽ����������ֱ࣬��b==0��bһ�����Ե�0����Ϊ���е��������Ա�1������ 




//��չŷ�����
typedef long long LL; 
const LL MAXN = 1000000; 
 
LL extgcd(LL a, LL b, LL &x, LL &y) {
	LL d = a;
	if(b != 0) {
		d = extgcd(b, a%b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1; y = 0;
	}
	return d;
}

//ax+by=c  http://blog.csdn.net/loi_dqs/article/details/49488851 
//����c�� ������������c��ͬ�����ܱ�С����a/gcdΪ��С����
//��� c%gcd != 0 �Ļ��� �����޽� ��
//a�� ���ս��Ϊ(a*c/gcd)mod(l/gcd) 
//printf("%lld\n", ((x*c/gcd)%(l/gcd)+(l/gcd))%(l/gcd));

//ax+by=1�����gcd(a,b)!=1��˵�������������ʣ����޽�ģ������������ʵ�ʱ�� ax+by=1�Ż������
//ֻҪb!=0��һֱ����ȥ��ֱ������0��x=1��y=0��Ȼ��ִ�� y -= (a / b) * x, ���൱��һ���ݹ飬ÿ��ab������xy���Ž�����
//�����𰸵�ʱ�����Ź�����һ�飬�Ϳ��Եõ����ˣ������粩�� 




//��С������ 

typedef long long LL;  
const LL MAXN = 1000000;

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a%b);
}

LL lcm(LL a, LL b) {
	return a / gcd(a, b) * b;
} 




//����չŷ������㷨���ģ���Է���
typedef long long LL;  
const LL MAXN = 1000000;
LL x0, y0, kx, ky;  

LL exgcd(LL a, LL b, LL &x, LL &y) {  
     if(a==0 && b==0) return -1;  
     if(b == 0) { 
		 x=1; y=0; 
		 return a;  
	 }  
     LL d = exgcd(b, a%b, y, x);  
     y -= a/b*x;  
     return d;  
} 

LL MLE(LL a, LL b, LL mod) {  // ����(a*x)%mod=b ����С��������   ����С�˷���Ԫ ans��x 
    LL x, y;  
    LL gcd = exgcd(a, mod, x, y);  
    if(b%gcd != 0) return -1;  //������-1����÷����޽�  
    x *= b / gcd;  
    mod /= gcd;  
    if(mod < 0) mod =- mod;  
    LL ans = x % mod;  
    if(ans <= 0) ans += mod;  //������Ϊ�� ans+i*mod ��iΪ������  
    return ans;  
}  

bool LE(LL a, LL b, LL c) {   //�����Է���ax+by=c  
    LL x1, y1;  
    LL gcd = exgcd(a, b, x1, y1);  
    if(c%gcd) return false;  //��������  
    x0 = x1*c/gcd, y0 = y1*c/gcd;  
    kx = b/gcd, ky = -a/gcd;  
    return true;   //�н⣬�⼯Ϊ����x0+kx*t,y0+ky*t�� tΪ����  
}  

//ͬ�෽�� ax��b (mod n)����δ֪�� x �н⣬���ҽ��� gcd(a,n) | b���ҷ����н�ʱ�������� gcd(a,n) ���⡣
//��ⷽ�� ax��b (mod n) �൱����ⷽ�� ax+ ny= b, (x, yΪ����)
//�� d= gcd(a,n)���������� x �� y������ d= ax+ ny(����չŷ����µó�)����� d| b���򷽳�
//a* x0+ n* y0= d�� �������߳��� b/ d��(��Ϊ d|b�������ܹ�����)���õ� a* x0* b/ d+ n* y0* b/ d= b��
//���� x= x0* b/ d��y= y0* b/ d Ϊ ax+ ny= b ��һ���⣬���� x= x0* b/ d Ϊ ax= b (mod n ) �Ľ⡣
//ax��b (mod n)��һ����Ϊ x0= x* (b/ d ) mod n���ҷ��̵� d ����ֱ�Ϊ xi= (x0+ i* (n/ d ))mod n {i= 0... d-1}��
//��ans=x*(b/d),s=n/d;
//����ax��b (mod n)����С������Ϊ��(ans%s+s)%s;

