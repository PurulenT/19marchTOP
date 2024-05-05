#pragma once
#include <iostream>
using namespace std;


class Room
{
public:
	float len;
	float wid;
	string name;
	bool ceilingNeed = false;

	Room(float len, float wid, string name, bool ceilingNeed);
};

