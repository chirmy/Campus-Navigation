#include"keypoint.h"


int count = 1;											//定义为全局变量
int visited[M], low[M],flag[M];
int min;


/********************************************************/
/*	函数功能：输出关节点								*/
/*	函数参数：邻接表指针g,	关节点标志数组f				*/
/*	函数返回值：无										*/
/********************************************************/
void keypout(LinkedGraph* g, int f[])
{
	int i;
	for (i = 0; i < g->n; ++i)
		if (flag[i] != 0)
		{
			printf(" %s  \t是关节点\n\n", g->adjlist[i].vertex.name); // --①
			Out[OutSize++] = i;
		}
}


/********************************************************/
/*	函数功能：从v0点出发DFS，查找并输出关节点			*/
/*	函数参数：邻接表指针g,	第count个访问的顶点v0		*/
/*	函数返回值：无										*/
/********************************************************/
void DFSArticul(LinkedGraph g, int v0)					
{
	EdgeNode* p;
	int w;
	visited[v0] = min = ++count;						// 更新visit[]和min
	for (p = g.adjlist[v0].FirstEdge; p; p = p->next)	//对v0的每个邻接点进行检查 
	{ 
		w = p->adjvex;									//w是v0的邻接点序号
		if (visited[w] == 0)							//第w个结点未访问过
		{ 
			DFSArticul(g, w);
			if (low[w] < min) min = low[w];				//深度遍历v0结点的孩子结点w的low[w]<min 
			if (low[w] >= visited[v0]&& flag[w] == 0)	//low[w]>=min&&未输出过
				flag[w] = 1;							//关节点标志
		}
		else if (visited[w] < min) {					//w已经访问过了，说明w是回边
			min = visited[w]; 
		}
	}
	low[v0] = min;										//设置v0的low值
}


/********************************************************/
/*	函数功能：查找关节点								*/
/*	函数参数：邻接表指针g								*/
/*	函数返回值：无										*/
/********************************************************/
void FindArticul(LinkedGraph g ) {
	int i, j, v;
	EdgeNode* p;
	visited[0] = 1;										//设定邻接表上0号顶点为 生成树的根
	for (i = 1; i < g.n; ++i) { visited[i] = 0; flag[i] = 0; } //初始化为0
	p = g.adjlist[0].FirstEdge;							//取 根的第一个邻接点 
	v = p->adjvex; 
	DFSArticul(g, v);									//开始DFS
	if (count < g.n) 
	{
		printf("根是关节点");							 //根是关节点，输出相应信息
		Out[OutSize++] = 0;
		flag[0] = 1;
		while (p->next) {
			p = p->next; v = p->adjvex;
			if (visited[v] == 0) DFSArticul(g, v);
		}
	}
	keypout(&g, flag);									//输出关节点
	//putpixel(g.adjlist[Out[j]].vertex.x, g.adjlist[Out[j]].vertex.y,RED);
	setlinecolor(RED);									//设置划线颜色
	setlinestyle(PS_ENDCAP_ROUND, 20);					//设置划线粗度
	for (j = 0; j < OutSize; ++j)line(g.adjlist[Out[j]].vertex.x, g.adjlist[Out[j]].vertex.y, g.adjlist[Out[j]].vertex.x, g.adjlist[Out[j]].vertex.y);//printf("->%10s", g.adjlist[Out[j]].vertex.name);//检测使用
	system("pause");
}

