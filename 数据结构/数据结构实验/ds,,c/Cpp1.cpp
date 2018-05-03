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
typedef enum PointerTag {Link,Thread};   //Link==0:ָ��,Thread==1:����
typedef struct BiThrNode
{
 TElemType  data;
 struct BiThrNode *lchild, *rchild;   //���Һ���ָ��
 PointerTag  LTag,RTag;     //���ұ�־������
}BiThrNode,*BiThrTree;BiThrTree pre;
Status CreateBiThrTree(BiThrTree &T)  //�������������������н���ֵ��һ���ַ������ո��ʾ����
 {                                     //������������ʾ�Ķ�����T
 char ch;
 cout<<"���������нڵ�Ԫ��";
 cin>>&ch;
 if(ch=='#') T=NULL;
 else
 {
  if(!(T=(BiThrNode *)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
  T->data=ch;                 //���ɸ����
  T->LTag=Link;
  T->RTag=Link;
  CreateBiThrTree(T->lchild); //����������
  CreateBiThrTree(T->rchild); //����������
 }
 return OK;
}//CreatBiTree
 
 
Status InOrderTraverse_Thr(BiThrTree &Thrt,Status (*Visit)(TElemType e))
{
 BiThrTree p;
 p=Thrt->lchild;        //pָ����ڵ�
 while(p!=Thrt)         //�������������ʱ,p==T
 {
  while(p->LTag==Link) p=p->lchild;
  if(!Visit(p->data)) return ERROR;  //����������Ϊ�յĽڵ�
  while(p->RTag==Thread && p->rchild!=Thrt)
  {
   p=p->rchild;
   Visit(p->data);      //���ʺ�̽ڵ�
  }//while
  p=p->rchild;
 }//whle(!p)
 return OK;
}//InOrderTraverse
 

void InThreading(BiThrTree p)
{
 if(p)
 {
  InThreading(p->lchild);     //������������
  if(!p->lchild)       //ǰ������
  {
   p->LTag=Thread;
   p->lchild=pre;
  }//if
  if(!pre->rchild)      //�������
  {
   pre->RTag=Thread;
   pre->rchild=p;
  }//if
  pre=p;         //����preָ��p��ǰ��
  InThreading(p->rchild);     //������������
 }
}//InThreading
 
 
Status InOrderThreadinng(BiThrTree &Thrt, BiThrTree T)
{            //�������������T,����������������,Thrtָ��ͷ�ڵ�
 if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
 Thrt->LTag=Link; Thrt->RTag=Thread;  //����ͷ�ڵ�
 Thrt->rchild=Thrt;       //��ָ���ָ
 if(!T) Thrt->lchild=Thrt;     //��������Ϊ��,����ָ���ָ
 else
 {
  Thrt->lchild=T;  pre=Thrt;
  InThreading(T);       //���������������������
  pre->rchild=Thrt; pre->RTag=Thread; //���һ���ڵ�������
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
 cout<<"��������������"<<endl;
 CreateBiThrTree(T);
cout<<"�������"<<endl;
cout<<"�������������"<<endl;
 InOrderThreadinng(Thrt, T);
 cout<<"���������"<<endl;
 cout<<"�������"<<endl;
 InOrderTraverse_Thr(Thrt,Visit);
 cout<<"����������"<<endl;
}
