#include <string>
#include <ctime>
#include <list>

using namespace std;

class assignments {
private:
	int dueday, duemonth, dueyear;
	string assignmentName, dueDate;
	bool completed=false;
public:
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

