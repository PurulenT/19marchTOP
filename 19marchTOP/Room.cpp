#include "Room.h"

//Room::Room() 
//{
//	char ans;
//	bool cycle = true;
//	cout << "Введите длинну комнаты. Введите число..."<<endl;
//	cin >> len;
//	cout << "Введите ширину комнаты. Введите число..." << endl;
//	cin>>wid;
//	cout << "Введите название комнаты..." << endl;
//	cin>>name;
//	while (cycle) {
//		cout << "Нужно ли клеить потолки? y/n" << endl;
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
//			cout << "Ответ не распознан!" << endl;
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
