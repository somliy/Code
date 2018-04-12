/*
company
 1000 ms       65536 KiB
Accepted/Submissions: 16/55 (29.09%)
   
Description
There are n kinds of goods in the company, with each of them has a inventory of  and direct unit benefit . Now you find due to price changes, for any goods sold on day i, if its direct benefit is val, the total benefit would be i?val.
Beginning from the first day, you can and must sell only one good per day until you can't or don't want to do so. If you are allowed to leave some goods unsold, what's the max total benefit you can get in the end?

Input
The first line contains an integers n(1≤n≤1000).
The second line contains n integers val1,val2,..,valn(?100≤.≤100).
The third line contains n integers cnt1,cnt2,..,cntn(1≤≤100).

Output
Output an integer in a single line, indicating the max total benefit.

Sample
Input

4
-1 -100 5 6
1 1 1 2
Output

51
Hint
sell goods whose price with order as -1, 5, 6, 6, the total benefit would be -1*1 + 5*2 + 6*3 + 6*4 = 51.

Source
“浪潮杯”山东省第八届ACM大学生程序设计竞赛（感谢青岛科技大学）
*/

#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
const int MANX = 10100;
struct node {
	ll v, c;
}cnt[MANX];
ll a[MANX], num = 0;

int main() {
	ll n;
	while(~scanf("%d", &n)) {
		for(ll i = 0; i < n; i++) 
			cin >> cnt[i].v;
		for(ll i = 0; i < n; i++) 
			cin >> cnt[i].c;
		for(ll i = 0; i < n; i++) {
			for(ll j = 0; j < cnt[i].c; j++) {
				a[num++] = cnt[i].v;
			}
		}
		sort(a, a+num);
		ll sum = 0, ans = 0, index = 0;
		for(ll i = num-1; i >= 0; i--) {
			sum += a[i];
			index += sum;
			ans = max(ans, index);
		}
		cout << ans << endl;
	}
	
	return 0;	
}
