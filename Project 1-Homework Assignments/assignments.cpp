#include "Header.h"


string assignments::getDueDate() {
	return dueDate;
}

string assignments::getName() {
	return assignmentName;
}

void assignments::changecomplete() {
	completed = true;
	return;
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