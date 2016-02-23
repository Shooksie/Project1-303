#include"AssignManger.h"
#include"Assignment.h"
#include <iostream>
#include <fstream>

using namespace std;
//main
//test main

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
	cout << "Welcome to Assignment Manager!" << endl << endl << "Would you like to being? " << "Yes = 1  &  No = 0" << endl;
	cin >> answer;
	while (answer != 0 && answer != 1) {
		cout << endl << "Not Valid Input.  Please Try Again." << endl;
		cin >> answer;

	}
	if (answer == 0) {
		cout << endl << "Good Bye!" << endl;
	}

	else if (answer == 1) {
		cout << endl << setw(12) << "MENU" << endl << endl;
		cout << "1 Display Assignments" << endl << "2 Add Assignment" << endl << "3 Edit Due Date" << endl << "4 Edit Description" << endl << "5 Complete Assignment"
			<< endl << "6 Number of Late Assignments" << endl << "7 Save" << endl << "8 Exit" << endl << endl;
		cout << "Enter a digit that corresponds with an action. " << endl;
		cin >> answer;
		while (answer != 1 && answer != 2 && answer != 3 && answer != 4 && answer != 5 && answer != 6 && answer != 7 && answer != 8) {
			cout << endl << "Not Valid Input.  Please Try Again." << endl;
			cin >> answer;

		}
		if (answer == 1) {
			cout << endl << "COMPLETED ASSIGNMENTS" << endl << endl;
			MainAssignments.printComp();
			cout << endl << "==========================================================" << endl << endl;
			cout << "UNCOMPLETED ASSIGNMENTS" << endl << endl;
			MainAssignments.printUncomp();

		}
		if (answer == 2) {}
		if (answer == 3) {}
		if (answer == 4) {}
		if (answer == 5) {
			int int_Month;
			int int_Day;
			int int_Year;
			string the_Month;
			string the_Day;
			string the_Year;
			string the_Date;

			cout << "Enter the date of the assigned homework you wish to complete." << endl;
			cout << "Month (as a number) : ";
			cin >> int_Month;
			cout << "Day (as a number) : ";
			cin >> int_Day;
			cout << "Year (as a number) : ";
			cin >> int_Year;

			//Take into consideration leap year?? 


			//validating user input
			while (int_Month > 12 || int_Month <= 0) {
				cout << "You Entered an Invalid Month. Please Try again" << endl;
				cout << "Month (as a number) : ";
				cin >> int_Month;
				cout << "Day (as a number) : ";
				cin >> int_Day;
				cout << "Year (as a number) : ";
				cin >> int_Year;
			}

			//validating user input
			while (int_Day > 31 || int_Day <= 0) {
				cout << "You Entered an Invalid Day. Please Try again" << endl;
				cout << "Month (as a number) : ";
				cin >> int_Month;
				cout << "Day (as a number) : ";
				cin >> int_Day;
				cout << "Year (as a number) : ";
				cin >> int_Year;
			}

			//validating user input
			while (int_Year < 0) {
				cout << "You Entered an Invalid Year. Please Try again" << endl;
				cout << "Month (as a number) : ";
				cin >> int_Month;
				cout << "Day (as a number) : ";
				cin >> int_Day;
				cout << "Year (as a number) : ";
				cin >> int_Year;
			}


			stringstream convert_Month, convert_Day, convert_Year;

			// typecasting
			convert_Month << int_Month;
			convert_Day << int_Day;
			convert_Year << int_Year;

			the_Month = convert_Month.str();
			the_Day = convert_Day.str();
			the_Year = convert_Year.str();

			//creating the date as a string (user friendly)
			the_Date = the_Month + "-" + the_Day + "-" + the_Year;


			// look through uncompleted assignments to see if there is an assignment with that assigned date
			//if there is, change the status to complete
			if (MainAssignments.searchAssignment(the_Date) == true) {
				cout << "Changing this assignment to complete!" << endl;
				//THIS IS WHERE IM HAVING A LOGIC ISSUE
			}
			//if not valid date, let user know
			else
				cout << "Not a real assignment" << endl;
		}
		if (answer == 6) {

			if ((MainAssignments.getNumberLate() > 1) || (MainAssignments.getNumberofAssignments() == 0)) {
				cout << endl << "There are " << MainAssignments.getNumberLate() << " late assignments." << endl;
			}
			else if (MainAssignments.getNumberLate() == 1) {
				cout << endl << "There is " << MainAssignments.getNumberLate() << " late assignment." << endl;
			}
		}
		if (answer == 7) {}
		if (answer == 8) {}

	}


	system("pause");
	//////////////////////////////////////////////////////////////////////////Sarah
}