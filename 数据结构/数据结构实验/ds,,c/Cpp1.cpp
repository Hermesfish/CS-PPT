#include <iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char TElemType;
typedef enum PointerTag {Link,Thread};   //Link==0:指针,Thread==1:线索
typedef struct BiThrNode
{
 TElemType  data;
 struct BiThrNode *lchild, *rchild;   //左右孩子指针
 PointerTag  LTag,RTag;     //左右标志即线索
}BiThrNode,*BiThrTree;BiThrTree pre;
Status CreateBiThrTree(BiThrTree &T)  //按先序次序输入二叉树中结点的值（一个字符），空格表示空树
 {                                     //构造二叉链表表示的二叉树T
 char ch;
 cout<<"请输入树中节点元素";
 cin>>&ch;
 if(ch=='#') T=NULL;
 else
 {
  if(!(T=(BiThrNode *)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
  T->data=ch;                 //生成根结点
  T->LTag=Link;
  T->RTag=Link;
  CreateBiThrTree(T->lchild); //构造左子树
  CreateBiThrTree(T->rchild); //构造右子树
 }
 return OK;
}//CreatBiTree
 
 
Status InOrderTraverse_Thr(BiThrTree &Thrt,Status (*Visit)(TElemType e))
{
 BiThrTree p;
 p=Thrt->lchild;        //p指向根节点
 while(p!=Thrt)         //空树或遍历结束时,p==T
 {
  while(p->LTag==Link) p=p->lchild;
  if(!Visit(p->data)) return ERROR;  //访问左子树为空的节点
  while(p->RTag==Thread && p->rchild!=Thrt)
  {
   p=p->rchild;
   Visit(p->data);      //访问后继节点
  }//while
  p=p->rchild;
 }//whle(!p)
 return OK;
}//InOrderTraverse
 

void InThreading(BiThrTree p)
{
 if(p)
 {
  InThreading(p->lchild);     //左子树线索化
  if(!p->lchild)       //前驱线索
  {
   p->LTag=Thread;
   p->lchild=pre;
  }//if
  if(!pre->rchild)      //后继线索
  {
   pre->RTag=Thread;
   pre->rchild=p;
  }//if
  pre=p;         //保持pre指向p的前驱
  InThreading(p->rchild);     //右子树线索化
 }
}//InThreading
 
 
Status InOrderThreadinng(BiThrTree &Thrt, BiThrTree T)
{            //中序遍历二叉树T,并将其中序线索化,Thrt指向头节点
 if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
 Thrt->LTag=Link; Thrt->RTag=Thread;  //建立头节点
 Thrt->rchild=Thrt;       //右指针回指
 if(!T) Thrt->lchild=Thrt;     //若二叉树为空,则左指针回指
 else
 {
  Thrt->lchild=T;  pre=Thrt;
  InThreading(T);       //中序遍历进行中序线索化
  pre->rchild=Thrt; pre->RTag=Thread; //最后一个节点线索化
  Thrt->rchild=pre;
 }
 return OK;
}//InOrderThreading
 

Status Visit(TElemType e)
{
 cout<<e<<endl;;
    return OK;
}
 
 
void main()
{
 BiThrTree  T,Thrt;
 cout<<"创建线索二叉树"<<endl;
 CreateBiThrTree(T);
cout<<"创建完成"<<endl;
cout<<"中序遍历线索化"<<endl;
 InOrderThreadinng(Thrt, T);
 cout<<"线索化完成"<<endl;
 cout<<"中序访问"<<endl;
 InOrderTraverse_Thr(Thrt,Visit);
 cout<<"中序访问完成"<<endl;
}
