#pragma once
#include<stdio.h>

#define FINITY 5000						/*此处5000代表无穷大*/
#define M 35
typedef char vertextype;				/*顶点值类型*/
typedef int edgetype;					/*边类型*/


/*结点信息（包括名称、简介、界面坐标）*/
typedef struct vertex
{
	char name[20];
	char *introduce;
	int x;
	int y;
}spot;

/*	邻接矩阵	*/
typedef struct							
{
	spot vexs[M];
	edgetype edges[M][M];
	int n, e;							/*定点总数与边数*/
}Mgraph;



