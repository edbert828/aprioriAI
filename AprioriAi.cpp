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

bool checktextdata(){
		if(!in){
		return false;
	}
}
void inputdata(){
		
	char str[255];
	while(in){
		in.getline(str,255);
		if(in){
		 
		}
		
	}
}
int main(){
	string sttr[100];
	 int i=0;
	 if(checktextdata==false)
	cout<<"cannot find data";

	else{
		inputdata();
	}
}
