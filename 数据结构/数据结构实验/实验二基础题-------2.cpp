#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

//�ӿա���Ӻͳ���
int n=0;

typedef struct Q{
	int data;
	Q *next;
}Q,*QLink;

void InitQ(QLink &q){
	//����һ������
	q->next=q;
}//InitQ

void Push(QLink &q,int &e){
	//���
	QLink p;
	p=new Q;
	p->data=e;
	p->next=q->next;
	q->next=p;
	n++;

}//Push

void OutQ(QLink &q,int &e){
	//����
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
		cout<<"���������ֵ�����ڣ��˳����˳�����"<<endl;
		exit(0);	
	}
}//OutQ

void ClearQ(QLink &q){
	//�öӿ�
	q=q->next;
}//ClearQ

void checkQ(QLink &q,int &e){
	//�鿴��βԪ��
	if(q->next==q){
		cout<<"�˶���Ϊ�գ��������˳�����"<<endl;
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
	cout<<"��ѡ�������"<<endl;
	cout<<"	1,���  2������  3���鿴��βԪ��  4����ն���  5���˳�  "<<endl;
	cin>>x;
	switch(x){
	case 1:
		cout<<"��������������ֵ��"<<"\t";
		cin>>m;
		Push(Qu,m);
		break;
	case 2:
		cout<<"������������ӵ�ֵ��"<<"\t";
		cin>>n;
		OutQ(Qu,n);
		cout<<n<<"����"<<endl;
		break;
	case 3:
		checkQ(Qu,y);
		cout<<"��βԪ��Ϊ��"<<y<<endl;
		break;
	}//switch
	}while(x!=5);













getch();
}