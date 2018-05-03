#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip.h>

//链式栈


typedef struct Stack{
	Stack *next;
	int data;
}Stack,*SLink;

typedef struct{
	SLink top;
	int length;
}SqStack;

void InitStack(SqStack &S){
	//构造一个空栈
	S.top=NULL;						//设栈顶指针的初值为"空" 
	S.length=0;						//空栈中元素个数为
}//InitStack

void Push(SqStack &S,int &e){
	//在栈顶之上插入元素 e 为新的栈顶元素
			
	SLink p;
	p=new Stack;					//建新的结点
	p->data=e;	
	p->next=S.top;
	S.top=p; 
	++S.length;
}//Push

void Pop(SqStack &S,int &e){
	//若栈不空，则删除S的栈顶元素，用e返回其值
	if(!S.top)
	{	cout<<"此栈为空栈！！！"<<endl;
		exit(0);
	}
	e=S.top->data;
	S.top=S.top->next;
}//Pop

void GetTop(SqStack &S,int &e){
	//若栈不空，取栈顶元素，用e返回其值
	if(!S.top)
	{	cout<<"此栈为空栈!!!"<<endl;
		exit(0);
	}
	e=S.top->data;
	cout<<e<<endl;
}//GetTop

void ClearStack(SqStack &S){
	//
	if(!S.top)
		cout<<"此栈已经为空!!!"<<endl;
	S.top=NULL;
}//ClearStack


void main(){
	SqStack Stack;
	InitStack(Stack);
	int m,n,x,y,z,i=0;
	cout<<"请输入您要建立的栈的大小："<<endl;
	cin>>n;
	
	//需改正!!!
	do{
	cout<<"请选择操作："<<endl;
	cout<<"    "<<"1，进栈  2，出栈  3，查看栈顶值  4，清空栈  5，退出"<<endl;
	cin>>m;
	switch(m){
	case 1:	
		cout<<"请输入进栈值："<<endl;
		cin>>z;
		if(i==n)
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
	


	



	getch();
}
