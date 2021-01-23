#include"Bestpath_Multispot.h"


int MinDis = 0;                                                 //����·����С����
int Prode[M];                                                   //�洢������ʽڵ������·������
int index = 0;                                                  //Prode[index]
bool mark[M] ;                                                  //���ʱ�־λ


/****************************************************************/
/*	�������ܣ������������·��			    		        */
/*	�����������ڽӾ���g��������ʽڵ�����wantview_vexs	        */
/*          �����Сvex_num����ʼ���ʽڵ�wantview_vexs[order]   */
/*          ��������d,·������p                                 */
/*	��������ֵ����										        */
/****************************************************************/
void Bestpath_Multispot(Mgraph g,int wantview_vexs[],int vex_num,int order, int d[][M], int p[][M])
{
    int i, j, dis;
    dis = FINITY;                                               //ÿ��ѡ����һ�ڵ����ʱ����ʼ����������disΪ�����
    if (index >= vex_num-1)                                     //ȫ��������ɱ���
    {
        mark[order] = TRUE;                                     //��ǵ�order����Ϊ�ѷ���
        for (i = 0; i < vex_num; ++i)                           //Ѱ�����һ�����
        {
            if (!mark[i])                                       //δ��� 
            {
                Prode[index] = wantview_vexs[i];                //��wantview_vexs[i]����Prode[index]������
                MinDis = MinDis + d[wantview_vexs[order]][wantview_vexs[i]];//�������
                break;                                          //���ҵ����һ�����˳�ѭ��
            }
        }
        /*�������*/
       settextcolor(BLACK);
       settextstyle(23, 0, _T("����"));
       char text[30] = "";
       sprintf_s(text, sizeof(text), "��ѷ���·������Ϊ %d ��", MinDis);
       outtextxy(1085, 440, text);

       printf("\n��ѷ���·������Ϊ %d��\t:",MinDis);
       for (j = 0; j < vex_num - 1; ++j)                        //�������·����copy��Out[]����
       {
           printf("%10s-->", g.vexs[Prode[j]].name);
           Out[OutSize++] = Prode[j];
       }
        printf("%10s\n", g.vexs[Prode[j]].name);
        Out[OutSize++] = Prode[j];
        makeline(g);                                            //����·������
        return;
    }
    int v0 = wantview_vexs[order],v;                            //v0Ϊ���α����е���ʼ�ڵ㣬vΪ��ɸѡ������һ�ڵ�Ĵ���
    mark[order] = TRUE;                                         //����v0��ı�־λΪ1
    for (i = 0; i < vex_num; ++i)                               //�ҵ�����v0·����̵ĵ�
    {
        if (!mark[i]  && dis >=d[v0][wantview_vexs[i]])         //δ���&&�����disС
        {
            v = i;
            dis = d[v0][wantview_vexs[i]];                      //����disֵ
        }
    }
    Prode[index++] = wantview_vexs[v];                          //��v�ڵ����Prode������
    MinDis = MinDis + dis;                                      //��������
    Bestpath_Multispot(g, wantview_vexs, vex_num, v, d, p);     //������v�ڵ㿪ʼѰ�Ҿ���v�ڵ�����Ľڵ�
}


/****************************************************************/
/*	�������ܣ���װ Bestpath_Multispot��������·������	        */
/*	�����������ڽӾ���g��������ʽڵ�����wantview_vexs	        */
/*          �����Сvex_num�� ��������d,·������p               */
/*	��������ֵ����										        */
/****************************************************************/
void BestpathOutput(Mgraph g, int wantview_vexs[], int vex_num,  int d[][M], int p[][M])
{
    int i,j;
    for (i = 0; i < M; ++i) { mark[i] = FALSE; }
    Prode[index++] = wantview_vexs[0];                          //����һ���ڵ����Prode������
    Bestpath_Multispot(g, wantview_vexs, vex_num,0, d, p);      //Ѱ�Ҵ�wantview_vexs[0]�ڵ㿪ʼ������·��
   
    for (i = 0; i < vex_num - 1; ++i)                           //��������·�����
    {
        printf("��%10s", g.vexs[Prode[i]].name);                 //������
        Out[OutSize++] = Prode[i];
        floydoutput(g, p, Prode[i],Prode[i+1]);
        Out[OutSize++] = Prode[i + 1];
        for (j = 1; j < OutSize; ++j)printf("->%10s", g.vexs[Out[j]].name);
        for (i = 0; i < M; ++i)Out[i] = 0;
        OutSize = 0;
        printf("\n");
        //printf("->%10s\n", g.vexs[Prode[i+1]].name);
    }
}
