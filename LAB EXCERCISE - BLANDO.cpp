#include <iostream>
#include <dirent.h>
#include <vector>
#include <sys/stat.h>
#include <cstdio>
#include <cstring>
using namespace std;

void Options();
void displayList();	
void listAllfiles();
void listExtensionFiles();
void listNameWise(const string& directory_path, const string& file_to_search);


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
	cout << "List of All Files: " <<endl;
	cout <<endl;
	
	listAllfiles();
	cout <<endl;
	
	}
	if(choice == 2){
		cout << "List of All Extesnsion Files: " <<endl;	
		cout <<endl;
	
		listExtensionFiles();
		cout <<endl;
	
	}
	if(choice == 3)	{
		cout <<"List of File Name Wise: " <<endl;
		
    	string directory_path = "C://Users//user//Documents"; 
   		string file_to_search = "Wise.txt";
   		listNameWise(directory_path, file_to_search);
    	
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
	const char* path = "C://Users//user//Documents"; 
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
	// Directory path to search
    std::string directory_path = "C://Users//user//Documents"; // Current directory

    // List of file extensions to filter by
    vector<std::string> extensions = {".cpp", ".txt", ".pptx"};

    // Open the directory
    DIR* dir = opendir(directory_path.c_str());
    if (dir == nullptr) {
        cerr << "Error opening directory: " << directory_path << endl;
        
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        string filename = entry->d_name;
        string full_path = directory_path + "/" + filename;

        // Check if the entry is a regular file
        struct stat file_stat;
        if (stat(full_path.c_str(), &file_stat) == 0 && S_ISREG(file_stat.st_mode)) {
            // Check if the file has one of the desired extensions
            bool has_ext = false;
            for (const auto& ext : extensions) {
                if (filename.size() >= ext.size() && 
                    filename.compare(filename.size() - ext.size(), ext.size(), ext) == 0) {
                    has_ext = true;
                    break;
                }
            }

            if (has_ext) {
                cout << filename << endl;
            }
        }
    }

    // Close the directory
    closedir(dir);
} 


void listNameWise(const std::string& directory_path, const std::string& file_to_search) {
    // Open the directory
    DIR* dir = opendir(directory_path.c_str());
    if (dir == nullptr) {
        std::cerr << "Error opening directory: " << directory_path << std::endl;
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string filename = entry->d_name;
        std::string full_path = directory_path + "/" + filename;

        // Check if the entry is a regular file
        struct stat file_stat;
        if (stat(full_path.c_str(), &file_stat) == 0 && S_ISREG(file_stat.st_mode)) {
            if (filename == file_to_search) {
                std::cout << filename << std::endl;
                closedir(dir);
                return; // Exit after finding and displaying the file
            }
        }
    }

    closedir(dir);
}


