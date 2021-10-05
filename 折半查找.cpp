//折半查找，适用条件为采用顺序存储结构的有序表

#define M 500
typedef struct
{
  int key;
  float info;
}s_list;

int bisearch(s_list r[],int n,int k){
  int high=n,low=1,mid;
  while(high>=low){
    mid=(high+low)/2;
    if(r[mid].key==k) return mid;
    else if(r[mid].key>k) high=mid-1;
    else low=mid+1;
  }
  return 0;//循环正常结束代表high<low，即未找到结果
}