/*


*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<vector> 

using namespace std;

typedef long long ll; 
const int MAXN = 9999999;
const int maxn = 8010;
const int inf = 0x3f3f3f3f;

int main() {
    int n, len, flag = 0, index, ans = 0;
    char str[8005];
    cin >> len;
    cin >> str+1;
    n = len;
    for(int i = 1; i <= n; i++) {
        for(int j = n; j >= 1; j--) {
            if(i == j) {
                flag++;
                if(len%2==0 || flag > 1) {//如果有一次并且是偶数长度，肯定不行，flag==2，说明有两次，奇数个数也不行 
                    cout << "Impossible" << endl;
                    return 0;
                } 
                index = len/2 - i + 1;//移动到中间位置的步数 
                break;
            }
            else if(str[i] == str[j]) {
                ans += n - j;//移动的距离 
                for(int l = j; l < n; l++) {
                    str[l] = str[l+1];//往前移动 
                }
                str[n] = str[i];//维护字符串为移动后 
                n--;//略过已经移动好的，下一次遍历就从没有判定的地方开始 
                break;
            }
        }
    }
    cout << ans+index << endl;
    return 0;
}
