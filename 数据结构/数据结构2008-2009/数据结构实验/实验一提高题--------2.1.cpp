#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

int a[100];

int josephus(int n,int s,int m)
{
	if(!(n*s*m))
	{
		cout<<"������󣡣���"<<endl;
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
				cout<<i+1<<"����"<<endl;
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
					cout<<j+1<<"����"<<endl;
			
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
		cout<<"����������Ϸ��������"<<endl;
		cin>>n;
		cout<<"�����뿪ʼ��λ���뱨�����ȣ�"<<endl;
		cin>>s;
		cin>>m;
		
		x=josephus(n,s,m);
			cout<<x<<"ʤ��"<<endl;
			cout<<"��ѡ��"<<endl;
			cout<<"1,������Ϸ; 2,�˳�����"<<endl;
			cin>>y;
		
	}while(y==1);
	getch();
}