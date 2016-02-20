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
/* when reading in from the text file, are we assuming that the status will be a part of it? becuase we have the options to 
change the status*/

/*basically what im getting at is that the file isnt real-time data, and that when you read in an item, its not like it was assigned
at that moment*/
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
