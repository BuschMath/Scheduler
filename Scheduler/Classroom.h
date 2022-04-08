#ifndef CLASSROOM_H
#define CLASSROOM_H

enum RoomType
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
	unsigned short int roomNumber;
	unsigned short int maxRoomCapacity;
	RoomType roomType;
	BuildingName buildingName;
};

#endif // !CLASSROOM_H