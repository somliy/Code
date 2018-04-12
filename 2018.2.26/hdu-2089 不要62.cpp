#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int s[1000005];
char str[8],a[2]="4",b[5]="62";
void init(){
    for(int i=1;i<=1000000;i++){
        itoa(i,str,10);
        if(strstr(str,a)!=NULL || strstr(str,b)!=NULL) s[i]=0;
        else s[i]=1;
    }
}
int main(){
    int n,m;
    init();
    while(scanf("%d%d",&m,&n)!=EOF){
        if(n==0&&m==0) break;
        int sum=0;
        for(int i=m;i<=n;i++)
            sum+=s[i];
        printf("%d\n",sum);
    }
    return 0;
}
