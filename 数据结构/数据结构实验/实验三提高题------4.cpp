#include <iostream.>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;


typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;							//��̬��������洢�շ�����

typedef char **HuffmanCode;						//��̬��������洢�շ��������

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n){
	//w���n���ַ���Ȩֵ����>0��,����շ�����HT�������n���ַ��ĺշ�������HC
	if(n<=1)
	{	cout<<"������󣡣���"<<endl;
		exit(0);
	}
	int m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));	//0�ŵ�Ԫδ��
	int i;
	int s1,s2;
	HuffmanTree p;
	for(p=HT+1,i=1;i<=n;++i,++p,++w)
	{
		(*p).weight=*w;
		(*p).parent=0;
		(*p).lchild=0;
		(*p).rchild=0;	
	}
	for(;i<=m;++i,++p){
		(*p).weight=0;
		(*p).parent=0;
		(*p).lchild=0;
		(*p).rchild=0;
	}
	for(i=n+1;i<=m;i++){
		//��HT[1...i-1]ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1��s2
		Select(HT,i-1,s1,s2);//�����⣡������������������������������������������������
		HT[s1].parent=i;	HT[s2].parent=i;
		HT[i].lchild=s1;	HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	//--------��Ҷ�ӵ���������ÿ���ַ��ĺշ�������------
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));		//����n���ַ������ͷָ������
	char *cd=(char *)malloc(n*sizeof(char));			//���������Ĺ����ռ�
	cd[n-1]='\0';
	unsigned int c,f;
	for(i=1;i<=n;i++){
		int start=n-1;									//���������λ��
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)//��Ҷ�ӵ������������
			if(HT[f].lchild==c)
				cd[--start]='0';
			else
				cd[--start]='1';
			HC[i]=(char *)malloc((n-start)*sizeof(char));	//Ϊ��i���ַ��������ռ�
			strcpy(HC[i],&cd[start]);
	}//for
	free(cd);												//�ͷŹ����ռ�
}//HuffmanCoding




















void main(){



getch();
}