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

	string assignedDate;
	string description;
	string dueDate;
	string status;
	string newAssignmentString;

	// Read in assignments and add them to the assignment manager
	while (fin.good()) {

		assignmentNew.getReadData(fin);
		MainAssignments.addAssignment(assignmentNew);

	}

	cout << "Welcome to Assignment Manager!" << endl;

	bool again = true;
	string theDate;
	MainAssignments.checkComplete();
	MainAssignments.checkUncomplete();
	while (again) {

		int selection = Menu();

		switch (selection) {

		// Display Assignments
		case 1:
			cout << endl << "COMPLETED ASSIGNMENTS" << endl << endl;
			MainAssignments.printComp();
			cout << "==========================================================" << endl << endl;
			cout << "UNCOMPLETED ASSIGNMENTS" << endl << endl;
			MainAssignments.printUncomp();
			break;

		// Add Assignment
		case 2:

			cout << endl << "Enter the Date of the Assigned Homework. (Month-Day-Year)" << endl;
			cin >> assignedDate;
			cout << endl << "Enter the Description of the Homework." << endl;
			getchar();
			getline(cin, description);
			cout << endl << "Enter the Due Date of the Homework. (Month-Day-Year)" << endl;
			cin >> dueDate;
			cout << endl << "Enter the Status of the Homework. (completed or assigned)" << endl;
			cin >> status;

			//if not a valid assignment
			newAssignmentString = assignedDate +","+ description + "," + dueDate + "," + status;
			if (!assignmentNew.setAssignment(newAssignmentString)) {
				cout << endl << "Cannot Add Assignment." << endl;
			}

			//if that assignment already exists
			else if (MainAssignments.searchAssignment(assignedDate)) {
				cout << endl << "Cannot Add Assignment. Already Exists." << endl;
			}

			//add assignment to completed or uncomplete list
			else {
				MainAssignments.addAssignment(assignmentNew);
				cout << endl <<  "Created Assignment: ";
				assignmentNew.printTofile(cout);
				cout << endl;
			}

			break;

		// Edit Due Date
		case 3:
			cout << endl << "Enter the Date of the Assigned Homework You Wish to Modify. (Month-Day-Year)" << endl;
			cin >> theDate;

			//if not valid date, let user know
			if (!MainAssignments.editdueDate(theDate)) {
				cout << endl << "Not a Valid Date or Not Found." << endl;
			}
			break;

		// Edit Description
		case 4:
			cout << endl << "Enter the Date of the Assigned Homework You Wish to Modify. (Month-Day-Year)" << endl;
			cin >> theDate;
			
			//if you couldnt find or invalid date
			if (!MainAssignments.editDescription(theDate)) {
				cout << endl << "Not a Valid Date or Not Found." << endl;
			}

			break;
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// Complete Assignment 
		case 5:
			cout << endl << "Enter the Date of the Assigned Homework You Wish to Modify. (Month-Day-Year)" << endl;
			cin >> theDate;
			// look through uncompleted assignments to see if there is an assignment with that assigned date
			//if there is, change the status to complete
			if (MainAssignments.completeAssignment(theDate)) {
				cout << endl << "Changing This Assignment to Complete!" << endl;

			}
			//if not valid date, let user know
			else
				cout << endl << "Not a Valid Date." << endl;
			break;
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
			if (true) {
				ofstream fout("input.txt");
				MainAssignments.writeTofile(fout);
			}
			break;

		// Exit
		case 8:
			again = false;
			cout << endl << "Goodbye!" << endl;
			break;
		}

	}

	system("pause");

}