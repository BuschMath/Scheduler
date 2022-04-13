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

RoomType Classroom::StringToRoomType(string input)
{
	if (input == "normal")
		return RoomType::normal;
	if (input == "lab")
		return RoomType::lab;
	if (input == "computer")
		return RoomType::computer;
	if (input == "auditorium")
		return RoomType::auditorium;

	return RoomType::normal;
}
