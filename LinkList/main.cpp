/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "LinkList.h"
#include <conio.h>

FILE *fp;
char filename[30] = "D:/LinkListData.txt";

int main(void)
{
	Lists Lists = NULL;		// 十字链表头指针
	LinkList L = NULL;	// 单链表头指针
	int op = 1;
	int i;
	ElemType e;
	InitLists(Lists);
	while (op)
	{
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On Link Structure \n");
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
		printf("    请选择你的操作[0~14]:");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			if (InitaList(L) == OK)
			{
				InsertaList(Lists, L);
				printf("线性表创建成功！\n");
			}
			else
			{
				printf("线性表创建失败！\n");
			}
			printf("输入任意键继续。。。");getch();
			break;
		case 2:
			L = SelectList(Lists);
			if (L)
			{
				/*获取L所在ListsNode的前驱结点*/
				// todo
				DestroyList(L);
				/*让前驱结点的next指向后继结点*/
				// todo
				printf("线性表销毁成功！\n");
			}
			else
			{
				printf("线性表不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 3:
			L = SelectList(Lists);
			if (L)
			{
				ClearList(L);
				printf("线性表重置成功！\n");
			}
			else
			{
				printf("线性表不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 4:
			L = SelectList(Lists);
			if (L)
			{
				if (ListEmpty(L))
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

			printf("输入任意键继续。。。");getch();
			break;
		case 5:
			L = SelectList(Lists);
			if (L)
			{
				printf("线性表长度为%d\n", ListLength(L));
			}
			else
			{
				printf("线性表不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 6:
			L = SelectList(Lists);
			if (L)
			{
				printf("请输入元素的位置：\n");
				scanf("%d", &i);
				if (GetElem(L, i, e) == OK)
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

			printf("输入任意键继续。。。");getch();
			break;
		case 7:
			L = SelectList(Lists);
			if (L)
			{
				printf("请输入需要查询的元素：\n");
                scanf("%d", &e);
                i = LocateElem(L, e);
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

			printf("输入任意键继续。。。");getch();
			break;
		case 8:
			L = SelectList(Lists);
			if (L)
			{
				ElemType cur_e, pre_e;
				printf("请输入需要获得其前驱元素的元素：\n");
				scanf("%d", &cur_e);
				if (PriorElem(L, cur_e, pre_e) == OK)
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

			printf("输入任意键继续。。。");getch();
			break;
		case 9:
			L = SelectList(Lists);
			if (L)
			{
				ElemType cur_e, next_e;
				printf("请输入需要获得其后继元素的元素：\n");
				scanf("%d", &cur_e);
				if (NextElem(L, cur_e, next_e) == OK)
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

			printf("输入任意键继续。。。");getch();
			break;
		case 10:
			L = SelectList(Lists);
			if (L)
			{
				printf("请输入插入的位置：\n");
				scanf("%d", &i);
				printf("请输入需要插入的元素：\n");
				scanf("%d", &e);
				if (ListInsert(L, i, e) == OK)
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

			printf("输入任意键继续。。。");getch();
			break;
		case 11:
			L = SelectList(Lists);
			if (L)
			{
				if (L->next)
				{
					printf("请输入删除的位置：\n");
					scanf("%d", &i);
					if (ListDelete(L, i, e) == OK)
					{
						printf("删除成功！\n");
					}
					else
					{
						printf("输入的位置不合法！\n");
					}
				}
				else
				{
					printf("线性表是空表！\n");
				}
			}
			else
			{
				printf("线性表不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 12:
			L = SelectList(Lists);
			if (L)
			{
				if (!ListTrabverse(L))
				{
					printf("线性表是空表！\n");
				}
				else
				{
					printf("遍历完成！\n");
				}
			}
			else
			{
				printf("线性表不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 13:
			printf("输入任意键继续。。。");getch();
			break;
		case 14:
			printf("输入任意键继续。。。");getch();
			break;
		case 0:
			break;
		} //end of switch
	}	 //end of while
	printf("欢迎下次再使用本系统！\n");
	return 0;
} //end of main()

/*
 * 初始条件：
 * 操作结果：构造一个空的十字链表
 */
status InitLists(Lists &Lists)
{
	Lists = (ListsNode *)malloc(sizeof(ListsNode));
	Lists->next = NULL;
	Lists->L = NULL;

	return OK;
}

/*
 * 初始条件：
 * 操作结果：根据用户输入选择一个线性表
 */
LinkList SelectList(Lists Lists)
{
	ListsNode *p;
	int i, j = 0;

	printf("您想对第几个线性表进行该项操作：\n");
	scanf("%d", &i);

	if (!Lists->next)
	{
		printf("当前没有线性表！\n");
		return NULL;
	}
	for (p = Lists; p != NULL; p = p->next)
	{
		j++;
		if (j == i)
		{
			printf("第%d个线性表选取成功！\n", i);
			return p->L;
		}
	}
	printf("输入的位置不合法！\n");
	return NULL;
}

status InsertaList(Lists Lists, LinkList L)
{
	ListsNode *p;
	p = Lists;
	while (p->next)
	{
		p = p->next;
	}
	p->L = L;
	p->next = NULL;

	return OK;
}

/*
 * 初始条件：线性表L不存在
 * 操作结果：构造一个空的线性表
 */
status InitaList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if (!L) exit(OVERFLOW);
	L->next = NULL;

	return OK;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：销毁线性表L
 */
status DestroyList(LinkList L)
{
	free(L);
	L = NULL;

	return OK;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：将L重置为空表
 */
status ClearList(LinkList L)
{
	if (!ListEmpty(L)) // L不为空表
	{
		free(L->next);
		L->next = NULL;
	}

	return OK;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：若L为空表则返回TRUE,否则返回FALSE
 */
status ListEmpty(LinkList L)
{
	if (!L->next) return TRUE;
	return FALSE;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：返回L中数据元素的个数
 */
int ListLength(LinkList L)
{
	int length = 0;
	LNode *p;

	for (p = L->next; p != NULL; p = p->next)
	{
		length++;
	}

	return length;
}

/*
 * 初始条件：线性表L已存在，1≤i≤ListLength(L)
 * 操作结果：用e返回L中第i个数据元素的值
 */
status GetElem(LinkList L, int i, ElemType &e)
{
	// 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
	LNode *p = L->next; // 初始化，p指向第一个结点
	int j = 1;			// j为计数器

	while (p && j < i) // 顺指针向后查找，直到p指向第i个元素或p为空
	{
		p = p->next;
		j++;
	}
	if (!p || j > i) return ERROR; // 第i个元素不存在
	e = p->data;	  // 取第i个元素

	return OK;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：返回L中数据元素的位置，若这样的数据元素不存在，则返回值为0
 */
int LocateElem(LinkList L, ElemType e)
{
	LNode *p;
	int i = 0;

	for (p = L->next; p != NULL; p = p->next)
	{
		i++;
		if (p->data == e) return i;
	}

	return 0;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义
 */
status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
	LNode *p;

	for (p = L->next; p != NULL; p = p->next)
	{
		if (!p->next) return ERROR;
		if (p->next->data == cur_e)
		{
			pre_e = p->data;
		}
	}

	return OK;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义
 */
status NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
	LNode *p;

	for (p = L->next; p != NULL; p = p->next)
	{
		if (!p->next) return ERROR;
		if (p->data == cur_e)
		{
			next_e = p->next->data;
		}
	}

	return OK;
}

/*
 * 初始条件：线性表L已存在，1≤i≤ListLength(L)+1
 * 操作结果：在L的第i个位置之前插入新的数据元素e
 */
status ListInsert(LinkList L, int i, ElemType e)
{
	// 在带头结点的单链线性表L中第i个位置之前插入e
	LNode *p = L, *q;
	int j = 0;

	while (p && j < i - 1) // 寻找第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERROR;					 // i小于1或者大于表长加1
	q = (LinkList)malloc(sizeof(LNode)); // 生成新结点
	q->data = e;						 // 将数据赋给新结点
	q->next = p->next;					 // 插入新结点
	p->next = q;

	return OK;
}

/*
 * 初始条件：线性表L已存在且非空，1≤i≤ListLength(L)
 * 操作结果：删除L的第i个数据元素，用e返回其值
 */
status ListDelete(LinkList L, int i, ElemType &e)
{
	LNode *p = L, *q;
	int j = 0;

	while (p->next && j < i - 1) // 寻找第i个结点，并令p指向其前驱
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1) return ERROR; // 删除位置不合理
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);

	return OK;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：对L中的每个数据元素进行遍历
 */
int ListTrabverse(LinkList L)
{
	LNode *p;
	int i = 0;

	for (p = L->next; p != NULL; p = p->next)
	{
		printf("%d", p->data);
		i++;
	}

	return i;
}

/*
 * 初始条件：线性表L已存在
 * 操作结果：保存线性表数据
 */
status SaveData()
{
    return OK;
}

/*
 * 初始条件：线性表L不存在
 * 操作结果：读取线性表数据
 */
status ReadData()
{
    return OK;
}
