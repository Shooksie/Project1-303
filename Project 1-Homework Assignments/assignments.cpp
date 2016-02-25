#include "Assignment.h"
#include "Date\StringTokenizer.h"
#include <iostream>

//////////////////////////////////////////////////toptip.c
void assignment::trim(string& s) {

	size_t p = s.find_first_not_of(" \t");
	s.erase(0, p);
	p = s.find_last_not_of(" \t");
	if (string::npos != p)
		s.erase(p + 1);

}
//////////////////////////////////////////////////toptip.c





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool assignment::setAssignment(string assignment) {
	String_Tokenizer st(assignment, ",");
	dueDate = st.next_token();
	assignmentName = st.next_token();
	assignedDate = st.next_token();
	status = st.next_token();
	trim(assignedDate);
	trim(assignmentName);
	trim(dueDate);
	trim(status);

	// make sure the due date and assigned date are valid
	// make sure the status isnt late or anything else


	if (status != "completed" && status != "assigned") {
		cout << endl <<  "You Entered an Invalid Status." << endl;
		return false;
	}

	if (status == "completed") {
		completed = true;
	}
	else if (status == "assigned") {
		completed = false;
	}
	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
	dueDate = st.next_token();
	assignmentName = st.next_token();
	assignedDate = st.next_token();
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
	output << "Due Date: " << getDueDate() << endl << "Description: " << getName() << endl;
	output << "Assigned Date: " << getAssignedDate() << endl <<  "Status: " << getStatus() << endl << endl;
}

void assignment::printTofile(ostream& output) {
	output << dueDate << ", " << assignmentName << ", " << assignedDate << ", " << status;
}

bool assignment::compare(assignment toCompare) {
	Date date01(toCompare.getAssignedDate());
	if (date1 > date01) {
		return true;
	}
	return false;
}
void assignment::modifyDueDate(string& dueDate1) {
	dueDate = dueDate1;
	date2 = dueDate;
}