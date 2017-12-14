/* Binary Tree */
#include "BinaryTree.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

FILE *fp;
int index = 0;		// 创建二叉树中definition数组的index
char filename[30] = "D:/BinaryTreeData.txt";
/*
int main(void)
{
	int op = 1;
	// InitTrees(Trees);
	while (op)
	{
		system("cls");
		printf("\n\n");
		printf("      Menu for Binary Tree On Binary Linked List \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitBiTree       12. RightChild\n");
		printf("    	  2. DestroyBiTree    13. LeftSibling\n");
		printf("    	  3. CreateBiTree     14. RightSibling\n");
		printf("    	  4. CleanBiTree      15. InsertChild\n");
		printf("    	  5. BiTreeEmpty      16. DeleteChild\n");
		printf("    	  6. BiTreeDepth      17. PreOrderTraverse\n");
		printf("    	  7. Root             18. InOrderTraverse\n");
        printf("    	  8. Value            19. PostOrderTraverse\n");
        printf("    	  9. Assign           20. LevelOrderTraverse\n");
        printf("    	  10. Parent          21. SaveData\n");
        printf("    	  11. LeftChild       22. ReadData\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~22]:");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			if (InitBiTree(Trees.elem[Trees.length].BiTree)) == OK)
			{
				Trees.length++;
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
				ListsNode *p;
				if (Lists->L == L) 		// 由于没有设头结点，需要单独判断
				{
					Lists = Lists->next;
					DestroyList(L);
				}
				else
				{
					p = PriorList(Lists, L);	// 获取L所在ListsNode的前驱结点
					p->next = p->next->next;	// 让前驱结点的next指向后继结点
					DestroyList(L);
				}
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
		} //end of switch
	}	 //end of while
	printf("欢迎下次再使用本系统！\n");
	return 0;
} //end of main()
*/

/*
 * 初始条件：二叉树T不存在
 * 操作结果：构造空二叉树T
 */
status InitBiTree(BiTree &T)
{
	T = NULL;
	
	return OK;
}

/*
 * 初始条件：二叉树T已存在
 * 操作结果：销毁二叉树T
 */
status DestroyBiTree(BiTree &T)
{
	if (BiTreeEmpty(T)) return ERROR;

	if (!BiTreeEmpty(T->lchild))
	{
		DestroyBiTree(T->lchild);
	}
	if (!BiTreeEmpty(T->rchild))
	{
		DestroyBiTree(T->rchild);
	}
	free(T);
	T = NULL;

	return OK;
}

/*
 * 初始条件：definition 给出二叉树T的定义
 * 操作结果：按definition构造二叉树T
 */
status CreateBiTree(BiTree &T, TElemType definition[10])
{
	TElemType e = definition[index];
	
	index++;
	if (!e.score)
	{
		T = NULL;
	}
	else
	{
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
		T->data.key = e.key;					// 生成根节点
		T->data.score = e.score;
		CreateBiTree(T->lchild, definition);	// 构造左子树
		CreateBiTree(T->rchild, definition);	// 构造右子树
	}
	
	return OK;
}

/*
 * 初始条件：二叉树T已存在
 * 操作结果：将二叉树T清空
 */
status ClearBiTree(BiTree &T)
{
	if (BiTreeEmpty(T)) return ERROR;
	ClearBiTree(T->lchild);
	ClearBiTree(T->rchild);
	free(T);
	
	return OK;
}

/*
 * 初始条件：二叉树T已存在
 * 操作结果：若T为空二叉树则返回TRUE，否则返回FALSE
 */
status BiTreeEmpty(BiTree T)
{
	if (!T) return TRUE;
	
	return FALSE;
}

/*
 * 初始条件：二叉树T已存在
 * 操作结果：返回T的深度
 */
int BiTreeDepth(BiTree T)
{
	int ldepth, rdepth;
	
	if (BiTreeEmpty(T)) return 0;
	
	ldepth = BiTreeDepth(T->lchild);
	rdepth = BiTreeDepth(T->rchild);
	
	return ldepth > rdepth ? ldepth + 1 : rdepth + 1;
}

/*
 * 初始条件：二叉树T已存在
 * 操作结果：返回T的根
 */
BiTree Root(BiTree T)
{
	return T;
}

/*
 * 初始条件：二叉树T已存在，e是T中的某个结点
 * 操作结果：返回e的值
 */
int Value(BiTree T, TElemType e)
{
	if (!BiTreeEmpty(T))
	{
		if (e.key == T->data.key)
		{
			return T->data.score;
		}
		else
		{
			Value(T->lchild, e);
			Value(T->rchild, e);
		}
	}
	
	return ERROR;	// e不在T中或T为空
}

