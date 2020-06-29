#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct node     /*����ṹ���Ͱ��������� */
{	int number;        /*���ӵı��*/
	int mydata;        /* ���ӵĶ��� */
	struct node *next; /* ָ����һֻ���ӵ�ָ�� */
} linklist;
linklist *CreateCircle( int n ){ /* ����һ����nֻ���ӵ�Ȧ�� */
    linklist *head,*p,*s;
    int i;
    head =(linklist*)malloc(sizeof(linklist)); /*�׽ڵ㴴��*/
    p = head;   p->number = 1;
    scanf("%d",&p->mydata); /* ����(������)��ȷ����һֻ���ֵĺ���*/
    p->next = NULL;
    for( i=2; i<=n; i++ ){  /* ������*/
		s = (linklist*)malloc(sizeof(linklist) ); /*  ȷ�������ڴ�ռ� */
		s->number = i; /* ��Ÿ�ֵ  */
		scanf("%d",&s->mydata); /* ����(������)��ȷ����һֻ���ֵĺ���*/
		p->next = s; /*  ָ����һ����� */
		p = s;  /*  ����ֵ */
    }
    p->next=head;   /*������β��ӹ���ѭ������*/
    return p;  /* �������һֻ���ӵ�ָ�룬��Ϊ��ָ���һֻ���� */
}


//��ҵ
linklist *DeleteNext(linklist *p)    /* ɾ����ѭ�������p��ָ����һ����� */
{
        linklist   *s;
         if ( p && p->next!=p)
		{
               s = p->next;
               p->next = s->next;     //��������ɾ��
               free(s);               //�ͷ�
               return p;
        }
		 else if(p)
		 {
               free(p);
               return NULL;
         }
		 else
               return NULL;
}


int KingOfMonkey(int n,linklist *head){
    linklist *p = head;       /* headָ�����һֻ���ӽ�� */
    int i, j, steps = p->mydata;       /*�����һֻ���ӵĶ�����ʼ */
    for( j=1; j<=n-1; j++ ) {   /*�ظ��ù���n-1��*/
        for( i=1; i<steps; i++ )    p=p->next;
	    /* ��p��ָ����һ���ڵ�ɾ��, ɾ��ǰȡ�䶨�� */
        steps = p->next->mydata;  /*  ָ����һֻ���ӵĶ��� */
        printf(" %d ", p->next->number);
        DeleteNext(p);     /* ɾ����һ����� */
    }
    return p->number;     /*  ���غ����ı��  */
 }

int main(){
    linklist *head;
    int n;
    printf("��������ӵ�������ÿֻ���ӵĶ���(������������)��");
    scanf("%d",&n);
    head = CreateCircle(n); /*������ѭ�������������һ������ָ�� */
    printf("\nThe king is monkey[%d].\n", KingOfMonkey(n,head));
    return 0;
}
