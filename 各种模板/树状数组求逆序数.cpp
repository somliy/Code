#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;
const int N = 500005;

struct Node
{
    int v,order;
};

int n;
int c[N];
int aa[N];    //��ɢ���������
Node a[N];    //��״����

int Lowbit(int x)
{
    return x & (-x);
}

void Update(int t,int val)
{
    for(int i=t; i<=n; i+=Lowbit(i))
        c[i] += val;
}

int getSum(int x)
{
    int ans=0;
    for(int i=x; i>0; i-=Lowbit(i))
        ans += c[i];
    return ans;
}

bool cmp(Node a,Node b)
{
    return a.v<b.v;
}

int main()
{
    while(~scanf("%d",&n),n)
    {
        //��ɢ��
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i].v);
            a[i].order=i;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1; i<=n; i++)
            aa[a[i].order]=i;

        //��״������������
        memset(c,0,sizeof(c));
        long long ans=0;
        for(int i=1; i<=n; i++)
        {
            Update(aa[i],1);
            ans+=i-getSum(aa[i]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
