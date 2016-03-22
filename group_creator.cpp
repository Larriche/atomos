/***********************************************************************************
*                                                                                   *
*       Atomos v1.0                                                                 *
*                                                                                   *
*       Author - Richman Larry Clifford                                             *
*       20th March 2016                                                             *
*                                                                                   *
************************************************************************************/


#include <iostream>        // for screen input and output 
#include <vector>          // for the vector data structure
#include <algorithm>       // for the shuffling algorithm
#include <ctime>           // for getting current system time for seeding rand
#include <cstdlib>         // for system functionalities
#include <fstream>         // for file input and output

using namespace std;

int main()
{
	vector<string> names;
	vector<string>::iterator iter;
	ifstream data_src;
	ofstream output;
	int grp_max,i;
	
	system("color 0a");
	
	cout <<"\t\t\tAtomos Class Group Creator v1.0 \n\t\tCopyright 2016   -   Richman Larry Clifford\n";
	cout << "\t\t------------------------------------------\n\n\n";
	
	
	
	data_src.open("names.txt");
	
	if(data_src.fail()){
	    cout << "\tUnable to load names.txt.\n\tPlease,create a"
		     << " text file called names.txt with the \n\t"
	        << "names and place it in the program folder and run again.\n\n";
	    
		cout <<"\n\t";    
	    system("pause");
	    exit(1);
    }                                                    
		     
	while(!data_src.eof()){
		string name;
		getline(data_src,name);
		names.push_back(name);
	}
	data_src.close();
	
	     
	cout << "\tPlease enter number of people in each group:";
	cin >> grp_max;
	
	i = 1; // keeps count of group creation
	
	// shuffling the names
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(names.begin(),names.end());
	
	output.open("groups.txt");
	
	int picked = 0;
	for(iter = names.begin();iter != names.end();iter++){
		if(picked == grp_max){
			picked = 0;
			i++;
		}
		
		if(picked == 0)
		    output << "\n\nGROUP " << i << endl;
		    
		output << *iter << endl;
		picked++;
	}
		    	
	output.close();
	
	cout << "\n\n\tThe groups have been generated in groups.txt\n"
	     << "\n\tThanks for using Atomos. :)\n\t";
	system("pause");
	return 0;
}
