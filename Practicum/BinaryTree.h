#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

#define LH +1   // 左高
#define EH 0    // 等高
#define RH -1   // 右高

typedef int status;

typedef struct User {
    int id;
    struct AVLNode *friends, *fans, *follows;// sets
} User;

typedef struct AVLNode {
    User user;
    int bf;                             // 平衡因子
    struct AVLNode *lchild, *rchild;    // 左、右孩子指针
} AVLNode, *AVLTree;

typedef AVLTree Set;

