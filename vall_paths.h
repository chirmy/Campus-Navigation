#pragma once
#include<stdlib.h>
#include"ljjz.h"
#include"stack.h"
#include "GUI.h"
//#include "GUI.cpp"
extern int Out[M];
extern int OutSize;


/********************************************************/
/*	�������ܣ�����������·��							*/
/*	�����������ڽӾ���G,���pos,�յ�end,ջָ��*s		*/
/*	��������ֵ����										*/
/********************************************************/
void allpahts(Mgraph G, int pos, int end, sqstack* s);


/********************************************************/
/*	�������ܣ��������������·��						*/
/*	�����������ڽӾ���G,���start,�յ�end				*/
/*	��������ֵ����										*/
/********************************************************/
void allpathsout(Mgraph G, int start, int end);