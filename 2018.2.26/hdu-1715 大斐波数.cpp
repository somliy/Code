#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>

using namespace std;

int arr[1005][1005];

void add(int *a, int *b, int n) {
    int temp = 0;
    for(int i = 0; i <= 500; i++) {
        int x = a[i] + b[i] + temp;
        arr[n][i] = x%10;
        temp = x / 10;
    }
}

int main() {
    arr[1][0] = 1;
    arr[2][0] = 1;
    for(int i = 3; i <= 1000; i++) {
        add(arr[i-1], arr[i-2], i);
    }
    int n, m;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> m;
        int j;
        for(j = 1000; j >= 0; j--)
            if(arr[m][j]) break;
        for(;j >= 0; j --)
            printf("%d", arr[m][j]);
        printf("\n");
    }
    return 0;
}
