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
��� 



struct cmp1 {  
    bool operator ()(int &a, int &b){  
        return a > b;//��Сֵ����  
    }  
};  

struct cmp2 {  
    bool operator ()(int &a, int &b){  
        return a < b;//���ֵ����  
    }  
};  

struct number1 { 
    int x;  
    bool operator < (const number1 &a) const {  
        return x > a.x;//��Сֵ����  
    }  
};  

struct number2 {  
    int x;  
    bool operator < (const number2 &a) const {  
        return x < a.x;//���ֵ����  
    }  
};  

	priority_queue<int>que;//����Ĭ�����ȼ��������  
  
    priority_queue<int,vector<int>,cmp1>que1;//��Сֵ����  
    priority_queue<int,vector<int>,cmp2>que2;//���ֵ����  
  
    priority_queue<int,vector<int>,greater<int> >que3;//ע�⡰>>���ᱻ��Ϊ����  
                                                      //������������������������ÿո�Ÿ���  
    priority_queue<int,vector<int>,less<int> >que4;////���ֵ����  
  
    priority_queue<number1>que5;  
    priority_queue<number2>que6;  
