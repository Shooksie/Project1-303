#include "AssignManger.h"
#include <iostream>

using namespace std;


bool assignmentManager::searchAssignment(string assignedDate) {

	list<assignment>::iterator itr;
	for (itr = uncomplete.begin(); itr != uncomplete.end(); itr++) {
		if (itr->getAssignedDate() == assignedDate) {
			return true;
		}
	}
	for (itr = completed.begin(); itr != completed.end(); itr++) {
		if (itr->getAssignedDate() == assignedDate) {
			return true;
		}
	}
	return false;
}

int assignmentManager::getNumberCompleted() {
	return number_Completed;
}

int assignmentManager::getNumberLate() {
	number_Late = 0;
	list<assignment>::iterator itr;
	for (itr = uncomplete.begin(); itr != uncomplete.end(); itr++) {

		if (itr->getStatus() == "late") {
			number_Late++;
		}
	}
	for (itr = completed.begin(); itr != completed.end(); itr++) {

		if (itr->getStatus() == "late") {
			number_Late++;
		}
	}
	return number_Late;
}

int assignmentManager::getNumberUncompleted() {
	return number_Uncompleted;
}

int assignmentManager::getNumberofAssignments() {
	return total_Assignments;
}



void assignmentManager::addAssignment(assignment& newassign) {
	//Adds an assignment
	if (newassign.getComplete())//check to see if assignment has been completed or not
	{
		list<assignment>::iterator itr = completed.begin();
		while (itr != completed.end() && itr->getDay() < newassign.getDay()) {
			++itr;
		}
		completed.insert(itr, newassign);
		//if completed it pushes assignment to the front of the Completed List
		number_Completed++;
		total_Assignments++;
		return;
	}
	list<assignment>::iterator itr = uncomplete.begin();
	while (itr != uncomplete.end() && itr->getDay() < newassign.getDay()) {
		++itr;
	}
	uncomplete.insert(itr, newassign);
	//if its not completed it pushes the assignment to the front of the Uncompleted List
	number_Uncompleted++;
	total_Assignments++;
	return;
}

void assignmentManager::printComp() {//prints the completed list items
	list<assignment>::iterator itr;
	for (itr = completed.begin(); itr != completed.end(); itr++) {
		itr->printAssignment(cout);
	}
	return;
}

void assignmentManager::printOrdered() {//prints all the assignments in order
	printUncomp();
	printComp();
}

void assignmentManager::printUncomp() {//prints all uncompleted assignments
	list<assignment>::iterator itr;
	for (itr = uncomplete.begin(); itr != uncomplete.end(); itr++) {

		itr->printAssignment(cout);


	}
	return;
}

void assignmentManager::writeTofile(ostream& foutput) {
	list<assignment>::iterator itr;
	int number = 0;
	for (itr = uncomplete.begin(); itr != uncomplete.end(); itr++) {
		if (number != 0) {
			foutput << endl;
		}
		itr->printTofile(foutput);
		number++;
	}
	number = 0;
	for (itr = completed.begin(); itr != completed.end(); itr++) {
		if (number < completed.size()) {
			foutput << endl;
		}
		itr->printTofile(foutput);
		number++;
	}
}

void assignmentManager::printLate() { //prints all late assignments
	list<assignment>::iterator itr;
	for (itr = completed.begin(); itr != completed.end(); itr++) {
		if (itr->getStatus() == "late") {
			itr->printAssignment(cout);
		}
	}
}


bool assignmentManager::editdueDate(string& assignedDate)
{
	list<assignment>::iterator itr;
	for (itr = uncomplete.begin(); itr != uncomplete.end(); itr++) {

		if (itr->getAssignedDate() == assignedDate) {
			cout << endl<< "What is the New Due Date for the Assignment?" << endl;
			string newDate;
			cin >> newDate;
			cout << endl << "Changing the Due Date from " << itr->getDueDate() << " to " << newDate << "." << endl << endl;
			itr->modifyDueDate(newDate);
			return true;
		}
	}
	for (itr = completed.begin(); itr != completed.end(); itr++) {

		if (itr->getAssignedDate() == assignedDate) {
			cout << endl << "What is the New Due Date for the Assignment?" << endl;
			string newDate;
			cin >> newDate;
			cout << endl << "Changing the Due Date from " << itr->getDueDate() << " to " << newDate << "." << endl << endl;
			itr->modifyDueDate(newDate);
			
			return true;
		}
	}
	return false;

}

bool assignmentManager::editDescription(string& assignedDate) {
	list<assignment>::iterator itr;
	for (itr = uncomplete.begin(); itr != uncomplete.end(); itr++) {

		if (itr->getAssignedDate() == assignedDate) {
			cout << endl << "What is the New Description for the Assignment?" << endl;
			string description;
			getchar();
			getline(cin, description);
			cout << endl << "Changing the Description from '" << itr->getName() << "' to '" << description << "'." << endl << endl;
			itr->setName(description);
			return true;
		}
	}
	for (itr = completed.begin(); itr != completed.end(); itr++) {

		if (itr->getAssignedDate() == assignedDate) {
			cout << endl << "What is the New Description for the Assignment?" << endl;
			string description;
			getchar();
			getline(cin,description);
			cout << endl << "Changing the Description from '" << itr->getName() << "' to '" << description << "'." << endl << endl;
			itr->setName(description);
			return true;
		}
	}
	return false;
}

// look through uncompleted assignments to see if there is an assignment with that assigned date
//if there is, change the status to complete
bool assignmentManager::completeAssignment(string assignedDate) {

	list<assignment>::iterator itr;
	for (itr = uncomplete.begin(); itr != uncomplete.end(); itr++) {

		if (itr->getAssignedDate() == assignedDate) {
			itr->changecomplete();
			itr->setStatus(1);
			addAssignment(*itr);
			uncomplete.erase(itr);
			cout << endl << "Changing This Assignment to Complete!" << endl << endl;
			return true;
		}
	}
	return false;
}
