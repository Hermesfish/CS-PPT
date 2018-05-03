//非递归中序遍历算法
#include <iostream>
#include <conio.h>
#include <stack>
using namespace std;


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

void InOrderTraverse(BiTree &T){
	//采用非递归算法输出二叉树中的值
	stack<BiTNode *> s;
	BiTree p=T;
	while(p||!s.empty()){
		if(p)
		{
			s.push(p);
			p=p->lchild;
		}								//根指针进栈，遍历左子树
		else
		{								//根指针退栈，访问根结点，遍历右子树
			p=s.top();
			cout<<p->data<<"    ";
			s.pop();
			p=p->rchild;
		}//else
	}//while
}//InOrderTraverse

void main(){
	BiTree Root;
	cout<<" '0' 作为空树"<<endl;
	Root=(BiTNode *)malloc(sizeof(BiTNode));
	CreateBiTree(Root);
	cout<<"中序输出二叉树："<<endl;
	InOrderTraverse(Root);
	cout<<endl;
	getch();
}
