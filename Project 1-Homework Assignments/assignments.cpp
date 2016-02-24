#include "Assignment.h"


//////////////////////////////////////////////////toptip.c
void assignment::trim(string& s) {

		size_t p = s.find_first_not_of(" \t");
		s.erase(0, p);
		p = s.find_last_not_of(" \t");
		if (string::npos != p)
		s.erase(p + 1);

}
//////////////////////////////////////////////////toptip.c

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
	string line;
	getline(in, line);
	String_Tokenizer st(line, ",");
	assignedDate = st.next_token();
	assignmentName = st.next_token();
	dueDate = st.next_token();
	status = st.next_token();
	trim(assignedDate);
	trim(assignmentName);
	trim(status);
	trim(dueDate);
	

	if (status == "completed" || status == "late") {
		completed = true;
	}
	else if (status == "assigned") {
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

void assignment::printAssignment(ostream& output) {
	output << "Assigned Date: " << getAssignedDate() << endl << "Description: " << getName() << endl;
	output << "Due Date: " << getDueDate() << endl << "Status: " << getStatus() << endl << endl;
}

Date assignment::date1(string dueDate) {
	Date theDueDate(dueDate);
	return  theDueDate;

}
Date assignment::date2(string assignedDate) {
	Date theDueDate(dueDate);
	return theDueDate;
}
