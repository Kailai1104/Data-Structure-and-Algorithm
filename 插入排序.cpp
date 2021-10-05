//插入排序

typedef struct
{
  int key;
  float info;
}JD;

void straisort(JD & r[],int n){
  int i,j;
  for(i=2;i<=n;i++){
    r[0]=r[i];
    j=i-1;
    while(r[j].key>r[0].key){
      r[j+1]=r[j];
      j--;
    }
    r[j+1]=r[0];
  }
}
