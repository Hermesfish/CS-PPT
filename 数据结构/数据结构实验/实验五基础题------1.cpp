#include <iostream.h>
#include <conio.h>

void ShellInsert(int *a,int dk,int n){
	//对顺序表a作一趟希尔插入排序。
	int i;
	int j;
	for(i=dk+1;i<=n;i++){
		if(a[i]<a[i-dk])
		{                                                                                    
			a[0]=a[i];
			for(j=i-dk;j>0&&(a[0]<a[j]);j-=dk)	
				a[j+dk]=a[j];
			a[j+dk]=a[0];
		}
	}//for
}//ShellInsert

void ShellSort(int *a,int *dlta,int t,int m){
	//按增量序列dlta[0...t-1]对顺序表a作希尔排序
	int k;
	for(k=0;k<t;k++)
		ShellInsert(a,dlta[k],m);
}//ShellSort

void main(){
	int A[100];
	int dlta[2]={1,3};
	int n;
	cout<<"请输入您要排序的数的个数（小于100）："<<endl;
	cin>>n;
	cout<<"请输入这组数："<<"\t";
	for(int i=1;i<=n;i++)
		cin>>A[i];
	cout<<"希尔排序后的结果为："<<endl;
	
	ShellSort(A,dlta,2,n);
	
	for(int j=1;j<=n;j++)
		cout<<A[j]<<"\t";
	cout<<endl;
getch();
}