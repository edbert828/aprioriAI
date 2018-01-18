#include<iostream>
#include <fstream>
#include<string>

using namespace std;

int num;
int start=0;
int start2=0;
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

struct Subset{
	int item;
	Subset *next;
	Subset *prev;	
};
struct Gl{
	int id;
	int value=0;
	int check;
	Subset *start; 
	Subset *end;	
	Gl *next;
	Gl *prev;
}*list3[100],*tail3[100];

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
		cout<<"no data found";
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

void count(){
	for(int i=0;i<=num;i++){
		Il *temp=list2[i];
		while(temp!=NULL){
			Gl *temp2=list3[start2];
			while(temp2!=NULL){
					if(start2==0){
						Subset *temp3=temp2->start;
					if(temp3->item==temp->id){
						temp2->value+=1;
					}
				}
				else if(start2==1){
					Subset *temp3=temp2->start;
						if(temp3->item==temp->id){
							Subset *temp4=temp3->next;
							Il *temps=temp;
							while(temps!=NULL){
								if(temp4->item==temps->id){
								temp2->value+=1;
							}
								temps=temps->next;
							}
						}
						
				}
				else if(start2==2){
					Subset *temp3=temp2->start;
					if(temp3->item==temp->id){
						Subset *temp4=temp3->next;
						Il *temps=temp;
						while(temps!=NULL){
							if(temp4->item==temps->id){
								Subset *temp5=temp4->next;
								Il *tempss=temp;
								while(tempss!=NULL){
								if(temp5->item==tempss->id){
								temp2->value+=1;
								}
								tempss=tempss->next;
							}	
							}
							temps=temps->next;
						}
					}
				}
					
				temp2=temp2->next;			
			}
			temp=temp->next;
		}
	}
	
}

