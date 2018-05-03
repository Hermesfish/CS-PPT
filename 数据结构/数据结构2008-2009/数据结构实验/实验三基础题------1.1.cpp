#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

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
	if(ch=='p')
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
	//����������е�����
	if(T!=NULL){
		InOrderTraverse(T->lchild);
		cout<<T->data<<"    ";
		InOrderTraverse(T->rchild);
	}

}//InOrderTraverse


void main(){
	BiTree Root;
	CreateBiTree(Root);
	InOrderTraverse(Root);
	cout<<endl;
getch();
}