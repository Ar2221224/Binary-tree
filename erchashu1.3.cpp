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

void DestroyBiTree(BiTree &T) { /* 销毁二叉树T */
		if(T)
			{
					DestroyBiTree(T->lchild); /*销毁左子树*/
					DestroyBiTree(T->rchild); /*销毁右子树*/
					T=NULL;     // 为什么当free(T);时会出现重复乱码？
            }
}

Status BiTreeEmpty(BiTree T) { /* 对二叉树判空。若为空返回
                                       TRUE，否则返回FALSE。*/
		if(T==NULL) return TRUE;
		return FALSE;
}

Status BreakBiTree(BiTree &T,BiTree &L,BiTree &R) {
			/*将一棵二叉树T分解成根、左子树和右子树3个部分。*/
        if(T==NULL) return ERROR;
		else
{
				L=T->lchild;            /* 用L返回T的左子树 */
				R=T->rchild;           /* 用R返回T的右子树 */
				T->lchild=NULL;        /* 分解T的左子树 */
				T->rchild=NULL;        /* 分解T的右子树 */
				return OK;
			}
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

Status Cutleft(BiTree &T,BiTree &LT) {
         /* 剪除左子树。若T非空，
则剪除T的左子树，并用LT返回。 */
					if(T==NULL)
{
	LT=NULL;
return ERROR;
}
					LT=T->lchild;		/* 用LT返回T的左子树 */
					T->lchild=NULL;  /* 剪除T的原有左子树 */
					return OK;
}

Status Cutright(BiTree &T,BiTree &RT) {
         /* 剪除右子树。若T非空，
则剪除T的右子树，并用RT返回。 */
					if(T==NULL)
{
	RT=NULL;
return ERROR;
}
					RT=T->rchild; 		/* 用RT返回T的右子树 */
					T->rchild=NULL;     /* 剪除T的原有右子树 */
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
		BiTree T,L,R,A,B,C,D,E,F,G,H,I,J,K;
		InitBiTree(T);
		e='H';
		H=MakeBiTree(e,NULL,NULL);
		e='I';
		I=MakeBiTree(e,NULL,NULL);
		e='F';
		F=MakeBiTree(e,H,I);
		e='D';
		D=MakeBiTree(e,F,NULL);
		e='B';
		B=MakeBiTree(e,NULL,D);
		e='J';
		J=MakeBiTree(e,NULL,NULL);
		e='K';
		K=MakeBiTree(e,NULL,NULL);
		e='G';
		G=MakeBiTree(e,J,K);
		e='E';
		E=MakeBiTree(e,NULL,G);
		e='C';
		C=MakeBiTree(e,E,NULL);
		e='A';
		A=MakeBiTree(e,B,C);
        T=A;
        printf("二叉树T的序列表示\n");
        Display(T);
        printf("\n判空\n");
        i=BiTreeEmpty(T);
        if(i)	printf("二叉树T是空树\n");
        else    printf("二叉树T不是空树\n");
        printf("\n执行剪除T左右子树，用LR返回\n");
        Cutleft(T,L);
        Cutright(T,R);
        printf("T的序列\n");
        Display(T);
        printf("\nL的序列\n");
        Display(L);
        printf("\nR的序列\n");
        Display(R);
        printf("\n执行替换，用LR替换T左右子树\n");
        ReplaceLeft(T,L);
        ReplaceRight(T,R);
        printf("T的序列\n");
        Display(T);
        printf("\nL的序列\n");
        Display(L);
        printf("\nR的序列\n");
        Display(R);
        printf("\n分解操作，左右分到LR\n");
        BreakBiTree(T,L,R);
        printf("T的序列\n");
        Display(T);
        printf("\nL的序列\n");
        Display(L);
        printf("\nR的序列\n");
        Display(R);
        printf("\n销毁T\n");
        DestroyBiTree(T);
        printf("T的序列\n");
        Display(T);
        printf("\n判空\n");
        i=BiTreeEmpty(T);
        if(i)	printf("二叉树T是空树\n");
        else printf("二叉树T不是空树\n");
        return 0;
}
