#pragma once
#include<stdio.h>
#include"ljjz.h"
typedef struct
{
   int  top;
   int stack[M];
}sqstack;

/************************************************/
/*	�������ܣ���ʼ��ջ			                */
/*	����������ջָ��*s				            */
/*	��������ֵ����								*/
/************************************************/
void initstack(sqstack* s);


/************************************************/
/*	�������ܣ���ջ     			                */
/*	����������ջָ��*s����ջ����n	            */
/*	��������ֵ����								*/
/************************************************/
void push(sqstack* s, int n);

/************************************************/
/*	�������ܣ���ջ     			                */
/*	����������ջָ��*s           	            */
/*	��������ֵ����ջ����n						*/
/************************************************/
int pop(sqstack& s);