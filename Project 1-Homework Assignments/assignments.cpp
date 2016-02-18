#include "Assignment.h"


string assignment::getDueDate() {
	return dueDate;
}

string assignment::getName() {
	return assignmentName;
}

void assignment::changecomplete() {
	if (!completed) {
		completed = true;
		return;
	}
	completed = false;
}


void assignment::setName(string description) {
	assignmentName = description;
}

void assignment::getReadData(istream& in) {
	in >> assignedDate;
	in >> assignmentName;
	in >> dueDate;
	in >> status;
	if (status == "completed" || status == "Late") {
		completed = true;
	}
	else if (status == "Assigned") {
		completed = false;
	}
}
bool assignment::getComplete() {
	return completed;
}
