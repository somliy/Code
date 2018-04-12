#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

double f(int x) {
    double ans = 1.0;
    int flag = -1;
    for(int i = 2; i <= x; i++) {
        ans += (double)flag/i;
        flag *= -1;
    }
    return ans;
}

int main() {
    int n, x;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        printf("%.2lf\n", f(x));
    }
    return 0;
}
