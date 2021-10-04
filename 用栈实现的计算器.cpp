#include<iostream>
#include<stack>
using namespace std;

//大于是2，等于是1，小于是0；
int chars_r_m[7][7]={ {2,2,0,0,0,2,2},
                      {2,2,0,0,0,2,2},
                      {2,2,2,2,0,2,2},
                      {2,2,2,2,0,2,2},
                      {0,0,0,0,0,1,2},
                      {2,2,2,2,2,2,2},
                      {0,0,0,0,0,0,1} };

int altering_char(char c){
  int res=-1;
  switch(c){
    case '+':res=0;break;
    case '-':res=1;break;
    case '*':res=2;break;
    case '/':res=3;break;
    case '(':res=4;break;
    case ')':res=5;break;
    case '#':res=6;break;
    default:cout<<"error!";exit(0);break;
  }
  return res;
}

int chars_relation(char c1,char c2){
  int i1=altering_char(c1);
  int i2=altering_char(c2);
  return chars_r_m[i1][i2];
}

double _operator(double a,char optr,double b){
  double ans=0;
  switch(optr){
    case '+':ans=a+b;break;
    case '-':ans=a-b;break;
    case '*':ans=a*b;break;
    case '/':ans=a/b;break;
    default:cout<<"error!";exit(0);break;
  }
  return ans;
}

int main(){
  stack<char>OPTR;//算符栈
  stack<double>OPND;//操作数栈
  char c;
  scanf("%c",&c);
  if(c!='#'){
    cout<<"error!";
    exit(0);
  }
  else OPTR.push(c);
  bool flag=1;
  while(!OPTR.empty()){
    if(flag) scanf("%c",&c);
    else flag=1;
    if(c=='\n') break;
    if(c-'0'>=0 && c-'0'<=9){
      OPND.push(double(c-'0'));
    }
    else{
      int temp=chars_relation(OPTR.top(),c);
      if(temp==0){
        OPTR.push(c);
        continue;
      }
      else if(temp==1){
        OPTR.pop();
        continue;
      }
      else if(temp==2){
        double a=OPND.top();
        OPND.pop();
        double b=OPND.top();
        OPND.pop();
        double tans=_operator(b,OPTR.top(),a);
        OPTR.pop();
        OPND.push(tans);
        flag=0;
        continue;
      }
    }
  }
  cout<<OPND.top();
  return 0;
}

/*这是一个用栈实现的计算器，
目前只能计算输入为十以内正整数的算式，
但是可以识别算符的优先级*/