#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

typedef struct BiTNode{
	char data;
	BiTNode *lchild,*rchild;		//���Һ���ָ��
}BiTNode,*BiTree;

int n=0;

void CreateBiTree(BiTree &T){
	//�������������������н���ֵ��һ���ַ������ո��ַ���ʾ����
	//������������ʾ�Ķ�����T
	char ch;
	cout<<"���������ݣ�"<<"\t";
	cin>>ch;
	if(ch=='0')
		T=NULL;
	else
	{
		T=(BiTNode * )malloc(sizeof(BiTNode));
		T->data=ch;						//���ɸ����
		CreateBiTree(T->lchild);		//����������
		CreateBiTree(T->rchild);		//����������
	}
}//CreateBiTree

void sum(BiTree &T){
	//����������Ľ�����Ŀ
	if(T){
		n++;
		sum(T->lchild);
		sum(T->rchild);
	}
}//sum


void main(){
	cout<<" '0' ��Ϊ����"<<endl;
	cout<<"������˶�������"<<endl;
	BiTree root;
	root=(BiTNode *)malloc(sizeof(BiTNode));
	CreateBiTree(root);
	sum(root);
	cout<<endl;
	cout<<"�˶������Ľ����Ϊ"<<n<<"��"<<endl;


getch();
}

