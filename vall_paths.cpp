#include"vall_paths.h"


int flagg[M],pre, plength,kinds_num=0 ;					//标志数组flagg、路径长度plength


/********************************************************/
/*	函数功能：两结点间所有路径							*/
/*	函数参数：邻接矩阵G,起点pos,终点end,栈指针*s		*/
/*	函数返回值：无										*/
/********************************************************/
void allpahts(Mgraph G, int pos, int end, sqstack* s)
{
	int i;
	if (pos == end)										//到达终点
	{
		settextcolor(BLACK);
		settextstyle(23, 0, _T("黑体"));
		char text[20];
		sprintf_s(text, sizeof(text), "第%d条路径长度:%d米", kinds_num+1, plength);
		outtextxy(1110, 440, text);

		printf("第%d条路径长度：%d\t",kinds_num,plength);//输出此路径长度
		for (i = 0; i < s->top; ++i)					//输出此路线
		{
			printf("%10s-->", G.vexs[s->stack[i]].name);
			Out[OutSize++] = s->stack[i];
		}
		printf("%10s\n\n", G.vexs[end].name);			//输出此路线的终点
		Out[OutSize++] = end;
		kinds_num++;
		makeline(G);									//划线
		IMAGE map;										//初始化图形界面大小
		loadimage(&map, _T("地标地图.jpg"), 1080, 760);	//载入地图
		putimage(0, 0, &map);							//显示地图
		clearrectangle(1110, 430, 1400, 460);
		return;
	}
	flagg[pos] = 1;										//标记为已访问
	pre = pos;											//记录此路径pos点的前一个结点pre
	push(s, pos);										//此pos点入栈
	for (i = 0; i < G.n; ++i)							//遍历pos点可走的所有路径
		if (!flagg[i] && G.edges[pos][i] != 0 && G.edges[pos][i] != FINITY)//如果pos和i点之间存在路
		{
			plength = plength + G.edges[pos][i];		//路径长度加上pos与i之间的距离
			allpahts(G, i, end, s);
			plength = plength - G.edges[pos][i];		//路径长度减去pos与i之间的距离
		}
	flagg[pos] = 0;										//删除标记
	s->top--;											//栈中剔除
}


/********************************************************/
/*	函数功能：输出两结点间所有路径						*/
/*	函数参数：邻接矩阵G,起点start,终点end				*/
/*	函数返回值：无										*/
/********************************************************/
void allpathsout(Mgraph G, int start, int end)
{
	int i,pos = start;
	for (i = 0; i < G.n; ++i)flagg[i] = 0;				//初始化标志数组flagg
	sqstack* s;
	s = (sqstack*)malloc(sizeof(sqstack));				//申请栈内存
	initstack(s);										//初始化栈
	pre = start;
	plength =0;
	printf("%10s--->%10s  所有路径：\n\n", G.vexs[start].name, G.vexs[end].name);
	allpahts(G, pos, end, s);							//调用allpahts函数

	/*界面输出*/
	settextcolor(BLACK);
	settextstyle(23, 0, _T("黑体"));
	char text[20]="" ;
	sprintf_s(text, sizeof(text), " 共有 %d 条路径", kinds_num);
	outtextxy(1110, 440, text);
	kinds_num = 0;
	system("pause");
}