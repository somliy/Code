#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>

using namespace std;

int main() {
    int n, m, a[100];
    a[2] = 1, a[3] = 2;
    for(int i = 4; i <= 40; i++) {
        a[i] = a[i-1] + a[i-2];
    }
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> m;
        cout << a[m] << endl;
    }
    return 0;
}
