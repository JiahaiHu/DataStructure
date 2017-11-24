/* Linear Table On Sequence Structure */
#include "SqList.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<conio.h>

FILE *fp;
char filename[30] = "D:/SqListData.txt";

int main(void)
{
	Lists Lists;
	SqList *pL;
	int op=1;
	int i;
	ElemType e;
	InitLists(Lists);
  	while(op)
	{
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitaList       7. LocateElem\n");
		printf("    	  2. DestroyList     8. PriorElem\n");
		printf("    	  3. ClearList       9. NextElem \n");
		printf("    	  4. ListEmpty       10. ListInsert\n");
		printf("    	  5. ListLength      11. ListDelete\n");
		printf("    	  6. GetElem         12. ListTrabverse\n");
		printf("    	  13. SaveData       14. ReadData\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("      请选择你的操作[0~14]:");
		scanf("%d",&op);
		switch (op)
		{
			case 1:
				if (Lists.length < LISTS_SIZE)
				{
                    if (InitaList(Lists.L[Lists.length]) == OK)
                    {
                        Lists.length++;
                        printf("线性表创建成功！\n");
                    }
                    else
                    {
                        printf("线性表创建失败！\n");
                    }
				}
				else
				{
					printf("不能再创建更多的线性表！");
				}

				printf("输入任意键继续。。。");getch();
				break;
			case 2:
				pL = SelectList(Lists);
				if (pL)
				{
				    if ((*pL).elem)
                    {
						for (i = 0; i < Lists.length; i++)
						{
							if (Lists.L + i == pL) break;
						}
                        DestroyList(*pL);
						for (int j = i ; j < Lists.length - 1; j++)
						{
							Lists.L[i].elem = Lists.L[i + 1].elem;
							Lists.L[i].length = Lists.L[i + 1].length;
						}

                        Lists.length--;
                        printf("线性表销毁成功！\n");
                    }
                    else
                    {
                        printf("线性表不存在！\n");
                    }
				}

				printf("输入任意键继续。。。");getch();
				break;
			case 3:
				pL = SelectList(Lists);
                if (pL)
                {
                    if ((*pL).elem)
                    {
                        ClearList(*pL);
                        printf("线性表重置成功！\n");
                    }
                    else
                    {
                        printf("线性表不存在！\n");
                    }
                }

				printf("输入任意键继续。。。");getch();
				break;
			case 4:
				pL = SelectList(Lists);
				if (pL)
                {
                    if ((*pL).elem)
                    {
                        if (ListEmpty(*pL))
                        {
                            printf("线性表是空表！\n");
                        }
                        else
                        {
                            printf("线性表不是空表！\n");
                        }
                    }
                    else
                    {
                        printf("线性表不存在！\n");
                    }
                }

				printf("输入任意键继续。。。");getch();
				break;
			case 5:
				pL = SelectList(Lists);
				if (pL)
                {
                    if ((*pL).elem)
                    {
                        printf("线性表长度为%d\n", ListLength(*pL));
                    }
                    else
                    {
                        printf("线性表不存在！\n");
                    }
                }

				printf("输入任意键继续。。。");getch();
				break;
			case 6:
				pL = SelectList(Lists);
				if (pL)
                {
                    if ((*pL).elem)
                    {
                        printf("请输入元素的位置：\n");
                        scanf("%d", &i);
                        if (GetElem(*pL, i, e) == OK)
                        {
                            printf("第%d个位置的元素是%d\n", i, e);
                        }
                        else
                        {
                            printf("输入的位置不合法！\n");
                        }
                    }
                    else
                    {
                        printf("线性表不存在！\n");
                    }
                }

				printf("输入任意键继续。。。");getch();
				break;
			case 7:
				pL = SelectList(Lists);
				if (pL)
                {
                    if ((*pL).elem)
                    {
                        printf("请输入需要查询的元素：\n");
                        scanf("%d", &e);
                        i = LocateElem(*pL, e);
                        if (i)
                        {
                            printf("该元素在第%d个位置！\n", i);
                        }
                        else
                        {
                            printf("线性表中不存在该元素！\n");
                        }
                    }
                    else
                    {
                        printf("线性表不存在！\n");
                    }
                }

				printf("输入任意键继续。。。");getch();
				break;
			case 8:
				pL = SelectList(Lists);
				if (pL)
                {
                    if ((*pL).elem)
                    {
                        ElemType cur_e, pre_e;
                        printf("请输入需要获得其前驱元素的元素：\n");
                        scanf("%d", &cur_e);
                        if (PriorElem(*pL, cur_e, pre_e) == OK)
                        {
                            printf("该元素的前驱元素是%d\n", pre_e);
                        }
                        else
                        {
                            printf("线性表中不存在该元素或该元素没有前驱元素！\n");
                        }
                    }
                    else
                    {
                        printf("线性表不存在！\n");
                    }
                }

				printf("输入任意键继续。。。");getch();
				break;
			case 9:
				pL = SelectList(Lists);
				if (pL)
                {
                    if ((*pL).elem)
                    {
                        ElemType cur_e, next_e;
                        printf("请输入需要获得其后继元素的元素：\n");
                        scanf("%d", &cur_e);
                        if (NextElem(*pL, cur_e, next_e) == OK)
                        {
                            printf("该元素的后继元素是%d\n", next_e);
                        }
                        else
                        {
                            printf("线性表中不存在该元素或该元素没有后继元素！\n");
                        }
                    }
                    else
                    {
                        printf("线性表不存在！\n");
                    }
                }

				printf("输入任意键继续。。。");getch();
				break;
			case 10:
				pL = SelectList(Lists);
				if (pL)
                {
                    if ((*pL).elem)
                    {
                        printf("请输入插入的位置：\n");
                        scanf("%d", &i);
                        printf("请输入需要插入的元素：\n");
                        scanf("%d", &e);
                        if (ListInsert(*pL, i, e) ==  OK)
                        {
                            printf("插入成功！\n");
                        }
                        else
                        {
                            printf("输入的位置不合法！\n");
                        }
                    }
                    else
                    {
                        printf("线性表不存在！\n");
                    }
                }

				printf("输入任意键继续。。。");getch();
				break;
			case 11:
				pL = SelectList(Lists);
				if (pL)
                {
                    if ((*pL).elem)
                    {
                        if ((*pL).length) {
                            printf("请输入删除的位置：\n");
                            scanf("%d", &i);
                            if (ListDelete(*pL, i, e) == OK)
                            {
                                printf("删除成功！");
                            }
                            else
                            {
                                printf("输入的位置不合法！\n");
                            }
                        }
                        else
                        {
                            printf("线性表是空表");
                        }
                    }
                    else
                    {
                        printf("线性表不存在！\n");
                    }
                }

				printf("输入任意键继续。。。");getch();
				break;
			case 12:
				pL = SelectList(Lists);
				if (pL)
                {
                    if (!ListTrabverse(*pL))
                    {
                        printf("线性表是空表！\n");
                    }
                    else
                    {
                        printf("遍历完成！\n");
                    }
                }

				printf("输入任意键继续。。。");getch();
				break;
			case 13:
                if (SaveData(Lists) == OK)
                {
					printf("线性表数据保存成功！\n");
				}
				else
				{
					printf("线性表数据保存失败！\n");
				}

				printf("输入任意键继续。。。");getch();
				break;
			case 14:
				if (ReadData(Lists) == OK)
				{
					printf("线性表数据读取成功！\n");
				}
				else
				{
					printf("线性表数据读取失败！\n");
				}

				printf("输入任意键继续。。。");getch();
				break;
			case 0:
				break;
		} // end of switch
	} // end of while
  	printf("欢迎下次再使用本系统！\n");
} // end of main()

/*
 * 初始条件：
 * 操作结果：构造一个空的线性表数组
 */
status InitLists(Lists &Lists)
{
	int i;

	Lists.L = (SqList *)malloc(LISTS_SIZE * sizeof(SqList));
	for (i = 0; i < LISTS_SIZE; i++)
	{
		Lists.L[i].elem = NULL;
	}
	Lists.length = 0;

	return OK;
}

/*
 * 初始条件：
 * 操作结果：根据用户输入选择一个线性表
 */
SqList * SelectList(Lists &Lists)
{
	int i;

	printf("您想对第几个线性表进行该项操作：\n");
	scanf("%d", &i);

	if (Lists.length == 0)
	{
		printf("当前没有线性表！\n");
		return NULL;
	}
	else if (i > Lists.length)
	{
		printf("输入的位置不合法！\n");
		return NULL;
	}

	printf("第%d个线性表选取成功！\n", i);

	return Lists.L + i - 1;
}

/*
 * 初始条件：线性表L不存在
 * 操作结果：构造一个空的线性表
 */
status InitaList(SqList &L)
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE & sizeof(ElemType));		// 分配空间
	if (!L.elem) exit(OVERFLOW);	// 存储分配失败
	L.length = 0;					// 空表长度为0
	L.listsize = LIST_INIT_SIZE;	// 初始存储容量

	return OK;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：销毁线性表L
 */
