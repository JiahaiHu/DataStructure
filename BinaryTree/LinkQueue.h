#include "BinaryTree.h"

typedef  BiTree QElemType 

typedef struct QNode {
    QElemType T;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;     // 队头指针
    QueuePtr rear;      // 队尾指针
} LinkQueue;

status InitQueue(LinkQueue &Q);
status QueueEmpty(LinkQueue &Q);
status EnQueue(LinkQueue &Q, QElemType &e);
status DeQueue(LinkQueue &Q, QElemType e);
