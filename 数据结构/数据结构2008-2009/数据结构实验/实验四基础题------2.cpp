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
	cout<<"��������Ҫ����������ĸ����ڵ�Ĺؼ��֣���0Ϊ������"<<endl;
	
	do{
		cin>>m[i++];
	}while(m[i-1]!=0);

	for(int j=0;j<i-1;j++){
		L.push_back(m[j]);
		cout<<"����ɹ���"<<endl;
	}
	L.sort();
	cout<<"������ڵ�˳��Ϊ��"<<endl;
	disp(L);
	int n,x;
	do{
		cout<<"1,���ң� 2���˳���"<<"\t";
		cin>>n;
		if(n==1){
			cout<<"������Ҫ���ҵ�����"<<"\t";
			cin>>x;
			if(Search(L,x))
			{
				cout<<"���ҳɹ�����Ҫ���ҵĽڵ�Ϊ������ĵ�"<<Search(L,x)<<"���ڵ㡣"<<endl;
			}
			else
				cout<<"����ʧ�ܣ�����"<<endl;
		}	
	}while(n!=2);
getch();
}