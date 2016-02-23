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

	while (fin.good()) {

		assignmentNew.getReadData(fin);
		MainAssignments.addAssignment(assignmentNew);

	}


	int answer;
	cout << "Welcome to Assignment Manager!" << endl << endl << "Would you like to begin? " << "Yes = 1  &  No = 0" << endl;
	cin >> answer;
	while (answer != 0 && answer != 1) {
		cout << endl << "Not Valid Input.  Please Try Again." << endl;
		cin >> answer;
	}

	bool again;

	if (answer == 1)
		again = true;
	else
		again = false;


	while (again) {

		int selection = Menu();

		switch (selection) {
		case 1:
			cout << endl << "COMPLETED ASSIGNMENTS" << endl << endl;
			MainAssignments.printComp();
			cout << endl << "==========================================================" << endl << endl;
			cout << "UNCOMPLETED ASSIGNMENTS" << endl << endl;
			MainAssignments.printUncomp();
			break;
		case 2:
			cout << "not done";
			break;
		case 3:
			cout << "not done";
			break;
		case 4:
			cout << "not done";
			break;
		case 5:
			cout << "not done";
			break;
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
		case 7:
			cout << "not done";
			break;
		case 8:
			cout << "not done";
			break;
		}

		cout << "Would you like to go back to Menu? Yes = 1 & No = 0" << endl;
		cin >> answer;

		while (answer != 0 && answer != 1) {
			cout << endl << "Not Valid Input.  Please Try Again." << endl;
			cin >> answer;
		}

		if (answer == 1)
			again = true;
		else
			again = false;
	}

	cout << endl << "Good Bye!" << endl;

	system("pause");
	//////////////////////////////////////////////////////////////////////////Sarah
}
