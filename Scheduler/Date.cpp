#include "Date.h"

Date::Date()
{
	day = 1;
	month = Month::January;
	year = 1900;
}

Date::Date(unsigned short int day_, Month month_, unsigned short int year_)
{
	day = day_;
	month = month_;
	year = year_;
}

Date::~Date()
{
}

bool Date::isOlder(Date date)
{
	if (year < date.year)
		return true;
	if (month < date.month)
		return true;
	if (day < date.day)
		return true;
	return false;
}
