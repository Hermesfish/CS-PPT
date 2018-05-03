#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

typedef struct BiTNode{
	char data;
	BiTNode *lchild,*rchild;		//左右孩子指针
}BiTNode,*BiTree;


void CreateBiTree(BiTree &T){
	//按先序次序输入二叉树中结点的值（一个字符），空格字符表示空树
	//构造二叉链表表示的二叉树T
	char ch;
	cout<<"请输入数据："<<"\t";
	cin>>ch;
	if(ch=='p')
		T=NULL;
	else
	{
		T=(BiTNode * )malloc(sizeof(BiTNode));
		T->data=ch;						//生成根结点
		CreateBiTree(T->lchild);		//构造左子树
		CreateBiTree(T->rchild);		//构造右子树
	}
}//CreateBiTree

void InOrderTraverse(BiTree &T){
	//中序输出树中的数据
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