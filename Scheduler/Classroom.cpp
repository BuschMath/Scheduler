#include "Classroom.h"

string Classroom::RoomTypeToString(RoomType input)
{
	switch (input)
	{
	case RoomType::normal: return "normal";
		break;
	case RoomType::lab: return "lab";
		break;
	case RoomType::computer: return "computer";
		break;
	case RoomType::auditorium: return "auditorium";
		break;
	default: return "error";
		break;
	}
}