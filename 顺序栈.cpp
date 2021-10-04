//栈的顺序存储表示
#define MAXQSIZE 100
typedef struct
{
  int Stack[MAXQSIZE];
  int top;//指向栈顶元素
}SqStack;

void InitStack(SqStack & S){
  S.top=-1;
}

bool Push(SqStack & S,int e){
  if(S.top+1>=MAXQSIZE) return false;//栈满
  S.Stack[++S.top]=e;
  return true;
}

bool Pop(SqStack & S,int & e){
  if(S.top==-1) return false;//栈空
  e=S.Stack[S.top--];
  return true;
}