#pragma once
#include"ljjz.h"
#include"shortestpath.h"
#include "GUI.h"
#include<stdio.h>
extern int Out[M];
extern int OutSize;
/****************************************************************/
/*	�������ܣ������������·��			    		        */
/*	�����������ڽӾ���g��������ʽڵ�����wantview_vexs	        */
/*          �����Сvex_num����ʼ���ʽڵ�wantview_vexs[order]   */
/*          ��������d,·������p                                 */
/*	��������ֵ����										        */
/****************************************************************/
void Bestpath_Multispot(Mgraph g, int wantview_vexs[], int vex_num, int order, int d[][M], int p[][M]);


/****************************************************************/
/*	�������ܣ���װ Bestpath_Multispot��������·������	        */
/*	�����������ڽӾ���g��������ʽڵ�����wantview_vexs	        */
/*          �����Сvex_num�� ��������d,·������p               */
/*	��������ֵ����										        */
/****************************************************************/
void BestpathOutput(Mgraph g, int wantview_vexs[], int vex_num, int d[][M], int p[][M]);