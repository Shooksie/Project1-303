#include"AssignManger.h"
#include"Assignment.h"
#include <iostream>
#include <fstream>

using namespace std;

void main() {

	ifstream fin("input.txt");


	// Check for file errors first
	if (!fin)
	{
		cout << "Error opening input files!\n";
		system("pause");
		return;
	}
	//WHY wont this work.s.df.sdf
	

	assignmentManager MainAssignments;
	assignment assignmentNew;
	MainAssignments.addAssignment(assignmentNew);

	assignmentNew.getReadData(fin);

	cout << assignmentNew.getDueDate();
	/*
	int answer;
	cout << "Welcome to Assignment Manager!" << endl << endl << "Would you like to being? " << "Yes = 1  &  No = 0" << endl;
	cin >> answer;
	while (answer != 0 && answer != 1) {
		cout << endl << "Not Valid Input.  Please Try Again." << endl;
		cin >> answer;
		
	}
	
		if (answer == 1) {
		cout << endl << setw(12) << "MENU" << endl << endl;
		cout << "1 Display Assignments" << endl << "2 Add Assignment" << endl << "3 Edit Due Date" << endl << "4 Edit Description" << endl << "5 Complete Assignment"
			 << endl << "6 Number of Late Assignments" << endl << "7 Save" << endl << "8 Exit" << endl << endl;
		cout << "Enter a digit that corresponds with an action. " << endl;
		cin >> answer;
		while (answer != 1 && answer != 2 && answer != 3 && answer != 4 && answer != 5 && answer != 6 && answer != 7 && answer != 8) {
			cout << endl << "Not Valid Input.  Please Try Again." << endl;
			cin >> answer;
			
		}
		if (answer == 1) {}
		if (answer == 2) {}
		if (answer == 3) {}
		if (answer == 4) {}
		if (answer == 5) {}
		if (answer == 6) {}
		if (answer == 7) {}
		if (answer == 8) {}
	


		
			
			
			
	}
	else if (answer == 0) {
		cout << endl << "Good Bye!" << endl;
		
	}*/
	
		
		system("pause");
				//////////////////////////////////////////////////////////////////////////Sarah
}
