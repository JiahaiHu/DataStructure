/* Binary Tree */
#include "LinkQueue.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

FILE *fp;
int index = 0;		// 创建二叉树中definition数组的index
char filename[30] = "D:/BinaryTreeData.txt";

int main(void)
{
	Trees Trees;
	BiTree T;
	int i;
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
					printf("二叉树创建成功！\n");
				}
			}
			else
			{
				printf("二叉树创建失败！\n");
			}

			printf("输入任意键继续。。。");getch();
			break;
		case 2:
			T = SelectTree(Trees);
			if (T)
			{
				/*获取删除的位置*/
				for (i = 0; i < Trees.length; i++)
				{
					if (Trees.elem[i].T == T) break;
				}
				if (DestroyBiTree(T) == OK)
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
			// todo
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

status AddTree(Trees Trees)
{
	InitBiTree(Trees.elem[Trees.length].T);
	Trees.length++;
}

BiTree SelectTree(Trees Trees)
{
	int i;

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

	return Trees.elem[i-1].T;
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
		Parent(T->lchild, e);
	}
	if (!BiTreeEmpty(T->rchild))
	{
		if (e.key == T->rchild->data.key)
		{
			return T;
		}
		Parent(T->rchild, e);
	}
	
	return NULL;	// T无孩子
}

/*
 * 初始条件：二叉树T已存在，e是T中的某个结点
 * 操作结果：返回e的左孩子结点指针。若e无左孩子，则返回NULL
 */
BiTree LeftChild(BiTree T, TElemType e)
{	
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
			LeftChild(T->lchild, e);
			LeftChild(T->rchild, e);
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
			RightChild(T->lchild, e);
			RightChild(T->rchild, e);
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
	if (BiTreeEmpty(T)) return NULL;	// T为空
	if (!BiTreeEmpty(T->lchild))
	{
		if (e.key == T->lchild->data.key)	// e是左孩子
		{
			return NULL;
		}
		LeftSibling(T->lchild, e);
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
		LeftSibling(T->rchild, e);
	}
	
	return NULL;	// T无孩子
}

/*
 * 初始条件：二叉树T已存在，e是T中的某个结点
 * 操作结果：返回e的右兄弟结点指针。若e是T的右孩子或者无有兄弟，则返回NULL
 */
BiTree RightSibling(BiTree T, TElemType e)
{
	if (BiTreeEmpty(T)) return NULL;	// T为空
	if (!BiTreeEmpty(T->rchild))
	{
		if (e.key == T->rchild->data.key)	// e是右孩子
		{
			return NULL;
		}
		RightSibling(T->rchild, e);
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
		RightSibling(T->lchild, e);
	}
	
	return NULL;	// T无孩子
}

/*
 * 初始条件：二叉树T存在，p指向T中的某个结点，LR为0或1，,非空二叉树c与T不相交且右子树为空
 * 操作结果：根据LR为0或者1，插入c为T中p所指结点的左或右子树，p所指结点的原有左子树或右子树则为c的右子树
 */
status InsertChild(BiTree T, TElemType *p, int LR, BiTree c)
{
	BiTree temp = NULL;

	if (!BiTreeEmpty(T)) return ERROR;	// T为空
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
		InsertChild(T->lchild, p, LR, c);
		InsertChild(T->rchild, p, LR, c);
	}
}

/*
 * 初始条件：二叉树T存在，p指向T中的某个结点，LR为0或1
 * 操作结果：根据LR为0或者1，删除c为T中p所指结点的左或右子树
 */
status DeleteChild(BiTree T, TElemType *p, int LR)
{	
	if (BiTreeEmpty(T)) return ERROR;		// T为空
	if (!BiTreeEmpty(T->lchild))
	{
		if (p->key == T->lchild->data.key)	// c为T的左孩子
		{
			DestroyBiTree(T->lchild);		// 销毁c
		}
		DeleteChild(T->lchild, p, LR);
	}
	if (!BiTreeEmpty(T->rchild))
	{
		if (p->key == T->rchild->data.key)	// c为T的右孩子
		{
			DestroyBiTree(T->rchild);		// 销毁c
		}
		DeleteChild(T->rchild, p, LR);
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
	QElemType temp;

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
	}
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
status EnQueue(LinkQueue &Q, QElemType e)
{
	QueuePtr p = NULL;

	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	
	return OK;
}


/*
 * 初始条件：队列Q已存在
 * 操作结果：删除Q的队头元素，并用e返回其值
 */
status DeQueue(LinkQueue &Q, QElemType &e)
{
	if (QueueEmpty(Q)) return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
	{
		Q.rear = Q.front;
	}
	free(p);

	return OK;
}
