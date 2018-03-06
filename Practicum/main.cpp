#include "BinaryTree.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <Windows.h>

FILE *fp;
bool taller, shorter;
char filename[30] = "D:/SetData.txt";

Set U = NULL;   // users set
Set S = NULL;
Set T1 = NULL;   // test set
Set T2 = NULL;   // test set

int main()
{
    Set *p = NULL;   // pointer
    int op = 1;
	int id;

	while (op)
	{
		system("cls");
		printf("\n\n");
		printf("      Menu for Set ADT On AVL Tree Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. set_init           9. set_subset\n");
		printf("    	  2. set_destroy        10. set_equal\n");
		printf("    	  3. set_insert         11. member_add\n");
		printf("    	  4. set_remove         12. member_delete\n");
		printf("    	  5. set_intersection   13. member_search\n");
		printf("    	  6. set_union          14. member_modify\n");
		printf("    	  7. set_difference     15. TraverseAVL\n");
		printf("    	  8. set_member         16. indirect_friends\n");
		printf("    	  17. commom_hobby      18. common_follow\n");
		printf("    	  19. SaveData          20. ReadData\n");
		printf("    	  21. CreateRandomData  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~14]:");
		scanf("%d", &op);
		switch (op)
		{
            case 1:     // init
                set_init(T1);
                printf("初始化成功！\n");

                printf("输入任意键继续。。。");getch();
                break;
            case 2:     // destroy
                set_destroy(T1);
                printf("销毁成功！\n");

                printf("输入任意键继续。。。");getch();
                break;
            case 3:     // insert
                User user;
                Select1or2(p);
                user = input_user();
                if (set_insert(*p, user, taller))
                {
                    printf("插入成功！\n");
                }
                else
                {
                    printf("插入失败！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 4:     // remove
                Select1or2(p);
                printf("请输入被删除人的id：");
                scanf("%d", &id);getchar();
                if (set_remove(*p, id, shorter))
                {
                    printf("删除成功！\n");
                }
                else
                {
                    printf("删除失败！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 5:     // intersection
                set_init(S);
                if (set_intersection(T1, T2, S))
                {
                    printf("交集操作成功！\n");
                    printf("两个集合的交集为：\n");
                    TraverseAVL(S);
                }
                else
                {
                    printf("交集操作失败！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 6:     // union
                if (set_union(T1, T2))
                {
                    printf("并集操作成功！\n");
                    printf("两个集合的并集为：\n");
                    TraverseAVL(T1);
                }
                else
                {
                    printf("并集操作失败！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 7:     // difference
                if (set_diffrence(T1, T2))
                {
                    printf("差集操作成功！\n");
                    printf("两个集合的差集为：\n");
                    TraverseAVL(T1);
                }
                else
                {
                    printf("差集操作失败！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 8:     // member
                Select1or2(p);
                printf("请输入id：");
                scanf("%d", &id);getchar();
                if (set_member(*p, id))
                {
                    printf("集合中有此人！\n");
                }
                else
                {
                    printf("集合中没有此人！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 9:     // subset
                if (set_subset(T1, T2))
                {
                    printf("是子集！\n");
                }
                else
                {
                    printf("不是子集！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 10:    // equal
                if (set_equal(T1, T2))
                {
                    printf("两个集合相同！\n");
                }
                else
                {
                    printf("两个集合不同！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 11:    // member_add
                SelectSet(p);
                user = input_user();
                if (set_insert(*p, user, taller))
                {
                    printf("成员添加成功！\n");
                }
                else
                {
                    printf("成员添加失败！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 12:    // member_delete
                SelectSet(p);
                printf("请输入被删除人的id：");
                scanf("%d", &id);getchar();
                if (set_remove(*p, id, shorter))
                {
                    printf("成员删除成功！\n");
                }
                else
                {
                    printf("成员删除失败！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 13:    // member_search
                SelectSet(p);
                printf("请输入需要查找的用户的id：");
                scanf("%d", &id);getchar();
                S = SearchAVL(*p, id);
                if (S)
                {
                    printf("该用户在此集合中！\n");
                    show_info(SearchAVL(U, id));
                }
                else
                {
                    printf("搜索不到该成员！\n");
                }
                printf("输入任意键继续。。。");getch();
                break;
            case 14:    // member_modify
                SelectSet(p);
                printf("请输入需要修改的信息的id：");
                scanf("%d", &id);getchar();
                S = SearchAVL(*p, id);
                if (S)
                {
                    printf("请输入修改后的新id：");
                    scanf("%d", &user.id);getchar();
                    if (set_remove(*p, id, taller) && set_insert(*p, user, taller))
                    {
                        printf("修改成功！\n");
                    }
                    else
                    {
                        printf("修改失败！\n");
                    }
                }
                else
                {
                    printf("该用户不存在！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 15:    // Traverse
                S = SelectUser(U);
                if (S)
                {
                    show_info(S);
                }
                else
                {
                    printf("该用户不存在！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 16:    // indirect_friends
                set_init(T1);
                S = SelectUser(U);
                if (S)
                {
                    TraverseFriends(S->user.friends, T1);
                    set_remove(T1, S->user.id, shorter);
                    printf("该用户的二度好友有：\n");
                    TraverseAVL(T1);
                }
                else
                {
                    printf("该用户不存在！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 17:    // common_hobby
                set_init(T1);
                set_init(T2);
                set_init(S);
                T1 = SelectUser(U);
                T2 = SelectUser(U);
                set_intersection(T1->user.hobbys, T2->user.hobbys, S);
                printf("两个用户共同的爱好有：\n");
                TraverseAVL(S);

                printf("输入任意键继续。。。");getch();
                break;
            case 18:    // common_follow
                set_init(T1);
                set_init(T2);
                set_init(S);
                T1 = SelectUser(U);
                T2 = SelectUser(U);
                set_intersection(T1->user.follows, T2->user.follows, S);
                printf("两个用户共同关注的人有：\n");
                TraverseAVL(S);

                printf("输入任意键继续。。。");getch();
                break;
            case 19:    // Save
                if (SaveData(U))
                {
                    printf("数据保存成功！\n");
                }
                else
                {
                    printf("数据保存失败！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 20:    // Load
                if (ReadData(U))
                {
                    printf("数据读取成功！\n");
                }
                else
                {
                    printf("数据读取失败！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 21:    // create random data
                for (int id = 1; id < 31; id++)
                {
                    Sleep(1000);
                    set_insert(U, create_user(id), taller);
                }
                printf("随机生成数据成功！\n");

                printf("输入任意键继续。。。");getch();
                break;
		    case 0:
                break;
        }
    }
    printf("欢迎下次再使用本系统！\n");
    return 0;
}

User create_user(int id)
{
    User user, frd, fan, follow;
    int num_fans, num_friends, num_follows;
    User hobby;
    int num_hobbys;

    user.id = id;
    set_init(user.fans);
    set_init(user.friends);
    set_init(user.follows);
    set_init(user.hobbys);

    srand((unsigned) time(NULL));
    num_fans = 1 + rand() % 10;
    for (int i = 0; i < num_fans; i++)
    {
        fan.id = 1 + rand() % 30;
        set_insert(user.fans, fan, taller);
    }
    set_remove(user.fans, id, shorter);

    Sleep(1000);
    srand((unsigned) time(NULL));
    num_friends = 1 + rand() % 10;
    for (int i = 0; i < num_friends; i++)
    {
        frd.id = 1 + rand() % 30;
        set_insert(user.friends, frd, taller);
    }
    set_remove(user.friends, id, shorter);

    Sleep(1000);
    srand((unsigned) time(NULL));
    num_follows = 1 + rand() % 10;
    for (int i = 0; i < num_follows; i++)
    {
        follow.id = 1 + rand() % 30;
        set_insert(user.follows, follow, taller);
    }
    set_remove(user.follows, id, shorter);

    Sleep(1000);
    srand((unsigned) time(NULL));
    num_hobbys = 1 + rand() % 10;
    for (int i = 0; i < num_hobbys; i++)
    {
        hobby.id = 1 + rand() % 10;
        set_insert(user.hobbys, hobby, taller);
    }

    return user;
}

void show_info(AVLNode *T)
{
    printf("该用户的朋友有：\n");
    TraverseAVL(T->user.friends);
    printf("该用户的粉丝有：\n");
    TraverseAVL(T->user.fans);
    printf("该用户关注的人有：\n");
    TraverseAVL(T->user.follows);
    printf("该用户的爱好有：\n");
    TraverseAVL(T->user.hobbys);
}

User input_user()
{
    int id_user, id_friend, id_fan, id_follow;
    User user, frd, fan, follow;
    int id_hobby;
    User hobby;

    printf("请输入用户的id：");
    scanf("%d", &id_user);getchar();
    user.id = id_user;
    set_init(user.friends);
    set_init(user.fans);
    set_init(user.follows);
    printf("请输入朋友的id：");
    while (1)
    {
        scanf("%d", &id_friend);getchar();
        if (id_friend > 0)
        {
            frd.id = id_friend;
            set_insert(user.friends, frd, taller);
        }
        else break;
    }
    printf("请输入粉丝的id：");
    while (1)
    {
        scanf("%d", &id_fan);getchar();
        if (id_fan > 0)
        {
            fan.id = id_fan;
            set_insert(user.fans, fan, taller);
        }
        else break;
    }
    printf("请输入关注的人的id：");
    while (1)
    {
        scanf("%d", &id_follow);getchar();
        if (id_follow > 0)
        {
            follow.id = id_follow;
            set_insert(user.follows, follow, taller);
        }
        else break;
    }
    printf("请输入爱好的id：");
    while (1)
    {
        scanf("%d", &id_hobby);getchar();
        if (id_hobby > 0)
        {
            hobby.id = id_hobby;
            set_insert(user.hobbys, hobby, taller);
        }
        else break;
    }

    return user;
}

void Select1or2(Set *&p)
{
    int i;
    printf("请选择集合(1 or 2)：");
    scanf("%d", &i);getchar();
    if (i == 1)
    {
        p = &T1;
    }
    else if (i == 2)
    {
        p = &T2;
    }
}

void SelectSet(Set *&p)
{
    int i;
    AVLNode *T;

    printf("你想对哪个集合进行操作：\n");
    printf("1. friends\n");
    printf("2. fans\n");
    printf("3. follows\n");
    printf("4. hobbys\n");
    printf("5. users\n");
    scanf("%d", &i);
    if (i == 5)
    {
        p = &U;
    }
    else
    {
        T = SelectUser(U);
        if (i == 1)
        {
           p = &T->user.friends;
        }
        else if (i == 2)
        {
            p = &T->user.fans;
        }
        else if (i == 3)
        {
            p = &T->user.follows;
        }
        else if (i == 4)
        {
            p = &T->user.hobbys;
        }
    }
}

AVLNode *SelectUser(Set U)
{
    int id;
    printf("请输入要选择的用户的id：");
    scanf("%d", &id);getchar();
    return SearchAVL(U, id);
}

status InitAVL(AVLTree &T)
{
    T = NULL;

    return true;
}

status DestroyAVL(AVLTree T)
{
    if (T == NULL) return TRUE;

    DestroyAVL(T->lchild);
    DestroyAVL(T->rchild);
    free(T);
    T = NULL;

    return TRUE;
}

AVLNode *SearchAVL(AVLTree T, int id)
{
    AVLTree p = T;
    while (p)
    {
        if (p->user.id == id) return p;
        else if (p->user.id < id) p = p->rchild;
        else if (p->user.id > id) p = p->lchild;
    }
    return p;
}

status InsertAVL(AVLTree &T, User user, bool &taller)
{
    if (!T)
    {
        T = (AVLTree)malloc(sizeof(AVLNode));
        T->user = user;
        T->lchild = NULL;
        T->rchild = NULL;
        T->bf = EH;
        taller = true;
    }
    else
    {
        if (user.id == T->user.id)
        {
            taller = FALSE;
            return ERROR;
        }
        if (user.id < T->user.id)
        {
            if (!InsertAVL(T->lchild, user, taller)) return ERROR;
            if (taller)
            {
                switch (T->bf)
                {
                    case LH:
                        LeftBalance(T);
                        taller = FALSE;
                        break;
                    case EH:
                        T->bf = LH;
                        taller = TRUE;
                        break;
                    case RH:
                        T->bf = EH;
                        taller = FALSE;
                        break;
                }
            }
        }
        else
        {
            if (!InsertAVL(T->rchild, user, taller)) return ERROR;
            if (taller)
            {
                switch (T->bf)
                {
                    case LH:
                        T->bf = EH;
                        taller = FALSE;
                        break;
                    case EH:
                        T->bf = RH;
                        taller = TRUE;
                        break;
                    case RH:
                        RightBalance(T);
                        taller = FALSE;
                        break;
                }
            }
        }
    }
    return OK;
}

void R_Rotate(AVLTree &T)
{
    AVLTree lchild = T->lchild;
    T->lchild = lchild->rchild;
    lchild->rchild = T;
    T = lchild;
}

void L_Rotate(AVLTree &T)
{
    AVLTree rchild = T->rchild;
    T->rchild = rchild->lchild;
    rchild->lchild = T;
    T = rchild;
}

void LeftBalance(AVLTree &T)
{
    AVLTree lchild = NULL;
    AVLTree lrchild = NULL;

    lchild = T->lchild;
    switch (lchild->bf)
    {
        case LH:
            T->bf = lchild->bf = EH;
            R_Rotate(T);
            break;
        case EH:
            T->bf = LH;
            lchild->bf = RH;
            R_Rotate(T);
            break;
        case RH:
            lrchild = lchild->rchild;
            switch (lrchild->bf)
            {
                case LH:
                    T->bf = RH;
                    lchild->bf = EH;
                    break;
                case EH:
                    T->bf = lchild->bf = EH;
                    break;
                case RH:
                    T->bf = EH;
                    lchild->bf = LH;
                    break;
            }
            lrchild->bf = EH;
            L_Rotate(T->lchild);
            R_Rotate(T);
            break;
    }
}

void RightBalance(AVLTree &T)
{
    AVLTree rchild = NULL;
    AVLTree rlchild = NULL;

    rchild = T->rchild;
    switch (rchild->bf)
    {
        case LH:
            rlchild = rchild->lchild;
            switch(rlchild->bf)
            {
                case LH:
                    T->bf = EH;
                    rchild->bf = RH;
                    break;
                case EH:
                    T->bf = EH;
                    rchild->bf = EH;
                    break;
                case RH:
                    T->bf = LH;
                    rchild->bf = EH;
                    break;
            }
            rlchild->bf = EH;
            R_Rotate(T->rchild);
            L_Rotate(T);
            break;
        case EH:        // DeleteAVL需要，InsertAVL不需要
            T->bf = RH;
            rchild->bf = LH;
            L_Rotate(T);
            break;
        case RH:
            T->bf = EH;
            rchild->bf = EH;
            L_Rotate(T);
            break;
    }
}

status DeleteAVL(AVLTree &T, int id, bool &shorter)
{
    if (T == NULL) return ERROR;
    else if (id == T->user.id)
    {
        AVLTree q = NULL;
        if (T->lchild == NULL)
        {
            q = T;
            T = T->rchild;
            shorter = true;
        }
        else if (T->rchild == NULL)
        {
            q = T;
            T = T->lchild;
            shorter = true;
        }
        else
        {
            q = T->lchild;
            while(q->rchild)
            {
                q = q->rchild;
            }
            T->user = q->user;
            DeleteAVL(T->lchild, q->user.id, shorter);
        }
    }
    else if (id < T->user.id)
    {
        if (!DeleteAVL(T->lchild, id, shorter))
        {
            return ERROR;
        }
        if (shorter)
        {
            switch (T->bf)
            {
                case LH:
                    T->bf = EH;
                    shorter = true;
                    break;
                case EH:
                    T->bf = RH;
                    shorter = false;
                    break;
                case RH:
                    RightBalance(T);
                    if (T->rchild->bf == EH)
                        shorter = false;
                    else
                        shorter = true;
                    break;
            }
        }
    }
    else
    {
        if (!DeleteAVL(T->rchild, id, shorter))
        {
            return ERROR;
        }
        if (shorter)
        {
            switch(T->bf)
            {
                case LH:
                    LeftBalance(T);
                    if (T->lchild->bf == EH)
                        shorter = false;
                    else
                        shorter = true;
                    break;
                case EH:
                    T->bf = LH;
                    shorter = false;
                    break;
                case RH:
                    T->bf = EH;
                    shorter = true;
                    break;
            }
        }
    }
    return OK;
}

status TraverseAVL(AVLTree T)
{
    InOrderTraverse(T);
    printf("\n");
    return OK;
}

void PreOrderTraverse(AVLTree T)
{
    if (T)
    {
        printf("%d ", T->user.id);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
     }
}

void InOrderTraverse(AVLTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        printf("%d ", T->user.id);
        InOrderTraverse(T->rchild);
    }
}

status set_init(Set &S)
{
    return InitAVL(S);
}

status set_destroy(Set &S)
{
    return DestroyAVL(S);
}

status set_insert(Set &S, User user, bool &taller)
{
    return InsertAVL(S, user, taller);
}

status set_remove(Set &S, int id, bool &shorter)
{
    return DeleteAVL(S, id, shorter);
}

status set_intersection(Set S, Set T, Set &D)
{
    if (!T) return OK;
    if (set_member(S, T->user.id))
    {
        set_insert(D, T->user, taller);
    }
    set_intersection(S, T->lchild, D);
    set_intersection(S, T->rchild, D);
    return OK;
}

status set_union(Set &S, Set T)
{
    if (!T) return OK;
    set_insert(S, T->user, taller);
    set_union(S, T->lchild);
    set_union(S, T->rchild);
    return OK;
}

status set_diffrence(Set &S, Set T)
{
    if (!S || !T) return OK;
    set_remove(S, T->user.id, shorter);
    set_diffrence(S, T->lchild);
    set_diffrence(S, T->rchild);
    return OK;
}

int set_size(Set S)
{
    int num = 0;
    if (!S) return 0;
    else
    {
        num = 1 + set_size(S->lchild) + set_size(S->rchild);
    }
    return num;
}

bool set_member(Set S, int id)
{
    if (!S) return false;
    if (S->user.id == id) return true;
    else if (id < S->user.id)
    {
        if (set_member(S->lchild, id)) return true;
    }
    else
    {
        if (set_member(S->rchild, id)) return true;
    }
    return false;
}

bool set_subset(Set S, Set T)
{
    if (!T) return true;
    if (set_member(S, T->user.id))
    {
        if (!set_subset(S, T->lchild)) return false;
        if (!set_subset(S, T->rchild)) return false;
        return true;
    }
    else return false;
}

bool set_equal(Set S, Set T)
{
   if (!set_subset(S, T)) return false;
   if (!set_subset(T, S)) return false;
   return true;
}

status SaveData(Set U)
{
    int num;

    if ((fp = fopen(filename, "wb")) == NULL)
	{
		printf("文件打开失败！\n");
		return ERROR;
	}
    num = set_size(U);
    fwrite(&num, sizeof(int), 1, fp);   // num_users
    SaveUsers(U);

    fclose(fp);
    return OK;
}

status ReadData(Set &U)
{
    int num_users, num_friends, num_fans, num_follows;
    int id_user, id_friend, id_fan, id_follow;
    User user, frd, fan, follow;
    int num_hobbys;
    int id_hobby;
    User hobby;

    if ((fp = fopen(filename, "rb")) == NULL)
	{
		printf("文件打开失败！\n");
		return ERROR;
	}
    fread(&num_users, sizeof(int), 1, fp);      // num_users
    for (int i = 0; i < num_users; i++)
    {
        fread(&id_user, sizeof(int), 1, fp);    // id_user
        user.id = id_user;

        fread(&num_friends, sizeof(int), 1, fp);    // num_friends
        set_init(user.friends);
        for (int j = 0; j < num_friends; j++)
        {
            fread(&id_friend, sizeof(int), 1, fp);  // id_friend
            frd.id = id_friend;
            frd.fans = frd.follows = frd.friends = NULL;
            set_insert(user.friends, frd, taller);
        }

        fread(&num_fans, sizeof(int), 1, fp);    // num_fans
        set_init(user.fans);
        for (int j = 0; j < num_fans; j++)
        {
            fread(&id_fan, sizeof(int), 1, fp);  // id_fan
            fan.id = id_fan;
            fan.fans = fan.follows = fan.friends = NULL;
            set_insert(user.fans, fan, taller);
        }

        fread(&num_follows, sizeof(int), 1, fp);    // num_follows
        set_init(user.follows);
        for (int j = 0; j < num_follows; j++)
        {
            fread(&id_follow, sizeof(int), 1, fp);  // id_follow
            follow.id = id_follow;
            follow.fans = follow.follows = follow.friends = NULL;
            set_insert(user.follows, follow, taller);
        }

        fread(&num_hobbys, sizeof(int), 1, fp);    // num_hobbys
        set_init(user.hobbys);
        for (int j = 0; j < num_hobbys; j++)
        {
            fread(&id_hobby, sizeof(int), 1, fp);  // id_hobby
            hobby.id = id_hobby;
            hobby.fans = hobby.follows = hobby.friends = NULL;
            set_insert(user.hobbys, hobby, taller);
        }

        set_insert(U, user, taller);
    }

    fclose(fp);
    return OK;
}

void TraverseFriends(Set S, Set &F)
{
    Set T;
    if (S)
    {
        T = SearchAVL(U, S->user.id);
        TraverseIndirectFriends(T->user.friends, F);
        TraverseFriends(S->lchild, F);
        TraverseFriends(S->rchild, F);
    }
}

void TraverseIndirectFriends(Set S, Set &F)
{
    if (S)
    {
        set_insert(F, S->user, taller);
        TraverseIndirectFriends(S->lchild, F);
        TraverseIndirectFriends(S->rchild, F);
    }
}

void SaveUsers(Set U)
{
    if (U)
    {
        SaveUser(U);
        SaveUsers(U->lchild);
        SaveUsers(U->rchild);
    }
}

void SaveUser(Set T)
{
    int num;

    fwrite(&(T->user.id), sizeof(int), 1, fp);    // id_user

    num = set_size(T->user.friends);
    fwrite(&num, sizeof(int), 1, fp);   // num_friends
    SaveUserId(T->user.friends);        // id_friend

    num = set_size(T->user.fans);
    fwrite(&num, sizeof(int), 1, fp);   // num_fans
    SaveUserId(T->user.fans);           // id_fan

    num = set_size(T->user.follows);
    fwrite(&num, sizeof(int), 1, fp);   // num_follows
    SaveUserId(T->user.follows);        // id_follow
    
    num = set_size(T->user.hobbys);
    fwrite(&num, sizeof(int), 1, fp);   // num_hobby
    SaveUserId(T->user.hobbys);         // id_hobby
}


void SaveUserId(Set T)
{
    if (T)
    {
        fwrite(&(T->user.id), sizeof(int), 1, fp);
        SaveUserId(T->lchild);
        SaveUserId(T->rchild);
    }
}
