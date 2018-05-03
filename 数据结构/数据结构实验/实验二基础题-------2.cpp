#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

//队空、入队和出队
int n=0;

typedef struct Q{
	int data;
	Q *next;
}Q,*QLink;

void InitQ(QLink &q){
	//构造一个队列
	q->next=q;
}//InitQ

void Push(QLink &q,int &e){
	//入队
	QLink p;
	p=new Q;
	p->data=e;
	p->next=q->next;
	q->next=p;
	n++;

}//Push

void OutQ(QLink &q,int &e){
	//出队
	QLink p;
	QLink t;
	p=new Q;
	t=new Q;
	p=q;
	int i;
	for(i=0;i<=n;i++){
		if(p->next->data==e)
		{
			t=p->next;
			p->next=t->next;
			delete t;
			break;
		}//if
		p=p->next;	
	}//for
	if(i==(n+1)){
		cout<<"您所输入的值不存在！此程序将退出！！"<<endl;
		exit(0);	
	}
}//OutQ

void ClearQ(QLink &q){
	//置队空
	q=q->next;
}//ClearQ

void checkQ(QLink &q,int &e){
	//查看队尾元素
	if(q->next==q){
		cout<<"此队列为空！！程序将退出！！"<<endl;
		exit(0);
	}
	e=q->next->data;
}//check


void main(){
	int m,x,n,y;
	QLink Qu;
	Qu=new Q;
	InitQ(Qu);
	do{
	cout<<"请选择操作："<<endl;
	cout<<"	1,入队  2，出队  3，查看队尾元素  4，清空队列  5，退出  "<<endl;
	cin>>x;
	switch(x){
	case 1:
		cout<<"请输入您想插入的值："<<"\t";
		cin>>m;
		Push(Qu,m);
		break;
	case 2:
		cout<<"请输入您想出队的值："<<"\t";
		cin>>n;
		OutQ(Qu,n);
		cout<<n<<"出队"<<endl;
		break;
	case 3:
		checkQ(Qu,y);
		cout<<"队尾元素为："<<y<<endl;
		break;
	}//switch
	}while(x!=5);













getch();
}