#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 10000
using namespace std;
int a[1300][maxn],pri[1300],tot=0,pos[maxn];
int n,k,p;
bool b[maxn];
void getpri(){
    for (int i=2; i<maxn; i++){
        if (!b[i]) pri[++tot]=i,pos[i]=tot;
        for (int j=i+i; j<maxn; j+=i) b[j]=true;
    }
}
void init(){
    int tep;
    for (int i=1; i<=tot; i++){
        tep=a[i][0]=1;
        for (int j=1; j<maxn; j++){
            tep=(tep*j);
            while (tep%pri[i]==0) tep/=pri[i];
            tep%=pri[i];
            a[i][j]=tep;
        }
    }
}
int exp_mod(int A,int B,int p){
    int ans=1;
    while (B){
        if (B&1) ans=(ans*A)%p;
        B>>=1;
        A=(A*A)%p;
    }
    return ans;
}
int cm(int A,int B,int p){
    int tep=exp_mod(a[pos[p]][B],p-2,p)*exp_mod(a[pos[p]][A-B],p-2,p);
    tep%=p;
    return (a[pos[p]][A]*tep)%p;
}
int count(int A,int p){
    if (A==0) return 0;
    return A/p+count(A/p,p);
}
int lucas(int A,int B,int p){
    if (B==0) return 1;
    if (count(A,p)>count(B,p)+count(A-B,p)) return 0;
    return lucas(A/p,B/p,p)*cm(A%p,B%p,p);
}
int main(){
    int cas=0;
    getpri();
    init();
    while (scanf("%d%d%d",&n,&k,&p)!=EOF){
        if (k>n-k) k=n-k;
        printf("Case #%d: %d\n",++cas,(lucas(n+1,k,p)+n-k)%p);
    }
    return 0;
}
