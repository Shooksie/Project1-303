#include "Assignment.h"

using namespace std;

class assignmentManager {
private:
	int number_Completed = 0;
	int total_Assignments = 0;
	int number_Uncompleted = 0;
	list<assignment> completed;
	list<assignment> uncomplete;
public:
	int getNumberCompleted();
	int getNumberUncompleted();
	int getNumberofAssignments();
	bool searchAssignment(string assignedDate);
	void checkComplete();
	void checkUncomplete();
	void addAssignment(assignment newassign);
	void sortlist(list<assignment> assignList);
	void printOrdered();
	void printComp();
	void printUncomp();
};




