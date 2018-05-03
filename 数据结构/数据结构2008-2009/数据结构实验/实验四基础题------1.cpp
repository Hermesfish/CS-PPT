#include <iostream.h>
#include <conio.h>


int Search_Bin(int *a,int key,int n){
	//在有序表a中折半查找其关键字等于key的数据数据元素，若找到，则函数值为
	//该元素在表中的位置，否则为0
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
	cout<<"请输入您想查找的元素值（请在1—10中选择）："<<endl;
	cin>>x;
	cout<<"您输入的元素的位置为："<<endl;
	cout<<Search_Bin(a,x,10)<<endl;
getch();
}