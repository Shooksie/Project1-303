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

string assignment::getAssignedDate() {
	return assignedDate;
}

string assignment::getStatus() {
	return status;
}

void assignment::printAssignment(ostream& output){
	output << "Due Date: " << getDueDate() << ", Description: " << getName();
	output << ", Assigned Date: " << getAssignedDate() << ", Status: " << getStatus() << endl;
}
