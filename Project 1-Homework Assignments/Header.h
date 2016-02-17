#include <string>
#include <ctime>
#include <list>

using namespace std;

class assignments {
private:
	int dueday, duemonth, dueyear;
	string assignmentName, dueDate, assignedDate, status;
	bool completed=false;

public:
	bool getComplete();
	int getDay();
	int getMonth();
	int getYear();
	void getReadData(istream& in);
	string getDueDate();
	string getName();
	void setDueDate(int day, int month, int year);
	void setName(string name);
	void changecomplete();
};

