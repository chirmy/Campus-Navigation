#include"MinTree.h"


/************************************************/
/*	函数功能：prime算法构造最小生成树			*/
/*	函数参数：邻接矩阵g，边向量tree				*/
/*	函数返回值：无								*/
/************************************************/
void prim(Mgraph* g, edge tree[M - 1])
{
	edge x;									/*辅助后期边向量交换*/
	int v,k,min,s,j,d;
	for (v = 1; v <= g->n - 1; ++v)			/*建立初始入选点并初始化tree边向量*/
	{
		tree[v-1].begin = 0;
		tree[v-1].end = v;
		tree[v-1].length = g->edges[0][v];
	}
	for (k = 0; k < g->n - 1; ++k)			/*依次求当前（第K条）最小两栖边*/
	{
		min = tree[k].length;
		s = k;
		for (j = k + 1; j < g->n - 1; ++j)
		{
			if(tree[j].length<min)
			{
				min = tree[j].length;
				s = j;						/*最小两栖边外最短边向量序号*/
			}
		}
		v = tree[s].end;					/*入选顶点为v*/

		x = tree[s]; tree[s] = tree[k]; tree[k] = x;/*将最小边加入Tree中*/
		for (j = k + 1; j < g->n - 1; ++j)	/*由于新顶点v的加入，更新两栖边的信息*/
		{
			if (tree[j].length > g->edges[v][tree[j].end])
			{
				tree[j].length = g->edges[v][tree[j].end];
				tree[j].begin = v;
			}
		}
	}

	printf("\nThe minimum cost spanning tree is:\n");/*输出最小生成树*/
	for (j = 0; j < g->n - 1; ++j)
		printf("%s---%s %5d\n", g->vexs[tree[j].begin].name, g->vexs[tree[j].end].name, tree[j].length);
	printf("The root of it is %s\n", g->vexs[0].name);

}

/********************************************************/
/*	函数功能：对边向量进行快速排序						*/
/*	函数参数：边向量edge;边向量左右下标；left,right		*/
/*	函数返回值：无										*/
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
/*	函数功能：从图g中的邻接矩阵中读取所有边信息			*/
/*	函数参数：边向量edges;邻接矩阵g						*/
/*	函数返回值：无										*/
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
/*	函数功能：kruskal求解最小生成树算法					*/
/*	函数参数：邻接矩阵g									*/
/*	函数返回值：无										*/
/********************************************************/
void kruskal(Mgraph g)
{
	int i, j, k = 0, ltfl;				/*ltfl连通分量*/
	int ver_num[M];						/*顶点编号*/
	edge edges[M * M];					/*用于存放图的所有边*/
	edge tree[M - 1];					/*用于存放最小生成树的边信息*/
	GetEdge(g, edges);					/*读取所有边信息*/
	quicksort(edges,0,g.e-1);			/*对所有边进行快排*/	
	for (i = 0; i < g.n; ++i)			/*为每个顶点设置编号*/
		ver_num[i] = i;
	for (i = 0; i < g.n - 1; ++i)
	{
		while (ver_num[edges[k].begin] == ver_num[edges[k].end])	/*选权值最小且不连通的边*/
			k++;
		tree[i] = edges[k];				/*将边k存进生成树中*/
		ltfl = ver_num[edges[k].end];	
		for (j = 0; j < g.n; ++j)
			if (ver_num[j] == ltfl)
				ver_num[j] = ver_num[edges[k].begin];			/*合并连通分量*/
		k++;
	}

	printf("\nThe minimum cost spanning tree is:\n");/*输出最小生成树*/
	for (j = 0; j <g.n-1; ++j)
		printf("%s---%s %5d\n",g.vexs[tree[j].begin].name,g.vexs[tree[j].end].name,tree[j].length);

}