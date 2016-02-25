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



void assignmentManager::addAssignment(assignment newassign) {
	//Adds an assignment
	if (newassign.getComplete())//check to see if assignment has been completed or not
	{
		completed.push_front(newassign);
		//if completed it pushes assignment to the front of the Completed List
		number_Completed++;
		total_Assignments++;
		return;
	}
	uncomplete.push_front(newassign);
	//if its not completed it pushes the assignment to the front of the Uncompleted List
	number_Uncompleted++;
	total_Assignments++;
	return;
}

void assignmentManager::checkComplete() {
	/* goes through the Uncompleted List to make sure there are
	no Completed assignments left in the Uncompleted List*/
	list<assignment>::iterator itr;//declare an Iterator
	for (itr = uncomplete.begin(); itr != uncomplete.end(); itr++) {
		if (itr->getComplete()) { //if itr->getComplete() return true then item as to swaped
			completed.push_front(*itr);
			list<assignment>::iterator itrTemp = itr;
			itr++;
			uncomplete.erase(itrTemp);

		}
	}
	return;
}

void assignmentManager::checkUncomplete() {
	/*goes through the Completed List to make sure there are
	no UnCompleted assignments left in the completed List*/
	list<assignment>::iterator itr;//declare an Iterator
	for (itr = completed.begin(); itr != completed.end(); itr++) {
		if (!itr->getComplete()) {/*if !itr->getComplete() return true then item as to swaped*/
				completed.push_front(*itr);  
				list<assignment>::iterator itrTemp = itr;
				itr++;
				uncomplete.erase(itrTemp);
		}
	}
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
void assignmentManager::sortlist(list<assignment> assignList) {
	
	list<assignment>::iterator itr;
	list<assignment>::iterator itr2;
	itr = assignList.begin();
	itr2 = assignList.end();
	int index = 0;
	int length = assignList.size();
	while (index < length){
		cout << itr->date1.toString();
		cout << itr2->date1.toString();
		Date dateA = itr->date1;
		Date dateB = itr2->date1;
		if (dateA > dateB)
		{
			assignList.push_back(*itr);
			assignList.pop_front();
			itr = assignList.begin();
			itr2++;
		}
		else if (dateA < dateB) {
			bool loop = true;
			while (loop) {
				itr2--;
				if (dateA > dateB)
				{
					assignList.insert(itr2++, *itr);
					assignList.pop_front();
					itr = assignList.begin();
					itr2++;
					loop = false;
				}
			}
		}
		index++;


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

void assignmentManager::sort() {
	sortlist(completed);
	sortlist(uncomplete);
}

bool assignmentManager::completeAssignment(string assignedDate) {

	list<assignment>::iterator itr;
	for (itr = uncomplete.begin(); itr != uncomplete.end(); itr++) {

		if (itr->getAssignedDate() == assignedDate) {
			itr->changecomplete();
			checkComplete();
			return true;
		}
	}
	return false;
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