#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType;

#define LIST_INIT_SIZE 10	// 线性表存储空间的初始分配量
#define LISTINCREMENT  10	// 线性表存储空间的分配增量
#define LISTS_SIZE 10		// 线性表数组长度

typedef struct {
    ElemType *elem;		// 存储空间基址
	int length;			// 当前长度
	int listsize;		// 分配的总长度
} SqList;

typedef struct {
	SqList *L;
	int length;			// 线性表个数
} Lists;

status InitLists(Lists &Lists);
SqList * SelectList(Lists &Lists);
status InitaList(SqList &L);
status DestroyList(SqList &L);
status ClearList(SqList &L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L, int i, ElemType &e);
status LocateElem(SqList L, ElemType e);
status PriorElem(SqList L, ElemType cur, ElemType &pre_e);
status NextElem(SqList L, ElemType cur, ElemType &next_e);
status ListInsert(SqList &L, int i, ElemType e);
status ListDelete(SqList &L, int i, ElemType &e);
int ListTrabverse(SqList L);
status SaveData(Lists &Lists);
status ReadData(Lists &Lists);
