#include"Bestpath_Multispot.h"


int MinDis = 0;                                                 //最优路线最小长度
int Prode[M];                                                   //存储所想访问节点的最优路径次序
int index = 0;                                                  //Prode[index]
bool mark[M] ;                                                  //访问标志位


/****************************************************************/
/*	函数功能：计算多结点最优路径			    		        */
/*	函数参数：邻接矩阵g，所需访问节点数组wantview_vexs	        */
/*          数组大小vex_num，起始访问节点wantview_vexs[order]   */
/*          距离向量d,路径向量p                                 */
/*	函数返回值：无										        */
/****************************************************************/
void Bestpath_Multispot(Mgraph g,int wantview_vexs[],int vex_num,int order, int d[][M], int p[][M])
{
    int i, j, dis;
    dis = FINITY;                                               //每次选择下一节点次序时，初始化两点间距离dis为无穷大
    if (index >= vex_num-1)                                     //全部结点均完成便利
    {
        mark[order] = TRUE;                                     //标记第order个数为已访问
        for (i = 0; i < vex_num; ++i)                           //寻找最后一个结点
        {
            if (!mark[i])                                       //未标记 
            {
                Prode[index] = wantview_vexs[i];                //将wantview_vexs[i]存入Prode[index]数组中
                MinDis = MinDis + d[wantview_vexs[order]][wantview_vexs[i]];//距离叠加
                break;                                          //查找到最后一个即退出循环
            }
        }
        /*界面输出*/
       settextcolor(BLACK);
       settextstyle(23, 0, _T("黑体"));
       char text[30] = "";
       sprintf_s(text, sizeof(text), "最佳访问路径长度为 %d 米", MinDis);
       outtextxy(1085, 440, text);

       printf("\n最佳访问路径长度为 %d米\t:",MinDis);
       for (j = 0; j < vex_num - 1; ++j)                        //输出最优路径并copy给Out[]数组
       {
           printf("%10s-->", g.vexs[Prode[j]].name);
           Out[OutSize++] = Prode[j];
       }
        printf("%10s\n", g.vexs[Prode[j]].name);
        Out[OutSize++] = Prode[j];
        makeline(g);                                            //最优路径划线
        return;
    }
    int v0 = wantview_vexs[order],v;                            //v0为本次遍历中的起始节点，v为所筛选出的下一节点的次序
    mark[order] = TRUE;                                         //设置v0点的标志位为1
    for (i = 0; i < vex_num; ++i)                               //找到距离v0路径最短的点
    {
        if (!mark[i]  && dis >=d[v0][wantview_vexs[i]])         //未标记&&距离比dis小
        {
            v = i;
            dis = d[v0][wantview_vexs[i]];                      //更新dis值
        }
    }
    Prode[index++] = wantview_vexs[v];                          //将v节点加入Prode数组中
    MinDis = MinDis + dis;                                      //距离增加
    Bestpath_Multispot(g, wantview_vexs, vex_num, v, d, p);     //继续从v节点开始寻找距离v节点最近的节点
}


/****************************************************************/
/*	函数功能：包装 Bestpath_Multispot多结点最优路径函数	        */
/*	函数参数：邻接矩阵g，所需访问节点数组wantview_vexs	        */
/*          数组大小vex_num， 距离向量d,路径向量p               */
/*	函数返回值：无										        */
/****************************************************************/
void BestpathOutput(Mgraph g, int wantview_vexs[], int vex_num,  int d[][M], int p[][M])
{
    int i,j;
    for (i = 0; i < M; ++i) { mark[i] = FALSE; }
    Prode[index++] = wantview_vexs[0];                          //将第一个节点放入Prode数组中
    Bestpath_Multispot(g, wantview_vexs, vex_num,0, d, p);      //寻找从wantview_vexs[0]节点开始的最优路径
   
    for (i = 0; i < vex_num - 1; ++i)                           //两点间具体路径输出
    {
        printf("·%10s", g.vexs[Prode[i]].name);                 //输出起点
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
