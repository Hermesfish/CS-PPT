#include <iostream>
#include <string>
#include <conio.h>

using namespace std;


void sort(string *n,int m){
	string str;

	for(int i=1;i<m;i++){
		for(int j=m-1;j>=i;j--){
			if(n[j+1].compare(n[j])<=0)
			{
				str=n[j+1];
				n[j+1]=n[j];
				n[j]=str;
			}
		}
	}
}//sort

void disp(string *n,int m){
	for(int i=1;i<=m;i++){
		cout<<n[i]<<"\t";
	}
}//disp

void main(){
	string name[10];
	int i=1;	
	do{
	cout<<"请输入国家的名字(停止输入请输入’1‘)："<<endl;
	cin>>name[i];
	i++;
	}while(name[i-1]!="1");
	sort(name,i-2);
	disp(name,i-2);
	cout<<endl;
getch();
}