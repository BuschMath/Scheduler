#ifndef DATE_H
#define DATE_H

#include <vector>
#include <string>

using namespace std;

enum class DaysOfWeek
{
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};

enum class Month
{
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

struct Time
{
	unsigned short int hour;
	unsigned short int min;
};

class Date
{
public:

	Date();
	Date(unsigned short int day_, Month month_, unsigned short int year_);
	~Date();

	bool isOlder(Date date);
	string MonthToString(Month input);
	string DayToString(DaysOfWeek input);
	Month StringToMonth(string input);
	DaysOfWeek StringSubToDay(string input);

	unsigned short int day;
	Month month;
	unsigned short int year;

	vector<Month> ListOfMonths = { Month::January, Month::February, Month::March, Month::April, Month::May, Month::June,
									Month::July, Month::August, Month::September, Month::October, Month::November,
									Month::December };

	vector<DaysOfWeek> ListOfDays = { DaysOfWeek::Sunday, DaysOfWeek::Monday, DaysOfWeek::Tuesday, DaysOfWeek::Wednesday,
										DaysOfWeek::Thursday, DaysOfWeek::Friday, DaysOfWeek::Saturday };
};

#endif // !DATE_H



