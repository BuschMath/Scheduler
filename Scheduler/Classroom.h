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

enum BuildingName
{
	Science,
	LiberalArts,
	AppliedScienceTechnology
};

class Classroom
{
public:
	string RoomTypeToString(RoomType input);
	RoomType StringToRoomType(string input);

	unsigned short int roomNumber;
	unsigned short int maxRoomCapacity;
	RoomType roomType;
	BuildingName buildingName;
	vector<RoomType> roomTypeList = { RoomType::normal, RoomType::lab, RoomType::computer, RoomType::auditorium };
};

#endif // !CLASSROOM_H