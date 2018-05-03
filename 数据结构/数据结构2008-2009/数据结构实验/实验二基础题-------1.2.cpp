#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip.h>

//��ʽջ


typedef struct Stack{
	Stack *next;
	int data;
}Stack,*SLink;

typedef struct{
	SLink top;
	int length;
}SqStack;

void InitStack(SqStack &S){
	//����һ����ջ
	S.top=NULL;						//��ջ��ָ��ĳ�ֵΪ"��" 
	S.length=0;						//��ջ��Ԫ�ظ���Ϊ
}//InitStack

void Push(SqStack &S,int &e){
	//��ջ��֮�ϲ���Ԫ�� e Ϊ�µ�ջ��Ԫ��
			
	SLink p;
	p=new Stack;					//���µĽ��
	p->data=e;	
	p->next=S.top;
	S.top=p; 
	++S.length;
}//Push

void Pop(SqStack &S,int &e){
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ
	if(!S.top)
	{	cout<<"��ջΪ��ջ������"<<endl;
		exit(0);
	}
	e=S.top->data;
	S.top=S.top->next;
}//Pop

void GetTop(SqStack &S,int &e){
	//��ջ���գ�ȡջ��Ԫ�أ���e������ֵ
	if(!S.top)
	{	cout<<"��ջΪ��ջ!!!"<<endl;
		exit(0);
	}
	e=S.top->data;
	cout<<e<<endl;
}//GetTop

void ClearStack(SqStack &S){
	//
	if(!S.top)
		cout<<"��ջ�Ѿ�Ϊ��!!!"<<endl;
	S.top=NULL;
}//ClearStack


void main(){
	SqStack Stack;
	InitStack(Stack);
	int m,n,x,y,z,i=0;
	cout<<"��������Ҫ������ջ�Ĵ�С��"<<endl;
	cin>>n;
	
	//�����!!!
	do{
	cout<<"��ѡ�������"<<endl;
	cout<<"    "<<"1����ջ  2����ջ  3���鿴ջ��ֵ  4�����ջ  5���˳�"<<endl;
	cin>>m;
	switch(m){
	case 1:	
		cout<<"�������ջֵ��"<<endl;
		cin>>z;
		if(i==n)
		{		
			cout<<"Sorry!!!"<<endl<<"ջ���!!"<<endl<<"�˳����˳�!!!"<<endl;
			exit(0);
		}
		Push(Stack,z);
		i++;
		break;
	case 2:		
		Pop(Stack,x);
		cout<<x<<"��ջ"<<endl;
		break;
	case 3:	
		cout<<"ջ��ֵΪ��"<<endl;
		GetTop(Stack,y);	
		break;
	case 4:		
		ClearStack(Stack);	
		break;
	case 5:	
		cout<<"Exit!!"<<endl;	
		break;
	default:
		cout<<"������󣡣����˳����˳�������"<<endl;
		exit(0);
	}//switch
	}while(m!=5);
	getch();
	


	



	getch();
}
