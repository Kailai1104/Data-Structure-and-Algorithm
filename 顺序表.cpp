/*
顺序表C语言实现
*/

#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 80
#define LISTINCREMENT 10

typedef struct
{
  int*elem;//分配存储空间的基地址
  int length;//当前线性表的长度
  int listsize;//当前分配给线性表的存储容量
}SqList;//线性表

bool InitList_Sq(SqList & L){
  L.listsize=LIST_INIT_SIZE;
  L.length=0;
  L.elem=(int*)malloc((L.listsize+1)*sizeof(int));
  if(L.elem==NULL) return false;
  else return true;
}

int LocateElem_Sq(SqList L,int e){
  //如果查找失败，将返回0*
  for(int i=1;i<=L.length;i++){
    if(L.elem[i]==e) return i;
  }
  return 0;
}

bool ListInsert_Sq(SqList & L,int i,int e){
  //在第i个元素前插入元素e
  if(L.length==L.listsize) return false;//表满，插入失败
  if(i<=0 || i>L.length+1) return false;//插入位置非法，失败
  for(int j=L.length;j>=i;j--){
    L.elem[j+1]=L.elem[j];
  }
  L.elem[i]=e;
  L.length++;//记得将表长加一
  return true;
}

bool ListDelete_Sq(SqList & L,int i){
  //删除第i个位置的元素
  if(i<=0 || i>L.length) return false;//删除位置非法，失败（这里暗含了对于表空非法的判断）
  /*if(L.length==0) return false;*/
  for(int j=i;j<L.length;j++){
    L.elem[j]=L.elem[j+1];
  }
  L.length--;//记得将表长减一
  return true;
}

int main(){
  //一些简单的测试
  SqList L;
  if(!InitList_Sq(L)){
    printf("error!");
    return 0;
  }
  int e;
  printf("Please input an int:");
  scanf("%d",&e);
  ListInsert_Sq(L,L.length+1,e);
  printf("%d\n",LocateElem_Sq(L,e));
  ListDelete_Sq(L,L.length);
  printf("%d\n",LocateElem_Sq(L,e));
  return 0;
}