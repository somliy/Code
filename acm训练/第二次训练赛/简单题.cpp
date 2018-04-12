/*
简单题
Time Limit: 1000 ms Memory Limit: 65536 KiB
  
Problem Description
小明最近开始近视了，所以经常地看错东西，比如在他的眼中'0'和'O'是没有区别的， 虽然看上去确实没有什么区别，但是第一个是数字中的0，第二个却是大写的'o',又比如'1','l'和'I'他现在看成是相同的，但是他们真的相同吗？ 第一个是数字1，第二个是小写的'L'，第三个是大写的'i',所以小明经常办糊涂事，今天老师给小明一份交作业的记录名单，让小明判断是不是有多交作业 的同学，那么小明会判断错吗？？？？

Input
多组输入，每组先输入一个n(1<=n<=100)表示名单上人的数目，接下来n行，每行一个字符串，表示交作业人的名字(len<=40,保证只有英文字母和数字)。

Output
如果小明判断有了错误输出"shibushisha",否则输出"goodboy"。

Sample Input
2
OOOOOO
000000
2
OOOOOO
00l000
Sample Output
shibushisha
goodboy
Hint
对于第一组，有两份作业，小明会把两个名字当成同一个名字。

Source
“师创杯”山东理工大学第八届ACM程序设计竞赛
*/

#include <cstdio>  
#include <cstring>  
#include<iostream>
#include <algorithm>  
using namespace std;  
int main()  
{  
    int n;  
    char a[105][45];  
    while(scanf("%d",&n)!=EOF)  
    {  
        for(int i=0;i<n;i++)  
        {  
            scanf("%s",a[i]); 
        }  
        int f=0;  
        for(int i=0;i<n;i++)  
        {  
            for(int j=i+1;j<n;j++)  
            {  
                int lena=strlen(a[i]);  
                int lenb=strlen(a[j]);  
                if(lena==lenb)  
                {  
                    f=0;  
                    for(int k=0;k<lena;k++)  
                    {  
                        if(a[i][k]!=a[j][k])  
                        {  
                            if(a[i][k]=='0'&&a[j][k]=='O')  
                            {  
                                f=1;  
                            }  
                            else if(a[i][k]=='O'&&a[j][k]=='0')  
                            {  
                                f=1;  
                            }  
                            else if(a[i][k]=='1'&&a[j][k]=='I')  
                            {  
                                f=1;  
                            }  
                            else if(a[i][k]=='1'&&a[j][k]=='l')  
                            {  
                                f=1;  
                            }  
                            else if(a[i][k]=='l'&&a[j][k]=='1')  
                            {  
                                f=1;  
                            }  
                            else if(a[i][k]=='l'&&a[j][k]=='I')  
                            {  
                                f=1;  
                            }  
                            else if(a[i][k]=='I'&&a[j][k]=='l')  
                            {  
                                f=1;  
                            }  
                            else if(a[i][k]=='I'&&a[j][k]=='1')  
                            {  
                                f=1;  
                            }  
                            else  
                            {  
                                f=0;  
                                break;  
                            }  
                        }  
                    }  
                    if(f==1)
					break;  
                }  
            }  
            if(f==1)
			break;  
        }  
        if(f==1)
		printf("shibushisha\n");  
        else
	 printf("goodboy\n");  
    }  
    return 0;  
}  

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<set>
//
//using namespace std;
//typedef long long ll;
//set<string> se;
//
//int main() {
//	int n;
//	string s;
//	while(~scanf("%d", &n)) {
//		se.clear();
//		int t = n;
//		while(t--) {
//			cin >> s;
//			for(int i = 0; i < s.size(); i++) {
//				if(s[i] == 'O' || s[i] == 'o')
//					s[i] = '0';
//				if(s[i] == 'l' || s[i] == 'I' || s[i] == 'L')
//					s[i] = '1';
//			} 
////			cout << s << endl;
//			se.insert(s);
//		}
//		if(se.size() == n) cout << "goodboy" << endl;
//		else cout << "shibushisha" << endl;
//	}
//}
//

