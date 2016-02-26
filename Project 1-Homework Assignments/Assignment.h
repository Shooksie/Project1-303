#pragma once
#include <string>
#include <list>
#include <iostream>
#include <ctime>
#include "Date\Date.h"
#include "Date\StringTokenizer.h"


#pragma warning(disable:4996)




using namespace std;

class assignment {
private:
	string dueDate;
	string assignmentName, assignedDate, status;
	bool completed = false;

public:
	bool setAssignment(string assignment);
	bool getComplete();//returns the status of the assignment.
	void getReadData(istream& in);
	string getDueDate();
	string getName();
	string getAssignedDate();
	void setStatus(int num);
	string getStatus();
	void setName(string name);
	void modifyDueDate(string& date);
	void changecomplete();
	void printAssignment(ostream& output);
	void printTofile(ostream& output);
	void trim(string& s);
	Date getDay();
	string getDate();
};
