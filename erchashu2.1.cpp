#include<stdio.h>
#include<stdlib.h>
#define TRUE   1
#define FALSE  0
#define OK     1
#define ERROR  0
typedef int Status;
typedef char TElemType;
typedef struct BiTNode {
		TElemType data;                 //数据域
		struct BiTNode *lchild,*rchild;     //左、右孩子指针域
} BiTNode,*BiTree;

void InitBiTree(BiTree &T) {   /* 创建一棵空二叉树。 */
		T=NULL;      /* 空二叉树无结点 */
}

BiTree MakeBiTree(TElemType e,BiTree L,BiTree R) {
/* 创建一棵二叉树T，其中根结点的值为e，
L和R分别作为左子树和右子树。 */
		BiTree T;
		T=(BiTree)malloc(sizeof(BiTNode)); /*给树分配空间*/
		if(NULL==T) return NULL;        /*若T为空二叉树，返回NULL*/
		T->data=e;                      /* 根结点的值为e */
		T->lchild=L;					/* L作为T的左子树 */
		T->rchild=R; 					/* R作为T的右子树 */
		return T;
}

Status BiTreeEmpty(BiTree T) { /* 对二叉树判空。若为空返回
                                       TRUE，否则返回FALSE。*/
		if(T==NULL) return TRUE;
		return FALSE;
}

Status Display(BiTree T) {    /* 显示树T */
		if(T==NULL)
			{
				printf("#");		/* 递归遍历，遍历至没有时用#表示 */
				return ERROR;
            }
					else
						{
							printf("%c",T->data);  /* 输出T的根 */
							printf("(");
							Display(T->lchild);     /* 输出T的左子树 */
							printf(",");
							Display(T->rchild);     /* 输出T的右子树 */
							printf(")");
							return OK;
						}
}

int main()
	{
        int i;
        TElemType e;
        BiTree T,A;
        InitBiTree(T);
        i=BiTreeEmpty(T);
        printf("二叉树T的序列表示\n");
        Display(T);
        printf("\n判空\n");
		if(i)	printf("二叉树T是空树\n");
		else    printf("二叉树T不是空树\n");
		e='A';
        printf("\n");
		T=MakeBiTree(e,NULL,NULL);
        i=BiTreeEmpty(T);
        printf("二叉树T的序列表示\n");
        Display(T);
        printf("\n判空\n");
		if(i)	printf("二叉树T是空树\n");
		else    printf("二叉树T不是空树\n");
		return 0;
    }
