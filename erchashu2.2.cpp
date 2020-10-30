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

Status ReplaceLeft(BiTree &T,BiTree &LT) {
/* 替换左子树。若T非空，则用LT替换
T的原有左子树，并用LT返回T的原有左子树。 */
		BiTree temp;                  /* 定义temp以替换左子树 */
		if(T==NULL) return ERROR;
		temp=T->lchild;                /* 用temp存储T的左子树 */
		T->lchild=LT;                  /* 用LT替换T的原有左子树 */
		LT=temp;					 /* 用LT返回T的原有左子树 */
		return OK;
}

Status ReplaceRight(BiTree &T,BiTree &RT) {
/* 替换右子树。若T非空，则用RT替换
T的原有右子树，并用RT返回T的原有右子树。 */
		BiTree temp;                  /* 定义temp以替换左子树 */
		if(T==NULL) return ERROR;
		temp=T->rchild;                /* 用temp存储T的右子树 */
		T->rchild=RT;                  /* 用RT替换T的原有右子树 */
		RT=temp; 					 /* 用RT返回T的原有右子树 */
		return OK;
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
		BiTree T,U,V,A,B,C,D,E,I,J,K,L,M,N;
		InitBiTree(T);
		InitBiTree(U);
		InitBiTree(V);
		e='D';
		D=MakeBiTree(e,NULL,NULL);
		e='B';
		B=MakeBiTree(e,D,NULL);
		e='E';
		E=MakeBiTree(e,NULL,NULL);
		e='C';
		C=MakeBiTree(e,NULL,E);
		e='A';
		A=MakeBiTree(e,B,C);
        T=A;
		e='J';
		J=MakeBiTree(e,NULL,NULL);
		e='K';
		K=MakeBiTree(e,NULL,NULL);
		e='I';
		I=MakeBiTree(e,J,K);
        U=I;
		e='M';
		M=MakeBiTree(e,NULL,NULL);
		e='N';
		N=MakeBiTree(e,NULL,NULL);
		e='L';
		L=MakeBiTree(e,M,N);
        V=L;
        printf("二叉树T的序列表示\n");
        Display(T);
        printf("\n");
        printf("二叉树U的序列表示\n");
        Display(U);
        printf("\n");
        printf("二叉树V的序列表示\n");
        Display(V);
        printf("\n");
        printf("\n执行替换，用U和V分别替换T的左右子树\n");
        ReplaceLeft(T,U);
        ReplaceRight(T,V);
        printf("T的序列\n");
        Display(T);
        printf("\n");
        return 0;
}
