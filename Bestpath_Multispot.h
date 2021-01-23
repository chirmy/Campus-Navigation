#pragma once
#include"ljjz.h"
#include"shortestpath.h"
#include "GUI.h"
#include<stdio.h>
extern int Out[M];
extern int OutSize;
/****************************************************************/
/*	函数功能：计算多结点最优路径			    		        */
/*	函数参数：邻接矩阵g，所需访问节点数组wantview_vexs	        */
/*          数组大小vex_num，起始访问节点wantview_vexs[order]   */
/*          距离向量d,路径向量p                                 */
/*	函数返回值：无										        */
/****************************************************************/
void Bestpath_Multispot(Mgraph g, int wantview_vexs[], int vex_num, int order, int d[][M], int p[][M]);


/****************************************************************/
/*	函数功能：包装 Bestpath_Multispot多结点最优路径函数	        */
/*	函数参数：邻接矩阵g，所需访问节点数组wantview_vexs	        */
/*          数组大小vex_num， 距离向量d,路径向量p               */
/*	函数返回值：无										        */
/****************************************************************/
void BestpathOutput(Mgraph g, int wantview_vexs[], int vex_num, int d[][M], int p[][M]);