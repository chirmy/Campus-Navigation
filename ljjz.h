#pragma once
#include<stdio.h>

#define FINITY 5000						/*�˴�5000���������*/
#define M 35
typedef char vertextype;				/*����ֵ����*/
typedef int edgetype;					/*������*/


/*�����Ϣ���������ơ���顢�������꣩*/
typedef struct vertex
{
	char name[20];
	char *introduce;
	int x;
	int y;
}spot;

/*	�ڽӾ���	*/
typedef struct							
{
	spot vexs[M];
	edgetype edges[M][M];
	int n, e;							/*�������������*/
}Mgraph;