status DestroyList(SqList &L)
{
	free(L.elem);
	L.elem = NULL;

	return OK;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：将L重置为空表
 */
status ClearList(SqList &L)
{
	if (!ListEmpty(L))	// L不为空表
	{
		L.length = 0;
	}

	return OK;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：若L为空表则返回TRUE,否则返回FALSE
 */
status ListEmpty(SqList L)
{
	if (L.length == 0) return TRUE;
	return FALSE;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：返回L中数据元素的个数
 */
int ListLength(SqList L)
{
	return L.length;
}

/*
 * 初始条件：线性表L已存在，1≤i≤ListLength(L)
 * 操作结果：用e返回L中第i个数据元素的值
 */
status GetElem(SqList L, int i, ElemType &e)
{
	if (i < 0 || i > L.length) return ERROR;

	e = L.elem[i-1];

	return OK;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：返回L中数据元素的位置，若这样的数据元素不存在，则返回值为0
 */
int LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e) return i + 1;
	}

	return 0;	// 未找到
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义
 */
status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
	int i;

	i = LocateElem(L, cur_e);
	if (i == 0 || i == 1) return ERROR;

	pre_e = L.elem[i-2];

	return OK;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义
 */
status NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
	int i;

	i = LocateElem(L, cur_e);
	if (i == 0 || i == L.length) return ERROR;

	next_e = L.elem[i];

	return OK;
}

/*
 * 初始条件：线性表L已存在，1≤i≤ListLength(L)+1
 * 操作结果：在L的第i个位置之前插入新的数据元素e
 */
status ListInsert(SqList &L, int i, ElemType e)
{
	ElemType *p, *q, *newbase;

	if (i < 1 || i > L.length + 1) return ERROR;	// i值不合法

	if (L.length == L.listsize)
	{
		newbase = (ElemType *)realloc(L.elem,
			(L.listsize + LISTINCREMENT) * sizeof(ElemType));	// 当前存储空间已满，增加分配
		if (!newbase) exit(OVERFLOW);	// 存储分配失败
		L.elem = newbase;				// 新基址
		L.listsize += LISTINCREMENT;	// 增加存储容量
	}
	q = &(L.elem[i-1]);			// 获取插入位置

	for (p = &(L.elem[L.length - 1]); p >= q; p--)
	{
		*(p + 1) = *p;			// 插入位置及之后的元素后移
	}
	*q = e;				// 插入e
	L.length++;			// 表长增1

	return OK;
}

/*
 * 初始条件：线性表L已存在且非空，1≤i≤ListLength(L)
 * 操作结果：删除L的第i个数据元素，用e返回其值
 */
status ListDelete(SqList &L, int i, ElemType &e)
{
	ElemType *p, *q;

	if (i < 1 || i > L.length) return ERROR;	// i值不合法

	p = &(L.elem[i - 1]);			// 获取元素位置
	e = *p;							// 获取删除元素
	q = &(L.elem[L.length - 1]); 	// 表尾元素的位置
	for (++p; p <= q; p++)
	{
		*(p - 1) = *p;			// 被删除元素之后的元素前移
	}
	L.length--;		// 表长减1

	return OK;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：对L中的每个数据元素进行遍历
 */
int ListTrabverse(SqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("%d\n", L.elem[i]);
	}

	return L.length;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：保存线性表数据
 */
status SaveData(Lists &Lists)
{
	int i;
	if ((fp = fopen(filename, "wb")) == NULL)
	{
		printf("文件打开失败！");
		return ERROR;
	}
	for (i = 0; i < Lists.length; i++)
	{
		fwrite(&(Lists.L[i].length), sizeof(int), 1, fp);
		fwrite(&(Lists.L[i].listsize), sizeof(int), 1, fp);
		fwrite(Lists.L[i].elem, sizeof(ElemType), Lists.L[i].length, fp);
	}
	fclose(fp);

	return OK;
}

/*
 * 初始条件：线性表L不存在
 * 操作结果：读取线性表数据
 */
status ReadData(Lists &Lists)
{
    SqList *pL;
	Lists.length = 0;
	int i;
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		printf("文件打开失败");
		return ERROR;
	}

	while (fread(&(Lists.L[Lists.length].length), sizeof(int), 1, fp))
	{
	    pL = &Lists.L[Lists.length];

        fread(&((*pL).listsize), sizeof(int), 1, fp);
		(*pL).elem = (ElemType *)malloc((*pL).listsize * sizeof(ElemType));		// 分配空间
		if (!(*pL).elem) exit(OVERFLOW);	// 存储分配失败

		for (i = 0; i < (*pL).length; i++)
        {
            fread(&((*pL).elem[i]), sizeof(ElemType), 1, fp);
        }
		Lists.length++;
	}
	fclose(fp);

	return OK;
}
