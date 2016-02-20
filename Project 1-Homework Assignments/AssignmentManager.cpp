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
			uncomplete.push_front(*itr);
			completed.erase(itr);
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
	itr = assignList.begin();//itr should always be the head of the list
	itr2 = assignList.end();//itr2 should always be the tail of the list
	int index = 0;
	int length = assignList.size();
	while (index < length)
	{
		if (itr->date2 > itr2->date2)
		{
			assignList.push_front(*itr);
			assignList.pop_back();
		}
		else if (itr->date2 < itr2->date2) {
			bool loop = true;
			while (itr != itr2) {
				itr2--;
				if (itr->date2 > itr2->date2)
				{
					itr2++;
					assignList.insert(itr2, *itr);
					assignList.pop_back();
					itr = assignList.begin();
					itr2 = itr;
				
				}
			}
		}
		itr2 = assignList.end();
		itr = assignList.begin();
		index++;

	
}