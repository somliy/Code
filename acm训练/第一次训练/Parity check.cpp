/*
Parity check
 2000 ms       524288 KiB
Accepted/Submissions: 29/108 (26.85%)
   
Description
Fascinated with the computer games, Gabriel even forgets to study. Now she needs to finish her homework, and there is an easy problem:

f(n)=

She is required to calculate f(n) mod 2 for each given n. Can you help her?

Input
Multiple test cases. Each test case is an integer n(0≤n≤) in a single line.

Output
For each test case, output the answer of f(n)mod2.

Sample
Input

2
Output

1
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
	char c[100000];
	while(~scanf("%s", c)) {  
        int len = strlen(c);  
        int ans = 0;  
        for(int i = 0; i < len; i++) 
            ans = (ans*10 + (c[i]-'0')) % 3;   
        if(ans==0) cout << "0" << endl;
        else if(ans==1 || ans==2) cout << "1" << endl;  
    }  
    return 0;  
}
