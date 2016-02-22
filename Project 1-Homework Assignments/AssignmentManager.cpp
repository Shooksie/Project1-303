#include "AssignManger.h"
#include <iostream>

using namespace std;


void assignmentManager::addAssignment(assignment newassign) {
	//Adds an assignment
	if (newassign.getComplete())//check to see if assignment has been completed or not
	{
		completed.push_front(newassign);
		//if completed it pushes assignment to the front of the Completed List
		return;
	}
	uncomplete.push_front(newassign);
	//if its not completed it pushes the assignment to the front of the Uncompleted List
	return;
}

int assignmentManager::getNumberCompleted() {
	return number_Completed;
}

int assignmentManager::getNumberUncompleted() {
	return number_Uncompleted;
}

int assignmentManager::getNumberofAssignments() {
	return total_Assignments;
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
			uncomplete.remove(*itr);
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

void assignmentManager::sortlist(list<assignment> assignList) {
	list<assignment>::iterator itr;
	list<assignment>::iterator itr2;
	itr = assignList.begin();
	itr2 = assignList.end();
	int index = 0;
	int length = assignList.size();
	while (index < length)
	{
		if (itr->date1 > itr2->date1)
		{
			assignList.push_back(*itr);
			assignList.pop_front();
			itr = assignList.begin();
			itr2++;
		}
		else if (itr->date1 < itr2->date2) {
			bool loop = true;
			while (loop) {
				itr2--;
				if (itr->date1 > itr2->date1)
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
