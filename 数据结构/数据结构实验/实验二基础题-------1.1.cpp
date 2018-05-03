#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

const STACK_INIT_SIZE=100;					//�洢�ռ��ʼ������
const STACKINCREMENT=10;						//�洢�ռ��������

typedef struct{
	int *base;								//�ڹ���֮ǰ������֮��base��ֵΪNULL
	int *top;								//ջ��ָ��
	int stacksize;							//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;

void InitStack(SqStack &S){
	//����һ����ջS
	S.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!S.base)
		exit(0);							//�洢����ʧ��
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	//cout<<"��ʼ�����"<<endl;
}//InitStack

void GetTop(SqStack S,int &e){
	//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if(S.top==S.base)
	{	cout<<"��ջΪ��!!!"<<endl;
		exit(0);
	}
	e=*(S.top-1);
	cout<<e<<endl;
//	cout<<"ȡֵ����"<<endl;
}//GetTop

void Push(SqStack &S,int e){
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if(S.top-S.base>S.stacksize){//ջ����׷�Ӵ洢�ռ�
		S.base=(int *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(int));
	if(!S.base)
	{	cout<<"�·���ռ�ʧ�ܣ�����"<<endl;
		exit(0);
	}
	S.top = S.base + S.stacksize;
	S.stacksize += STACKINCREMENT;
	}
	*S.top++=e;
//	cout<<"����Ԫ�سɹ�"<<endl;
}//Push

void Pop(SqStack &S,int &e){
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if(S.base==S.top)
	{	cout<<"��ջΪ��ջ���޷�ɾ��������"<<endl;
		exit(0);
	}
	e=*--S.top;
//	cout<<"ɾ���ɹ�������"<<endl;
}//Pop

void ClearStack(SqStack &S){
	//��S��Ϊ��ջ
	if(S.base==S.top)
		cout<<"��ջ�Ѿ�Ϊ��!!!"<<endl;
	S.top=S.base;
}//ClearStack

void main(){
	SqStack Stack;
	int m,n,x,y,z,i=0;
	InitStack(Stack);
	cout<<"��������Ҫ������ջ�Ĵ�С��"<<endl;
	cin>>n;
	Stack.stacksize=n;
	do{
	cout<<"��ѡ�������"<<endl;
	cout<<"    "<<"1����ջ  2����ջ  3���鿴ջ��ֵ  4�����ջ  5���˳�"<<endl;
	cin>>m;
	switch(m){

	case 1:	
		cout<<"�������ջֵ��"<<endl;
		cin>>z;
		if(i==Stack.stacksize)
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
}