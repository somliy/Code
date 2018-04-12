/*
������

X�����ĳ����������M��������ÿ������Ľ�����һ����������
���ң����ڵ����������ı����Ǹ��̶�ֵ��
Ҳ����˵�����м���Ľ�����������һ���ȱ����С����磺
16,24,36,54
��ȱ�ֵΪ��3/2

���ڣ��������������һЩ���ߵĽ�������
����ݴ�������ܵ����ĵȱ�ֵ��

�����ʽ��
��һ��Ϊ����N����ʾ���µ�һ�а���N��������
�ڶ���N��������Xi(Xi<1 000 000 000 000)���ÿո�ֿ���ÿ��������ʾ���鵽��ĳ�˵Ľ�������

Ҫ�������
һ������A/B�ķ�����Ҫ��A��B���ʡ���ʾ���ܵ�������ϵ��

�������ݱ�֤�������ʽ��ȷ�������������Ǵ��ڵġ�

���磬���룺
3
1250 200 32

����Ӧ�������
25/4

�����磬���룺
4
3125 32 32 200

����Ӧ�������
5/2


�����磬���룺
3
549755813888 524288 2

����Ӧ�������
4/1

��ԴԼ����
��ֵ�ڴ����� < 256M
CPU���� < 3000ms

���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

���д������ͬһ��Դ�ļ��У�����ͨ���󣬿����ύ��Դ�롣

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
