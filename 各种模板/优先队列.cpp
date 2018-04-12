#include<stdio.h>  
#include<functional>  
#include<queue>  
#include<vector>  

using namespace std;  



void clear(priority_queue<int,vector<int>,cmp>& q) {
    priority_queue<int,vector<int>,cmp> empty;
    swap(empty, q);
}
clear(priority_queue<int,vector<int>,cmp>& q);
清空 



struct cmp1 {  
    bool operator ()(int &a, int &b){  
        return a > b;//最小值优先  
    }  
};  

struct cmp2 {  
    bool operator ()(int &a, int &b){  
        return a < b;//最大值优先  
    }  
};  

struct number1 { 
    int x;  
    bool operator < (const number1 &a) const {  
        return x > a.x;//最小值优先  
    }  
};  

struct number2 {  
    int x;  
    bool operator < (const number2 &a) const {  
        return x < a.x;//最大值优先  
    }  
};  

	priority_queue<int>que;//采用默认优先级构造队列  
  
    priority_queue<int,vector<int>,cmp1>que1;//最小值优先  
    priority_queue<int,vector<int>,cmp2>que2;//最大值优先  
  
    priority_queue<int,vector<int>,greater<int> >que3;//注意“>>”会被认为错误，  
                                                      //这是右移运算符，所以这里用空格号隔开  
    priority_queue<int,vector<int>,less<int> >que4;////最大值优先  
  
    priority_queue<number1>que5;  
    priority_queue<number2>que6;  
