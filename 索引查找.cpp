//索引查找，适用条件为采用顺序存储结构的有序表

typedef struct//索引
{
  int key;
  int link;
}SD;

typedef struct//数据
{
  int key;
  float info;
}JD;

int blocksearch(JD r[],SD nd[],int b,int k,int n){//n个记录被分成b块
  int i,j;
  for(i=1;i<=b;i++){
    if(nd[i].key>=k) break;
  }
  if(i==b+1) return 0;//k在r中不存在
  for(j=nd[i].link;j<=n;j++){
    if(r[j].key>nd[i].key) return 0;//超出索引指示的块的范围而未找到，说明不存在
    if(r[j].key==k) return j;
  }
  if(j==n+1) return 0;
}