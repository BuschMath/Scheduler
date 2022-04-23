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

Month Date::StringToMonth(string input)
{
	if (input == "January")
		return Month::January;
	else if (input == "February")
		return Month::February;
	else if (input == "March")
		return Month::March;
	else if (input == "April")
		return Month::April;
	else if (input == "May")
		return Month::May;
	else if (input == "June")
		return Month::June;
	else if (input == "July")
		return Month::July;
	else if (input == "August")
		return Month::August;
	else if (input == "September")
		return Month::September;
	else if (input == "October")
		return Month::October;
	else if (input == "November")
		return Month::November;
	else if (input == "December")
		return Month::December;

	return Month();
}

DaysOfWeek Date::StringSubToDay(string input)
{
	if (input == "Su")
		return DaysOfWeek::Sunday;
	else if (input == "Mo")
		return DaysOfWeek::Monday;
	else if (input == "Tu")
		return DaysOfWeek::Tuesday;
	else if (input == "We")
		return DaysOfWeek::Wednesday;
	else if (input == "Th")
		return DaysOfWeek::Thursday;
	else if (input == "Fr")
		return DaysOfWeek::Friday;
	else if (input == "Sa")
		return DaysOfWeek::Saturday;

	return DaysOfWeek();
}
