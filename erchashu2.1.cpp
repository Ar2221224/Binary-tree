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

Status BiTreeEmpty(BiTree T) { /* �Զ������пա���Ϊ�շ���
                                       TRUE�����򷵻�FALSE��*/
		if(T==NULL) return TRUE;
		return FALSE;
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
        BiTree T,A;
        InitBiTree(T);
        i=BiTreeEmpty(T);
        printf("������T�����б�ʾ\n");
        Display(T);
        printf("\n�п�\n");
		if(i)	printf("������T�ǿ���\n");
		else    printf("������T���ǿ���\n");
		e='A';
        printf("\n");
		T=MakeBiTree(e,NULL,NULL);
        i=BiTreeEmpty(T);
        printf("������T�����б�ʾ\n");
        Display(T);
        printf("\n�п�\n");
		if(i)	printf("������T�ǿ���\n");
		else    printf("������T���ǿ���\n");
		return 0;
    }
