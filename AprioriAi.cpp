#include<iostream>
#include <fstream>
#include<string>

using namespace std;

int num;
ifstream in("consolelist.txt");
ifstream in2("setlist.txt");
struct Cl{
	int id;
	string Consolename;
	Cl *next;
	Cl *prev;
}*list,*tail;



struct Il{
	int id;
	Il *next;
	Il *prev;
}*list2[100],*end[100];

struct Gl{
	int id;
	Gl *next;
	Gl *prev;
}*list3,*tail3;

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
void itemlist(){
	if(!in2){
		cout<<"no data";
	}
	else{
		char intt[255];
		int idd;
		int i=0;
		string s;
		while(in2){
			in2.getline(intt,255);
			s=intt;
			idd=intt[0]-'0';
			if(s!="stop"){
				if(s!="next"){
					Il *temp=new Il();
					temp->id=idd;
					if(list2[i]==NULL){
						list2[i]=end[i]=temp;
					}
					else{
						temp->prev=end[i];
						end[i]->next=temp;
						end[i]=temp;
					}
					list2[i]->prev=NULL;
					end[i]->next=NULL;
					
				}
				else{
				i++;	
				}
			} 
		
		else{
			num=i;
			break;
			
		}
		}
	}
}



void gamelist(){
	
	for(int a=0;a<5;a++){
	
		Gl *temp=new Gl();
		temp->id=1;
	
		if(list3==NULL){
		list3=tail3=temp;
		cout<<list3->id;
		}	
		else{
			
			tail3->next=temp;
			temp->prev=tail3;
			tail3=temp;
			
		}
		list3->prev=NULL;
		tail3->next=NULL;
	}
}

int main(){
	string sttr[100];
	 if(checktextdata==false)
	cout<<"cannot find data";

	else{
		inputdata();
		cout<<"List of item:\n";
		showdata();
		itemlist();
		cout<<"\n\n";
		cout<<"List of purchase per week\n";
		for(int i=0;i<=num;i++){
			cout<<i+1<<".   |";
			Il *temp=list2[i];
			while(temp!=NULL){
				cout<<temp->id<<"|";
				temp=temp->next;
			}
			cout<<endl;
		}
		gamelist();
		
	}
}
