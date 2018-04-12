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
const int MAXN = 9999999;
const int maxn = 100;
const int inf = 0x3f3f3f3f;


int main() {
	int n;
	cin >> n;
	int t = n / 3600;
	int h = (n % 3600) / 60;
	int s = n % 60;
	printf("%d:%d:%d\n", t, h, s);
	
    return 0;
} 
