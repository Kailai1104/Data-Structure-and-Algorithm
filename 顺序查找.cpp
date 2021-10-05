//顺序查找，亮点为监视哨

#define M 500
typedef struct
{
  int key;
  float info;
}s_list;

int seqsrch(s_list r[],int n,int k){
  r[0].key=k;//设置监视哨
  for(int i=n;i>=0;i--){
    if(r[i].key==k) return i;
  }
}