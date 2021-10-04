//循环队列（顺序队列的升级版）
#define MAXQSIZE 100
typedef struct
{
  int base[MAXQSIZE];
  int front;//头指针，若队列不空，指向队列头元素，队列空时指向0
  int rear;//尾指针，若队列不空，指向队尾元素的下一个位置
}SqQueue;

void InitQueue(SqQueue & Q){
  Q.front=Q.rear=0;//此队列的索引从0开始，且Q.rear>=Q.front
}

bool EnQueue(SqQueue & Q,int e){
  if((Q.rear+1)%MAXQSIZE==Q.front) return false;//队列将满，牺牲一个存储空间
  Q.base[Q.rear]=e;
  Q.rear=(Q.rear+1)%MAXQSIZE;
  return true;
}

bool DeQueue(SqQueue & Q,int & e){
  if(Q.rear==Q.front) return false;//队列空
  e=Q.base[Q.front];
  Q.front=(Q.front+1)%MAXQSIZE;
  return true;
}

int Queue_size(SqQueue Q){
  //返回队列元素个数
  return (Q.rear+MAXQSIZE-Q.front)%MAXQSIZE;
}