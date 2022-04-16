#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <vector>
#include <string>

using namespace std;

enum class RoomType
{
	normal,
	lab,
	computer,
	auditorium
};

enum class BuildingName
{
	Science,
	LiberalArts,
	AppliedScienceTechnology
};

class Classroom
{
public:
	Classroom();
	Classroom(string roomNumber_, unsigned short int maxRoomCapacity_, RoomType roomType_, BuildingName buildingName_);
	string RoomTypeToString(RoomType input);
	RoomType StringToRoomType(string input);
	string BuildingNameToString(BuildingName input);
	
	string roomNumber;
	unsigned short int maxRoomCapacity;
	RoomType roomType;
	BuildingName buildingName;
	
	vector<RoomType> roomTypeList = { RoomType::normal, RoomType::lab, RoomType::computer, RoomType::auditorium };
	vector<BuildingName> buildingNameList = { BuildingName::AppliedScienceTechnology, BuildingName::LiberalArts, BuildingName::Science };
};

#endif // !CLASSROOM_H