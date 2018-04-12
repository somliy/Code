/*
标题：日期问题

小明正在整理一批历史文献。这些历史文献中出现了很多日期。小明知道这些日期都在1960年1月1日至2059年12月31日。令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。  

比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。  

给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？

输入
----
一个日期，格式是"AA/BB/CC"。  (0 <= A, B, C <= 9)  

输出
----
输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。多个日期按从早到晚排列。  

样例输入
----
02/03/04  

样例输出
----
2002-03-04  
2004-02-03  
2004-03-02  

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。
----------------------------------------------


闰年的判断，月份的判断，每月天数的判断， 然后选出符合规定的

变成数字，例如20020203是一个数字

放入set中，自动排序去重，然后输出，注意输出格式 


*/ 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<set>

using namespace std;

const int MAXN = 10000;
const int maxn = 10;
int flag;
set<int> se;

bool year(int y) {
	flag = 0;
	if(2060 <= y || y <= 1959) 
		return false;
	if(y%400==0 || (y%4==0&&y%100!=0)) 
		flag = 1;
	return true; 
}

bool mounth(int m, int d) {
	if(m <= 0 || d <= 0 || m >= 13) return false;
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		if(d > 31) return false;
	if(m==4||m==6||m==9||m==11)
		if(d > 30) return false;
	if(m==2) {
		if(flag && d > 29) return false;
		if(!flag && d > 28) return false; 
	}
	return true;
}

int main() {
	int a, b, c;
	scanf("%d/%d/%d", &a, &b, &c);
	for(int i = 19; i <= 20; i++) {
		if(year(i*100+a)) {
			if(mounth(b, c)) 
				se.insert((i*100+a)*10000+b*100+c);
		}
		if(year(i*100+c)) {
			if(mounth(a, b)) 
				se.insert((i*100+c)*10000+a*100+b);
			if(mounth(b, a)) 
				se.insert((i*100+c)*10000+b*100+a);
		}
	}
	for(set<int>::iterator it = se.begin(); it != se.end(); it++) {
		printf("%d-%02d-%02d\n", *it/10000, *it%10000/100, *it%100);
	}
	return 0;
} 
