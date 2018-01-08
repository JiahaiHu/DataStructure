
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int VertexType;
typedef int Index;
// typedef int InfoType;

#define MAX_VERTEX_NUM 20                   // 最大顶点个数
typedef enum {DG, DN, UDG, UDN} GraphKind;  // {有向图，有向网，无向图，无向网}

typedef struct ArcNode {
    int adjvex;                 // 该弧所指向的顶点的位置
    struct ArcNode *nextarc;    // 指向下一条弧的指针
    // InfoType *info;          // 该弧相关信息的指针，如权值
} ArcNode;

typedef struct VNode {
    VertexType data;            // 顶点信息
    ArcNode *firstarc;          // 指向第一条依附该顶点的弧的指针
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;         // 图的当前顶点数和弧数
    int kind;                   // 图的种类标志
} ALGraph;


typedef Index QElemType;

typedef struct QNode {
    QElemType v;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;     // 队头指针
    QueuePtr rear;      // 队尾指针
} LinkQueue;




status InitGraphes(ALGraph *Graphes[5]);
ALGraph * SelectGraph(ALGraph *Graphes[5]);
status CreateGraph(ALGraph &G, VertexType V[MAX_VERTEX_NUM], int VR[MAX_VERTEX_NUM][MAX_VERTEX_NUM]);
status DestroyGraph(ALGraph &G);
int LocateVex(ALGraph G, VertexType u);
VertexType GetVex(ALGraph G, int v);
status PutVex(ALGraph &G, Index v, VertexType value);
VertexType FirstAdjVex(ALGraph G, VertexType v);
VertexType NextAdjVex(ALGraph G, VertexType v, VertexType w);
status InsertVex(ALGraph &G, VertexType v);
status DeleteVex(ALGraph &G, VertexType v);
status InsertArc(ALGraph &G, Index v, Index w);
status DeleteArc(ALGraph &G, Index v, Index w);
status PrintElement(VertexType v);
status DFSTraverse(ALGraph G, status (*Visit)(VertexType v));
status BFSTraverse(ALGraph G, status (*Visit)(VertexType v));
status SaveData(ALGraph *Graphes[5]);
status ReadData(ALGraph *Graphes[5]);

status InitQueue(LinkQueue &Q);
status QueueEmpty(LinkQueue &Q);
status EnQueue(LinkQueue &Q, QElemType &e);
status DeQueue(LinkQueue &Q, QElemType &e);
