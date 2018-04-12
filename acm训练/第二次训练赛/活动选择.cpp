/*
�ѡ��
 1000 ms       65536 KiB
Accepted/Submissions: 7/28 (25.00%)
   
Description
�Դ�С�׺�С�ڵ�С�������Ժ�С�׾���ѧУ�ڹ���ѧ������С�׵õ���һ����������ѧУҪ�ٰ�һЩ�����С�װ��Ž��ң��������ѧУ�Ľ�����Դ�ȽϵĽ��ţ�����Ҫ�þ����ٵĽ���(ͬһ�����Ҳ���ͬʱ�ٰ������)��

Input
 �������룬ÿ������һ��n(1 <= n <= 100000)��ʾ�����������������n��ÿ����������l,r(1 < l < r < 10^9)�����Ŀ�ʼʱ�������ʱ�䡣

Output
�����Ҫ��С���ҵ�������

Sample
Input

3
1 2
3 4
2 9
Output

2
Source
��ʦ������ɽ������ѧ�ڰ˽�ACM������ƾ��� ������
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
