//链队列

typedef struct QNode
{//结点类型
  int data;
  struct QNode *next;
}*QueuePtr;

typedef struct 
{//链队列类型
  QueuePtr front;//队头指针
  QueuePtr rear;//队尾指针
}LinkQueue;

bool InitQueue(LinkQueue & Q){
  Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
  if(Q.front==NULL) return false;
  Q.front->next=NULL;//不要忘记将新生成的头结点的next置空
  else return true;
}

bool EnQueue(LinkQueue & Q,int e){
  QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
  if(p==NULL) return false;
  p->data=e;
  p->next=NULL;
  Q.rear->next=p;
  Q.rear=p;
  return true;
}

bool DeQueue(LinkQueue & Q,int & e){
  if(Q.front==Q.rear) return false;//队空，无法出队
  QueuePtr p=Q.front->next;
  e=p->data;
  Q.front->next=p->next;
  //将最后一个元素删除时Q.rear会变成野指针，需要特殊处理
  if(Q.rear==p) Q.rear=Q.front;
  free(p);
  return true;
}