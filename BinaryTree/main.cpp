/* Binary Tree */
#include "LinkQueue.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

FILE *fp;
int index = 0;		// 创建二叉树中definition数组的index
char filename[30] = "D:/BinaryTreeData.txt";

int main(void)
{
	Trees Trees;
	BinaryTree *BT;
	BiTree c;
	int i, score, LR;
	TElemType e, *definition;
	int op = 1;

	InitTrees(Trees);
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
			if (Trees.length < Trees.listsize)
			{
				if (AddTree(Trees) == OK)
				{
					printf("二叉树初始化成功！\n");
				}
			}
			else
			{
				printf("二叉初始化失败！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 2:
			BT = SelectTree(Trees);
			if (BT)
			{
				/*获取删除的位置*/
				for (i = 0; i < Trees.length; i++)
				{
					if (Trees.elem[i].T == BT->T) break;
				}
				if (DestroyBiTree(BT->T) == OK)
				{
					/*后面的二叉树前移*/
					for (int j = i; j < Trees.length - 1; j++)
					{
						Trees.elem[j] = Trees.elem[j+1];
					}
					Trees.length--;
					printf("二叉树销毁成功！\n");
				}
				else
				{
					printf("二叉树销毁失败！\n");
				}
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 3:
			BT = SelectTree(Trees);
			if (BT)
			{
				definition = (TElemType *)malloc(10 * sizeof(TElemType));
				for (int j = 0; j < 10; j++)
				{
					printf("请输入关键字：\n");
					scanf("%d", &i);
					if (i == -1) break;
					definition[j].key = i;
					if (i != 0)
					{
						printf("请输入结点的值：\n");
						scanf("%d", &score);
						definition[j].score = score;
					}
				}
				index = 0;
				if (CreateBiTree(BT->T, definition) == OK)
				{
					printf("二叉树创建成功！\n");
				}
				else
				{
					printf("二叉树创建失败！\n");
				}
				free(definition);
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 4:
			BT = SelectTree(Trees);
			if (BT)
			{
				if (CleanBiTree(BT->T) == OK)
				{
					printf("二叉树清空成功！\n");
				}
				else
				{
					printf("二叉树清空失败！\n");
				}
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;

			printf("输入任意键继续。。。");getch();
			break;
		case 5:
			BT = SelectTree(Trees);
			if (BT)
			{
				if (BiTreeEmpty(BT->T))
				{
					printf("二叉树为空！\n");
				}
				else
				{
					printf("二叉树不为空！\n");
				}
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 6:
			BT = SelectTree(Trees);
			if (BT)
			{
				i = BiTreeDepth(BT->T);
				printf("二叉树的深度为%d！\n", i);
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 7:
			BT = SelectTree(Trees);
			if (BT)
			{
				c = Root(BT->T);
				printf("根结点的值为%d！\n", c->data.score);
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 8:
			BT = SelectTree(Trees);
			if (BT)
			{
				printf("请输入关键字：");
				scanf("%d", &e.key);
				score = Value(BT->T, e);
				if (score != -1)
				{
					printf("该结点的值为%d！\n", score);
				}
				else
				{
					printf("不存在该结点！\n");
				}
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 9:
			BT = SelectTree(Trees);
			if (BT)
			{
				printf("请输入所要修改的结点的关键字：\n");
				scanf("%d", &e.key);
				printf("将该结点的值改为：\n");
				scanf("%d", &score);
				if (Assign(BT->T, e, score) == OK)
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
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 10:
			BT = SelectTree(Trees);
			if (BT)
			{
				printf("请输入关键字：");
				scanf("%d", &e.key);
				c = Parent(BT->T, e);
				if (c)
				{
					printf("该结点的双亲结点的值为%d！\n", c->data.score);
				}
				else
				{
					printf("该结点没有双亲结点！\n");
				}
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 11:
			BT = SelectTree(Trees);
			if (BT)
			{
				printf("请输入关键字：");
				scanf("%d", &e.key);
				c = LeftChild(BT->T, e);
				if (c)
				{
					printf("该结点的左孩子的值为%d！\n", c->data.score);
				}
				else
				{
					printf("该结点没有左孩子！\n");
				}
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 12:
			BT = SelectTree(Trees);
			if (BT)
			{
				printf("请输入关键字：");
				scanf("%d", &e.key);
				c = RightChild(BT->T, e);
				if (c)
				{
					printf("该结点的右孩子的值为%d！\n", c->data.score);
				}
				else
				{
					printf("该结点没有右孩子！\n");
				}
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 13:
			BT = SelectTree(Trees);
			if (BT)
			{
				printf("请输入关键字：");
				scanf("%d", &e.key);
				c = LeftSibling(BT->T, e);
				if (c)
				{
					printf("该结点的左兄弟的值为%d！\n", c->data.score);
				}
				else
				{
					printf("该结点没有左兄弟！\n");
				}
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 14:
			BT = SelectTree(Trees);
			if (BT)
			{
				printf("请输入关键字：");
				scanf("%d", &e.key);
				c = RightSibling(BT->T, e);
				if (c)
				{
					printf("该结点的右兄弟的值为%d！\n", c->data.score);
				}
				else
				{
					printf("该结点没有右兄弟！\n");
				}
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 15:
			BT = SelectTree(Trees);
			if (BT)
			{
				printf("请输入插入结点的关键字：");
				scanf("%d", &e.key);
				printf("请输入插入左子树还是右子树(0/1)：");
				scanf("%d", &LR);
				// 创建子树c
				definition = (TElemType *)malloc(10 * sizeof(TElemType));
				for (int j = 0; j < 10; j++)
				{
					printf("请输入关键字：\n");
					scanf("%d", &i);
					if (i == -1) break;
					definition[j].key = i;
					if (i != 0)
					{
						printf("请输入结点的值：\n");
						scanf("%d", &score);
						definition[j].score = score;
					}
				}
				index = 0;
				if (CreateBiTree(c, definition) == OK)
				{
					printf("二叉树创建成功！\n");
					PreOrderTraverse(c, PrintElement);
				}
				else
				{
					printf("二叉树创建失败！\n");
				}
				free(definition);
				if (InsertChild(BT->T, &e, LR, c) == OK)
				{
					printf("子树插入成功！\n");
				}
				else
				{
					printf("子树插入失败！\n");
				}
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 16:
			BT = SelectTree(Trees);
			if (BT)
			{
				printf("请输入关键字：");
				scanf("%d", &e.key);
				printf("请输入删除左子树还是右子树(0/1)：");
				scanf("%d", &LR);
				if (DeleteChild(BT->T, &e, LR) == OK)
				{
					printf("子树删除成功！\n");
				}
				else
				{
					printf("子树删除失败！\n");
				}
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 17:
			BT = SelectTree(Trees);
			if (BT)
			{
				if (PreOrderTraverse(BT->T, PrintElement) == OK)
				{
					printf("调用成功！\n");
				}
				else
				{
					printf("调用失败！\n");
				}
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 18:
			BT = SelectTree(Trees);
			if (BT)
			{
				if (InOrderTraverse(BT->T, PrintElement) == OK)
				{
					printf("调用成功！\n");
				}
				else
				{
					printf("调用失败！\n");
				}
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 19:
			BT = SelectTree(Trees);
			if (BT)
			{
				if (PostOrderTraverse(BT->T, PrintElement) == OK)
				{
					printf("调用成功！\n");
				}
				else
				{
					printf("调用失败！\n");
				}
			}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 20:
			BT = SelectTree(Trees);
			if (BT)
			{
				if (LevelOrderTraverse(BT->T, PrintElement) == OK)
				{
					printf("调用成功！\n");
				}
				else
				{
					printf("调用失败！\n");
				}
		}
			else
			{
				printf("二叉树不存在！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 21:
			if (SaveData(Trees) == OK)
			{
				printf("数据保存成功！\n");
			}
			else
			{
				printf("数据保存失败！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 22:
			if (ReadData(Trees) == OK)
			{
				printf("数据读取成功！\n");
			}
			else
			{
				printf("数据读取失败！\n");
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


status InitTrees(Trees &Trees)
{
	Trees.elem = (BinaryTree *)malloc(LIST_INIT_SIZE * sizeof(BinaryTree));
	if (!Trees.elem) exit(OVERFLOW);
	Trees.length = 0;
	Trees.listsize = LIST_INIT_SIZE;

	return OK;
}

status AddTree(Trees &Trees)
{
	char name[20];
	InitBiTree(Trees.elem[Trees.length].T);
	printf("请输入二叉树的名称：");
	scanf("%s", name);
	strcpy(Trees.elem[Trees.length].name, name);
	Trees.length++;
	return OK;
}

status ShowTrees(Trees Trees)
{
	for (int i = 0; i < Trees.length; i++)
	{
		printf("%d:%s\n", i+1, Trees.elem[i].name);
	}
	return OK;
}

BinaryTree * SelectTree(Trees Trees)
{
	int i;

	ShowTrees(Trees);
	printf("您想对第几个二叉树进行该项操作：\n");
	scanf("%d", &i);

	if (Trees.length == 0)
	{
		printf("当前没有二叉树！\n");
		return NULL;
	}
	else if (i > Trees.length)
	{
		printf("输入的位置不合法！\n");
		return NULL;
	}

	printf("第%d个二叉树选取成功！\n", i);

	return Trees.elem + i - 1;
}

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
	if (e.key == 0)
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
status CleanBiTree(BiTree &T)
{
	if (BiTreeEmpty(T)) return ERROR;
	CleanBiTree(T->lchild);
	CleanBiTree(T->rchild);
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
	int lvalue, rvalue;

	if (!BiTreeEmpty(T))
	{
		if (e.key == T->data.key)
		{
			return T->data.score;
		}
		else
		{
			lvalue = Value(T->lchild, e);
			rvalue = Value(T->rchild, e);
			if (lvalue != -1) return lvalue;
			if (rvalue != -1) return rvalue;
		}
	}

	return -1;	// e不在T中或T为空
}

/*
 * 初始条件：二叉树T已存在，e是T中的某个结点
 * 操作结果：结点e赋值为value
 */
status Assign(BiTree T, TElemType &e, int value)
{
	status lstatus, rstatus;
	if (!BiTreeEmpty(T))
	{
		if (e.key == T->data.key)
		{
			T->data.score = value;
			return OK;
		}
		else
		{
			lstatus = Assign(T->lchild, e, value);
			rstatus = Assign(T->rchild, e, value);
			if (lstatus != ERROR) return lstatus;
			if (rstatus != ERROR) return rstatus;
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
	BiTree l, r;

	if (BiTreeEmpty(T))		// T为空
	{
		return NULL;
	}
	if (!BiTreeEmpty(T->lchild))
	{
		if (e.key == T->lchild->data.key)
		{
			return T;
		}
	}
	if (!BiTreeEmpty(T->rchild))
	{
		if (e.key == T->rchild->data.key)
		{
			return T;
		}
	}
	l = Parent(T->lchild, e);
	r = Parent(T->rchild, e);
	if (l != NULL) return l;
	if (r != NULL) return r;
	
	return NULL;	// T无孩子
}

/*
 * 初始条件：二叉树T已存在，e是T中的某个结点
 * 操作结果：返回e的左孩子结点指针。若e无左孩子，则返回NULL
 */
BiTree LeftChild(BiTree T, TElemType e)
{
	BiTree l, r;

	if (!BiTreeEmpty(T))
	{
		if (e.key == T->data.key)
		{
			if (!BiTreeEmpty(T->lchild))
			{
				return T->lchild;
			}
			return NULL;
		}
		else
		{
			l = LeftChild(T->lchild, e);
			r = LeftChild(T->rchild, e);
			if (l != NULL) return l;
			if (r != NULL) return r;
		}
	}

	return NULL;	// e不在T中或T为空
}

/*
 * 初始条件：二叉树T已存在，e是T中的某个结点
 * 操作结果：返回e的右孩子结点指针。若e无右孩子，则返回NULL
 */
BiTree RightChild(BiTree T, TElemType e)
{
	BiTree l, r;

	if (!BiTreeEmpty(T))
	{
		if (e.key == T->data.key)
		{
			if (!BiTreeEmpty(T->rchild))
			{
				return T->rchild;
			}
			return NULL;
		}
		else
		{
			l = RightChild(T->lchild, e);
			r = RightChild(T->rchild, e);
			if (l != NULL) return l;
			if (r != NULL) return r;
		}
	}

	return NULL;	// e不在T中或T为空
}

/*
 * 初始条件：二叉树T已存在，e是T中的某个结点
 * 操作结果：返回e的左兄弟结点指针。若e是T的左孩子或者无左兄弟，则返回NULL
 */
BiTree LeftSibling(BiTree T, TElemType e)
{
	BiTree l, r;

	if (BiTreeEmpty(T)) return NULL;	// T为空
	if (!BiTreeEmpty(T->lchild))
	{
		if (e.key == T->lchild->data.key)	// e是左孩子
		{
			return NULL;
		}
	}
	if (!BiTreeEmpty(T->rchild))
	{
		if (e.key == T->rchild->data.key)	// e是右孩子
		{
			/*
			if (!BiTreeEmpty(T->lchild))
			{
				return T->lchild;
			}
			return NULL;	// e无左兄弟
			*/
			return T->lchild;
		}
	}
	l = LeftSibling(T->lchild, e);
	r = LeftSibling(T->rchild, e);
	if (l != NULL) return l;
	if (r != NULL) return r;

	return NULL;	// T无孩子
}

/*
 * 初始条件：二叉树T已存在，e是T中的某个结点
 * 操作结果：返回e的右兄弟结点指针。若e是T的右孩子或者无有兄弟，则返回NULL
 */
BiTree RightSibling(BiTree T, TElemType e)
{
	BiTree l, r;

	if (BiTreeEmpty(T)) return NULL;	// T为空
	if (!BiTreeEmpty(T->rchild))
	{
		if (e.key == T->rchild->data.key)	// e是右孩子
		{
			return NULL;
		}
	}
	if (!BiTreeEmpty(T->lchild))
	{
		if (e.key == T->lchild->data.key)	// e是左孩子
		{
			/*
			if (!BiTreeEmpty(T->rchild))
			{
				return T->rchild;
			}
			return NULL;	// e无右兄弟
			*/
			return T->rchild;
		}
	}
	l = RightSibling(T->lchild, e);
	r = RightSibling(T->rchild, e);
	if (l != NULL) return l;
	if (r != NULL) return r;

	return NULL;	// T无孩子
}

/*
 * 初始条件：二叉树T存在，p指向T中的某个结点，LR为0或1，,非空二叉树c与T不相交且右子树为空
 * 操作结果：根据LR为0或者1，插入c为T中p所指结点的左或右子树，p所指结点的原有左子树或右子树则为c的右子树
 */
status InsertChild(BiTree T, TElemType *p, int LR, BiTree c)
{
	BiTree temp = NULL;
	status l, r;

	if (BiTreeEmpty(T)) return ERROR;	// T为空
	if (p->key == T->data.key)
	{
		if (LR == 0)
		{
			temp = T->lchild;
			T->lchild = c;
			c->rchild = temp;
			return OK;
		}
		else if (LR == 1)
		{
			temp = T->rchild;
			T->rchild = c;
			c->rchild = temp;
			return OK;
		}
	}
	else
	{
		l = InsertChild(T->lchild, p, LR, c);
		r = InsertChild(T->rchild, p, LR, c);
		if (l != ERROR) return l;
		if (r != ERROR) return r;
	}
    return ERROR;
}

/*
 * 初始条件：二叉树T存在，p指向T中的某个结点，LR为0或1
 * 操作结果：根据LR为0或者1，删除c为T中p所指结点的左或右子树
 */
status DeleteChild(BiTree T, TElemType *p, int LR)
{
	status l, r;

	if (BiTreeEmpty(T)) return ERROR;		// T为空
	if (p->key == T->data.key)
	{
		if (LR == 0)
		{
			DestroyBiTree(T->lchild);		// 销毁c
			return OK;
		}
		if (LR == 1)
		{
			DestroyBiTree(T->rchild);		// 销毁c
			return OK;
		}
	}
	else
	{
		l = DeleteChild(T->lchild, p, LR);
		r = DeleteChild(T->rchild, p, LR);
		if (l != ERROR) return l;
		if (r != ERROR) return r;
	}

	return ERROR;	// T无孩子
}

// 最简单的Visit函数
status PrintElement(TElemType e)
{
	printf("%d\n", e.score);
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
	LinkQueue Q;
	QElemType temp = NULL;

	if (!BiTreeEmpty(T))
	{
		InitQueue(Q);
		EnQueue(Q, T);
		while(!QueueEmpty(Q))
		{
			DeQueue(Q, temp);
			Visit(temp->data);
			if(!BiTreeEmpty(temp->lchild))
			{
				EnQueue(Q, temp->lchild);
			}
            if(!BiTreeEmpty(temp->rchild))
			{
				EnQueue(Q, temp->rchild);
			}
		}
		return OK;
	}
	return ERROR;
}

int NumberOfNodes(BiTree T)
{
	int num = 0;
	if (T == NULL) 
	{
		return 1;
	}
	else
	{
		num = NumberOfNodes(T->lchild) + NumberOfNodes(T->rchild) + 1;
	}

	return num;
}
status PreOrderWrite(BiTree T, FILE *fp)
{
	int zero = 0;
	if (!BiTreeEmpty(T))
	{
		fwrite(&T->data.key, sizeof(int), 1, fp);
		fwrite(&T->data.score, sizeof(int), 1, fp);
		if (PreOrderWrite(T->lchild, fp))
		{
			if (PreOrderWrite(T->rchild, fp))
			{
				return OK;
			}
		}
		return ERROR;
	}
	else
	{	
		fwrite(&zero, sizeof(int), 1, fp);
		fwrite(&zero, sizeof(int), 1, fp);
		return OK;
	}
}

status SaveData(Trees Trees)
{
	int i, num;

	if ((fp = fopen(filename, "wb")) == NULL)
	{
		printf("文件打开失败！\n");
		return ERROR;
	}
	fwrite(&(Trees.length), sizeof(int), 1, fp);	// 写入二叉树个数
	for (i = 0; i < Trees.length; i++)
	{
		fwrite(Trees.elem[i].name, sizeof(char), 20, fp);	// 写入二叉树名称
		num = NumberOfNodes(Trees.elem[i].T);
		fwrite(&num, sizeof(int), 1, fp);			// 写入二叉树结点个数
		PreOrderWrite(Trees.elem[i].T, fp);
		// fwrite(-1, sizeof(int), 1, fp);
	}
	fclose(fp);
	return OK;
}

status ReadData(Trees &Trees)
{
	int length, i, num;
	TElemType *definition;

	if ((fp = fopen(filename, "rb")) == NULL)
	{
		printf("文件打开失败！\n");
		return ERROR;
	}
	fread(&length, sizeof(int), 1, fp);
	Trees.length = length;
	for (i = 0; i < length; i++)
	{
		fread(Trees.elem[i].name, sizeof(char), 20, fp);
		fread(&num, sizeof(int), 1, fp);
		definition = (TElemType *)malloc((num + 1) * sizeof(TElemType));
		for (int j = 0; j < num; j++)
		{
			fread(&(definition[j].key), sizeof(int), 1, fp);
			fread(&(definition[j].score), sizeof(int), 1, fp);
		}
		definition[num].key = -1;
		index = 0;
		CreateBiTree(Trees.elem[i].T, definition);
		free(definition);
	}
	fclose(fp);
	return OK;
}

// ----------- 队列的基本操作 ------------

/*
 * 初始条件：队列Q不存在
 * 操作结果：构造一个空队列Q
 */
status InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;

	return OK;
}

/*
 * 初始条件：队列Q已存在
 * 操作结果：若Q为空队列，则返回TRUE，否则返回FALSE
 */
status QueueEmpty(LinkQueue &Q)
{
	if (Q.front == Q.rear) return TRUE;

	return FALSE;
}

/*
 * 初始条件：队列Q已存在
 * 操作结果：插入元素e为Q的新的队尾元素
 */
status EnQueue(LinkQueue &Q, QElemType &e)
{
	QueuePtr p = NULL;

	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->T = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;

	return OK;
}


/*
 * 初始条件：队列Q已存在
 * 操作结果：删除Q的队头元素，并用e返回其值
 */
status DeQueue(LinkQueue &Q, QElemType &e)
{
    QNode *p;
	if (QueueEmpty(Q)) return ERROR;
	p = Q.front->next;
	e = p->T;
	Q.front->next = p->next;
	if (Q.rear == p)
	{
		Q.rear = Q.front;
	}
	free(p);

	return OK;
}
