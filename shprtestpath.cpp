#include"shortestpath.h"

extern int Out[M];
extern int OutSize;
/****************************************************/
/*	函数功能：Floyed方法求所有顶点对之间最短路径	*/
/*	函数参数：邻接矩阵g，距离向量d,路径向量p		*/
/*	递推公式：										*/
/*	A-1[i][j]=g.edges[i][j]							*/
/*	Ak+1[i][j]=min{Ak[i][j],Ak[i][k+1]+Ak[k+1][j]}	*/
/*	函数返回值：无									*/
/****************************************************/
void floyd(Mgraph g, dist d, path p)
{
	int i, j, k;
	for (i = 0; i < g.n; ++i)
		for (j = 0; j < g.n; ++j)
		{
			d[i][j] = g.edges[i][j];				//初始化d
			if (i!=j&& d[i][j] < FINITY)			//初始化p
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
/*	函数功能：Floyed方法最短路径单景点对输出				*/
/*	函数参数：邻接矩阵g，路径向量p,两地标序号i,j			*/
/*	算法思想：递归											*/
/*	函数返回值：无											*/
/************************************************************/
void floydoutput(Mgraph g, path p, int i, int j)
{
	if (p[i][j] == i)return;								//检测到两端结点返回
	floydoutput(g, p, i, p[i][j]);							//前半部
	printf("->%10s", g.vexs[p[i][j]].name);					//输出结点名称	
	Out[OutSize++] = p[i][j];								//将各输出结点压入Out数组
	floydoutput(g, p, p[i][j],j);							//后半部
}

/************************************************************/
/*	函数功能：Floyed最短路径接口函数						*/
/*	函数参数：邻接矩阵g，距离向量d,路径向量p,两地标序号v1,v2*/
/*	函数返回值：无											*/
/************************************************************/
void floydprint(Mgraph g, dist d, path p,int v1,int v2)
{
	if (v1 == v2)return;
	Out[OutSize++] = v1;
	printf(" %12s\t--- %12s\t最短路径长度为 %3d: \t%s", g.vexs[v1].name, g.vexs[v2].name, d[v1][v2], g.vexs[v1].name);
	floydoutput(g, p, v1, v2);
	printf("->%s\n\n\n", g.vexs[v2].name);
	Out[OutSize++] = v2;
}
