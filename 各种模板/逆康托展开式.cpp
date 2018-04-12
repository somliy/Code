/*
计算一个序列在排列中的顺序
*/
#include <iostream>
#include <cstring>
using namespace std;
long int factory[]={1,1,2,6,24,120,720,5040,40320,362880,3628800};//阶乘表
long Contor(char str[], int n)
{
    long result = 0;
    for(int i = 0; i < n; i++)
    {
        int counted = 0;
        for(int j = i+1; j < n; j++)
        {
            if(str[i] > str[j])             //当前未出现的元素中是排在第几个
                ++counted;
        }
        result += counted*factory[n-i-1];
    }
    return result+1;                        //从0开始
}

int main()
{
    char str[100];
    cin >> str;
    cout << Contor(str, strlen(str));
    return 0;
}
