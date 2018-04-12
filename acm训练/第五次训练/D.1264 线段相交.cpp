/*
1264 线段相交  
基准时间限制：1 秒 空间限制：131072 KB 分值: 0 难度：基础题 收藏  关注
给出平面上两条线段的两个端点，判断这两条线段是否相交（有一个公共点或有部分重合认为相交）。 如果相交，输出"Yes"，否则输出"No"。
Input
第1行：一个数T，表示输入的测试数量(1 <= T <= 1000)
第2 - T + 1行：每行8个数，x1,y1,x2,y2,x3,y3,x4,y4。(-10^8 <= xi, yi <= 10^8)
(直线1的两个端点为x1,y1 | x2, y2,直线2的两个端点为x3,y3 | x4, y4)
Output
输出共T行，如果相交输出"Yes"，否则输出"No"。
Input示例
2
1 2 2 1 0 0 2 2
-1 1 1 1 0 0 1 -1
Output示例
Yes
No
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

bool f(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	if(x2-x1 == 0) {
		if((x3<=x1 && x1<x4)||x3>=x1 && x1>x4) return true;
		return false; 
	}else if(y2-y1 == 0) {
		if((y3<=y1 && y1<y4)||y3>=y1 && y1>y4) return true;
		return false; 
	}else {
		double p1 = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
		double p2 = (x2-x1)*(y4-y1)-(y2-y1)*(x4-x1);
		if((p1<=0&&p2>0)||(p1>=0&&p2<0)||(p1<0&&p2>=0)||(p1>0&&p2<=0)) 
			return true;
		return false;
	}
	
} 
int main() {
	int t;
	cin >> t;
	while(t--) {
		double x1,x2,x3,x4,y1,y2,y3,y4;
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		if(f(x1,y1,x2,y2,x3,y3,x4,y4)&&f(x3,y3,x4,y4,x1,y1,x2,y2)) cout << "Yes" << endl;
		else cout << "No" << endl;
		
	}
	return 0;
}
