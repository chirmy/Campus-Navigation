#include"shortestpath.h"

extern int Out[M];
extern int OutSize;
/****************************************************/
/*	�������ܣ�Floyed���������ж����֮�����·��	*/
/*	�����������ڽӾ���g����������d,·������p		*/
/*	���ƹ�ʽ��										*/
/*	A-1[i][j]=g.edges[i][j]							*/
/*	Ak+1[i][j]=min{Ak[i][j],Ak[i][k+1]+Ak[k+1][j]}	*/
/*	��������ֵ����									*/
/****************************************************/
void floyd(Mgraph g, dist d, path p)
{
	int i, j, k;
	for (i = 0; i < g.n; ++i)
		for (j = 0; j < g.n; ++j)
		{
			d[i][j] = g.edges[i][j];				//��ʼ��d
			if (i!=j&& d[i][j] < FINITY)			//��ʼ��p
				p[i][j] = i;
			else
				p[i][j] = -1;
		}
	for (k = 0; k < g.n; ++k)
		for (i = 0; i < g.n; ++i)
			for (j = 0; j < g.n; ++j)
				if (d[i][j] > d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = k;
				}
}

/************************************************************/
/*	�������ܣ�Floyed�������·������������				*/
/*	�����������ڽӾ���g��·������p,���ر����i,j			*/
/*	�㷨˼�룺�ݹ�											*/
/*	��������ֵ����											*/
/************************************************************/
void floydoutput(Mgraph g, path p, int i, int j)
{
	if (p[i][j] == i)return;								//��⵽���˽�㷵��
	floydoutput(g, p, i, p[i][j]);							//ǰ�벿
	printf("->%10s", g.vexs[p[i][j]].name);					//����������	
	Out[OutSize++] = p[i][j];								//����������ѹ��Out����
	floydoutput(g, p, p[i][j],j);							//��벿
}

/************************************************************/
/*	�������ܣ�Floyed���·���ӿں���						*/
/*	�����������ڽӾ���g����������d,·������p,���ر����v1,v2*/
/*	��������ֵ����											*/
/************************************************************/
void floydprint(Mgraph g, dist d, path p,int v1,int v2)
{
	if (v1 == v2)return;
	Out[OutSize++] = v1;
	printf(" %12s\t--- %12s\t���·������Ϊ %3d: \t%s", g.vexs[v1].name, g.vexs[v2].name, d[v1][v2], g.vexs[v1].name);
	floydoutput(g, p, v1, v2);
	printf("->%s\n\n\n", g.vexs[v2].name);
	Out[OutSize++] = v2;
}
