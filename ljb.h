#pragma once
#include<stdio.h>
#include"ljjz.h"
#include<stdlib.h>
#define M 35
typedef char Datetype;						//����ֵ����

/*�߱���*/
typedef struct node
{
	int adjvex;
	struct node* next;
}EdgeNode;

/*ͷ�������*/
typedef struct vnode
{
	spot vertex;
	EdgeNode* FirstEdge;
	int id;
}Vertexnode;

/*�ڽӱ�����*/
typedef struct
{
	Vertexnode adjlist[M];
	int n, e;/*�������ͱ���*/
}LinkedGraph;


/********************************************************/
/*	�������ܣ��ڽӾ���ת��Ϊ�ڽӱ�						*/
/*	�����������ڽӱ�ָ��g���ڽӾ���G					*/
/*	��������ֵ����										*/
/********************************************************/
void ljb_from_ljjz(LinkedGraph* g, Mgraph G);