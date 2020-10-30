#include<stdio.h>
#include<stdlib.h>
#define TRUE   1
#define FALSE  0
#define OK     1
#define ERROR  0
typedef int Status;
typedef char TElemType;
typedef struct BiTNode {
		TElemType data;                 //������
		struct BiTNode *lchild,*rchild;     //���Һ���ָ����
} BiTNode,*BiTree;

void InitBiTree(BiTree &T) {   /* ����һ�ÿն������� */
		T=NULL;      /* �ն������޽�� */
}

BiTree MakeBiTree(TElemType e,BiTree L,BiTree R) {
/* ����һ�ö�����T�����и�����ֵΪe��
L��R�ֱ���Ϊ���������������� */
		BiTree T;
		T=(BiTree)malloc(sizeof(BiTNode)); /*��������ռ�*/
		if(NULL==T) return NULL;        /*��TΪ�ն�����������NULL*/
		T->data=e;                      /* ������ֵΪe */
		T->lchild=L;					/* L��ΪT�������� */
		T->rchild=R; 					/* R��ΪT�������� */
		return T;
}

void DestroyBiTree(BiTree &T) { /* ���ٶ�����T */
		if(T)
			{
					DestroyBiTree(T->lchild); /*����������*/
					DestroyBiTree(T->rchild); /*����������*/
					T=NULL;     // Ϊʲô��free(T);ʱ������ظ����룿
            }
}

Status BiTreeEmpty(BiTree T) { /* �Զ������пա���Ϊ�շ���
                                       TRUE�����򷵻�FALSE��*/
		if(T==NULL) return TRUE;
		return FALSE;
}

Status BreakBiTree(BiTree &T,BiTree &L,BiTree &R) {
			/*��һ�ö�����T�ֽ�ɸ�����������������3�����֡�*/
        if(T==NULL) return ERROR;
		else
{
				L=T->lchild;            /* ��L����T�������� */
				R=T->rchild;           /* ��R����T�������� */
				T->lchild=NULL;        /* �ֽ�T�������� */
				T->rchild=NULL;        /* �ֽ�T�������� */
				return OK;
			}
}

Status ReplaceLeft(BiTree &T,BiTree &LT) {
/* �滻����������T�ǿգ�����LT�滻
T��ԭ��������������LT����T��ԭ���������� */
		BiTree temp;                  /* ����temp���滻������ */
		if(T==NULL) return ERROR;
		temp=T->lchild;                /* ��temp�洢T�������� */
		T->lchild=LT;                  /* ��LT�滻T��ԭ�������� */
		LT=temp;					 /* ��LT����T��ԭ�������� */
		return OK;
}

Status ReplaceRight(BiTree &T,BiTree &RT) {
/* �滻����������T�ǿգ�����RT�滻
T��ԭ��������������RT����T��ԭ���������� */
		BiTree temp;                  /* ����temp���滻������ */
		if(T==NULL) return ERROR;
		temp=T->rchild;                /* ��temp�洢T�������� */
		T->rchild=RT;                  /* ��RT�滻T��ԭ�������� */
		RT=temp; 					 /* ��RT����T��ԭ�������� */
		return OK;
}

Status Cutleft(BiTree &T,BiTree &LT) {
         /* ��������������T�ǿգ�
�����T��������������LT���ء� */
					if(T==NULL)
{
	LT=NULL;
return ERROR;
}
					LT=T->lchild;		/* ��LT����T�������� */
					T->lchild=NULL;  /* ����T��ԭ�������� */
					return OK;
}

Status Cutright(BiTree &T,BiTree &RT) {
         /* ��������������T�ǿգ�
�����T��������������RT���ء� */
					if(T==NULL)
{
	RT=NULL;
return ERROR;
}
					RT=T->rchild; 		/* ��RT����T�������� */
					T->rchild=NULL;     /* ����T��ԭ�������� */
					return OK;
}

Status Display(BiTree T) {    /* ��ʾ��T */
		if(T==NULL)
			{
				printf("#");		/* �ݹ������������û��ʱ��#��ʾ */
				return ERROR;
            }
					else
						{
							printf("%c",T->data);  /* ���T�ĸ� */
							printf("(");
							Display(T->lchild);     /* ���T�������� */
							printf(",");
							Display(T->rchild);     /* ���T�������� */
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
        printf("������T�����б�ʾ\n");
        Display(T);
        printf("\n�п�\n");
        i=BiTreeEmpty(T);
        if(i)	printf("������T�ǿ���\n");
        else    printf("������T���ǿ���\n");
        printf("\nִ�м���T������������LR����\n");
        Cutleft(T,L);
        Cutright(T,R);
        printf("T������\n");
        Display(T);
        printf("\nL������\n");
        Display(L);
        printf("\nR������\n");
        Display(R);
        printf("\nִ���滻����LR�滻T��������\n");
        ReplaceLeft(T,L);
        ReplaceRight(T,R);
        printf("T������\n");
        Display(T);
        printf("\nL������\n");
        Display(L);
        printf("\nR������\n");
        Display(R);
        printf("\n�ֽ���������ҷֵ�LR\n");
        BreakBiTree(T,L,R);
        printf("T������\n");
        Display(T);
        printf("\nL������\n");
        Display(L);
        printf("\nR������\n");
        Display(R);
        printf("\n����T\n");
        DestroyBiTree(T);
        printf("T������\n");
        Display(T);
        printf("\n�п�\n");
        i=BiTreeEmpty(T);
        if(i)	printf("������T�ǿ���\n");
        else printf("������T���ǿ���\n");
        return 0;
}
