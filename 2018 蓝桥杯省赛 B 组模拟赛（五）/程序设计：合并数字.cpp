#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

stack<int> s;

int main() {
	int n, x, y, ans = 0;
	cin >> n >> x;
	s.push(x);
	if(n == 1) cout << "0" << endl;
	else {
		for(int i = 2; i <= n; i++) {
			cin >> x;
			s.push(x);
			while(s.size()>=2) {
				x = s.top();s.pop();
				y = s.top();s.pop();
				if(abs(x-y) == 1) {
					ans++;
					if(x>y) s.push(y);
					else s.push(x);
				}
				else {
					s.push(y);
					s.push(x);
					break;
				}
			}
		}
		cout << ans <<endl;
	}
	return 0;
}
