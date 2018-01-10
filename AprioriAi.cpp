#include<iostream>
#include <fstream>
#include<string>
using namespace std;

ifstream in("consolelist.txt");

struct Cl{
	int id;
	string Consolename;
	Cl *next;
	Cl *prev;
}*list,*tail;

void inputtolist(string con,int id){
	
	Cl *temp=new Cl();
	temp->id=id;
	temp->Consolename=con;

	if(list==NULL){
	list=tail=temp;
	}	
	else{
		;
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
		
	}
	list->prev=NULL;
	tail->next=NULL;

		
}
bool checktextdata(){
		if(!in){
		return false;
	}
}
void inputdata(){
		
	char str[255];
	string sttr;
	int i=1;
	while(in){
		in.getline(str,255);
		if(in){
		 	sttr=str;
		 	inputtolist(sttr,i);
		}
		i++;
	}
}
void showdata(){
	Cl *show=list;
	while(show!=NULL){
		
		cout<<show->id<<"."<<show->Consolename<<endl;
		show=show->next;
	}
}
int main(){
	string sttr[100];
	 int i=0;
	 if(checktextdata==false)
	cout<<"cannot find data";

	else{
		inputdata();
		showdata();
	}
}
