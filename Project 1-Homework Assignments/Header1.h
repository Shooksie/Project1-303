#include "Header.h"

using namespace std;

class assignmentManager {
private:
	list<assignments> completed;
	list<assignments> uncomplete;
public:
	void checkComplete();
	void checkUncomplete();
	void addAssignment(assignments newassign);
	void sortlist(list<assignments> assignList);
	void printOrdered();
	void printComp();
	void printUncomp();
};


