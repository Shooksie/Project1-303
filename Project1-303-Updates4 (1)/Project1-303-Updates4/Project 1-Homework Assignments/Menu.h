#pragma once
#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

int Menu() {

	int answer;

	cout << endl << setw(12) << "MENU" << endl << endl;
	cout << "1 Display Assignments" << endl << "2 Add Assignment" << endl << "3 Edit Due Date" << endl << "4 Edit Description" << endl << "5 Complete Assignment"
		<< endl << "6 Number of Late Assignments" << endl << "7 Save" << endl << "8 Exit" << endl << endl;
	cout << "Enter a digit that corresponds with an action. " << endl;
	cin >> answer;
	while (answer != 1 && answer != 2 && answer != 3 && answer != 4 && answer != 5 && answer != 6 && answer != 7 && answer != 8) {
		cout << endl << "Not Valid Input.  Please Try Again." << endl;
		cin >> answer;

	}

	return answer;
}