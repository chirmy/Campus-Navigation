#include"MinTree.h"


/************************************************/
/*	�������ܣ�prime�㷨������С������			*/
/*	�����������ڽӾ���g��������tree				*/
/*	��������ֵ����								*/
/************************************************/
void prim(Mgraph* g, edge tree[M - 1])
{
	edge x;									/*�������ڱ���������*/
	int v,k,min,s,j,d;
	for (v = 1; v <= g->n - 1; ++v)			/*������ʼ��ѡ�㲢��ʼ��tree������*/
	{
		tree[v-1].begin = 0;
		tree[v-1].end = v;
		tree[v-1].length = g->edges[0][v];
	}
	for (k = 0; k < g->n - 1; ++k)			/*������ǰ����K������С���ܱ�*/
	{
		min = tree[k].length;
		s = k;
		for (j = k + 1; j < g->n - 1; ++j)
		{
			if(tree[j].length<min)
			{
				min = tree[j].length;
				s = j;						/*��С���ܱ�����̱��������*/
			}
		}
		v = tree[s].end;					/*��ѡ����Ϊv*/

		x = tree[s]; tree[s] = tree[k]; tree[k] = x;/*����С�߼���Tree��*/
		for (j = k + 1; j < g->n - 1; ++j)	/*�����¶���v�ļ��룬�������ܱߵ���Ϣ*/
		{
			if (tree[j].length > g->edges[v][tree[j].end])
			{
				tree[j].length = g->edges[v][tree[j].end];
				tree[j].begin = v;
			}
		}
	}

	printf("\nThe minimum cost spanning tree is:\n");/*�����С������*/
	for (j = 0; j < g->n - 1; ++j)
		printf("%s---%s %5d\n", g->vexs[tree[j].begin].name, g->vexs[tree[j].end].name, tree[j].length);
	printf("The root of it is %s\n", g->vexs[0].name);

}

/********************************************************/
/*	�������ܣ��Ա��������п�������						*/
/*	����������������edge;�����������±ꣻleft,right		*/
/*	��������ֵ����										*/
/********************************************************/
void quicksort(edge edges[], int left, int right)
{
	edge x;
	int i, j, flag = 1;
	if (left < right)
	{
		i = left; j = right; x = edges[i];
		while (i < j)
		{
			while (i < j && x.length < edges[j].length)j--;
			if (i < j) edges[i++] = edges[j];
			while (i < j && x.length > edges[i].length)i++;
			if (i < j) edges[j--] = edges[i];
		}
		edges[i] = x;
		quicksort(edges, left, i - 1);
		quicksort(edges, i + 1, right);
	}
}


/********************************************************/
/*	�������ܣ���ͼg�е��ڽӾ����ж�ȡ���б���Ϣ			*/
/*	����������������edges;�ڽӾ���g						*/
/*	��������ֵ����										*/
/********************************************************/
void GetEdge(Mgraph g, edge edges[])
{
	int i, j, k=0;
	for(i=0;i<g.n;++i)
		for (j = 0; j < i; ++j)
			if (g.edges[i][j] != 0 && g.edges[i][j] < FINITY)
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k++].length = g.edges[i][j];
			}
}


/********************************************************/
/*	�������ܣ�kruskal�����С�������㷨					*/
/*	�����������ڽӾ���g									*/
/*	��������ֵ����										*/
/********************************************************/
void kruskal(Mgraph g)
{
	int i, j, k = 0, ltfl;				/*ltfl��ͨ����*/
	int ver_num[M];						/*������*/
	edge edges[M * M];					/*���ڴ��ͼ�����б�*/
	edge tree[M - 1];					/*���ڴ����С�������ı���Ϣ*/
	GetEdge(g, edges);					/*��ȡ���б���Ϣ*/
	quicksort(edges,0,g.e-1);			/*�����б߽��п���*/	
	for (i = 0; i < g.n; ++i)			/*Ϊÿ���������ñ��*/
		ver_num[i] = i;
	for (i = 0; i < g.n - 1; ++i)
	{
		while (ver_num[edges[k].begin] == ver_num[edges[k].end])	/*ѡȨֵ��С�Ҳ���ͨ�ı�*/
			k++;
		tree[i] = edges[k];				/*����k�����������*/
		ltfl = ver_num[edges[k].end];	
		for (j = 0; j < g.n; ++j)
			if (ver_num[j] == ltfl)
				ver_num[j] = ver_num[edges[k].begin];			/*�ϲ���ͨ����*/
		k++;
	}

	printf("\nThe minimum cost spanning tree is:\n");/*�����С������*/
	for (j = 0; j <g.n-1; ++j)
		printf("%s---%s %5d\n",g.vexs[tree[j].begin].name,g.vexs[tree[j].end].name,tree[j].length);

}