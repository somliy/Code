#include<iostream>  
using namespace std;  
//p为矩阵链，p[0],p[1]代表第一个矩阵，p[1],p[2]代表第二个矩阵，length为p的长度  
//所以如果有六个矩阵，length=7，m为存储最优结果的二维矩阵，t为存储选择最优结果路线的  
//二维矩阵  
void MatrixChainOrder(int *p,int (*m)[10],int (*t)[10],int length)  
{  
    int n=length-1;  
    int i,j,k,q,num=0;  
    //A[i][i]只有一个矩阵，所以相乘次数为0，即m[i][i]=0;  
    for(i=1;i<length;i++)  
    {  
        m[i][i]=0;  
    }  
    //i代表矩阵链的长度，i=2表示有两个矩阵相乘时如何划分  
    for(i=2;i<=n;i++)  
    {  
        //j表示从第j个矩阵开始的i个矩阵如何划分是最优  
        for(j=1;j<=n-i+1;j++)  
        {  
            //k为从第j个数i个矩阵就是k，从j到k表示他们之间的i个矩阵如何划分  
            k=j+i-1;  
            //m[j][k]存储了从j到k使用最佳划分所得到的最优结果  
            m[j][k]=0x7fffffff;  
            //q为介于j到k-1之间的数，目的是利用q对j到k之间的矩阵进行试探性的划分，  
            //从而找到最优划分，这是一种遍历性的试探。  
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
