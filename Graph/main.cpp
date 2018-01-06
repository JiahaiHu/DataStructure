/* Graph */
#include "Graph.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

int main(void){
    ALGraph G;
    VertexType V[MAX_VERTEX_NUM];
    VertexType v, w;
    int VR[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum;
    int op=1;
    int i, j;
    while (op)
    {
        system("cls");
        printf("\n\n");
        printf("      Menu for Graph On Adjacency List \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. CreateGraph       7. NextAdjVex\n");
        printf("    	  2. DestroyGraph      8. InsertVex\n");
        printf("    	  3. LocateVex         9. DeleteVex \n");
        printf("    	  4. GetVex            10. InsertArc\n");
        printf("    	  5. PutVex            11. DeleteArc\n");
        printf("    	  6. FirstAdjVex       12. DFSTraverse\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~12]:");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                printf("请输入顶点数：");
                scanf("%d", &vexnum);
                printf("请依次输入顶点信息：\n");
                for (i = 0; i < vexnum; i++)
                {
                    scanf("%d", &V[i]);
                }
                V[vexnum] = -1;
                printf("请输入顶点关系信息：\n");
                for (i = 0; i < vexnum; i++)
                {
                    for (j = 0; j < vexnum; j++)
                    {
                        scanf("%d", &VR[i][j]);
                    }
                }
                if (CreateGraph(G, V, VR))
                {
                    printf("创建成功!\n");
                }
                // test
                for (i = 0; i < vexnum; i++)
                {

                }
                printf("输入任意键继续。。。"); getch();
                break;
            case 2:
                printf("输入任意键继续。。。"); getch();
                break;
            case 3:
                printf("请输出该顶点的值：");
                scanf("%d", &v);
                i = LocateVex(G, v);
                if (i == -1)
                {
                    printf("不存在该顶点！\n");
                }
                else
                {
                    printf("该顶点的位置为%d！\n", i);
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 4:
                printf("请输出该顶点的位置：");
                scanf("%d", &v);
                if (v < G.vexnum)
                {
                    i = GetVex(G, v);
                    printf("该顶点的值为%d！\n", i);
                }
                else
                {
                    printf("输入不合法！\n");
                }
     
                printf("输入任意键继续。。。"); getch();
                break;
            case 5:
                scanf("%d", &i);
                scanf("%d", &v);
                if (i < G.vexnum)
                {
                    if (PutVex(G, i, v))
                    {
                        printf("赋值成功！\n");
                    }
                }
                else
                {
                    printf("不存在该顶点！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 6:
                printf("请输入顶点的值：");
                scanf("%d", &i);
                v = FirstAdjVex(G, i);
                if (v)
                {
                    printf("该顶点第一个邻接顶点的值为%d！\n", v);
                }
                else
                {
                    printf("该顶点没有邻接顶点！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 7:
                printf("请输入顶点的值：");
                scanf("%d", &v);
                printf("请输入邻接顶点的值：");
                scanf("%d", &w);
                i = NextAdjVex(G, v, w);
                if (i)
                {
                    printf("该顶点下一个邻接顶点的值为%d！\n", i);
                }
                else
                {
                    printf("该邻接顶点是最后一个邻接顶点！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 8:
                printf("请输入需要插入的顶点的值：");
                scanf("%d", &v);
                if (G.vexnum < MAX_VERTEX_NUM)
                {
                    if (InsertVex(G, v))
                    {
                        printf("顶点插入成功！\n");
                    }
                }
                else
                {
                    printf("已达到最大顶点数！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 9:
                printf("请输入需要删除的顶点的值：");
                scanf("%d", &v);
                if (DeleteVex(G, v))
                {
                    printf("顶点删除成功！\n");
                }
                else
                {
                    printf("顶点删除失败！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 10:
                printf("请输入需要插入的弧对应的顶点位置：");
                scanf("%d %d", &v, &w);
                if (InsertArc(G, v, w))
                {
                    printf("弧插入成功！\n");
                }
                else
                {
                    printf("弧插入失败！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 11:
                printf("请输入需要删除的弧对应的顶点位置：");
                scanf("%d %d", &v, &w);
                if (DeleteArc(G, v, w))
                {
                    printf("弧删除成功！\n");
                }
                else
                {
                    printf("弧删除失败！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 12:
                printf("输入任意键继续。。。"); getch();
                break;
            case 0:
                break;
        } //end of switch
    }     //end of while
    printf("欢迎下次再使用本系统！\n");
    return 0;
}//end of main()


/*
 * 初始条件：V是图的顶点集，VR是图的关系集
 * 操作结果：按V和VR的定义构造图G
 */
status CreateGraph(ALGraph &G, VertexType V[MAX_VERTEX_NUM], int VR[MAX_VERTEX_NUM][MAX_VERTEX_NUM])
{
    ArcNode *arctemp;

    G.kind = DG;    // 构造有向图
    G.vexnum = 0;
    for (int i = 0; i < MAX_VERTEX_NUM; i++)
    {
        if (V[i] == -1) break;
        G.vertices[i].data = V[i];              // 结点信息赋值
        G.vertices[i].firstarc = NULL;          // 第一条弧指针初始化
        G.vexnum++;
    }
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            // 邻接链表中的顶点位置先大后小
            if (VR[i][j])      // i,j之间有弧
            {
                if (G.vertices[i].firstarc == NULL)     // 是第一条依附该顶点的弧
                {
                    // printf("done\n");
                    G.vertices[i].firstarc = (ArcNode *)malloc(sizeof(ArcNode));
                    G.vertices[i].firstarc->adjvex = j;
                    G.vertices[i].firstarc->nextarc = NULL;
                }
                else
                {
                    arctemp = (ArcNode *)malloc(sizeof(ArcNode));
                    arctemp->adjvex = j;
                    arctemp->nextarc = G.vertices[i].firstarc;
                    G.vertices[i].firstarc = arctemp;
                }
                G.arcnum++;
            }
        }
    }

    return OK;
}

/*
 * 初始条件：G已存在
 * 操作结果：销毁图G
 */
status DestroyGraph(ALGraph &G)
{
    ArcNode *arc, *temp;

    for (int i = 0; i < G.vexnum; i++)
    {
        arc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = NULL;
        while (arc)
        {
            temp = arc->nextarc;
            free(arc);
            arc = temp;
        }
    }
    G.arcnum = 0;
    G.vexnum = 0;

    return OK;
}

/*
 * 初始条件：图G存在，u和G中的顶点具有相同特征
 * 操作结果：若u在图G中存在，返回顶点u的位置信息，否则返回其它信息
 */
int LocateVex(ALGraph G, VertexType u)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == u)
        {
            return i;
        }
    }
    return -1;  // 不存在
}

/*
 * 初始条件：图G存在，v是G中的某个顶点
 * 操作结果：返回v的值
 */
VertexType GetVex(ALGraph G, Index v)
{
    return G.vertices[v].data;
}

/*
 * 初始条件：图G存在，v是G中的某个顶点
 * 操作结果：对v赋值value
 */
status PutVex(ALGraph &G, Index v, VertexType value)
{
    G.vertices[v].data = value;

    return OK;
}

/*
 * 初始条件：图G存在，v是G的一个顶点
 * 操作结果：返回v的第一个邻接顶点，如果v没有邻接顶点，返回“空”
 */
VertexType FirstAdjVex(ALGraph G, VertexType v)
{
    ArcNode *firstarc;

    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == v)
        {
            firstarc = G.vertices[i].firstarc;
            if (firstarc)
            {
                return G.vertices[firstarc->adjvex].data;
            }
            else
            {
                return 0;
            }
        }
    }

    return 0;
}

/*
 * 初始条件：图G存在，v是G的一个顶点,w是v的邻接顶点
 * 操作结果：返回v的（相对于w）下一个邻接顶点，如果w是最后一个邻接顶点，返回“空”
 */
VertexType NextAdjVex(ALGraph G, VertexType v, VertexType w)
{
    ArcNode *arc, *nextarc;

    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == v)
        {
            for (arc = G.vertices[i].firstarc; arc != NULL; arc = arc->nextarc)
            {
                if (G.vertices[arc->adjvex].data == w)
                {
                    // printf("%d", G.vertices[arc->adjvex].data);
                    // printf("%d", G.vertices[arc->nextarc->adjvex].data);
                    nextarc = arc->nextarc;
                    if (nextarc)
                    {
                        return G.vertices[nextarc->adjvex].data;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}

/*
 * 初始条件：图G存在，v和G中的顶点具有相同特征
 * 操作结果：在图G中增加新顶点v
 */
status InsertVex(ALGraph &G, VertexType v)
{
    if (G.vexnum > MAX_VERTEX_NUM) return ERROR;

    G.vertices[G.vexnum].data = v;
    G.vertices[G.vexnum].firstarc = NULL;
    G.vexnum++;

    return OK;
}

/*
 * 初始条件：图G存在，v是G的一个顶点
 * 操作结果：在图G中删除顶点v和与v相关的弧
 */
status DeleteVex(ALGraph &G, VertexType v)
{
    Index index = -1;
    ArcNode *arc;

    // 获取顶点v的位置
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == v)
        {
            index = i;
            break;
        }
    }
    if (index == -1) return ERROR;

    // 删除顶点v
    for (int i = index; i < G.vexnum - 1; i++)
    {
        G.vertices[i] = G.vertices[i + 1];
    }
    G.vexnum--;

    // 删除各顶点邻接链表中与v相关的弧
    for (int i = 0; i < G.vexnum; i++)
    {
        DeleteArc(G, i, index);
    }
    // 更新邻接链表中删除顶点后面的顶点位置信息
    for (int i = 0; i < G.vexnum; i++)
    {
        for (arc = G.vertices[i].firstarc; arc != NULL; arc = arc->nextarc)
        {
            if (arc->adjvex > index)
            {
                arc->adjvex--;
            }
            else break;
        }
    }

    return OK;
}

/*
 * 初始条件：图G存在，v、w是G的顶点
 * 操作结果：在图G中增加弧<v,w>，如果图G是无向图，还需要增加<w,v>
 */
status InsertArc(ALGraph &G, Index v, Index w)
{
    ArcNode *arc, *temp;
    if (!G.vertices[v].firstarc)
    {
        temp = (ArcNode *)malloc(sizeof(ArcNode));
        temp->adjvex = w;
        temp->nextarc = NULL;
        G.vertices[v].firstarc = temp;
        return OK;
    }
    for (arc = G.vertices[v].firstarc; arc != NULL; arc = arc->nextarc)
    {
        if (arc->adjvex > w)
        {
            if (!arc->nextarc || arc->nextarc->adjvex < w)
            {
                temp = (ArcNode *)malloc(sizeof(ArcNode));
                temp->adjvex = w;
                temp->nextarc = arc->nextarc;
                arc->nextarc = temp;
                return OK;
            }
        }
        if (arc->adjvex < w)
        {
            temp = (ArcNode *)malloc(sizeof(ArcNode));
            temp->adjvex = w;
            temp->nextarc = arc->nextarc;
            arc->nextarc = temp;
            return OK;
        }
    }
    return ERROR;
}

/*
 * 初始条件：图G存在，v、w是G的顶点
 * 操作结果：在图G中删除弧<v,w>，如果图G是无向图，还需要删除<w,v>
 */
status DeleteArc(ALGraph &G, Index v, Index w)
{
    ArcNode *arc;

    // 没有邻接顶点，不需要删除
    if (!G.vertices[v].firstarc) return ERROR;

    if (G.vertices[v].firstarc->adjvex == w)
    {
        G.vertices[v].firstarc = G.vertices[v].firstarc->nextarc;
    }
    else if (G.vertices[v].firstarc->adjvex > w)
    {
        for (arc = G.vertices[v].firstarc; arc != NULL; arc = arc->nextarc)
        {
            if (arc->nextarc->adjvex == w)
            {
                arc->nextarc = arc->nextarc->nextarc;
            }
        }
    }
    return OK;
}

/*
 * 初始条件：图G存在
 * 操作结果：图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
 */
status DFSTraverse(ALGraph G, status (*Visit)(VertexType v))
{

    return OK;
}

/*
 * 初始条件：图G存在
 * 操作结果：图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
 */
status BFSTraverse(ALGraph G, status (*Visit)(VertexType v))
{

    return OK;
}

status SaveData(ALGraph G)
{

    return OK;
}

status LoadData(ALGraph G)
{

    return OK;
}
