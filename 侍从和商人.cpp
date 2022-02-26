#include "stdio.h"
#include "stdlib.h"
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

struct state //状态数据结构 依次为商人人数  例如（3，3） 3哥商人，3个随从
{
	int a, b;
};
//定义允许状态和决策变量
state t[10] = { {3,3},{3,2},{3,1},{3,0},{2,2},{1,1},
	{0,1},{0,2},{0,3},{0,0} }, j[5] = { {1,0},{0,1},{2,0},{1,1},{0,2} };
state f(state x,state y,int k) //法则运算  
{
	state z;
	k = k + 1;
	z.a = x.a + pow(-1, k) * y.a;
	z.b = x.b + pow(-1, k) * y.b;
	return z;
}
void show(state x) //输出x状态
{
	cout << '(' << x.a << ',' << x.b<< ')';
}
void showall(state *a,state *b,int k)//输出a，b数组中的状态集合
{
	for (int i = 0; i < k; i++)
	{
		show(a[i]);
		if (i != k - 1)
		{
			cout << "--["; show(b[i]); cout << "]->";
		}
	}
}
int ifstate(state x)//判断x状态是否可以存在并且返回存在的下标
{
	for (int i = 1; i < 10; i++)
	{
		if (x.a==t[i].a&&x.b==t[i].b)
		{
			return i;
		}
	}
	return 0;
}
bool ifequal(state x,state y) //判断x和y状态是否相等
{
	if (x.a == y.a && x.b == y.b)
	{
		return true;
	}
	return false;
}
void get(state x, state y, state *a, state *b,int k,int m) //计算x状态到y状态的路径
{
	state z;
	a[k] = x;
	if (ifequal(x,y))//输出成功的状态集合
	{
		showall(a,b,k+1);	cout << "完成" << endl;
		return;
	}
	if (k <m)
	{
		for (int i = 0; i < 5; i++)//算法递归核心
		{
			if (ifstate(f(x, j[i], k)))//如果做出决策后状态存在
			{
				z = f(x, j[i], k);
				b[k] = j[i];
				get(z, y, a, b, k + 1, m);
			
			}
		}
	}
}
int main() {
	state a[10],b[10];//a数组是记录状态，b数组是记录决策改变
	int m;//用于计数步数，输入一个步数,渡河m次，可以自己调次数，得到每次的渡河方法
	m = 11;
	get({ 3,3 }, { 0,0 }, a, b, 0, m);
	getchar();
}
