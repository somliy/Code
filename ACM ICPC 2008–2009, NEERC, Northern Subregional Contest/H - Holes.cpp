#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main() {
	freopen("holes.in","r",stdin);
    freopen("holes.out","w",stdout);
	int x;
    while(cin >> x) {
        if(x == 0) cout << 1 << endl;
        else {
            if(x%2 == 0) {
                for(int i = 1; i <= x/2; i++)
                	printf("8");
                cout << endl;
            }else {
                if(x == 1) cout << "0" << endl;
                else {
                    cout << "4";
                    for(int i = 1; i <= x/2; i++)
                    	printf("8");
                    cout<<endl;
                }
            }
        }
    }
    return 0;
} 
