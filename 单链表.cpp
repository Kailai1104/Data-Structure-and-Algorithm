/*
单链表C语言实现
（注意：顺序表与单链表都属于线性表，
  顺序表类似于数组）
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
  int data;//数据域
  LNode *next;//指针域
}*LinkList;

bool GetElem_L(LNode L,int i,int & e){
  LinkList p=L.next;
  for(int j=1;j<i;j++){
    if(p==NULL) break;
    p=p->next;
  }
  if(p==NULL) return false;//表长小于i
  e=p->data;
  return true;
}

bool ListInsert_L(LinkList L,int i,int e){
  //在第i个元素前插入e
  if(i<1) return false;//插入位置非法
  LinkList p=L;
  for(int j=0;j<i-1;j++){
    if(p==NULL) break;
    p=p->next;
  }
  if(p==NULL) return false;//表长小于i-1
  //初始化新结点
  LinkList q=(LinkList)malloc(sizeof(LNode));
  if(q==NULL) return false;//申请地址失败
  q->data=e;
  /* q->next=NULL;//这句赋值实际上是多余的 */
  //插入
  q->next=p->next;
  p->next=q;
  return true;
}

bool ListDelete_L(LinkList L,int i,int & e){
  //删除第i个元素
  if(i<1) return false;//插入位置非法
  LinkList p=L;
  for(int j=0;j<i-1;j++){
    if(p->next==NULL) break;
    p=p->next;
  }
  if(p->next==NULL) return false;//表长小于i
  LinkList q=p->next;
  p->next=q->next;
  e=q->data;
  free(q);
  return true;
}

void ClearList_L(LinkList L){
  while(L->next!=NULL){
    LinkList p=L->next;
    L->next=p->next;
    free(p);
  }
}

void CreateList_L(LinkList L,int n){
  //创建一个长度为n的链表
  L=(LinkList)malloc(sizeof(LNode));//初始化头结点
  L->next=NULL;
  for(int i=0;i<n;i++){
    LinkList p=(LinkList)malloc(sizeof(LNode));
    scanf("%d",&p->data);
    p->next=L->next;
    L->next=p;
  }
}

/*ClearList_L和CreateList_L都有一些基于头结点的很妙的操作