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
	char str1[maxn], str2[maxn];
//	gets(str1); gets(str2);
	cin >> str1;
	cin >> str2;
	if(strlen(str1) != strlen(str2)) 
		printf("1\n");
	else if(!strcmp(str1, str2)) 
		printf("2\n");
	else if(!strcmp(strlwr(str1), strlwr(str2)))
		printf("3\n");
	else 
		printf("4\n");
    return 0;
} 

