#include "stdio.h"
#include "stdlib.h"
#include<iostream>
#include<string>
using namespace std;

struct state //״̬���ݽṹ ����Ϊ�˹�����  ���磺(1,0,1,0) ��ʾ�ϰ�״̬�����ڣ������ڣ����ڣ��ײ���
{
	int a, b, c, d;
};
//��������״̬�;��߱���
state t[10] = { {1,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0},{1,0,1,0},{0,0,0,0},
	{0,1,0,0},{0,0,1,0},{0,0,0,1},{0,1,0,1} }, j[4] = { {1,0,0,0},{1,0,1,0},{1,0,0,1},{1,1,0,0} };
state f(state x,state y) //��������  ���磨1,1,1,1��+��1,0,1,0��=��0,1,0,1��
{
	state z;
	z.a = x.a != y.a;
	z.b = x.b != y.b;
	z.c = x.c != y.c;
	z.d = x.d != y.d;
	return z;
}
void show(state x) //���x״̬
{
	cout << '(' << x.a << ',' << x.b << ',' << x.c << ',' << x.d << ')';
}
void showall(state *a,state *b,int k)//���a��b�����е�״̬����
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
int ifstate(state x)//�ж�x״̬�Ƿ���Դ��ڲ��ҷ��ش��ڵ��±�
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
bool ifequal(state x,state y) //�ж�x��y״̬�Ƿ����
{
	if (x.a == y.a && x.b == y.b && x.c == y.c && x.d == y.d)
	{
		return true;
	}
	return false;
}
void get(state x, state y,int visit[], state *a, state *b,int k) //����x״̬��y״̬��·��
{
	state z;
	a[k] = x;
	if (ifequal(x,y))//����ɹ���״̬����
	{
		showall(a,b,k+1);	cout << "���" << endl;
		return;
	}
	for (int i = 0; i < 4; i++)//�㷨�ݹ����
		{
			if (ifstate(f(x, j[i]))&&visit[ifstate(f(x, j[i]))]==0)//����������ߺ�״̬���ڣ����Ҹ�״̬û�б�����
			{
				visit[ifstate(f(x, j[i]))] = 1;
				z = f(x, j[i]);
				b[k] = j[i];
				get(z, y,visit,a,b,k+1);
				visit[ifstate(f(x, j[i]))] = 0;//����һ��·�����Է��ʸ�״̬���ҳ����е�·��
			}
		}
	
}
int main() {
	int visit[10] = { 0 };//������ѭ�����飬��ÿ����ֻ�ܷ���һ��
	state a[10],b[10];//a�����Ǽ�¼״̬��b�����Ǽ�¼���߸ı�
	get({ 1,1,1,1 }, { 0,0,0,0 },visit,a,b,0);
	getchar();
}
