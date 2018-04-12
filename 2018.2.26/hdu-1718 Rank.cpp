#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;

ll arr[105];

int main(){
    ll index1, index2, a, b;
    while(~scanf("%lld", &index1)) {
        memset(arr, 0, sizeof arr);
        while(~scanf("%lld %lld", &a, &b)) {
            if(!a && !b) break;
            b = 100 - b;
            if(index1 == a) index2 = b;
            arr[b]++;
        }
        for(ll i = 1; i <= 100; i++)
            arr[i] = arr[i-1] + arr[i];
        cout << arr[index2-1]+1 << endl;
    }
    return 0;
}
