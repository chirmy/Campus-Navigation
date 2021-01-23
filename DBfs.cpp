#include"DBfs.h"


/********************************************************/
/*	�������ܣ��ļ���ȡ����ͼ���ڽӱ�					*/
/*	�����������ڽӱ�ָ��g,�ļ�����������ͼ��־			*/
/*	��������ֵ����										*/
/********************************************************/
void creat(LinkedGraph* g, char* filename, int c)
{
	int i, j, k;
	EdgeNode* s;
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp)
	{
		fscanf(fp, "%d%d", &g->n, &g->e);				/*���붥���������*/
		for (i = 0; i < g->n; ++i)
		{
			fscanf(fp, "%ls", &g->adjlist[i].vertex);	/*��������Ϣ*/
			g->adjlist[i].FirstEdge = NULL;				/*�߱���Ϊ�ձ�*/
		}
		for (k = 0; k < g->e; ++k)						/*ѭ��e�Σ������߱�*/
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
		g->n = 0;/*�ļ���ʧ��*/
}


/********************************************************/
/*	�������ܣ��Ӷ���i��ʼ������ȱ���ͼ����ͨ����		*/
/*	�����������ڽӱ�g�������ڵ����i					*/
/*	��������ֵ����										*/
/********************************************************/
void deep_dfs(LinkedGraph g, int i)
{
	EdgeNode* p;
	printf("visit vertex : %c\n", g.adjlist[i].vertex);	/*���ʽڵ�i*/
	visit[i] = 1;										/*��ǳ��ѱ�����*/
	p = g.adjlist[i].FirstEdge;
	while (p)											/*��p���ڽӵ�������������������*/
	{
		if (!visit[p->adjvex])							/*����˽��δ�����ʹ�*/
			deep_dfs(g, p->adjvex);
		p = p->next;
	}
}


/********************************************************/
/*	�������ܣ�������ȱ���ͼ							*/
/*	�����������ڽӾ���g									*/
/*	��������ֵ����										*/
/********************************************************/
void deep_DFsTraverse(LinkedGraph g)
{
	int i;
	for (i = 0; i < g.n; ++i)							/*��ʼ����־����*/
		visit[i] = 0;
	for (i = 0; i < g.n; ++i)
		if(!visit[i])deep_dfs(g, i);					/*Viδ�����ʹ�����½����������*/
}


/********************************************************/
/*	�������ܣ��Ӷ���i��ʼ������ȱ���ͼ����ͨ����		*/
/*	�����������ڽӱ�g�������ڵ����i					*/
/*	��������ֵ����										*/
/********************************************************/
void wide_bfs(LinkedGraph g, int i)
{
	int j;
	EdgeNode* p;
	
	int queen[M], front, rear;							/*ʹ�ö���FIFO*/
	front = rear = 0;

	printf("%c ", g.adjlist[i].vertex);
	visit[i] = 1;										/*��־�ѱ�����*/
	queen[rear++] = i;									/*�����*/

	while (rear > front)								/*������������ڽӱ�*/
	{
		j = queen[front++];
		p = g.adjlist[j].FirstEdge;
		while (p)
		{
			if (visit[p->adjvex] == 0)					/*Viδ������*/
			{
				printf("%c ", g.adjlist[p->adjvex].vertex);
				queen[rear++] = p->adjvex;				/*ѹ�����*/
				visit[p->adjvex] = 1;
			}
			p = p->next;
		}
	}
}


/********************************************************/
/*	�������ܣ�������ȱ���								*/
/*	�����������ڽӱ�g									*/
/*	��������ֵ��������ͨ�����ĸ���						*/
/********************************************************/
int wide_BFsTraverse(LinkedGraph g)
{
	int i, count;
	for (i = 0; i < g.n; ++i)							/*��ʼ����־����*/
		visit[i] = 0;
	for (i = 0; i < g.n; ++i)
	{
		if (visit[i] == 0)								/*Viδ�����ʹ�*/
		{
			printf("\n");
			count++;									/*��������1*/
			wide_bfs(g, i);
		}	
	}
	return count;
}


/********************************************************/
/*	�������ܣ���������									*/
/*	�����������ڽӱ�g									*/
/*	��������ֵ���������������������					*/
/********************************************************/
int TopSort(LinkedGraph g)
{
	int i,k = 0,v;
	int quene[M],front=0,rear=0;
	int flag[M];
	for (i = 0; i < g.n; ++i)							/*���ʱ�ǳ�ʼ��*/
		flag[i] = 0;
	EdgeNode* p;
	for (i = 0; i < g.n; ++i)							/*���Ϊ��Ľ��ѹ�����*/
		if (g.adjlist[i].id == 0 && flag[i] == 0) { quene[rear++] = i; flag[i] = 1; }
	printf("\nAOV�������������ǣ�\n");
	while (rear > front)
	{
		v = quene[front++];
		printf("%c ", g.adjlist[v].vertex);
		++k;											/*��ʱ����һ*/
		p = g.adjlist[v].FirstEdge;
		while (p)										/*��������v�ڽӵĶ�������-1*/
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
	return k;											/*�����������������������*/
}


/************************************************************/
/*	�������ܣ����ڽӾ���Ӷ���i��ʼ������ȱ���ͼ����ͨ����	*/
/*	�����������ڽӾ���G,�������i							*/
/*	��������ֵ����											*/
/************************************************************/
void ljjz_DFS(Mgraph G, int i)
{
	int j;
	printf("visit vertex : %s\n",G.vexs[i].name);			/*���ʽڵ�i*/
	visit[i] = 1;											/*��ǳ��ѱ�����*/
	for (j = 0; j < G.n; ++j)
	{
		if (!visit[j]&&G.edges[i][j]!=FINITY)
			ljjz_DFS(G, j);
	}
}


/********************************************************/
/*	�������ܣ����ڽӾ���������ȱ���ͼ					*/
/*	�����������ڽӾ���G									*/
/*	��������ֵ����										*/
/********************************************************/
void ljjz_DFsTraverse(Mgraph G)
{
	int i;
	for (i = 0; i < G.n; ++i)							/*��ʼ����־����*/
		visit[i] = 0;
	for (i = 0; i < G.n; ++i)
		if (!visit[i])ljjz_DFS(G, i);					/*Viδ�����ʹ�����½����������*/
}