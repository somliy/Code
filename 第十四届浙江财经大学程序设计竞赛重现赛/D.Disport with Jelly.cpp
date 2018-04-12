#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        printf("Case #%d: ",t);
        int L,R,K;
        cin >> L >> R >> K;
        if((K-L) == (R-K))
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }
    return 0;
}
