#pragma once
#include<stdio.h>
#include"ljjz.h"
#include<stdlib.h>
#define M 35
typedef char Datetype;						//顶点值类型

/*边表结点*/
typedef struct node
{
	int adjvex;
	struct node* next;
}EdgeNode;

/*头结点类型*/
typedef struct vnode
{
	spot vertex;
	EdgeNode* FirstEdge;
	int id;
}Vertexnode;

/*邻接表类型*/
typedef struct
{
	Vertexnode adjlist[M];
	int n, e;/*定点数和边数*/
}LinkedGraph;


/********************************************************/
/*	函数功能：邻接矩阵转换为邻接表						*/
/*	函数参数：邻接表指针g，邻接矩阵G					*/
/*	函数返回值：无										*/
/********************************************************/
void ljb_from_ljjz(LinkedGraph* g, Mgraph G);