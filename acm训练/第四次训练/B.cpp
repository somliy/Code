/*
51Nod - 1102 
有一个正整数的数组，化为直方图，求此直方图包含的最大矩形面积。例如 2,1,5,6,2,3，对应的直方图如下：



面积最大的矩形为5,6组成的宽度为2的矩形，面积为10。
Input
第1行：1个数N，表示数组的长度(0 <= N <= 50000) 
第2 - N + 1行：数组元素Ai。(1 <= Ai <= 10^9)
Output
输出最大的矩形面积
Sample Input
6
2
1
5
6
2
3
Sample Output
10
*/
#include <algorithm>
#include <cstdio>
#include <stack>
#include <iostream>
const int maxn = 50000+10;
typedef long long ll;
ll a[maxn];
using namespace std;
int main(){
    int n;
    while (cin>>n && n){
        ll ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        stack<int> s;
        s.push(0);a[++n]=0;
        for(int i=1;i<=n;i++){
            while (a[i]<a[s.top()]){
                ll x = a[s.top()];s.pop();
                ll y = i-s.top()-1;
                ans = max(ans,x*y);
            }
            s.push(i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
