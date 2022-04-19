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

string Date::MonthToString(Month input)
{
	switch (input)
	{
	case Month::January: return "January";
		break;
	case Month::February: return "February";
		break;
	case Month::March: return "March";
		break;
	case Month::April: return "April";
		break;
	case Month::May: return "May";
		break;
	case Month::June: return "June";
		break;
	case Month::July: return "July";
		break;
	case Month::August: return "August";
		break;
	case Month::September: return "September";
		break;
	case Month::October: return "October";
		break;
	case Month::November: return "November";
		break;
	case Month::December: return "December";
		break;
	default:
		break;
	}
	return string();
}

string Date::DayToString(DaysOfWeek input)
{
	switch (input)
	{
	case DaysOfWeek::Sunday: return "Sunday";
		break;
	case DaysOfWeek::Monday: return "Monday";
		break;
	case DaysOfWeek::Tuesday: return "Tuesday";
		break;
	case DaysOfWeek::Wednesday: return "Wednesday";
		break;
	case DaysOfWeek::Thursday: return "Thursday";
		break;
	case DaysOfWeek::Friday: return "Friday";
		break;
	case DaysOfWeek::Saturday: return "Saturday";
		break;
	default:
		break;
	}
	return string();
}
