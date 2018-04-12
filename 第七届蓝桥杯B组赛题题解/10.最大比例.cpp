/*
最大比例

X星球的某个大奖赛设了M级奖励。每个级别的奖金是一个正整数。
并且，相邻的两个级别间的比例是个固定值。
也就是说：所有级别的奖金数构成了一个等比数列。比如：
16,24,36,54
其等比值为：3/2

现在，我们随机调查了一些获奖者的奖金数。
请你据此推算可能的最大的等比值。

输入格式：
第一行为数字N，表示接下的一行包含N个正整数
第二行N个正整数Xi(Xi<1 000 000 000 000)，用空格分开。每个整数表示调查到的某人的奖金数额

要求输出：
一个形如A/B的分数，要求A、B互质。表示可能的最大比例系数

测试数据保证了输入格式正确，并且最大比例是存在的。

例如，输入：
3
1250 200 32

程序应该输出：
25/4

再例如，输入：
4
3125 32 32 200

程序应该输出：
5/2


再例如，输入：
3
549755813888 524288 2

程序应该输出：
4/1

资源约定：
峰值内存消耗 < 256M
CPU消耗 < 3000ms

请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

*/
#include <cstdio>
#include <algorithm>
struct fs {
    __int64 fz, fm;
    bool operator == (const fs &B)const {
        if (B.fz != fz || B.fm != fm) return 0;
        return 1;
    }
}data[105];
__int64 rd[105];
__int64 GCD(__int64 a, __int64 b) {
    __int64 c;
    while (c = a%b) a = b, b = c;
    return b;
}
fs slv(fs a, fs b) {
    if (a == b) return a;
    __int64 gcd;
    gcd = GCD(a.fz, b.fz);
    a.fz /= gcd; b.fz /= gcd;
    gcd = GCD(a.fm, b.fm);
    a.fm /= gcd; b.fm /= gcd;
    a.fz *= b.fm;
    b.fz *= a.fm;
    if (a.fz > b.fz) a.fm = b.fz;
    else a.fm = a.fz, a.fz = b.fz;
    return a;
}
int main() {
    int i, j, n;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) scanf("%I64d", rd + i), data[i].fm = 1;
    std::sort(rd, rd + n);
    for (i = j = 0; i < n; ++i) if (rd[i] != rd[i + 1]) data[j++].fz = rd[i];
    for (n = j - 1; n; --n) {
        for (i = 0; i < n; ++i) data[i] = slv(data[i], data[i + 1]);
    }
    if (j == 1) puts("1/1");
    else printf("%I64d/%I64d", data[0].fz, data[0].fm);
    return 0;
}
