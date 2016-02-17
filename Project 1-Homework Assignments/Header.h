#include <string>
#include <ctime>
#include <list>

using namespace std;

class assignments {
private:
	int duedate, duemonth, dueyear, duehour, duemin;
	string assignmentName;
	bool completed;
public:
	string getDueDate();
	string getName();
	void setDueDate(int day, int month, int year, int hour, int min);
	void setName(string name);
	void changecomplete();
};

