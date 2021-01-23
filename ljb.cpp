#include"ljb.h"

/********************************************************/
/*	函数功能：邻接矩阵转换为邻接表						*/
/*	函数参数：邻接表指针g，邻接矩阵G					*/
/*	函数返回值：无										*/
/********************************************************/
void ljb_from_ljjz(LinkedGraph* g, Mgraph G)
{
	int i, j, k;
	EdgeNode* s;
	g->n = G.n;											//结点个数
	g->e = G.e;											//边条数
	for (i = 0; i < g->n; ++i)							//结点转换
	{
		g->adjlist[i].vertex = G.vexs[i];
		g->adjlist[i].FirstEdge = NULL;					//边表置为空表
	}

	for (i = 0; i < g->n; ++i)							//边转换
	{
		for (j = 0; j < g->n; ++j)
		{
			if (j != i && G.edges[i][j] != 0 && G.edges[i][j] != FINITY)//有边且权重不为0
			{
				s = (EdgeNode*)malloc(sizeof(EdgeNode));
				s->adjvex = j;
				s->next = g->adjlist[i].FirstEdge;
				g->adjlist[i].FirstEdge = s;
			}
		}
	}

}
