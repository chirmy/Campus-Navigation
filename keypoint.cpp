#include"keypoint.h"


int count = 1;											//����Ϊȫ�ֱ���
int visited[M], low[M],flag[M];
int min;


/********************************************************/
/*	�������ܣ�����ؽڵ�								*/
/*	�����������ڽӱ�ָ��g,	�ؽڵ��־����f				*/
/*	��������ֵ����										*/
/********************************************************/
void keypout(LinkedGraph* g, int f[])
{
	int i;
	for (i = 0; i < g->n; ++i)
		if (flag[i] != 0)
		{
			printf(" %s  \t�ǹؽڵ�\n\n", g->adjlist[i].vertex.name); // --��
			Out[OutSize++] = i;
		}
}


/********************************************************/
/*	�������ܣ���v0�����DFS�����Ҳ�����ؽڵ�			*/
/*	�����������ڽӱ�ָ��g,	��count�����ʵĶ���v0		*/
/*	��������ֵ����										*/
/********************************************************/
void DFSArticul(LinkedGraph g, int v0)					
{
	EdgeNode* p;
	int w;
	visited[v0] = min = ++count;						// ����visit[]��min
	for (p = g.adjlist[v0].FirstEdge; p; p = p->next)	//��v0��ÿ���ڽӵ���м�� 
	{ 
		w = p->adjvex;									//w��v0���ڽӵ����
		if (visited[w] == 0)							//��w�����δ���ʹ�
		{ 
			DFSArticul(g, w);
			if (low[w] < min) min = low[w];				//��ȱ���v0���ĺ��ӽ��w��low[w]<min 
			if (low[w] >= visited[v0]&& flag[w] == 0)	//low[w]>=min&&δ�����
				flag[w] = 1;							//�ؽڵ��־
		}
		else if (visited[w] < min) {					//w�Ѿ����ʹ��ˣ�˵��w�ǻر�
			min = visited[w]; 
		}
	}
	low[v0] = min;										//����v0��lowֵ
}


/********************************************************/
/*	�������ܣ����ҹؽڵ�								*/
/*	�����������ڽӱ�ָ��g								*/
/*	��������ֵ����										*/
/********************************************************/
void FindArticul(LinkedGraph g ) {
	int i, j, v;
	EdgeNode* p;
	visited[0] = 1;										//�趨�ڽӱ���0�Ŷ���Ϊ �������ĸ�
	for (i = 1; i < g.n; ++i) { visited[i] = 0; flag[i] = 0; } //��ʼ��Ϊ0
	p = g.adjlist[0].FirstEdge;							//ȡ ���ĵ�һ���ڽӵ� 
	v = p->adjvex; 
	DFSArticul(g, v);									//��ʼDFS
	if (count < g.n) 
	{
		printf("���ǹؽڵ�");							 //���ǹؽڵ㣬�����Ӧ��Ϣ
		Out[OutSize++] = 0;
		flag[0] = 1;
		while (p->next) {
			p = p->next; v = p->adjvex;
			if (visited[v] == 0) DFSArticul(g, v);
		}
	}
	keypout(&g, flag);									//����ؽڵ�
	//putpixel(g.adjlist[Out[j]].vertex.x, g.adjlist[Out[j]].vertex.y,RED);
	setlinecolor(RED);									//���û�����ɫ
	setlinestyle(PS_ENDCAP_ROUND, 20);					//���û��ߴֶ�
	for (j = 0; j < OutSize; ++j)line(g.adjlist[Out[j]].vertex.x, g.adjlist[Out[j]].vertex.y, g.adjlist[Out[j]].vertex.x, g.adjlist[Out[j]].vertex.y);//printf("->%10s", g.adjlist[Out[j]].vertex.name);//���ʹ��
	system("pause");
}

