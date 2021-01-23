#include"mes_search.h"
#include <string.h>

/********************************************************/
/*	函数功能：景点信息搜索								*/
/*	函数参数：邻接矩阵g，景点名称name					*/
/*	函数返回值：景点简介字符串							*/
/********************************************************/
char* search(Mgraph g, char* name)
{
	char* vexname;
	int i;
	for (i = 0; i < g.n; ++i)							//循环寻找景点名称
		if (!strcmp(name, g.vexs[i].name))				//strcmp(name,g.vexs[i].name)==0 匹配成功
		{
			return g.vexs[i].introduce;
		}
	if (i == g.n)										//此景点不存在
	{
		printf("ERROR!\t抱歉，您的输入有误。\n");
		return NULL;
	}
}