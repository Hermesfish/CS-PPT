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
	//����һ���յ����Ա�L
	L.elem=(int*)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!L.elem)
		exit(0);						//�洢����ʧ��
	L.length=0;							//�ձ���Ϊ0
	L.listsize=LIST_INIT_SIZE;			//��ʼ�洢����
	cout<<"OK!"<<endl;
}

void ListInsert_Sq(SqList&L,int i,int e){
	//��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e��
	//i�ĺϷ�ֵΪ1<=i<=ListInsert_Sq(L)+1
	if(i<1||i>L.length+1)									//iֵ���Ϸ�
		cout<<"ERROR!"<<endl;
	if(L.length>=L.listsize){								//��ǰ�洢�ռ����������ӷ���
		int *newbase=(int*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(int));
		if(!newbase)
			exit(0);										//�洢����ʧ��
		L.elem=newbase;										//�»�ַ
		L.listsize+=LISTINCREMENT;							//���Ӵ洢����
	}
	int *q=&(L.elem[i-1]);
	for(int*p=&(L.elem[L.length-1]);p>=q;--p)
		*(p+1)=*p;
	*q=e;
	++L.length;
	cout<<"OK!"<<endl;
}//ListInsert_Sq

void ListDelete_Sq(SqList&L,int i,int&e){
	//��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ
	//i�ĺϷ�ֵΪ1<=i<=ListInsert_Sq(L)
	if((i<1)||(i>L.length))
		cout<<"ERROR!"<<endl;						//iֵ���Ϸ�
	int *p=&(L.elem[i-1]);							//pΪ��ɾ��Ԫ�ص�λ��
	e=*p;											//��ɾ��Ԫ�ص�ֵ����e 
	int *q=L.elem+L.length-1;						//��βԪ�ص�λ��
	for(++p;p<=q;++p)
		*(p-1)=*p;									//��ɾ��Ԫ��֮���Ԫ������
	--L.length;										//����1
	cout<<"OK!"<<endl;
}//ListDelete_Sq

bool compare(int m,int n){
	if(m==n)
		return true;
	else
		return false;
}

int LocateElem_Sq(SqList L,int e){
	//��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
	//���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0
	int i=1;											//i�ĳ�ֵΪ��1��Ԫ�ص�λ��
	int *p=L.elem;										//p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
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