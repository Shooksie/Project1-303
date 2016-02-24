#include"AssignManger.h"
#include"Assignment.h"
#include"Menu.h"
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


	assignmentManager MainAssignments;
	assignment assignmentNew;

	// Read in assignments and add them to the assignment manager
	while (fin.good()) {

		assignmentNew.getReadData(fin);
		MainAssignments.addAssignment(assignmentNew);

	}

	cout << "Welcome to Assignment Manager!" << endl;

	bool again = true;
	string theDate;

	while (again) {

		int selection = Menu();

		switch (selection) {

			// Display Assignments
		case 1:
			cout << endl << "COMPLETED ASSIGNMENTS" << endl << endl;
			MainAssignments.printComp();
			cout << endl << "==========================================================" << endl << endl;
			cout << "UNCOMPLETED ASSIGNMENTS" << endl << endl;
			MainAssignments.printUncomp();
			break;

			// Add Assignment
		case 2:
			cout << "not done";
			break;

			// Edit Due Date
		case 3:
			cout << "not done";
			break;

			// Edit Description
		case 4:
			cout << "not done";
			break;

			// Complete Assignment 
		case 5:
			cout << endl << "Enter the Date of the Assigned Homework You Wish to Complete. (Month-Day-Year)" << endl;
			cin >> theDate;
			// look through uncompleted assignments to see if there is an assignment with that assigned date
			//if there is, change the status to complete
			if (MainAssignments.searchAssignment(theDate) == true) {
				cout << endl << "Changing This Assignment to Complete!" << endl;
				//THIS IS WHERE IM HAVING A LOGIC ISSUE
			}
			//if not valid date, let user know
			else
				cout << endl << "Not a Valid Date." << endl;
			break;

			// Number of Late Assignments 
		case 6:
			if (MainAssignments.getNumberLate() > 1 || MainAssignments.getNumberofAssignments() == 0) {
				cout << endl << "THERE ARE " << MainAssignments.getNumberLate() << " LATE ASSIGNMENTS" << endl << endl;
				MainAssignments.printLate();
			}

			else if (MainAssignments.getNumberLate() == 1) {
				cout << endl << "THERE IS " << MainAssignments.getNumberLate() << " LATE ASSIGNMENT." << endl << endl;
				MainAssignments.printLate();
			}
			break;

			// Save Changes
		case 7:
			cout << "not done";
			break;

			// Exit
		case 8:
			again = false;
			cout << endl << "Goodbye!" << endl;
			break;
		}

	}
	/*
	Date newDate = assignmentNew.getAssignedDate();
	cout << newDate.toString() << endl;
	Date date = assignmentNew.date1("1-2-321");
	string text = date.toString();
	cout << text;
	if (newDate > date) {
	cout << "this happend later in time?";
	}
	else
	cout << "earlier";
	*/
	system("pause");
	//////////////////////////////////////////////////////////////////////////Sarah
}