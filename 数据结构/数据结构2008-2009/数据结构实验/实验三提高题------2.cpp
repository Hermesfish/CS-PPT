#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

typedef struct BiTNode{
	char data;
	BiTNode *lchild,*rchild;		//左右孩子指针
}BiTNode,*BiTree;

int n=0;

void CreateBiTree(BiTree &T){
	//按先序次序输入二叉树中结点的值（一个字符），空格字符表示空树
	//构造二叉链表表示的二叉树T
	char ch;
	cout<<"请输入数据："<<"\t";
	cin>>ch;
	if(ch=='0')
		T=NULL;
	else
	{
		T=(BiTNode * )malloc(sizeof(BiTNode));
		T->data=ch;						//生成根结点
		CreateBiTree(T->lchild);		//构造左子树
		CreateBiTree(T->rchild);		//构造右子树
	}
}//CreateBiTree

void sum(BiTree &T){
	//求出二叉树的结点的数目
	if(T){
		n++;
		sum(T->lchild);
		sum(T->rchild);
	}
}//sum


void main(){
	cout<<" '0' 作为空树"<<endl;
	cout<<"请输入此二叉树。"<<endl;
	BiTree root;
	root=(BiTNode *)malloc(sizeof(BiTNode));
	CreateBiTree(root);
	sum(root);
	cout<<endl;
	cout<<"此二叉树的结点数为"<<n<<"个"<<endl;


getch();
}

