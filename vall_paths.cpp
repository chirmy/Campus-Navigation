#include"vall_paths.h"


int flagg[M],pre, plength,kinds_num=0 ;					//��־����flagg��·������plength


/********************************************************/
/*	�������ܣ�����������·��							*/
/*	�����������ڽӾ���G,���pos,�յ�end,ջָ��*s		*/
/*	��������ֵ����										*/
/********************************************************/
void allpahts(Mgraph G, int pos, int end, sqstack* s)
{
	int i;
	if (pos == end)										//�����յ�
	{
		settextcolor(BLACK);
		settextstyle(23, 0, _T("����"));
		char text[20];
		sprintf_s(text, sizeof(text), "��%d��·������:%d��", kinds_num+1, plength);
		outtextxy(1110, 440, text);

		printf("��%d��·�����ȣ�%d\t",kinds_num,plength);//�����·������
		for (i = 0; i < s->top; ++i)					//�����·��
		{
			printf("%10s-->", G.vexs[s->stack[i]].name);
			Out[OutSize++] = s->stack[i];
		}
		printf("%10s\n\n", G.vexs[end].name);			//�����·�ߵ��յ�
		Out[OutSize++] = end;
		kinds_num++;
		makeline(G);									//����
		IMAGE map;										//��ʼ��ͼ�ν����С
		loadimage(&map, _T("�ر��ͼ.jpg"), 1080, 760);	//�����ͼ
		putimage(0, 0, &map);							//��ʾ��ͼ
		clearrectangle(1110, 430, 1400, 460);
		return;
	}
	flagg[pos] = 1;										//���Ϊ�ѷ���
	pre = pos;											//��¼��·��pos���ǰһ�����pre
	push(s, pos);										//��pos����ջ
	for (i = 0; i < G.n; ++i)							//����pos����ߵ�����·��
		if (!flagg[i] && G.edges[pos][i] != 0 && G.edges[pos][i] != FINITY)//���pos��i��֮�����·
		{
			plength = plength + G.edges[pos][i];		//·�����ȼ���pos��i֮��ľ���
			allpahts(G, i, end, s);
			plength = plength - G.edges[pos][i];		//·�����ȼ�ȥpos��i֮��ľ���
		}
	flagg[pos] = 0;										//ɾ�����
	s->top--;											//ջ���޳�
}


/********************************************************/
/*	�������ܣ��������������·��						*/
/*	�����������ڽӾ���G,���start,�յ�end				*/
/*	��������ֵ����										*/
/********************************************************/
void allpathsout(Mgraph G, int start, int end)
{
	int i,pos = start;
	for (i = 0; i < G.n; ++i)flagg[i] = 0;				//��ʼ����־����flagg
	sqstack* s;
	s = (sqstack*)malloc(sizeof(sqstack));				//����ջ�ڴ�
	initstack(s);										//��ʼ��ջ
	pre = start;
	plength =0;
	printf("%10s--->%10s  ����·����\n\n", G.vexs[start].name, G.vexs[end].name);
	allpahts(G, pos, end, s);							//����allpahts����

	/*�������*/
	settextcolor(BLACK);
	settextstyle(23, 0, _T("����"));
	char text[20]="" ;
	sprintf_s(text, sizeof(text), " ���� %d ��·��", kinds_num);
	outtextxy(1110, 440, text);
	kinds_num = 0;
	system("pause");
}