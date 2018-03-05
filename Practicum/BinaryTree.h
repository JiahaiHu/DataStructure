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

void show_info(AVLNode *T);
User input_user();
void Select1or2(Set *&p);
void SelectSet(Set *&p);
AVLNode *SelectUser(Set U);

status InitAVL(AVLTree &T);
status DestroyAVL(AVLTree T);
AVLNode *SearchAVL(AVLTree T, int id);
status InsertAVL(AVLTree &T, User user, bool &taller);
status DeleteAVL(AVLTree &T, int id, bool &shorter);
status TraverseAVL(AVLTree T);
void PreOrderTraverse(AVLTree T);
void InOrderTraverse(AVLTree T);

void R_Rotate(AVLTree &T);
void L_Rotate(AVLTree &T);
void LeftBalance(AVLTree &T);
void RightBalance(AVLTree &T);

status set_init(Set &S);
status set_destroy(Set &S);
status set_insert(Set &S, User user, bool &taller);
status set_remove(Set &S, int id, bool &shorter);
status set_intersection(Set S, Set T, Set &D);
status set_union(Set &S, Set T);
status set_diffrence(Set &S, Set T);
int set_size(Set S);
bool set_member(Set S, int id);
bool set_subset(Set S, Set T);
bool set_equal(Set S, Set T);

status SaveData(Set U);
status ReadData(Set &U);

void SaveUsers(Set U);
void SaveUser(Set T);
void SaveUserId(Set T);

User create_user(int id);
void TraverseFriends(Set S, Set &F);
void TraverseIndirectFriends(Set S, Set &F);
