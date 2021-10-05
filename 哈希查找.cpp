//哈希查找算法实现，用线性探测再散列法处理冲突
#define M 100//表长

int h(int k){//hash函数
  return k%97;
}

//线性探测再散列查找算法
int slbxxcz(int t[],int k){
  int i,j=0;
  i=h(k);
  while((j<M)&&(t[(i+j)%M]!=k) j++;
  i=(i+j)%M;
  if(t[i]==k) return i;
  else return 0;
}//老师的代码，十分简洁

//hash表构造算法，假设t[]数组中的所有元素的值已被初始化为0
bool slbxxcr(int t[],int k){
  int i,j=0;
  i=h(k);
  while((j<M)&&(t[(i+j)%M]!=0)&&(t[(i+j)%M]!=k)) j++;
  if(j==M) return 0;//没有位置了，插入失败
  i=(i+j)%M;
  if(t[i]==k) return 0;//表中已有此元素，插入失败
  else{
    t[i]=k;
    return 1;
  }
}