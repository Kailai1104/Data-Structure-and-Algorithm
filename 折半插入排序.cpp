#include<iostream>
using namespace std;
void binsort(int*a,int n){
  for(int i=1;i<n;i++){
    int x=a[i];
    int l=0;
    int h=i-1;
    int m;
    while(l<=h){
      m=(h+l)/2;
      if(a[m]<x) l=m+1;//因为排序时很少出现两个元素相等的情况，所以可以不特别判断a[m]==x，这样l也就成了唯一的插入位置了
      else h=m-1;
    }
    for(int j=i-1;j>=l;j--) a[j+1]=a[j];
    a[l]=x;
  }
}

int main(){
  int a[]={30,13,70,85,39,42,6,20};
  binsort(a,8);
  for(int i=0;i<8;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}