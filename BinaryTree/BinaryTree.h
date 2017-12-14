#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int KeyType;
typedef struct TElemType {
    KeyType key;
    int score;
} TElemType;

#define LIST_INIT_SIZE 10	// 线性表存储空间的初始分配量
#define LISTINCREMENT  10	// 线性表存储空间的分配增量

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;    // 左右孩子指针
} BiTNode, *BiTree;

typedef struct BinaryTree {
    char name[20];
    BiTree T;
} BinaryTree;

typedef struct Trees {
    BinaryTree *elem;
    int length;
    int listsize;
} Trees;

status InitBiTree(BiTree &T);
status DestroyBiTree(BiTree &T);
status CreateBiTree(BiTree &T, TElemType definition[10]);
status ClearBiTree(BiTree &T);
status BiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);
BiTree Root(BiTree T);
int Value(BiTree T, TElemType e);
status Assign(BiTree T, TElemType &e, int value);
BiTree Parent(BiTree T, TElemType e);
BiTree LeftChild(BiTree T, TElemType e);
BiTree RightChild(BiTree T, TElemType e);
BiTree LeftSibling(BiTree T, TElemType e);
BiTree RightSibling(BiTree T, TElemType e);
status InsertChild(BiTree T, TElemType *p, int LR, BiTree c);
status DeleteChild(BiTree T, TElemType *p, int LR);
status PreOrderTraverse(BiTree T, status (*Visit)(TElemType e));
status InOrderTraverse(BiTree T, status (*Visit)(TElemType e));
status PostOrderTraverse(BiTree T, status (*Visit)(TElemType e));
status LevelOrderTraverse(BiTree T, status (*Visit)(TElemType e));
