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
                if(len%2==0 || flag > 1) {//�����һ�β�����ż�����ȣ��϶����У�flag==2��˵�������Σ���������Ҳ���� 
                    cout << "Impossible" << endl;
                    return 0;
                } 
                index = len/2 - i + 1;//�ƶ����м�λ�õĲ��� 
                break;
            }
            else if(str[i] == str[j]) {
                ans += n - j;//�ƶ��ľ��� 
                for(int l = j; l < n; l++) {
                    str[l] = str[l+1];//��ǰ�ƶ� 
                }
                str[n] = str[i];//ά���ַ���Ϊ�ƶ��� 
                n--;//�Թ��Ѿ��ƶ��õģ���һ�α����ʹ�û���ж��ĵط���ʼ 
                break;
            }
        }
    }
    cout << ans+index << endl;
    return 0;
}
