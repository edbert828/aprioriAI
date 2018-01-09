#include<iostream>
#include <fstream>
#include<string>
using namespace std;

int main(){
	string sttr[100];
	 int i=0;
	ifstream in("consolelist.txt");
	if(!in){
		cout<<"cannot find data";
	}
	else{
	char str[255];
	
	while(in){
		in.getline(str,255);
		if(in){
		 sttr[i]=str;
		cout<<sttr[i]<<endl;
		}
		i++;
	}
	}
}
