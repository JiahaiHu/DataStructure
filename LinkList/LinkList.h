#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType;

typedef struct LNode {      // 单链表结点结构
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct ListsNode {      // 十字链表结构
    int length;
    LinkList L;
    struct ListsNode *next;
} ListsNode, *Lists;

status InitLists(Lists &Lists);
LinkList SelectList(Lists Lists);
status InsertaList(Lists Lists, LinkList L);
ListsNode * PriorList(Lists Lists, LinkList L);
status InitaList(LinkList &L);
status DestroyList(LinkList L);
status ClearList(LinkList L);
status ListEmpty(LinkList L);
int ListLength(LinkList L);
status GetElem(LinkList L, int i, ElemType &e);
status LocateElem(LinkList L, ElemType e);
status PriorElem(LinkList L, ElemType cur, ElemType &pre_e);
status NextElem(LinkList L, ElemType cur, ElemType &next_e);
status ListInsert(LinkList L, int i, ElemType e);
status ListDelete(LinkList L, int i, ElemType &e);
int ListTrabverse(LinkList L);
status SaveData(Lists Lists);
status ReadData(Lists Lists);