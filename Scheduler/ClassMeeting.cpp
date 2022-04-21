#include "ClassMeeting.h"

ClassMeeting::ClassMeeting()
{
	course = Course{ "Void", "Void", 000, 0, RoomType::auditorium};
	sectionID = "XXXX";
	maxCourseSeats = 0;
	weekdayMeet.push_back(DaysOfWeek::Sunday);
	startTime = Time{ 0, 0 };
	endTime = Time{ 0, 0 };;
	startDate = Date();
	endDate = Date();
	assignedInstructor = Professor();
}

ClassMeeting::ClassMeeting(Course course_, string sectionID_, unsigned short int maxCourseSeats_, 
							vector<DaysOfWeek> weekdayMeet_, Time startTime_, Time endTime_, Date startDate_, 
							Date endDate_, Professor instructor)
{
	course = course_;						
	sectionID = sectionID;
	maxCourseSeats = maxCourseSeats_;
	weekdayMeet = weekdayMeet_;
	startTime = startTime;
	endTime = endTime;
	startDate = startDate;
	endDate = endDate;
	assignedInstructor = instructor;
}
