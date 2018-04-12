/*
活动选择
 1000 ms       65536 KiB
Accepted/Submissions: 7/28 (25.00%)
   
Description
自从小白和小黑的小船翻了以后，小白就在学校勤工俭学，现在小白得到了一个任务：明天学校要举办一些活动，让小白安排教室，但是最近学校的教室资源比较的紧张，所以要用尽量少的教室(同一个教室不能同时举办两个活动)。

Input
 多组输入，每组输入一个n(1 <= n <= 100000)表示活动的数量，接下来的n行每行两个整数l,r(1 < l < r < 10^9)代表活动的开始时间与结束时间。

Output
输出需要最小教室的数量。

Sample
Input

3
1 2
3 4
2 9
Output

2
Source
“师创杯”山东理工大学第八届ACM程序设计竞赛 热身赛
*/

#include<cstdio>
#include <algorithm>


using namespace std;
const int maxn = 100000 + 100;
typedef long long ll;
struct Node {
    int t, s;
} node[maxn * 2];
int vis[maxn];

bool cmp(Node a, Node b) {
    if (a.t != b.t) return a.t < b.t;
    else return a.s < b.s;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        n = n * 2;
        for (int i = 0; i < n; i++) {
            scanf("%d", &node[i].t);
            if (i % 2 == 0) node[i].s = 1;
            else node[i].s = -1;
        }
        sort(node, node + n, cmp);
        int sum = 0, Max = 0;
        for (int i = 0; i < n; i++) {
            sum += node[i].s;
            Max = max(sum, Max);
        }
        printf("%d\n", Max);

    }

    return 0;
}
