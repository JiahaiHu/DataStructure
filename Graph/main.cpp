/* Graph */
#include "Graph.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

FILE *fp;
char filename[30] = "D:/ALGraphData.txt";

int graphnum = 0;

int main(void){
    ALGraph *Graphes[5];
    ALGraph *pG;
    ALGraph G;
    VertexType V[MAX_VERTEX_NUM];
    VertexType v, w;
    int VR[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum;
    int op=1;
    int i, j;
    InitGraphes(Graphes);
    while (op)
    {
        system("cls");
        printf("\n\n");
        printf("      Menu for Graph On Adjacency List \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. CreateGraph       8. InsertVex\n");
        printf("    	  2. DestroyGraph      9. DeleteVex\n");
        printf("    	  3. LocateVex         10. InsertArc\n");
        printf("    	  4. GetVex            11. DeleteArc\n");
        printf("    	  5. PutVex            12. DFSTraverse\n");
        printf("    	  6. FirstAdjVex       13. BFSTraverse\n");
        printf("    	  7. NextAdjVex        14. SaveData\n");
        printf("    	  0. Exit              15. ReadData\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~15]:");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                if (graphnum < 5)
                {
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
                    if (CreateGraph(*Graphes[graphnum], V, VR))
                    {
                        graphnum++;
                        printf("创建成功!\n");
                    }
                }
                else
                {
                    printf("不能再创建更多的图！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 2:
                pG = SelectGraph(Graphes);
                if (pG)
                {
                    printf("请确认需要销毁的图的编号：");
                    scanf("%d", &j);
                    if (DestroyGraph(*pG))
                    {

                        for (i = j; i < graphnum - 1; i++)
                        {
                            Graphes[i] = Graphes[i + 1];
                        }
                        graphnum--;
                        printf("销毁成功！\n");
                    }
                }
                else
                {
                    printf("输入的编号不合法！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 3:
                pG = SelectGraph(Graphes);
                if (pG)
                {
                    printf("请输出该顶点的值：");
                    scanf("%d", &v);
                    i = LocateVex(*pG, v);
                    if (i == -1)
                    {
                        printf("不存在该顶点！\n");
                    }
                    else
                    {
                        printf("该顶点的位置为%d！\n", i);
                    }
                }
                else
                {
                    printf("输入的编号不合法！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 4:
                pG = SelectGraph(Graphes);
                if (pG)
                {
                    printf("请输出该顶点的位置：");
                    scanf("%d", &v);
                    if (v < G.vexnum)
                    {
                        i = GetVex(*pG, v);
                        printf("该顶点的值为%d！\n", i);
                    }
                    else
                    {
                        printf("输入不合法！\n");
                    }
                }
                else
                {
                    printf("输入的编号不合法！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 5:
                pG = SelectGraph(Graphes);
                if (pG)
                {
                    printf("请输入要修改的顶点的位置：");
                    scanf("%d", &i);
                    printf("请输入修改后的值：");
                    scanf("%d", &v);
                    if (i < G.vexnum)
                    {
                        if (PutVex(*pG, i, v))
                        {
                            printf("赋值成功！\n");
                        }
                    }
                    else
                    {
                        printf("不存在该顶点！\n");
                    }
                }
                else
                {
                    printf("输入的编号不合法！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 6:
                pG = SelectGraph(Graphes);
                if (pG)
                {
                    printf("请输入顶点的值：");
                    scanf("%d", &i);
                    v = FirstAdjVex(*pG, i);
                    if (v)
                    {
                        printf("该顶点第一个邻接顶点的值为%d！\n", v);
                    }
                    else
                    {
                        printf("该顶点没有邻接顶点！\n");
                    }
                }
                else
                {
                    printf("输入的编号不合法！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 7:
                pG = SelectGraph(Graphes);
                if (pG)
                {
                    printf("请输入顶点的值：");
                    scanf("%d", &v);
                    printf("请输入邻接顶点的值：");
                    scanf("%d", &w);
                    i = NextAdjVex(*pG, v, w);
                    if (i)
                    {
                        printf("该顶点下一个邻接顶点的值为%d！\n", i);
                    }
                    else
                    {
                        printf("该邻接顶点是最后一个邻接顶点！\n");
                    }
                }
                else
                {
                    printf("输入的编号不合法！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 8:
                pG = SelectGraph(Graphes);
                if (pG)
                {
                    printf("请输入需要插入的顶点的值：");
                    scanf("%d", &v);
                    if (G.vexnum < MAX_VERTEX_NUM)
                    {
                        if (InsertVex(*pG, v))
                        {
                            printf("顶点插入成功！\n");
                        }
                    }
                    else
                    {
                        printf("已达到最大顶点数！\n");
                    }
                }
                else
                {
                    printf("输入的编号不合法！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 9:
                pG = SelectGraph(Graphes);
                if (pG)
                {
                    printf("请输入需要删除的顶点的值：");
                    scanf("%d", &v);
                    if (DeleteVex(*pG, v))
                    {
                        printf("顶点删除成功！\n");
                    }
                    else
                    {
                        printf("顶点删除失败！\n");
                    }
                }
                else
                {
                    printf("输入的编号不合法！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 10:
                pG = SelectGraph(Graphes);
                if (pG)
                {
                    printf("请输入需要插入的弧对应的顶点位置：");
                    scanf("%d %d", &v, &w);
                    if (InsertArc(*pG, v, w))
                    {
                        printf("弧插入成功！\n");
                    }
                    else
                    {
                        printf("弧插入失败！\n");
                    }
                }
                else
                {
                    printf("输入的编号不合法！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 11:
                pG = SelectGraph(Graphes);
                if (pG)
                {
                    printf("请输入需要删除的弧对应的顶点位置：");
                    scanf("%d %d", &v, &w);
                    if (DeleteArc(*pG, v, w))
                    {
                        printf("弧删除成功！\n");
                    }
                    else
                    {
                        printf("弧删除失败！\n");
                    }
                }
                else
                {
                    printf("输入的编号不合法！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 12:
                pG = SelectGraph(Graphes);
                if (pG)
                {
                    if (DFSTraverse(*pG, PrintElement))
                    {
                        printf("深度遍历成功！\n");
                    }
                }
                else
                {
                    printf("输入的编号不合法！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 13:
                pG = SelectGraph(Graphes);
                if (pG)
                {
                    if (BFSTraverse(*pG, PrintElement))
                    {
                        printf("广度遍历成功！\n");
                    }
                }
                else
                {
                    printf("输入的编号不合法！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 14:
                if (SaveData(Graphes))
                {
                    printf("数据保存成功！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 15:
                if (ReadData(Graphes))
                {
                    printf("数据读取成功！\n");
                }

                printf("输入任意键继续。。。"); getch();
                break;
            case 0:
                break;
        } //end of switch
    }     //end of while
    printf("欢迎下次再使用本系统！\n");
    return 0;
}//end of main()

status InitGraphes(ALGraph *Graphes[5])
{
    for (int i = 0; i < 5; i++)
    {
        Graphes[i] = (ALGraph *)malloc(sizeof(ALGraph));
    }
    return OK;
}

ALGraph * SelectGraph(ALGraph *Graphes[5])
{
    Index i;

    printf("请输入需要选择的图的编号：");
    scanf("%d", &i);
    if (i < graphnum)
    {
        return Graphes[i];
    }
    else
    {
        return NULL;
    }
}

/*
status AddGraph(ALGraph *Graphes[5], ALGraph G)
{
    if (graphnum < 5)
    {
        Graphes[graphnum] = (ALGraph *)malloc(sizeof(ALGraph));
        *Graphes[graphnum] = G;
        return OK;
    }
    else
    {
        return ERROR;
    }
}
*/

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

status PrintElement(VertexType v)
{
    printf("%d ", v);
    return OK;
}

static int visited[MAX_VERTEX_NUM];     // 访问标志数组
status (*VisitFunc)(VertexType v);           // 函数变量

// 从第i个顶点出发递归地深度优先遍历图G
void DFS(ALGraph G, Index i)
{
    ArcNode *arc;
    // 访问第i个顶点
    visited[i] = TRUE;
    VisitFunc(G.vertices[i].data);
    for (arc = G.vertices[i].firstarc; arc != NULL; arc = arc->nextarc)
    {
        // 对v的尚未访问的邻接顶点递归调用DFS
        if (!visited[arc->adjvex])
        {
            DFS(G, arc->adjvex);
        }
    }
}

/*
 * 初始条件：图G存在
 * 操作结果：图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
 */
status DFSTraverse(ALGraph G, status (*Visit)(VertexType v))
{
    int i;

    VisitFunc = Visit;      // 使用全局变量VisitFunc,使DFS不必设函数指针参数
    // 访问标志数组初始化
    for (i = 0; i < G.vexnum; i++)
    {
        visited[i] = FALSE;
    }
    for (i = 0; i < G.vexnum; i++)
    {
        // 对尚未访问的顶点调用DFS
        if (!visited[i])
        {
            DFS(G, i);
        }
    }

    return OK;
}

/*
 * 初始条件：图G存在
 * 操作结果：图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
 */
status BFSTraverse(ALGraph G, status (*Visit)(VertexType v))
{
    LinkQueue Q;
    ArcNode *arc;
    int i, j;

    for (i = 0; i < G.vexnum; i++)
    {
        visited[i] = FALSE;
    }
    InitQueue(Q);   // 置空的辅助队列Q
    for (i = 0; i < G.vexnum; i++)
    {
        // i尚未访问
        if (!visited[i])
        {
            visited[i] = TRUE;
            Visit(G.vertices[i].data);
            EnQueue(Q, i);  // i入队列
            while (!QueueEmpty(Q))
            {
                DeQueue(Q, j);  // 队头元素出队并置为j
                for (arc = G.vertices[i].firstarc; arc != NULL; arc = arc->nextarc)
                {
                    // 访问尚未访问的邻接顶点
                    if (!visited[arc->adjvex])
                    {
                        visited[arc->adjvex] = TRUE;
                        Visit(G.vertices[arc->adjvex].data);
                        EnQueue(Q, arc->adjvex);
                    }
                }
            }
        }
    }

    return OK;
}

status SaveData(ALGraph *Graphes[5])
{
    int i, j, k;
    ArcNode *arc;
    int VR[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = {0};

    if ((fp = fopen(filename, "wb")) == NULL)
	{
		printf("文件打开失败！\n");
		return ERROR;
	}
    fwrite(&graphnum, sizeof(int), 1, fp);
    for (i = 0; i < graphnum; i++)
    {
        fwrite(&Graphes[i]->vexnum, sizeof(int), 1, fp);    // 写入顶点数
        fwrite(&Graphes[i]->arcnum, sizeof(int), 1, fp);    // 写入弧数
        for (j = 0; j < Graphes[i]->vexnum; j++)
        {
            fwrite(&Graphes[i]->vertices[j], sizeof(VertexType), 1, fp);    // 写入顶点信息
        }
        for (j = 0; j < Graphes[i]->vexnum; j++)    // 将顶点关系信息保存到矩阵
        {
            for (arc = Graphes[i]->vertices[j].firstarc; arc != NULL; arc = arc->nextarc)
            {
                VR[j][arc->adjvex] = 1;
            }
        }
        for (j = 0; j < Graphes[i]->vexnum; j++)
        {
            for (k = 0; k < Graphes[i]->vexnum; k++)
            {
                fwrite(&VR[j][k], sizeof(int), 1, fp);  // 写入顶点关系
            }
        }
    }
    fclose(fp);
    return OK;
}

status ReadData(ALGraph *Graphes[5])
{
    int vexnum, arcnum;
    VertexType V[MAX_VERTEX_NUM];
    int VR[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int i, j, k;

    if ((fp = fopen(filename, "rb")) == NULL)
	{
		printf("文件打开失败！\n");
		return ERROR;
	}

    fread(&graphnum, sizeof(int), 1, fp);
    for (i = 0; i < graphnum; i++)
    {
        fread(&vexnum, sizeof(int), 1, fp);    // 读取顶点数
        fread(&arcnum, sizeof(int), 1, fp);    // 读取弧数
        for (j = 0; j < vexnum; j++)
        {
            fread(&V[j], sizeof(int), 1, fp);   // 读取顶点信息
        }
        V[vexnum] = -1;
        for (j = 0; j < vexnum; j++)
        {
            for (k = 0; k < vexnum; k++)
            {
                fread(&VR[j][k], sizeof(int), 1, fp);
            }
        }
        CreateGraph(*Graphes[i], V, VR);
    }
    fclose(fp);
    return OK;
}


// ----------- 队列的基本操作 ------------

/*
 * 初始条件：队列Q不存在
 * 操作结果：构造一个空队列Q
 */
status InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;

	return OK;
}

/*
 * 初始条件：队列Q已存在
 * 操作结果：若Q为空队列，则返回TRUE，否则返回FALSE
 */
status QueueEmpty(LinkQueue &Q)
{
	if (Q.front == Q.rear) return TRUE;

	return FALSE;
}

/*
 * 初始条件：队列Q已存在
 * 操作结果：插入元素e为Q的新的队尾元素
 */
status EnQueue(LinkQueue &Q, QElemType &e)
{
	QueuePtr p = NULL;

	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->v = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;

	return OK;
}


/*
 * 初始条件：队列Q已存在
 * 操作结果：删除Q的队头元素，并用e返回其值
 */
status DeQueue(LinkQueue &Q, QElemType &e)
{
    QNode *p;
	if (QueueEmpty(Q)) return ERROR;
	p = Q.front->next;
	e = p->v;
	Q.front->next = p->next;
	if (Q.rear == p)
	{
		Q.rear = Q.front;
	}
	free(p);

	return OK;
}

