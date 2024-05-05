#pragma once
using namespace std;
#include <vector>
#include "Room.h"

class Kvartira
{
public:
	vector<Room> rooms;

	void addRoom(const Room& room) {
		rooms.push_back(room);
	}
	//Kvartira(int kolvo);

};

