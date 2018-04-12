/*
����
Time Limit: 1000 ms Memory Limit: 65536 KiB
  
Problem Description
С�������ʼ�����ˣ����Ծ����ؿ���������������������'0'��'O'��û������ģ� ��Ȼ����ȥȷʵû��ʲô���𣬵��ǵ�һ���������е�0���ڶ���ȴ�Ǵ�д��'o',�ֱ���'1','l'��'I'�����ڿ�������ͬ�ģ��������������ͬ�� ��һ��������1���ڶ�����Сд��'L'���������Ǵ�д��'i',����С���������Ϳ�£�������ʦ��С��һ�ݽ���ҵ�ļ�¼��������С���ж��ǲ����жཻ��ҵ ��ͬѧ����ôС�����жϴ��𣿣�����

Input
�������룬ÿ��������һ��n(1<=n<=100)��ʾ�������˵���Ŀ��������n�У�ÿ��һ���ַ�������ʾ����ҵ�˵�����(len<=40,��ֻ֤��Ӣ����ĸ������)��

Output
���С���ж����˴������"shibushisha",�������"goodboy"��

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
���ڵ�һ�飬��������ҵ��С������������ֵ���ͬһ�����֡�

Source
��ʦ������ɽ������ѧ�ڰ˽�ACM������ƾ���
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

