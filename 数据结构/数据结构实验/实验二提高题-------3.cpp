#include <iostream>
#include <string>

using namespace std;

bool comp(char x,char y){
	if(x==y)
		return true;
	else
		return false;
}//comp

void main(){
	char str[100];
	cout<<"ÇëÊäÈë×Ö·û´®£º"<<endl;
	cin>>str;
	int i=0,m;
	while(str[i]){
		i++;
	}
	m=i%2;
	if(m){
		int p=i-1,q=0;
		int j;
		for(j=0;j<(i-1)/2;j++){
			if(!comp(str[q++],str[p--]))
				break;
		}//for
		if(j==(i-1)/2)
			cout<<"´Ë×Ö·û´®¶Ô³Æ£¡£¡£¡"<<endl;
		else
			cout<<"´Ë×Ö·û´®²»¶Ô³Æ£¡£¡£¡"<<endl;
	}//if
	else{
		int p=i-1,q=0;
		int j;
		for(j=0;j<(i/2);j++){
			if(!comp(str[q++],str[p--]))
				break;
		}//for
		if(j==i/2)
			cout<<"´Ë×Ö·û´®¶Ô³Æ£¡£¡£¡"<<endl;
		else
			cout<<"´Ë×Ö·û´®²»¶Ô³Æ£¡£¡£¡"<<endl;
	}//else

	


}