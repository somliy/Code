#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int dp[maxn][maxn];
int w[maxn],n;
int v[maxn],W;

void sovle()
{
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=W; j++){
            if(j < w[i]){
                dp[i][j] = dp[i+1][j];
            }else{
                dp[i][j] = max(dp[i+1][j], dp[i+1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[0][W] << endl;
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> w[i] >> v[i];
    }
    cin >> W;
    sovle();

    return 0;
}
