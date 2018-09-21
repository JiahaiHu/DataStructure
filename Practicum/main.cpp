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
char username[100][7] = {
    "赵一", "赵二", "赵三", "赵四", "赵五", "赵六", "赵七", "赵八", "赵九", "赵十",
    "钱一", "钱二", "钱三", "钱四", "钱五", "钱六", "钱七", "钱八", "钱九", "钱十",
    "孙一", "孙二", "孙三", "孙四", "孙五", "孙六", "孙七", "孙八", "孙九", "孙十",
    "李一", "李二", "李三", "李四", "李五", "李六", "李七", "李八", "李九", "李十",
    "周一", "周二", "周三", "周四", "周五", "周六", "周七", "周八", "周九", "周十",
    "吴一", "吴二", "吴三", "吴四", "吴五", "吴六", "吴七", "吴八", "吴九", "吴十",
    "郑一", "郑二", "郑三", "郑四", "郑五", "郑六", "郑七", "郑八", "郑九", "郑十",
    "王一", "王二", "王三", "王四", "王五", "王六", "王七", "王八", "王九", "王十",
    "陈一", "陈二", "陈三", "陈四", "陈五", "陈六", "陈七", "陈八", "陈九", "陈十",
    "张一", "张二", "张三", "张四", "张五", "张六", "张七", "张八", "张九", "张十"
};
char hobbyname[10][7] = {
    "篮球", "音乐", "电影", "国画", "写作", "阅读", "跑步", "跳舞", "聊天", "游戏"
};

Set U = NULL;   // users set
Set S = NULL;
Set T1 = NULL;   // test set
Set T2 = NULL;   // test set

