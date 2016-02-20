#include <string>
#include <list>
#include "Date\Date.h"

#ifndef ASSIGNMENT_HEADER
#define ASSIGNMENT_HEADER

using namespace std;

class assignment {
private:
	string dueDate;//string that contains the due date
	string assignDefine, assignedDate, status;//strings for the Assignment defintion, Assigned Date and the Status of the Item.
	bool completed=false;//bool to check if the Assignment is Completed
	
public:
	bool getComplete();//returns the status of the assignment.
	void getReadData(istream& in);//function that reads in data from a file by passing the input stream refrence
	string getDueDate();//
	string getName();
	string getAssignedDate();
	string getStatus();
	void setName(string name);
	void changecomplete();
	void printAssignment(ostream& output);
	Date date1(string dueDate);
	Date date2(string assignedDate);
};

#endif

/* Shouldn't dueDate and assignedDate be Dates and not strings? 
In that case we would not need date1 or date2. 
Just wondering how these all tie together -Bailey */
