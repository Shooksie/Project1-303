#include "AssignManger.h"
#include <iostream>

using namespace std;


void assignmentManager::addAssignment(assignment newassign) {
	if (newassign.getComplete())
	{
		completed.push_front(newassign);
		return;
	}
	uncomplete.push_front(newassign);
	return;
}

void assignmentManager::checkComplete() {
	list<assignment>::iterator itr;
	for (itr = uncomplete.begin(); itr != uncomplete.end(); itr++) {
		if (itr->getComplete()) {
			completed.push_front(*itr);
			uncomplete.erase(itr);
		}
	}
	return;
}

void assignmentManager::checkUncomplete() {
	list<assignment>::iterator itr;
	for (itr = completed.begin(); itr != completed.end(); itr++) {
		if (itr->getComplete()) {
			completed.push_front(*itr);
			uncomplete.remove(*itr);
		}
	}
	return;
}

void assignmentManager::printComp() {
	list<assignment>::iterator itr;
	for (itr = completed.begin(); itr != completed.end(); itr++) {
		itr->printAssignment(cout);
	}
	return;
}

void assignmentManager::printOrdered() {
	printUncomp();
	printComp();
}

void assignmentManager::printUncomp() {
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