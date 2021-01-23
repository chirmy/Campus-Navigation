#pragma once
#include<stdlib.h>
#include"ljjz.h"
#include"stack.h"
#include "GUI.h"
//#include "GUI.cpp"
extern int Out[M];
extern int OutSize;


/********************************************************/
/*	函数功能：两结点间所有路径							*/
/*	函数参数：邻接矩阵G,起点pos,终点end,栈指针*s		*/
/*	函数返回值：无										*/
/********************************************************/
void allpahts(Mgraph G, int pos, int end, sqstack* s);


/********************************************************/
/*	函数功能：输出两结点间所有路径						*/
/*	函数参数：邻接矩阵G,起点start,终点end				*/
/*	函数返回值：无										*/
/********************************************************/
void allpathsout(Mgraph G, int start, int end);