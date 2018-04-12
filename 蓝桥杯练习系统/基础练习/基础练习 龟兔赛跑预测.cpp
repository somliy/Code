/*


*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<vector> 

using namespace std;

typedef long long ll; 
const int maxn = 100;
const int inf = 0x3f3f3f3f;
const int MAXN = 100000;


int main() {
	int v1, v2, t, s, l, flag = -1;
	cin >> v1 >> v2 >> t >> s >> l;
	int t0 = 0;
	int s1 = 0;
	int s2 = 0;
	int tmp;
	while(s1<l && s2<l) {
		if(s1-s2>=t) {
			tmp = s;
			while(tmp-- && s2<l) {
				s2 += v2;
				t0++;
			}
			continue;
		}
		s1 += v1;
		s2 += v2;
		t0++;
	}
	if(s1>=l&&s2>=l) printf("D\n%d\n", t0);
	else if(s1>=l&&s2<l) printf("R\n%d\n", t0);
	else printf("T\n%d\n", t0);
    return 0; 
} 
