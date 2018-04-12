#include<iostream>  
using namespace std;  
//pΪ��������p[0],p[1]�����һ������p[1],p[2]����ڶ�������lengthΪp�ĳ���  
//�����������������length=7��mΪ�洢���Ž���Ķ�ά����tΪ�洢ѡ�����Ž��·�ߵ�  
//��ά����  
void MatrixChainOrder(int *p,int (*m)[10],int (*t)[10],int length)  
{  
    int n=length-1;  
    int i,j,k,q,num=0;  
    //A[i][i]ֻ��һ������������˴���Ϊ0����m[i][i]=0;  
    for(i=1;i<length;i++)  
    {  
        m[i][i]=0;  
    }  
    //i����������ĳ��ȣ�i=2��ʾ�������������ʱ��λ���  
    for(i=2;i<=n;i++)  
    {  
        //j��ʾ�ӵ�j������ʼ��i��������λ���������  
        for(j=1;j<=n-i+1;j++)  
        {  
            //kΪ�ӵ�j����i���������k����j��k��ʾ����֮���i��������λ���  
            k=j+i-1;  
            //m[j][k]�洢�˴�j��kʹ����ѻ������õ������Ž��  
            m[j][k]=0x7fffffff;  
            //qΪ����j��k-1֮�������Ŀ��������q��j��k֮��ľ��������̽�ԵĻ��֣�  
            //�Ӷ��ҵ����Ż��֣�����һ�ֱ����Ե���̽��  
            for(q=j;q<=k-1;q++)  
            {  
                num=m[j][q]+m[q+1][k]+p[j-1]*p[q]*p[k];  
                if(num<m[j][k])  
                {  
                    m[j][k]=num;  
                    t[j][k]=q;  
                }  
            }  
        }  
    }  
}  
void PrintAnswer(int(*t)[10],int i,int j)  
{  
    if(i==j)  
    {  
        cout<<"A"<<i;  
    }  
    else  
    {  
        cout<<"(";  
        PrintAnswer(t,i,t[i][j]);  
        PrintAnswer(t,t[i][j]+1,j);  
        cout<<")";  
    }  
}  
int main()  
{  
    int p[7]={30,35,15,5,10,20,25};  
    int m[10][10],t[10][10];  
    MatrixChainOrder(p,m,t,7);  
    PrintAnswer(t,1,6);  
    return 0;  
}
