#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

const LIST_INIT_SIZE=10;
const LISTINCREMENT=1;

typedef struct{
	int  *elem;
	int length;
	int listsize;
}SqList;

void InitList_sq(SqList&L){
	//构造一个空的线性表L
	L.elem=(int*)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!L.elem)
		exit(0);						//存储分配失败
	L.length=0;							//空表长度为0
	L.listsize=LIST_INIT_SIZE;			//初始存储容量
	cout<<"OK!"<<endl;
}

void ListInsert_Sq(SqList&L,int i,int e){
	//在顺序线性表L中第i个位置之前插入新的元素e，
	//i的合法值为1<=i<=ListInsert_Sq(L)+1
	if(i<1||i>L.length+1)									//i值不合法
		cout<<"ERROR!"<<endl;
	if(L.length>=L.listsize){								//当前存储空间已满，增加分配
		int *newbase=(int*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(int));
		if(!newbase)
			exit(0);										//存储分配失败
		L.elem=newbase;										//新基址
		L.listsize+=LISTINCREMENT;							//增加存储容量
	}
	int *q=&(L.elem[i-1]);
	for(int*p=&(L.elem[L.length-1]);p>=q;--p)
		*(p+1)=*p;
	*q=e;
	++L.length;
	cout<<"OK!"<<endl;
}//ListInsert_Sq

void ListDelete_Sq(SqList&L,int i,int&e){
	//在顺序线性表L中删除第i个元素，并用e返回其值
	//i的合法值为1<=i<=ListInsert_Sq(L)
	if((i<1)||(i>L.length))
		cout<<"ERROR!"<<endl;						//i值不合法
	int *p=&(L.elem[i-1]);							//p为被删除元素的位置
	e=*p;											//被删除元素的值赋给e 
	int *q=L.elem+L.length-1;						//表尾元素的位置
	for(++p;p<=q;++p)
		*(p-1)=*p;									//被删除元素之后的元素左移
	--L.length;										//表长减1
	cout<<"OK!"<<endl;
}//ListDelete_Sq

bool compare(int m,int n){
	if(m==n)
		return true;
	else
		return false;
}

int LocateElem_Sq(SqList L,int e){
	//在顺序线性表L中查找第1个值与e满足compare()的元素的位序
	//若找到，则返回其在L中的位序，否则返回0
	int i=1;											//i的初值为第1个元素的位序
	int *p=L.elem;										//p的初值为第1个元素的存储位置
	while(i<=L.length&&!compare(*p++,e))						
		++i;
	if(i<=L.length)
		return i;
	else 
		return 0;
}//LocateElem_Sq

void disp(SqList&L){
	int *p=L.elem;
	for(int i=0;i<L.listsize;i++){
		cout<<*p<<"\t";
		p++;
	}
}




void main(){
	SqList List;
	InitList_sq(List);
	int *p=List.elem;
	for(int i=0;i<List.listsize;i++){
		*p=i+1;
		p++;
	}
	cout<<endl;
	disp(List);
	cout<<endl;

	getch();
}