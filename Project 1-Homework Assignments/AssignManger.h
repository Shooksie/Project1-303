#include "Assignment.h"

using namespace std;

class assignmentManager {
private:
	list<assignment> completed;
	list<assignment> uncomplete;
public:
	void checkComplete();
	void checkUncomplete();
	void addAssignment(assignment newassign);
	void sortlist(list<assignment> assignList);
	void printOrdered();
	void printComp();
	void printUncomp();
};




