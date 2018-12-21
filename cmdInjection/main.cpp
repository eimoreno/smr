#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main (int argc, char* argv[]){
	int opt;
	
	cout << "Listing options" << endl;
	opterr=0;
	
	while((opt=getopt(argc, argv, "abc"))!=-1){
		
		switch(opt){
			case 'a':
			  cout << "Opção " << char(optopt) << endl;			
			  break;
			case 'b':
			  cout << "Opção " << char(optopt) << endl;			
			  break;
			case 'c':
			  cout << "Opção " << char(optopt) << endl;			
			  break;
			case '?':
			  cerr << "Opção desconhecida " << char(optopt) << endl;			
			  break;
			default:
			  cerr << "Opção desconhecida ????"<< endl;						  			  
		}
		
	}
}