void terminateprint(){
	Gl *temp2=list3[start2];
	while(temp2!=NULL){
		
		if(temp2->value<2){
			
			if(temp2->prev==NULL){
				
				list3[start2]=list3[start2]->next;
				list3[start2]->prev=NULL;
			}
			else if(temp2->next==NULL){
				tail3[start2]=tail3[start2]->prev;
				tail3[start2]->next=NULL;
			}
			else{
				temp2->prev->next=temp2->next;
				temp2->next->prev=temp2->prev;
				
			}	
			
		}
		
		temp2=temp2->next;
	}
	
	Gl *temp=list3[start2];
	while(temp!=NULL){
		Subset *temp3=temp->start;
		while(temp3!=NULL){
			cout<<temp3->item<<"   ";
			temp3=temp3->next;
		}
		cout<<"|"<<temp->value<<endl;
		temp=temp->next;
	}
	
}
bool check2(){
	

	Gl *temp=list3[start2];
	while(temp!=NULL){
		if(temp->value>=2)
		return true;
		temp=temp->next;
	}
	return false;
}
bool check3(){
		int iii=0;
	Gl *testt=list3[start2];
	while(testt!=NULL){		
	iii++;
		testt=testt->next;
		
	}
	
	if(iii<2){
		return false;
	}
	return true;
}
bool gamelist(){
	if(start2+1==1){
		cout<<"First Iteration";
		Cl *temp=list;
		while(temp!=NULL){
			Gl *temp2= new Gl();
			Subset *temp3=new Subset();
			
			temp3->item=temp->id;
			temp2->start=temp3;
			if(list3[start2]==NULL){
				list3[start2]=tail3[start2]=temp2;
			
			}
			else{
				
				tail3[start2]->next=temp2;
				temp2->prev=tail3[start2];
				tail3[start2]=temp2;
			}
		
			list3[start2]->prev=NULL;
			tail3[start2]->next=NULL;
			
			
			temp=temp->next;
		}
		count();
		Gl *tempp =list3[start2];
		cout<<endl;
		while(tempp!=NULL){
			cout<<tempp->start->item<<"   |";
			cout<<tempp->value<<endl;
			tempp=tempp->next;
		}
		if(check2()==false){
			return false;
		}
		cout<<endl<<"terminate subset list"<<endl;
		terminateprint();
			if(check3()==false){
			return false;
		}
		start2++;
		return true;
	}
	else if(start2+1==2){
		cout<<"\n\nSecond Iteration\n\n";
		Gl *temps =list3[0];
		while(temps!=NULL){
		Gl *temps2 =temps->next;
		while(temps2!=NULL){
		Gl *temps3 =new Gl();
		
		for(int ii=0;ii<=start2;ii++){
		Subset *temps4= new Subset();
		if(ii==0){
			temps4->item=temps->start->item;
			
		}
		else if(ii==1){
			temps4->item=temps2->start->item;
			
		}
		if(temps3->start==NULL)
			temps3->start=temps4;
		else{
			temps3->start->next=temps4;
			temps4->prev=temps3->start;
		}
		}
		if(list3[start2]==NULL){
			list3[start2]=tail3[start2]=temps3;
		}
		else{
			tail3[start2]->next=temps3;
			temps3->prev=tail3[start2];
			tail3[start2]=temps3;
		}
		list3[start2]->prev=NULL;
		tail3[start2]->next=NULL;
		temps2=temps2->next;
		}
		temps=temps->next;
		
		}
		count();
		Gl *show=list3[start2];
		while(show!=NULL){
			Subset *show2=show->start;
			while(show2!=NULL){
				cout<<show2->item<<"   ";
				show2=show2->next;
			}
			cout<<"|"<<show->value;
			cout<<endl;
			show=show->next;
		}
		if(check2()==false){
			return false;
		}
		cout<<endl<<endl;
		terminateprint();
		if(check3()==false){
			return false;
		}
		start2++;
		return true;
	}
	else if(start2+1==3){
		cout<<"\n\nLast Iteration";
		Gl *tempss = list3[start2-1];
		while(tempss!=NULL){
			Subset *tempss2=tempss->start;
			Gl *tempss3=tempss->next;
			while(tempss3!=NULL){
				Subset *tempss4=tempss3->start;
				if(tempss2->item==tempss4->item){
					Subset *tempss5=tempss2->next;
					Gl *tempss6=tempss3->next;
					
					while(tempss6!=NULL){
						Subset *tempss7=tempss6->start;

						if(tempss5->item==tempss6->start->item){
							if(tempss3->start->next->item==tempss7->next->item){
									Gl *tempss8=new Gl();
									
									Subset *tempss9=new Subset();
									tempss9->item=tempss->start->item;
									tempss9->next=tempss->start->next;
									tempss9->next->prev=tempss9;
								
									tempss9->next->next=tempss7->next;
									tempss9->next->next->prev=tempss9->next;
									tempss8->start=tempss9;
									
									if(list3[start2]==NULL){
										list3[start2]=tail3[start2]=tempss8;
									}
									else{
										tail3[start2]->next=tempss8;
										tempss8->prev=tail3[start2];
										tail3[start2]=tempss8;
									}
									
							}
						}
						tempss6=tempss6->next;
					}
				}
				tempss3=tempss3->next;
			}
			tempss=tempss->next;
		}
		
	
		cout<<endl;
		count();
		Gl *show=list3[start2];
		while(show!=NULL){
			Subset *show2=show->start;
			while(show2!=NULL){
				cout<<show2->item<<"  ";
				show2=show2->next;
			}
			cout<<"|"<<show->value;
			cout<<"\n";
			show=show->next;
		}
		if(check3()==false){
			cout<<"a";
			return false;
		}
			terminateprint();
			return false;
	}
	return false;
	
}

void startai(){
	while(1){
	if(	gamelist()==false){
		
		break;
	}
	
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
		cout<<"\n\n\n";
		
		string start="n";

		while(start!="y" && start!="Y"){
		cout<<"Start Algorith when press (Y/y):";
		cin>>start;
		if(start=="y" || start=="Y")
		startai();
		
	}
		
	}
}
