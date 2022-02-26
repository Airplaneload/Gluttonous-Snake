#include "stdio.h"
#include "stdlib.h"
#include<iostream>
#include<string>
using namespace std;

struct state //状态数据结构 依次为人狗鸡米  例如：(1,0,1,0) 表示南岸状态，人在，狗不在，鸡在，米不在
{
	int a, b, c, d;
};
//定义允许状态和决策变量
state t[10] = { {1,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0},{1,0,1,0},{0,0,0,0},
	{0,1,0,0},{0,0,1,0},{0,0,0,1},{0,1,0,1} }, j[4] = { {1,0,0,0},{1,0,1,0},{1,0,0,1},{1,1,0,0} };
state f(state x,state y) //法则运算  例如（1,1,1,1）+（1,0,1,0）=（0,1,0,1）
{
	state z;
	z.a = x.a != y.a;
	z.b = x.b != y.b;
	z.c = x.c != y.c;
	z.d = x.d != y.d;
	return z;
}
void show(state x) //输出x状态
{
	cout << '(' << x.a << ',' << x.b << ',' << x.c << ',' << x.d << ')';
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
		if (x.a==t[i].a&&x.b==t[i].b&&x.c==t[i].c&&x.d==t[i].d)
		{
			return i;
		}
	}
	return 0;
}
bool ifequal(state x,state y) //判断x和y状态是否相等
{
	if (x.a == y.a && x.b == y.b && x.c == y.c && x.d == y.d)
	{
		return true;
	}
	return false;
}
void get(state x, state y,int visit[], state *a, state *b,int k) //计算x状态到y状态的路径
{
	state z;
	a[k] = x;
	if (ifequal(x,y))//输出成功的状态集合
	{
		showall(a,b,k+1);	cout << "完成" << endl;
		return;
	}
	for (int i = 0; i < 4; i++)//算法递归核心
		{
			if (ifstate(f(x, j[i]))&&visit[ifstate(f(x, j[i]))]==0)//如果做出决策后状态存在，并且该状态没有被访问
			{
				visit[ifstate(f(x, j[i]))] = 1;
				z = f(x, j[i]);
				b[k] = j[i];
				get(z, y,visit,a,b,k+1);
				visit[ifstate(f(x, j[i]))] = 0;//让另一条路径可以访问该状态，找出所有的路径
			}
		}
	
}
int main() {
	int visit[10] = { 0 };//避免死循环数组，即每个点只能访问一遍
	state a[10],b[10];//a数组是记录状态，b数组是记录决策改变
	get({ 1,1,1,1 }, { 0,0,0,0 },visit,a,b,0);
	getchar();
}
