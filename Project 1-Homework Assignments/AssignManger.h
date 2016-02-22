#include "Header.h"

using namespace std;

class assignmentManager {
private:
	list<assignment> completed;
	list<assignment> uncomplete;
	int number_Completed;
	int number_Uncompleted;
	int total_Assignments;
public:
	void checkComplete();
	void checkUncomplete();
	void incrementCompleted();
	void decrementCompleted();
	int getNumberofAssignments();
	void addAssignment(assignment newassign);
	void sortlist(list<assignment> assignList);
	void printOrdered();
	void printComp();
	void printUncomp();
};




