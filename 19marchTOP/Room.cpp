#include "Room.h"

//Room::Room() 
//{
//	char ans;
//	bool cycle = true;
//	cout << "������� ������ �������. ������� �����..."<<endl;
//	cin >> len;
//	cout << "������� ������ �������. ������� �����..." << endl;
//	cin>>wid;
//	cout << "������� �������� �������..." << endl;
//	cin>>name;
//	while (cycle) {
//		cout << "����� �� ������ �������? y/n" << endl;
//		cin >> ans;
//		switch (ans) {
//		case 'y':
//			ceilingNeed = true;
//			cycle = false;
//			break;
//		case 'n':
//			ceilingNeed = false;
//			cycle = false;
//			break;
//		default:
//			cout << "����� �� ���������!" << endl;
//
//		}
//	}
//}

Room::Room(float len, float wid, string name, bool ceilingNeed)
{
	setlocale(LC_ALL, "rus");
	this->len = len;
	this->wid = wid;
	this->name = name;
	this->ceilingNeed = ceilingNeed;
}
