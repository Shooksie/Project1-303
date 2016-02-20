#include "Assignment.h"


string assignment::getDueDate() {
	//returns the due date of the assignment
	return dueDate;
}

string assignment::getName() {
	//returns the definition of the assignment
	return assignDefine;
}

void assignment::changecomplete() {
	if (!completed) {
		completed = true;
		return;
	}
	completed = false;
}

void assignment::setName(string description) {
	//sets the name of the assignment
	assignDefine = description;
}

void assignment::getReadData(istream& in) {
	in >> assignedDate;
	in >> assignDefine;
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
	//returns a bool to check if the assignment is complete or not
	return completed;
}

string assignment::getAssignedDate() {
	//returns the assigned date as a string
	return assignedDate;
}

string assignment::getStatus() {
	//returns the status of the assignment
	return status;
}

void assignment::printAssignment(ostream& output){
	output << "Due Date: " << getDueDate() << " Description: " << getName();
	output << " Assigned Date: " << getAssignedDate() << " Status: " << getStatus() << endl;
}
