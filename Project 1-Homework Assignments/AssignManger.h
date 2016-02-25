#include "Assignment.h"

using namespace std;


class assignmentManager {
private:
	list<assignment> completed;
	list<assignment> uncomplete;
	int number_Completed;
	int number_Uncompleted;
	int total_Assignments;
	int number_Late;
public:
	bool searchAssignment(string assignedDate);
	bool completeAssignment(string assignedDate);
	bool extendAssignment(string assignedDate, string newdue);
	bool editdueDate(string& assignedDate);
	bool editDescription(string& theDate);
	int getNumberCompleted();
	int getNumberLate();
	int getNumberUncompleted();
	int getNumberofAssignments();
	void addAssignment(assignment& newassign);
	void printOrdered();
	void printComp();
	void printUncomp();
	void writeTofile(ostream& output);
	void printLate();

};

