/*
quadratic equation
 2000 ms       131072 KiB
Accepted/Submissions: 26/168 (15.48%)
   
Description
With given integers a,b,c, you are asked to judge whether the following statement is true: "For any x, if a?+b?x+c=0, then x is an integer."

Input
The first line contains only one integer T(1≤T≤2000), which indicates the number of test cases.
For each test case, there is only one line containing three integers a,b,c(?5≤a,b,c≤5).

Output
or each test case, output “YES” if the statement is true, or “NO” if not.

Sample
Input

3
1 4 4
0 0 1
1 3 1
Output

YES
YES
NO
Source
“浪潮杯”山东省第八届ACM大学生程序设计竞赛（感谢青岛科技大学）




*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;
typedef long long ll;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;

		if(!a && !b) {
			if(!c) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
		else if(!a&&b) {
			if(c % b == 0) {
				cout << "YES" << endl;
			}else {
				cout << "NO" << endl;
			}
		}
		else {
			int s = b*b-4*a*c;
			if(s < 0) {
				cout << "YES" << endl;
				continue;	
			}
			double ans = sqrt(s);
			if(ans != (int)ans) {
				cout << "NO" << endl;
				continue;
			}
			int x1 = (-b+(int)ans)%(2*a);
			int x2 = (-b-(int)ans)%(2*a);
			if(!x1 && !x2) {
				cout << "YES" << endl;
			}else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
