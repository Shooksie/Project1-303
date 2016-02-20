#include <string>
#include <list>
#include "Date\Date.h"

#ifndef ASSIGNMENT_HEADER
#define ASSIGNMENT_HEADER

using namespace std;

class assignment {
private:
	string dueDate;
	string assignmentName, assignedDate, status;
	bool completed=false;
	
	
public:
	bool getComplete();//returns the status of the assignment.
	void getReadData(istream& in);
	string getDueDate();
	string getName();
	void setName(string name);
	void changecomplete();
	void printAssignment(ostream& output);
	Date date1(string dueDate);
	Date date2(string assignedDate);
};

#endif