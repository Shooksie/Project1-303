#include "Assignments.h"


string assignments::getDueDate() {
	return dueDate;

}

string assignments::getName() {
	return assignmentName;
}

void assignments::changecomplete() {
	if (!completed) {
		completed = true;
		return;
	}
	completed = false;
}

void assignments::setDueDate(int day, int month, int year) {
	dueday = day;
	duemonth = month;
	dueyear = year;
}

void assignments::setName(string description) {
	assignmentName = description;
}

int assignments::getDay() {
	return dueday;
}

int assignments::getMonth(){
	return duemonth;
}

int assignments::getYear() {
	return dueyear;
}
void assignments::getReadData(istream& in) {
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
bool assignments::getComplete() {
	return completed;
}