#include"DBfs.h"


/********************************************************/
/*	函数功能：文件读取建立图的邻接表					*/
/*	函数参数：邻接表指针g,文件名，有无向图标志			*/
/*	函数返回值：无										*/
/********************************************************/
void creat(LinkedGraph* g, char* filename, int c)
{
	int i, j, k;
	EdgeNode* s;
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp)
	{
		fscanf(fp, "%d%d", &g->n, &g->e);				/*读入顶点数与边数*/
		for (i = 0; i < g->n; ++i)
		{
			fscanf(fp, "%ls", &g->adjlist[i].vertex);	/*读入结点信息*/
			g->adjlist[i].FirstEdge = NULL;				/*边表置为空表*/
		}
		for (k = 0; k < g->e; ++k)						/*循环e次，建立边表*/
		{
			fscanf(fp, "%d%d", &i, &j);
			s = (EdgeNode*)malloc(sizeof(EdgeNode));
			s->adjvex = j;
			s->next = g->adjlist[i].FirstEdge;
			g->adjlist[i].FirstEdge = s;
			if (c == 0)
			{
				s = (EdgeNode*)malloc(sizeof(EdgeNode));
				s->adjvex = i;
				s->next = g->adjlist[j].FirstEdge;
				g->adjlist[j].FirstEdge = s;
			}
		}
		fclose(fp);
	}
	else
		g->n = 0;/*文件打开失败*/
}


/********************************************************/
/*	函数功能：从顶点i开始深度优先遍历图的连通分量		*/
/*	函数参数：邻接表g，遍历节点起点i					*/
/*	函数返回值：无										*/
/********************************************************/
void deep_dfs(LinkedGraph g, int i)
{
	EdgeNode* p;
	printf("visit vertex : %c\n", g.adjlist[i].vertex);	/*访问节点i*/
	visit[i] = 1;										/*标记成已被访问*/
	p = g.adjlist[i].FirstEdge;
	while (p)											/*从p的邻接点出发进行深度优先搜索*/
	{
		if (!visit[p->adjvex])							/*如果此结点未被访问过*/
			deep_dfs(g, p->adjvex);
		p = p->next;
	}
}


/********************************************************/
/*	函数功能：深度优先遍历图							*/
/*	函数参数：邻接矩阵g									*/
/*	函数返回值：无										*/
/********************************************************/
void deep_DFsTraverse(LinkedGraph g)
{
	int i;
	for (i = 0; i < g.n; ++i)							/*初始化标志数组*/
		visit[i] = 0;
	for (i = 0; i < g.n; ++i)
		if(!visit[i])deep_dfs(g, i);					/*Vi未被访问过情况下进行深度搜索*/
}


/********************************************************/
/*	函数功能：从顶点i开始广度优先遍历图的连通分量		*/
/*	函数参数：邻接表g，遍历节点起点i					*/
/*	函数返回值：无										*/
/********************************************************/
void wide_bfs(LinkedGraph g, int i)
{
	int j;
	EdgeNode* p;
	
	int queen[M], front, rear;							/*使用队列FIFO*/
	front = rear = 0;

	printf("%c ", g.adjlist[i].vertex);
	visit[i] = 1;										/*标志已被访问*/
	queen[rear++] = i;									/*入队列*/

	while (rear > front)								/*广度优先搜索邻接表*/
	{
		j = queen[front++];
		p = g.adjlist[j].FirstEdge;
		while (p)
		{
			if (visit[p->adjvex] == 0)					/*Vi未被访问*/
			{
				printf("%c ", g.adjlist[p->adjvex].vertex);
				queen[rear++] = p->adjvex;				/*压入队列*/
				visit[p->adjvex] = 1;
			}
			p = p->next;
		}
	}
}


/********************************************************/
/*	函数功能：广度优先遍历								*/
/*	函数参数：邻接表g									*/
/*	函数返回值：返回连通分量的个数						*/
/********************************************************/
int wide_BFsTraverse(LinkedGraph g)
{
	int i, count;
	for (i = 0; i < g.n; ++i)							/*初始化标志数组*/
		visit[i] = 0;
	for (i = 0; i < g.n; ++i)
	{
		if (visit[i] == 0)								/*Vi未被访问过*/
		{
			printf("\n");
			count++;									/*计数器加1*/
			wide_bfs(g, i);
		}	
	}
	return count;
}


/********************************************************/
/*	函数功能：拓扑排序									*/
/*	函数参数：邻接表g									*/
/*	函数返回值：拓扑排序的输出顶点个数					*/
/********************************************************/
int TopSort(LinkedGraph g)
{
	int i,k = 0,v;
	int quene[M],front=0,rear=0;
	int flag[M];
	for (i = 0; i < g.n; ++i)							/*访问标记初始化*/
		flag[i] = 0;
	EdgeNode* p;
	for (i = 0; i < g.n; ++i)							/*入度为零的结点压入队列*/
		if (g.adjlist[i].id == 0 && flag[i] == 0) { quene[rear++] = i; flag[i] = 1; }
	printf("\nAOV网的拓扑序列是：\n");
	while (rear > front)
	{
		v = quene[front++];
		printf("%c ", g.adjlist[v].vertex);
		++k;											/*计时器加一*/
		p = g.adjlist[v].FirstEdge;
		while (p)										/*将所有与v邻接的顶点的入度-1*/
		{
			i=p->adjvex;
			if (--(g.adjlist[i].id) == 0 && flag[i] == 0)
			{
				quene[front++] = i;
				flag[i] = 1;
			}
			p = p->next;
		}
	}
	return k;											/*返回拓扑排序的输出顶点个数*/
}


/************************************************************/
/*	函数功能：用邻接矩阵从顶点i开始深度优先遍历图的连通分量	*/
/*	函数参数：邻接矩阵G,遍历起点i							*/
/*	函数返回值：无											*/
/************************************************************/
void ljjz_DFS(Mgraph G, int i)
{
	int j;
	printf("visit vertex : %s\n",G.vexs[i].name);			/*访问节点i*/
	visit[i] = 1;											/*标记成已被访问*/
	for (j = 0; j < G.n; ++j)
	{
		if (!visit[j]&&G.edges[i][j]!=FINITY)
			ljjz_DFS(G, j);
	}
}


/********************************************************/
/*	函数功能：用邻接矩阵深度优先遍历图					*/
/*	函数参数：邻接矩阵G									*/
/*	函数返回值：无										*/
/********************************************************/
void ljjz_DFsTraverse(Mgraph G)
{
	int i;
	for (i = 0; i < G.n; ++i)							/*初始化标志数组*/
		visit[i] = 0;
	for (i = 0; i < G.n; ++i)
		if (!visit[i])ljjz_DFS(G, i);					/*Vi未被访问过情况下进行深度搜索*/
}