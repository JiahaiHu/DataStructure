#include "BinaryTree.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

FILE *fp;
bool taller, shorter;
char filename[30] = "D:/SetData.txt";

int main()
{
    Set U = NULL;   // users set
    AVLTree T = NULL;
    Set S1 = NULL;
    Set S2 = NULL;
    int op = 1;
	int id;

	while (op)
	{
		system("cls");
		printf("\n\n");
		printf("      Menu for Set ADT On AVL Tree Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. set_init           7. set_difference\n");
		printf("    	  2. set_destroy        8. set_member\n");
		printf("    	  3. set_insert         9. set_subset \n");
		printf("    	  4. set_remove         10. set_equal\n");
		printf("    	  5. set_intersection   11. set_\n");
		printf("    	  6. set_union          12. indirect_friends\n");
		printf("    	  13. SaveData          14. ReadData\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~14]:");
		scanf("%d", &op);
		switch (op)
		{
            case 1:
                set_init(T);
                printf("输入任意键继续。。。");getch();
                break;
            case 2:
                set_destroy(T);
                printf("销毁成功！\n");
                break;
            case 3:
                User user;
                // todo: input user info
                if (set_insert(T, user, taller))
                {
                    printf("插入成功！\n");
                }
                else
                {
                    printf("插入失败！\n");
                }
                break;
            case 4:
                printf("请输入被删除人的id：");
                scanf("%d", &id);getchar();
                if (set_remove(T, id, shorter))
                {
                    printf("删除成功！\n");
                }
                else
                {
                    printf("删除失败！\n");
                }
                break;
            case 5:
                break;
            case 8:
                printf("请输入id：");
                scanf("%d", &id);getchar();
                if (set_member(T, id))
                {
                    printf("集合中有此人！\n");
                }
                else
                {
                    printf("集合中没有此人！\n");
                }
                break;
            case 9:
                break;
		    case 0:
                break;
        }
    }
    printf("欢迎下次再使用本系统！\n");
    return 0;
}

AVLNode *SelectUser(Set U)
{

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
        if (user.id == T->user.id)
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
    PreOrderTraverse(T);
    return OK;
}

void PreOrderTraverse(AVLTree T)  
{  
    if (!T)  
    {  
          printf("%d\t",T->user.id);  
          PreOrderTraverse(T->lchild);  
          PreOrderTraverse(T->rchild);  
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
    // todo
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
        for (int j = 0; j < num_friends; i++)
        {
            fread(&id_friend, sizeof(int), 1, fp);  // id_friend
            frd.id = id_friend;
            frd.fans = frd.follows = frd.friends = NULL;
            set_insert(user.friends, frd, taller);
        }

        fread(&num_fans, sizeof(int), 1, fp);    // num_fans
        set_init(user.fans);
        for (int j = 0; j < num_fans; i++)
        {
            fread(&id_fan, sizeof(int), 1, fp);  // id_fan
            fan.id = id_fan;
            fan.fans = fan.follows = fan.friends = NULL;
            set_insert(user.fans, fan, taller);
        }

        fread(&num_follows, sizeof(int), 1, fp);    // num_follows
        set_init(user.follows);
        for (int j = 0; j < num_follows; i++)
        {
            fread(&id_follow, sizeof(int), 1, fp);  // id_follow
            follow.id = id_follow;
            follow.fans = follow.follows = follow.friends = NULL;
            set_insert(user.follows, follow, taller);
        }

        set_insert(U, user, taller);
    }

    fclose(fp);
    return OK;
}

void SaveUsers(Set U)
{
    if (!U)
    {
        SaveUser(U);
        SaveUsers(U->lchild);
        SaveUsers(U->rchild);
    }
}

void SaveUser(Set T)
{
    int num;

    fwrite(&T->user.id, sizeof(int), 1, fp);    // id_user

    num = set_size(T->user.friends);
    fwrite(&num, sizeof(int), 1, fp);   // num_friends
    SaveFriendsId(T->user.friends);     // id_friend
    
    num = set_size(T->user.fans);
    fwrite(&num, sizeof(int), 1, fp);   // num_fans
    SaveFansId(T->user.fans);           // id_fan
    
    num = set_size(T->user.follows);
    fwrite(&num, sizeof(int), 1, fp);   // num_follows
    SaveFollowsId(T->user.follows);     // id_follow
}


void SaveUserId(Set T)
{
    if (!T)
    {
        fwrite(&T->user.id, sizeof(int), 1, fp);
        SaveUserId(T->lchild);
        SaveUserId(T->rchild);
    }
}

void SaveFriendsId(Set T)
{
    if (!T)
    {
        SaveUserId(T->user.friends);
        SaveFriendsId(T->lchild);
        SaveFriendsId(T->rchild);
    }
}

void SaveFansId(Set T)
{
    if (!T)
    {
        SaveUserId(T->user.fans);
        SaveFansId(T->lchild);
        SaveFansId(T->rchild);
    }
}

void SaveFollowsId(Set T)
{
    if (!T)
    {
        SaveUserId(T->user.follows);
        SaveFansId(T->lchild);
        SaveFansId(T->rchild);
    }
}

