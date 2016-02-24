#include <string>
#include <list>
#include "Date\Date.h"
#include "Date\StringTokenizer.h"

#ifndef ASSIGNMENT_HEADER
#define ASSIGNMENT_HEADER

using namespace std;

class assignment {
private:
	string dueDate;
	string assignmentName, assignedDate, status;
	bool completed = false;

public:
	bool getComplete();//returns the status of the assignment.
	void getReadData(istream& in);
	string getDueDate();
	string getName();
	string getAssignedDate();
	string getStatus();
	void setName(string name);
	void modifyDueDate(string& date);
	void changecomplete();
	void printAssignment(ostream& output);
	void printTofile(ostream& output);
	void trim(string& s);
	Date date1 = assignedDate;
	Date date2 = dueDate;
	bool compare(assignment toCompare);
};
};

#endif

/* Shouldn't dueDate and assignedDate be Dates and not strings? 
In that case we would not need date1 or date2. 
Just wondering how these all tie together -Bailey */
