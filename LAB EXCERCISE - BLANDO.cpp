#include <iostream>
using namespace std;
void Options();
void displayList();	
void listAllfiles



int main(){
	
	int UserInput;
	
	do{
		
	Options();
	cout << "Enter the Number: ";
	cin >> UserInput;
	
	if(UserInput == 1){
	void displayList();
		
	
	
	
	}
	
	
	}while(UserInput != 4);
	
	
	
	
	
	
	return 0;
}


void Options(){
	cout << "1. To Display List of Files " << endl;
	cout << "2. To Create New Directory" << endl;
	cout << "3. To Change the Working Directory" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter the Number: ";
	
}
void displayList(){
	cout << "1. List All Files " << endl;
	cout << "2. List of Extension Files" << endl;
	cout << "3. List if Name Wise" << endl;
	
}
