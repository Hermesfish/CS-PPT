#include <iostream.h>
#include <conio.h>


int Search_Bin(int *a,int key,int n){
	//�������a���۰������ؼ��ֵ���key����������Ԫ�أ����ҵ�������ֵΪ
	//��Ԫ���ڱ��е�λ�ã�����Ϊ0
	int low=1;
	int high=n;
	int mid;
	while(low<=high){
		mid = (low+high)/2;
		if(key==a[mid])
			return mid;
		else if(key<a[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	return 0;
}//Search_Bin

void main(){
	int a[11];
	int x;
	for(int i=1;i<=10;i++){
		a[i]=i;
	}
	cout<<"������������ҵ�Ԫ��ֵ������1��10��ѡ�񣩣�"<<endl;
	cin>>x;
	cout<<"�������Ԫ�ص�λ��Ϊ��"<<endl;
	cout<<Search_Bin(a,x,10)<<endl;
getch();
}