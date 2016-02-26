#pragma once
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
string assignment::getDate() {
	time_t now;
	struct tm nowlocal;

	now = time(NULL);

	nowlocal = *localtime(&now);

	ostringstream convert;
	convert << nowlocal.tm_mday;
	string day = convert.str();

	ostringstream convert1;
	convert1 << nowlocal.tm_mon + 1;
	string month = convert1.str();

	ostringstream convert2;
	convert2 << nowlocal.tm_year + 1900;
	string year = convert2.str();
	string date = month + "-" + day + "-" + year;
	return date;
}
///////////////////////////////////////////////////////////


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
	if (status == "assigned") {
		Date todaysDate = getDate();
		Date due = dueDate;
		if (todaysDate > due) {
			status = "late";
		}
	}

	if (status != "completed" && status != "assigned" && status != "late") {
		cout << endl <<  "You Entered an Invalid Status." << endl;
		return false;
	}

	if (status == "completed"  || status == "late") {
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
	setAssignment(line);
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

void assignment::modifyDueDate(string& dueDate1) {
	dueDate = dueDate1;
}


void assignment::setStatus(int num) {
	if (num == 1) {
		status = "completed";
	}
	else if (num == 2) {
		status = "late";
	}
	else if (num == 3) {
		status == "assigned";
	}
	return;
}

Date assignment::getDay() {
	Date temp = dueDate;
	return temp;

}

