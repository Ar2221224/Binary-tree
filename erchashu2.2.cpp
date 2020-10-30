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
        printf("������T�����б�ʾ\n");
        Display(T);
        printf("\n");
        printf("������U�����б�ʾ\n");
        Display(U);
        printf("\n");
        printf("������V�����б�ʾ\n");
        Display(V);
        printf("\n");
        printf("\nִ���滻����U��V�ֱ��滻T����������\n");
        ReplaceLeft(T,U);
        ReplaceRight(T,V);
        printf("T������\n");
        Display(T);
        printf("\n");
        return 0;
}
