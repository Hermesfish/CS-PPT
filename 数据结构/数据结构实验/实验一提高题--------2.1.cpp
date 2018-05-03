#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

int a[100];

int josephus(int n,int s,int m)
{
	if(!(n*s*m))
	{
		cout<<"输入错误！！！"<<endl;
		exit(0);
	}
	int x=1,y=n;
	int i=s-1;
	int j;
	while(y){
		for(;i<n;i++){
			if(a[i]+1)
				a[i]=x++;
			if(a[i]==m)
			{	a[i]=-1;
				cout<<i+1<<"出局"<<endl;
				x=1;
				y--;
				
			}
		}
		for(j=0;j<n;j++){
			if(a[j]+1)
				a[j]=x++;
			if(a[j]==m){
				a[j]=-1;
				
				x=1;
				y--;
				if(!y)
					break;
				else
					cout<<j+1<<"出局"<<endl;
			
			}
		}
	}
		return (j+1);

}

void main(){
	int n,s,m,y=0;
	int x;
	do{
		for(int i=0;i<100;i++){
			a[i]=0;
		}
		cout<<"请输入人游戏总人数："<<endl;
		cin>>n;
		cout<<"请输入开始人位置与报数长度："<<endl;
		cin>>s;
		cin>>m;
		
		x=josephus(n,s,m);
			cout<<x<<"胜出"<<endl;
			cout<<"请选择："<<endl;
			cout<<"1,重新游戏; 2,退出程序："<<endl;
			cin>>y;
		
	}while(y==1);
	getch();
}