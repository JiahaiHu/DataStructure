
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int VertexType;
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


status CreateGraph(ALGraph &G, VertexType V[MAX_VERTEX_NUM], int VR[MAX_VERTEX_NUM][MAX_VERTEX_NUM]);
status DestroyGraph(ALGraph G);
int LocateVex(ALGraph G, VertexType u);
VertexType GetVex(ALGraph G, int v);
status PutVex(ALGraph &G, VertexType v, int value);
VertexType FirstAdjVex(ALGraph G, VertexType v);
VertexType NextAdjVex(ALGraph G, VertexType v, VertexType w);
status InsertVex(ALGraph &G, VertexType v);
status DeleteVex(ALGraph &G, VertexType v);
status InsertArc(ALGraph &G, VertexType v, VertexType w);
status DeleteArc(ALGraph &G, VertexType v, VertexType w);
status DFSTraverse(ALGraph G, status (*Visit)(VertexType v));
status BFSTraverse(ALGraph G, status (*Visit)(VertexType v));

