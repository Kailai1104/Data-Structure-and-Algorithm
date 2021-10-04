/*设顺序表L是一个递增有序表，试写一算法，
将元素x插入L中，并使L仍是一个有序表。*/

typedef struct
{
  int*elem;//分配存储空间的基地址
  int length;//当前线性表的长度
  int listsize;//当前分配给线性表的存储容量
}SqList;//线性表

//低端版
bool Insert(SqList & L,int x){
  if(L.length==L.listsize) return false;
  for(int i=1;i<=L.length;i++){
    if(L.elem[i]>x){
      for(int j=L.length;j>=i;j--){
        L.elem[j+1]=L.elem[j];
      }
      L.elem[i]=x;
      break;
    }
  }
  L.length++;//别忘了将L的长度加一
  return true;
}

//较高端版
bool Insert(SqList & L,int x){
  if(L.length==L.listsize) return false;
  int i;
  //倒序向前寻找插入点，边寻找边做移位操作
  for(i=L.length;i>0;i--){
    if(L.elem[i]>x){
      L.elem[i+1]=L.elem[i]
    }
    else break;
  }
  L.elem[i+1]=x;
  L.length++;
  return true;
}
