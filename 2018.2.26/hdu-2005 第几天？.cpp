#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int y) {
    if((y%4==0 && y%100!=0) || y%400==0) return true;
    return false;
}

int main() {
    int y, m, d;
    while(~scanf("%d/%d/%d", &y, &m, &d)) {
        month[2] = 28;
        if(check(y)) month[2] = 29;
        int ans = 0;
        month[0] = d;
        for(int i = 0; i < m; i++) {
            ans += month[i];
        }
        cout << ans << endl;
    }
    return 0;
}
