#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

const STACK_INIT_SIZE=100;					//存储空间初始分配量
const STACKINCREMENT=10;						//存储空间分配增量

typedef struct{
	int *base;								//在构造之前和销毁之后，base的值为NULL
	int *top;								//栈顶指针
	int stacksize;							//当前已分配的存储空间，以元素为单位
}SqStack;

void InitStack(SqStack &S){
	//构造一个空栈S
	S.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!S.base)
		exit(0);							//存储分配失败
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	//cout<<"初始化完毕"<<endl;
}//InitStack

void GetTop(SqStack S,int &e){
	//若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if(S.top==S.base)
	{	cout<<"此栈为空!!!"<<endl;
		exit(0);
	}
	e=*(S.top-1);
	cout<<e<<endl;
//	cout<<"取值结束"<<endl;
}//GetTop

void Push(SqStack &S,int e){
	//插入元素e为新的栈顶元素
	if(S.top-S.base>S.stacksize){//栈满，追加存储空间
		S.base=(int *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(int));
	if(!S.base)
	{	cout<<"新分配空间失败！！！"<<endl;
		exit(0);
	}
	S.top = S.base + S.stacksize;
	S.stacksize += STACKINCREMENT;
	}
	*S.top++=e;
//	cout<<"插入元素成功"<<endl;
}//Push

void Pop(SqStack &S,int &e){
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(S.base==S.top)
	{	cout<<"此栈为空栈，无法删除！！！"<<endl;
		exit(0);
	}
	e=*--S.top;
//	cout<<"删除成功！！！"<<endl;
}//Pop

void ClearStack(SqStack &S){
	//把S置为空栈
	if(S.base==S.top)
		cout<<"此栈已经为空!!!"<<endl;
	S.top=S.base;
}//ClearStack

void main(){
	SqStack Stack;
	int m,n,x,y,z,i=0;
	InitStack(Stack);
	cout<<"请输入您要建立的栈的大小："<<endl;
	cin>>n;
	Stack.stacksize=n;
	do{
	cout<<"请选择操作："<<endl;
	cout<<"    "<<"1，进栈  2，出栈  3，查看栈顶值  4，清空栈  5，退出"<<endl;
	cin>>m;
	switch(m){

	case 1:	
		cout<<"请输入进栈值："<<endl;
		cin>>z;
		if(i==Stack.stacksize)
		{		
			cout<<"Sorry!!!"<<endl<<"栈溢出!!"<<endl<<"此程序将退出!!!"<<endl;
			exit(0);
		}
		Push(Stack,z);
		i++;
		break;
	case 2:		
		Pop(Stack,x);
		cout<<x<<"出栈"<<endl;
		break;
	case 3:	
		cout<<"栈顶值为："<<endl;
		GetTop(Stack,y);	
		break;
	case 4:		
		ClearStack(Stack);	
		break;
	case 5:	
		cout<<"Exit!!"<<endl;	
		break;
	default:
		cout<<"输入错误！！！此程序将退出！！！"<<endl;
		exit(0);
	}//switch
	}while(m!=5);
	getch();
}