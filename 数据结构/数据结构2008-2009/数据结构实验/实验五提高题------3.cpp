#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>

using namespace std;

const LIST_INIT_SIZE=70;
const LIST_INCREMENT=20;

typedef struct Student{
	double grade;
	int rank;
	char name[30];
}Student;

typedef struct Studentarry{
	Student *base;
	Student *top;
	int length;
	int listsize;
}Studentarry;

void Init(Studentarry &Stu){
	Stu.base=(Student *)malloc(LIST_INIT_SIZE*sizeof(Student));
	Stu.top=(Student *)malloc(sizeof(Student));
	Stu.top=Stu.base;
	if(!Stu.base){
		cout<<"Error!!!"<<endl;
		exit(0);
	}
	Stu.length=0;
	Stu.listsize=LIST_INIT_SIZE;
}//Init

void Push(Studentarry &Stu,double g,char *n){
	if(Stu.length>=Stu.listsize)
	{
		Student *newbase=(Student *)malloc(LIST_INCREMENT*sizeof(Student));
		Stu.base=newbase;
		Stu.listsize+=LIST_INCREMENT;
		Stu.top=&Stu.base[Stu.length];
	
	}
	Student *p;
	p=Stu.top+1;
	p->grade=g;
	strcpy(p->name,n);
	Stu.top++;
	Stu.length++;
}//Push

void Sort(Studentarry &Stu){
	Student *S;

	S=Stu.base;
	int p=Stu.length;
	for(int i=1;i<Stu.length;i++){
		for(int j=Stu.length-1;j>=i;j--){
			if(S[j+1].grade<S[j].grade)
			{
				S[50]=S[j+1];
				S[j+1]=S[j];
				S[j]=S[50];
				S[j].rank=p+1-j;
				S[j+1].rank=p+1-(j+1);
			}
			else if(S[j+1].grade==S[j].grade)
			{
				p--;
				S[j+1].rank = S[j].rank=p+1-j;
				p++;
			}
			else 
				continue;
		}
	}
}//Sort












void disp(Studentarry &Stu){
	Student *p;
	p=Stu.top;		

	for(int i=0;i<Stu.length;i++){
		
		cout<<"第"<<p->rank<<"名的名字为："<<p->name<<"\t";
		cout<<"第"<<p->rank<<"名的成绩为："<<p->grade<<endl;
		if(p==Stu.base)
			break;	
		p--;
	}
}//disp


void main(){
	Studentarry Stud;
	Init(Stud);
	double g;
	char n[30];
	int m;
	cout<<"请输入总人数:"<<endl;
	cin>>m;
	for(int i=0;i<m;i++){
		cout<<"请输入第"<<i+1<<"个学生的姓名："<<endl;
		cin>>n;
		cout<<"请输入第"<<i+1<<"个学生的成绩："<<endl;
		cin>>g;
		Push(Stud,g,n);	
	}
//	disp(Stud);

	Sort(Stud);

	disp(Stud);


getch();
}