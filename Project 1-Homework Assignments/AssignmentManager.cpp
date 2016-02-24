#include "AssignManger.h"
#include <iostream>

using namespace std;

bool assignmentManager::searchAssignment(string assignedDate) {
;

	list<assignment>::iterator itr;
	for (itr = uncomplete.begin(); itr != uncomplete.end(); itr++) {

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
			uncomplete.erase(itr);
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
				uncomplete.erase(itr);
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
	for (itr = uncomplete.begin(); itr != uncomplete.end(); itr++) {
		itr->printTofile(foutput);
	}
	for (itr = completed.begin(); itr != completed.end(); itr++) {
		itr->printTofile(foutput);
	}
}
void assignmentManager::sortlist(list<assignment> assignList) {
	
	list<assignment>::iterator itr;
	list<assignment>::iterator itr2;
	itr = assignList.begin();
	itr2 = assignList.end();
	int index = 0;
	int length = assignList.size();
	while (index < length)
	{
		
		if (itr->compare(*itr2))
		{
			assignList.push_back(*itr);
			assignList.pop_front();
			itr = assignList.begin();
			itr2++;
		}
		else if (!itr->compare(*itr2)) {
			bool loop = true;
			while (loop) {
				itr2--;
				if (itr->compare(*itr))
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