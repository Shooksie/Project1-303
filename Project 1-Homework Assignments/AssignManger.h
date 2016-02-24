#include "Header.h"

using namespace std;


class assignmentManager {
private:
	list<assignment> completed;
	list<assignment> uncomplete;
public:
	bool searchAssignment(string assignedDate);
	bool completeAssignment(string assignedDate);
	void checkComplete();
	void checkUncomplete();
	void addAssignment(assignment newassign);
	void sortlist(list<assignment> assignList);
	void printOrdered();
	void printComp();
	void printUncomp();
	void writeTofile(ostream& output);
	void printLate();
	void sort();
};

