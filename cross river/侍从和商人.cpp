#include "stdio.h"
#include "stdlib.h"
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

struct state //״̬���ݽṹ ����Ϊ��������  ���磨3��3�� 3�����ˣ�3�����
{
	int a, b;
};
//��������״̬�;��߱���
state t[10] = { {3,3},{3,2},{3,1},{3,0},{2,2},{1,1},
	{0,1},{0,2},{0,3},{0,0} }, j[5] = { {1,0},{0,1},{2,0},{1,1},{0,2} };
state f(state x,state y,int k) //��������  
{
	state z;
	k = k + 1;
	z.a = x.a + pow(-1, k) * y.a;
	z.b = x.b + pow(-1, k) * y.b;
	return z;
}
void show(state x) //���x״̬
{
	cout << '(' << x.a << ',' << x.b<< ')';
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
		if (x.a==t[i].a&&x.b==t[i].b)
		{
			return i;
		}
	}
	return 0;
}
bool ifequal(state x,state y) //�ж�x��y״̬�Ƿ����
{
	if (x.a == y.a && x.b == y.b)
	{
		return true;
	}
	return false;
}
void get(state x, state y, state *a, state *b,int k,int m) //����x״̬��y״̬��·��
{
	state z;
	a[k] = x;
	if (ifequal(x,y))//����ɹ���״̬����
	{
		showall(a,b,k+1);	cout << "���" << endl;
		return;
	}
	if (k <m)
	{
		for (int i = 0; i < 5; i++)//�㷨�ݹ����
		{
			if (ifstate(f(x, j[i], k)))//����������ߺ�״̬����
			{
				z = f(x, j[i], k);
				b[k] = j[i];
				get(z, y, a, b, k + 1, m);
			
			}
		}
	}
}
int main() {
	state a[10],b[10];//a�����Ǽ�¼״̬��b�����Ǽ�¼���߸ı�
	int m;//���ڼ�������������һ������,�ɺ�m�Σ������Լ����������õ�ÿ�εĶɺӷ���
	m = 11;
	get({ 3,3 }, { 0,0 }, a, b, 0, m);
	getchar();
}
