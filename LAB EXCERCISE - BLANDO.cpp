#include <iostream>
#include <dirent.h>
using namespace std;
void Options();
void displayList();	
void listAllfiles();



int main(){
	
	int UserInput;
	
	do{
		
	Options();
	cout << "Enter the Number: ";
	cin >> UserInput;
	
	if(UserInput == 1){
	displayList();
	listAllfiles();
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
int listAllfiles(int Success){
	const char* path = "."; 
    DIR* directory = opendir(path);

    if (directory == nullptr) {
        cerr << "Error: Unable to open directory" << endl;
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(directory)) != nullptr) {
        cout << entry->d_name <<endl;
    }

    closedir(directory);
    
    
    return 0;
}
