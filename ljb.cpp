#include"ljb.h"

/********************************************************/
/*	�������ܣ��ڽӾ���ת��Ϊ�ڽӱ�						*/
/*	�����������ڽӱ�ָ��g���ڽӾ���G					*/
/*	��������ֵ����										*/
/********************************************************/
void ljb_from_ljjz(LinkedGraph* g, Mgraph G)
{
	int i, j, k;
	EdgeNode* s;
	g->n = G.n;											//������
	g->e = G.e;											//������
	for (i = 0; i < g->n; ++i)							//���ת��
	{
		g->adjlist[i].vertex = G.vexs[i];
		g->adjlist[i].FirstEdge = NULL;					//�߱���Ϊ�ձ�
	}

	for (i = 0; i < g->n; ++i)							//��ת��
	{
		for (j = 0; j < g->n; ++j)
		{
			if (j != i && G.edges[i][j] != 0 && G.edges[i][j] != FINITY)//�б���Ȩ�ز�Ϊ0
			{
				s = (EdgeNode*)malloc(sizeof(EdgeNode));
				s->adjvex = j;
				s->next = g->adjlist[i].FirstEdge;
				g->adjlist[i].FirstEdge = s;
			}
		}
	}

}