/*
 * 初始条件：二叉树T已存在，e是T中的某个结点
 * 操作结果：结点e赋值为value
 */
status Assign(BiTree T, TElemType &e, int value)
{	
	if (!BiTreeEmpty(T))
	{
		if (e.key == T->data.key)
		{
			T->data.score = value;
			return OK;
		}
		else
		{
			Assign(T->lchild, e, value);
			Assign(T->rchild, e, value);
		}
	}
	
	return ERROR;	// e不在T中或T为空
}

/*
 * 初始条件：二叉树T已存在，e是T中的某个结点
 * 操作结果：若e是T的非根结点，则返回它的双亲结点指针，否则返回NULL
 */
BiTree Parent(BiTree T, TElemType e)
{
}

/*
 * 初始条件：二叉树T已存在，e是T中的某个结点
 * 操作结果：返回e的左孩子结点指针。若e无左孩子，则返回NULL
 */
BiTree LeftChild(BiTree T, TElemType e)
{
}

/*
 * 初始条件：二叉树T已存在，e是T中的某个结点
 * 操作结果：返回e的右孩子结点指针。若e无右孩子，则返回NULL
 */
BiTree RightChild(BiTree T, TElemType e)
{
}

/*
 * 初始条件：二叉树T已存在，e是T中的某个结点
 * 操作结果：返回e的左兄弟结点指针。若e是T的左孩子或者无左兄弟，则返回NULL
 */
BiTree LeftSibling(BiTree T, TElemType e)
{
}

/*
 * 初始条件：二叉树T已存在，e是T中的某个结点
 * 操作结果：返回e的右兄弟结点指针。若e是T的右孩子或者无有兄弟，则返回NULL
 */
BiTree RightSibling(BiTree T, TElemType e)
{
}

/*
 * 初始条件：二叉树T存在，p指向T中的某个结点，LR为0或1，,非空二叉树c与T不相交且右子树为空
 * 操作结果：根据LR为0或者1，插入c为T中p所指结点的左或右子树，p	所指结点的原有左子树或右子树则为c的右子树
 */
status InsertChild(BiTree T, TElemType *p, int LR, BiTree c)
{
}

/*
 * 初始条件：二叉树T存在，p指向T中的某个结点，LR为0或1
 * 操作结果：根据LR为0或者1，删除c为T中p所指结点的左或右子树
 */
status DeleteChild(BiTree T, TElemType *p, int LR)
{
}

// 最简单的Visit函数
status PrintElement(TElemType e)
{
	printf("%d", e.score);
	return OK;
}

/*
 * 初始条件：二叉树T存在，Visit是对结点操作的应用函数
 * 操作结果：先序遍历T，对每个结点调用函数Visit一次且一次，一旦调用失败，则操作失败
 */
status PreOrderTraverse(BiTree T, status (*Visit)(TElemType e))
{
	if (!BiTreeEmpty(T))
	{
		if (Visit(T->data))
		{
			if (PreOrderTraverse(T->lchild, Visit))
			{
				if (PreOrderTraverse(T->rchild, Visit))
				{
					return OK;
				}
			}
		}
		return ERROR;
	}
	else
	{
		return OK;
	}
}

/*
 * 初始条件：二叉树T存在，Visit是对结点操作的应用函数
 * 操作结果：中序遍历t，对每个结点调用函数Visit一次且一次，一旦调用失败，则操作失败。
 */
status InOrderTraverse(BiTree T, status (*Visit)(TElemType e))
{
	if (!BiTreeEmpty(T))
	{
		if (InOrderTraverse(T->lchild, Visit))
		{
			if (Visit(T->data))
			{
				if (InOrderTraverse(T->rchild, Visit))
				{
					return OK;
				}
			}
		}
		return ERROR;
	}
	else
	{
		return OK;
	}
}

/*
 * 初始条件：二叉树T存在，Visit是对结点操作的应用函数
 * 操作结果：后序遍历t，对每个结点调用函数Visit一次且一次，一旦调用失败，则操作失败
 */
status PostOrderTraverse(BiTree T, status (*Visit)(TElemType e))
{	
	if (!BiTreeEmpty(T))
	{
		if (PostOrderTraverse(T->lchild, Visit))
		{
			if (PostOrderTraverse(T->rchild, Visit))
			{
				if (Visit(T->data))
				{
					return OK;
				}
			}
		}
		return ERROR;
	}
	else
	{
		return OK;
	}
}

/*
 * 初始条件：二叉树T存在，Visit是对结点操作的应用函数
 * 操作结果：层序遍历t，对每个结点调用函数Visit一次且一次，一旦调用失败，则操作失败
 */
status LevelOrderTraverse(BiTree T, status (*Visit)(TElemType e))
{
}












