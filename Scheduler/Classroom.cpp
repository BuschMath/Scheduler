#include "Classroom.h"

Classroom::Classroom()
{
	roomNumber = "0";
	maxRoomCapacity = 0;
	roomType = RoomType::normal;
	buildingName = BuildingName::Science;
}

Classroom::Classroom(string roomNumber_, unsigned short int maxRoomCapacity_, RoomType roomType_, BuildingName buildingName_)
{
	roomNumber = roomNumber_;
	maxRoomCapacity = maxRoomCapacity_;
	roomType = roomType_;
	buildingName = buildingName_;
}

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

string BuildingNameToString(BuildingName input)
{
	switch (input)
	{
	case BuildingName::Science: return "Science";
		break;
	case BuildingName::LiberalArts: return "Liberal Arts";
		break;
	case BuildingName::AppliedScienceTechnology: "Applied Science and Technology";
		break;
	default:
		break;
	}
}