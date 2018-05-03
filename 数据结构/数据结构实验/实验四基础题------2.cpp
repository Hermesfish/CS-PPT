#include <iostream>
#include <conio.h>
#include <list>

using namespace std;

void disp(list<int> List){
	list<int>::iterator a;
    for(a=List.begin(); a != List.end(); a++)
      cout<<*a<<"  ";
	cout<<endl;
}//disp

int Search(list<int> List,int key){
	list<int>::iterator b;
	int i=1;
	for(b=List.begin(); b!= List.end(); b++)
	{
		if(key==*b){
			return i;		
		}
		i++;
	}
	return 0;
}//Search


void main(){
	list<int> L;
	int m[100];
	int i=0;
	cout<<"请输入您要建立的链表的各个节点的关键字，以0为结束！"<<endl;
	
	do{
		cin>>m[i++];
	}while(m[i-1]!=0);

	for(int j=0;j<i-1;j++){
		L.push_back(m[j]);
		cout<<"插入成功！"<<endl;
	}
	L.sort();
	cout<<"单链表节点顺序为："<<endl;
	disp(L);
	int n,x;
	do{
		cout<<"1,查找； 2，退出。"<<"\t";
		cin>>n;
		if(n==1){
			cout<<"请输入要查找的数："<<"\t";
			cin>>x;
			if(Search(L,x))
			{
				cout<<"查找成功！您要查找的节点为单链表的第"<<Search(L,x)<<"个节点。"<<endl;
			}
			else
				cout<<"查找失败！！！"<<endl;
		}	
	}while(n!=2);
getch();
}