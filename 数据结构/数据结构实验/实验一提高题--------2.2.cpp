#include <iostream.h>
#include <conio.h>

int c[100];

class JosephusCircle{
	int n;
	int s;
	int m;
public:
	JosephusCircle(){n=1;s=1;m=1;}
	JosephusCircle(int n1,int s1,int m1):n(n1),s(s1),m(m1){cout<<"��ʼ��������"<<endl;};
	friend int josephus(JosephusCircle& a);
};

int josephus(JosephusCircle& a){
	if(!(a.m*a.n*a.s)||(a.m==a.s&&a.m==a.n&&a.n==1))
		cout<<"������󣡣���"<<endl;
	else{
	int x=1,y=a.n;
	int i=a.s-1;
	int j;
	while(y){
		for(;i<a.n;i++){
			if(c[i]+1)
				c[i]=x++;
			if(c[i]==a.m)
			{	c[i]=-1;
				cout<<i+1<<"����"<<endl;
				x=1;
				y--;
				
			}
		}
		for(j=0;j<a.n;j++){
			if(c[j]+1)
				c[j]=x++;
			if(c[j]==a.m){
				c[j]=-1;
				
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
	}//else
	return 0;
}

void main(){
	int n,s,m,y=0;
	int x;
	do{
		for(int i=0;i<100;i++){
			c[i]=0;
		}
		cout<<"��������Ϸ��������"<<endl;
		cin>>n;
		cout<<"�����뿪ʼ��λ���뱨�����ȣ�"<<endl;
		cin>>s;
		cin>>m;
		JosephusCircle b(n,s,m);
		x=josephus(b);
		if(x)
		{
			cout<<x<<"ʤ��"<<endl<<endl;
		}
			cout<<"��ѡ��"<<endl;
			cout<<"1,������Ϸ; 2,�˳�����"<<endl;
			cin>>y;
	}while(y==1);
	getch();
}