//�ǵݹ���������㷨
#include <iostream>
#include <conio.h>
#include <stack>
using namespace std;


typedef struct BiTNode{
	char data;
	BiTNode *lchild,*rchild;		//���Һ���ָ��
}BiTNode,*BiTree;


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

void InOrderTraverse(BiTree &T){
	//���÷ǵݹ��㷨����������е�ֵ
	stack<BiTNode *> s;
	BiTree p=T;
	while(p||!s.empty()){
		if(p)
		{
			s.push(p);
			p=p->lchild;
		}								//��ָ���ջ������������
		else
		{								//��ָ����ջ�����ʸ���㣬����������
			p=s.top();
			cout<<p->data<<"    ";
			s.pop();
			p=p->rchild;
		}//else
	}//while
}//InOrderTraverse

void main(){
	BiTree Root;
	cout<<" '0' ��Ϊ����"<<endl;
	Root=(BiTNode *)malloc(sizeof(BiTNode));
	CreateBiTree(Root);
	cout<<"���������������"<<endl;
	InOrderTraverse(Root);
	cout<<endl;
	getch();
}
