#include <iostream>
#include <dirent.h>

#include <vector>
#include <sys/>
using namespace std;
void Options();
void displayList();	
void listAllfiles();
void listExtensionFiles();


int main(){
	
	int UserInput;
	int choice;
	
	do{
		
	Options();
	cin >> UserInput;
	
	if(UserInput == 1){
	displayList();
	cout << "Enter Number: ";
	cin >> choice;
	
		if(choice == 1){
	listAllfiles();
	cout << "" <<endl;
		}else if(choice == 2){
		 listExtensionFiles();
		}	
		
		
		
		
		
		
		
		else{
		break;
		}
	
	
	
	
	
	
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
void listAllfiles(){
	const char* path = "."; 
    DIR* directory = opendir(path);

    if (directory == nullptr) {
        cerr << "Error: Unable to open directory" << endl;
        
    }

    struct dirent* entry;
    while ((entry = readdir(directory)) != nullptr) {
        cout << entry->d_name <<endl;
    }

    closedir(directory);
}
    
void listExtensionFiles(){
	string directory_path = "./"; // Current directory

    // List of file extensions to filter by
    vector<string> extensions = {".cpp", ".hpp", ".h", ".c", ".o"};

    // Open the directory
    DIR* dir = opendir(directory_path.c_str());
    if (dir == nullptr) {
        cerr << "Error opening directory: " << directory_path << std::endl;
        ;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        string filename = entry->d_name;
        string full_path = directory_path + "/" + filename;

        if (is_regular_file(full_path) && has_extension(filename, extensions)) {
            cout << filename << std::endl;
        }
    }
}   
    
}