int main()
{
    Set *p = NULL;   // pointer
    int op = 1;
	int id, i;
	int id_user = 0;
	User user;

	while (op)
	{
		system("cls");
		printf("\n\n");
		printf("      Menu for Set ADT On AVL Tree Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitAVL            16. set_equal\n");
		printf("    	  2. DestroyAVL         17. set_traverse\n");
		printf("    	  3. SearchAVL          18. member_add\n");
		printf("    	  4. InsertAVL          19. member_delete\n");
		printf("    	  5. DeleteAVL          20. member_search\n");
		printf("    	  6. TraverseAVL        21. member_modify\n");
		printf("    	  7. set_init           22. show_info\n");
		printf("    	  8. set_destroy        23. indirect_friends\n");
		printf("    	  9. set_insert         24. common_follow\n");
		printf("    	  10. set_remove        25. commom_hobby\n");
		printf("    	  11. set_intersection  26. Traverse\n");
		printf("    	  12. set_union         27. CreateRandomData\n");
		printf("    	  13. set_difference    28. SaveData\n");
		printf("    	  14. set_member        29. ReadData\n");
		printf("    	  15. set_subset        30. Complete\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~29]:");
		scanf("%d", &op);
		switch (op)
		{
            case 99:
                complete(U);
                break;
            case 1:     // InitAVL
                p = &T1;
                InitAVL(*p);
                printf("初始化成功！\n");

                printf("输入任意键继续。。。");getch();
                break;
            case 2:     // DestroyAVL
                if (p)
                {
                    DestroyAVL(*p);
                    printf("销毁成功！\n");
                    p = NULL;
                }
                else
                {
                    printf("不存在AVL树！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 3:     // SearchAVL
                if (p)
                {
                    printf("请输入需要查找的结点的key：");
                    scanf("%d", &id);getchar();
                    if (set_member(*p, id))
                    {
                        printf("该树中有此结点！\n");
                    }
                    else
                    {
                        printf("该树中没有此结点！\n");
                    }
                }
                else
                {
                    printf("不存在AVL树！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 4:     // InsertAVL
                if (p)
                {
                    printf("请输入要插入的结点的key：");
                    scanf("%d", &user.id);getchar();
                    if (set_insert(*p, user, taller))
                    {
                        printf("插入成功！\n");
                    }
                    else
                    {
                        printf("插入失败！\n");
                    }
                }
                else
                {
                    printf("不存在AVL树！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 5:    // DeleteAVL
                if (p)
                {
                    printf("请输入被删除的结点的key：");
                    scanf("%d", &id);getchar();
                    if (set_remove(*p, id, shorter))
                    {
                        printf("删除成功！\n");
                    }
                    else
                    {
                        printf("删除失败！\n");
                    }
                }
                else
                {
                    printf("不存在AVL树！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 6:     // TraverseAVL
                if (p)
                {
                    printf("该AVL树的前序遍历序列为：\n");
                    PreOrder(*p);
                    printf("\n");
                    printf("该AVL树的中序遍历序列为：\n");
                    InOrder(*p);
                    printf("\n");
                }
                else
                {
                    printf("不存在AVL树！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 7:     // set_init
                Select1or2(p);
                set_init(*p);
                printf("初始化成功！\n");

                printf("输入任意键继续。。。");getch();
                break;
            case 8:     // set_destroy
                Select1or2(p);
                set_destroy(*p);
                printf("销毁成功！\n");

                printf("输入任意键继续。。。");getch();
                break;
            case 9:     // set_insert
                Select1or2(p);
                printf("请输入集合元素的key：");
                scanf("%d", &user.id);getchar();
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
            case 10:    // set_remove
                Select1or2(p);
                printf("请输入被删除元素的key：");
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
            case 11:    // set_intersection
                set_init(S);
                if (set_intersection(T1, T2, S))
                {
                    printf("交集操作成功！\n");
                    printf("结果集合为：\n");
                    InOrder(S);
                    printf("\n");
                    printf("其内部实现AVL树的前序遍历序列为：\n");
                    PreOrder(S);
                    printf("\n");
                }
                else
                {
                    printf("交集操作失败！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 12:    // union
                if (set_union(T1, T2))
                {
                    printf("并集操作成功！\n");
                    printf("结果集合为：\n");
                    InOrder(T1);
                    printf("\n");
                    printf("其内部实现AVL树的前序遍历序列为：\n");
                    PreOrder(T1);
                    printf("\n");
                }
                else
                {
                    printf("并集操作失败！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 13:    // difference
                if (set_diffrence(T1, T2))
                {
                    printf("差集操作成功！\n");
                    printf("结果集合为：\n");
                    InOrder(T1);
                    printf("\n");
                    printf("其内部实现AVL树的前序遍历序列为：\n");
                    PreOrder(T1);
                    printf("\n");
                }
                else
                {
                    printf("差集操作失败！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 14:    // member
                Select1or2(p);
                printf("请输入元素的key：");
                scanf("%d", &id);getchar();
                if (set_member(*p, id))
                {
                    printf("集合中有此元素！\n");
                }
                else
                {
                    printf("集合中没有此元素！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 15:    // subset
                if (set_subset(T1, T2))
                {
                    printf("集合2是集合1的子集！\n");
                }
                else
                {
                    printf("集合2不是集合1的子集！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 16:    // equal
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
            case 18:    // member_add
                i = SelectSet(p, id_user);
                if (i == 5)     // users
                {
                    user = input_user();
                }
                else if (i == 4)    // hobbys
                {
                    printf("请输入新增爱好的id：");
                    scanf("%d", &user.id);
                    printf("请输入爱好：");
                    scanf("%s", user.name);
                }
                else
                {
                    printf("请输入新增成员的id：");
                    scanf("%d", &user.id);
                }
                if (set_insert(*p, user, taller))
                {
                    complete(U);
                    printf("成员添加成功！\n");
                }
                else
                {
                    printf("成员添加失败！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 19:    // member_delete
                i = SelectSet(p, id_user);  // i: set type
                if (*p)
                {
                    printf("请输入被删除人的id：");
                    scanf("%d", &id);getchar();

                    // 同步信息
                    T1 = SearchAVL(U, id);  // 被删除人
                    if (i == 1) // friends
                    {
                        // 同步被删除人的朋友集
                        set_remove(T1->user.friends, id_user, shorter);
                    }
                    else if (i == 2) // fans
                    {
                        // 同步被删除人的关注集
                        set_remove(T1->user.follows, id_user, shorter);
                    }
                    else if (i == 3) // follows
                    {
                        // 同步被删除人的粉丝集
                        set_remove(T1->user.fans, id_user, shorter);
                    }
                    else if (i == 5) // users
                    {
                        // 同步除被删除人外其他所有人的集合信息
                        for (int j = 1; j <= NUM_USER; j++)
                        {
                            if (j != id)
                            {
                                T2 = SearchAVL(U, j);
                                // 同步朋友集
                                set_remove(T2->user.friends, id, shorter);
                                // 同步关注集
                                set_remove(T2->user.follows, id, shorter);
                                // 同步粉丝集
                                set_remove(T2->user.fans, id, shorter);
                            }
                        }
                    }

                    // 删除该成员
                    if (set_remove(*p, id, shorter))
                    {
                        printf("成员删除成功！\n");
                    }
                    else
                    {
                        printf("成员删除失败！\n");
                    }
                }
                else
                {
                    printf("该集合中不存在此id！\n");
                }


                printf("输入任意键继续。。。");getch();
                break;
            case 20:    // member_search
                i = SelectSet(p, id_user);
                if (i == 4){
                    printf("请输入需要查找的爱好的id：");
                    scanf("%d", &id);getchar();
                    S = SearchAVL(*p, id);
                    if (S)
                    {
                        printf("该爱好在此集合中！\n");
                        printf("该爱好为%s\n", S->user.name);
                    }
                    else
                    {
                        printf("搜索不到该爱好！\n");
                    }
                }
                else
                {
                    printf("请输入需要查找的用户的id：");
                    scanf("%d", &id);getchar();
                    S = SearchAVL(*p, id);
                    if (S)
                    {
                        printf("该成员在此集合中！\n");
                        show_info(SearchAVL(U, id));
                    }
                    else
                    {
                        printf("搜索不到该成员！\n");
                    }
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 21:    // member_modify
                SelectSet(p, id_user);
                printf("请输入需要修改的信息的id：");
                scanf("%d", &id);getchar();
                S = SearchAVL(*p, id);
                if (S)
                {
                    printf("请输入修改后的新姓名：");
                    scanf("%s", S->user.name);getchar();
                    printf("修改成功！\n");
                }
                else
                {
                    printf("该用户不存在！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 22:    // show_info
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
            case 23:    // indirect_friends
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
            case 25:    // common_hobby
                set_init(T1);
                set_init(T2);
                set_init(S);
                T1 = SelectUser(U);
                T2 = SelectUser(U);
                set_intersection(T1->user.hobbys, T2->user.hobbys, S);
                if (S)
                {
                    printf("两个用户共同的爱好有：\n");
                    TraverseHobby(S, T1->user.hobbys);
                    printf("\n");
                }
                else
                {
                    printf("两个用户没有共同的爱好！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 24:    // common_follow
                set_init(T1);
                set_init(T2);
                set_init(S);
                T1 = SelectUser(U);
                T2 = SelectUser(U);
                set_intersection(T1->user.follows, T2->user.follows, S);
                if (S)
                {
                    printf("两个用户共同关注的人有：\n");
                    TraverseAVL(S);
                }
                else
                {
                    printf("两个用户没有共同关注的人！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 28:    // Save
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
            case 29:    // Load
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
            case 27:    // create random data
                for (int id = 1; id <= NUM_USER; id++)
                {
                    Sleep(1000);
                    set_insert(U, create_user(id), taller);
                }
                complete(U);
                printf("随机生成数据成功！\n");

                printf("输入任意键继续。。。");getch();
                break;
            case 26:    // Traverse
                SelectSet(p, id_user);
                printf("该集合的前序遍历序列为：\n");
                PreOrderTraverse(*p);
                printf("\n");
                printf("该集合的中序遍历序列为：\n");
                InOrderTraverse(*p);
                printf("\n");

                printf("输入任意键继续。。。");getch();
                break;
            case 17:    // set_traverse
                Select1or2(p);
                printf("该集合的前序遍历序列为：\n");
                PreOrder(*p);
                printf("\n");
                printf("该集合的中序遍历序列为：\n");
                InOrder(*p);
                printf("\n");

                printf("输入任意键继续。。。");getch();
                break;
            case 30:    // LoadTreeTestCase
                if (p)
                {
                    InitAVL(T1);
                    user.id = 4;
                    set_insert(T1, user, taller);
                    user.id = 5;
                    set_insert(T1, user, taller);
                    user.id = 11;
                    set_insert(T1, user, taller);
                    user.id = 12;
                    set_insert(T1, user, taller);
                    user.id = 13;
                    set_insert(T1, user, taller);
                    user.id = 15;
                    set_insert(T1, user, taller);
                    user.id = 22;
                    set_insert(T1, user, taller);
                    user.id = 28;
                    set_insert(T1, user, taller);
                    printf("成功加载测试数据！\n");
                }
                else
                {
                    printf("不存在AVL树！\n");
                }

                printf("输入任意键继续。。。");getch();
                break;
            case 31:    // LoadSetTestCase
                InitAVL(T1);
                user.id = 5;
                set_insert(T1, user, taller);
                user.id = 4;
                set_insert(T1, user, taller);
                user.id = 12;
                set_insert(T1, user, taller);
                user.id = 11;
                set_insert(T1, user, taller);
                user.id = 15;
                set_insert(T1, user, taller);
                InitAVL(T2);
                user.id = 5;
                set_insert(T2, user, taller);
                user.id = 4;
                set_insert(T2, user, taller);
                user.id = 15;
                set_insert(T2, user, taller);
                user.id = 1;
                set_insert(T2, user, taller);
                user.id = 20;
                set_insert(T2, user, taller);
                printf("成功加载测试数据！\n");

                printf("输入任意键继续。。。");getch();
                break;
		    case 0:     // exit
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
    strcpy(user.name, username[id-1]);
    set_init(user.fans);
    set_init(user.friends);
    set_init(user.follows);
    set_init(user.hobbys);

    srand((unsigned) time(NULL));
    num_fans = 1 + rand() % 10;
    for (int i = 0; i < num_fans; i++)
    {
        fan.id = 1 + rand() % NUM_USER;
        set_insert(user.fans, fan, taller);
    }
    set_remove(user.fans, id, shorter);

    Sleep(1000);
    srand((unsigned) time(NULL));
    num_friends = 1 + rand() % 10;
    for (int i = 0; i < num_friends; i++)
    {
        frd.id = 1 + rand() % NUM_USER;
        set_insert(user.friends, frd, taller);
    }
    set_remove(user.friends, id, shorter);

    Sleep(1000);
    srand((unsigned) time(NULL));
    num_follows = 1 + rand() % 10;
    for (int i = 0; i < num_follows; i++)
    {
        follow.id = 1 + rand() % NUM_USER;
        set_insert(user.follows, follow, taller);
    }
    set_remove(user.follows, id, shorter);

    Sleep(1000);
    srand((unsigned) time(NULL));
    num_hobbys = 1 + rand() % 10;
    for (int i = 0; i < num_hobbys; i++)
    {
        hobby.id = 1 + rand() % 10;
        strcpy(hobby.name, hobbyname[hobby.id-1]);
        set_insert(user.hobbys, hobby, taller);
    }

    return user;
}

void show_info(AVLNode *T)
{
    printf("该用户的名字为：%s\n", T->user.name);
    printf("该用户的朋友有：\n");
    TraverseAVL(T->user.friends);
    printf("该用户的粉丝有：\n");
    TraverseAVL(T->user.fans);
    printf("该用户关注的人有：\n");
    TraverseAVL(T->user.follows);
    printf("该用户的爱好有：\n");
    InOrderTraverseHobby(T->user.hobbys);
    printf("\n");
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
    printf("请输入用户的姓名：");
    scanf("%s", user.name);getchar();
    set_init(user.friends);
    set_init(user.fans);
    set_init(user.follows);
    set_init(user.hobbys);
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
            printf("请输入爱好：");
            scanf("%s", hobby.name);getchar();
            set_insert(user.hobbys, hobby, taller);
        }
        else break;
    }

    return user;
}

void SelectTree1or2(Set *&p)
{
    int i;
    printf("请选择AVL树(1 or 2)：");
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

int SelectSet(Set *&p, int &id)
{
    int i;  // set type(special for member_delete)
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
        id = T->user.id;
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
    return i;
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
            T->bf = EH;
            lchild->bf = EH;
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
                    T->bf = EH;
                    lchild->bf = EH;
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
            free(q);
            shorter = true;
        }
        else if (T->rchild == NULL)
        {
            q = T;
            T = T->lchild;
            free(q);
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
                        if (T->rchild->bf == EH)
                            shorter = false;
                        else
                            shorter = true;
                        RightBalance(T);
                        break;
                }
            }
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
                    if (T->rchild->bf == EH)
                        shorter = false;
                    else
                        shorter = true;
                    RightBalance(T);
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
                    if (T->lchild->bf == EH)
                        shorter = false;
                    else
                        shorter = true;
                    LeftBalance(T);
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

void InOrder(AVLTree T)
{
    if (T)
    {
        InOrder(T->lchild);
        printf("%d ", T->user.id);
        InOrder(T->rchild);
    }
}

void PreOrder(AVLTree T)
{
    if (T)
    {
        printf("%d ", T->user.id);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void TraverseHobby(Set S, AVLNode *T)
{
    if (S)
    {
        TraverseHobby(S->lchild, T);
        PrintHobby(T, S->user.id);
        TraverseHobby(S->rchild, T);
    }
}

void PrintHobby(AVLNode *T, int id)
{
    if (T)
    {
        PrintHobby(T->lchild, id);
        if (T->user.id == id)
        {
            printf("%d%s ", id, T->user.name);
        }
        PrintHobby(T->rchild, id);
    }
}

void PreOrderTraverseHobby(Set S)
{
    if (S)
    {
        printf("%d%s", S->user.id, S->user.name);
        PreOrderTraverseHobby(S->lchild);
        PreOrderTraverseHobby(S->rchild);
    }
}

void InOrderTraverseHobby(Set S)
{
    if (S)
    {
        InOrderTraverseHobby(S->lchild);
        printf("%d%s ", S->user.id, S->user.name);
        InOrderTraverseHobby(S->rchild);
    }
}

status TraverseAVL(AVLTree T)
{
    InOrderTraverse(T);
    printf("\n");
    return OK;
}

void PreOrderTraverse(AVLTree T)
{
    AVLNode *p;
    if (T)
    {
        p = SearchAVL(U, T->user.id);
        printf("%d%s ", T->user.id, p->user.name);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
     }
}

void InOrderTraverse(AVLTree T)
{
    AVLNode *p;
    if (T)
    {
        InOrderTraverse(T->lchild);
        p = SearchAVL(U, T->user.id);
        printf("%d%s ", T->user.id, p->user.name);
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

        fread(user.name, sizeof(char), 7, fp);  // name_user

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
            fread(hobby.name, sizeof(char), 7, fp);// name_hobby
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
    fwrite(T->user.name, sizeof(char), 7, fp);    // name_user

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
    SaveHobby(T->user.hobbys);          // id_hobby and name_hobby
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

void SaveHobby(Set T)
{
    if (T)
    {
        fwrite(&(T->user.id), sizeof(int), 1, fp);
        fwrite(T->user.name, sizeof(char), 7, fp);
        SaveHobby(T->lchild);
        SaveHobby(T->rchild);
    }
}

void complete(AVLNode *T)
{
    if (T)
    {
        complete_friend(T->user.friends, T->user.id);
        complete_fan(T->user.follows, T->user.id);
        complete_follow(T->user.fans, T->user.id);
        complete(T->lchild);
        complete(T->rchild);
    }

}

void complete_friend(AVLNode *T, int id)
{
    User user;
    AVLNode *p;
    if (T)
    {
        user.id = id;
        p = SearchAVL(U, T->user.id);
        set_insert(p->user.friends, user, taller);
        complete_friend(T->lchild, id);
        complete_friend(T->rchild, id);
    }
}

void complete_fan(AVLNode *T, int id)   // T为follows集
{
    User user;
    AVLNode *p;
    if (T)
    {
        user.id = id;
        p = SearchAVL(U, T->user.id);
        set_insert(p->user.fans, user, taller);
        complete_fan(T->lchild, id);
        complete_fan(T->rchild, id);
    }
}

void complete_follow(AVLNode *T, int id)    // T为fans集
{
    User user;
    AVLNode *p;
    if (T)
    {
        user.id = id;
        p = SearchAVL(U, T->user.id);
        set_insert(p->user.follows, user, taller);
        complete_fan(T->lchild, id);
        complete_fan(T->rchild, id);
    }
}
