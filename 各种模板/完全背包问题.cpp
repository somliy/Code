#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int n,W;
int dp[maxn][maxn];
int v[maxn], w[maxn];

void sovle()
{
    for(int i=0; i<n; i++){
        for(int j = 0; j <= W; j++){
            if(j < w[i]){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = max(dp[i][j], dp[i+1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][W] << endl;
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> w[i] >> v[i];
    cin >> W;
    sovle();

    return 0;
}
