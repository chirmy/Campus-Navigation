#include"mes_search.h"
#include <string.h>

/********************************************************/
/*	�������ܣ�������Ϣ����								*/
/*	�����������ڽӾ���g����������name					*/
/*	��������ֵ���������ַ���							*/
/********************************************************/
char* search(Mgraph g, char* name)
{
	char* vexname;
	int i;
	for (i = 0; i < g.n; ++i)							//ѭ��Ѱ�Ҿ�������
		if (!strcmp(name, g.vexs[i].name))				//strcmp(name,g.vexs[i].name)==0 ƥ��ɹ�
		{
			return g.vexs[i].introduce;
		}
	if (i == g.n)										//�˾��㲻����
	{
		printf("ERROR!\t��Ǹ��������������\n");
		return NULL;
	}
}