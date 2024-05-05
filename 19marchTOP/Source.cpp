#include <iostream>
#include <Vector>
#include "Kvartira.h"
#include "Room.h"
#include "Rulon.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int roomNumber, rulonNumber;
	float totalAreaWall = 0.0;
	cout << "Сколько комнат нужно поклеить? Введите число..." << endl;
	cin >> roomNumber;
	Kvartira kvartira;


	for (int i = 0; i < roomNumber; i++)
	{
		char ans;
		float len, wid;
		bool ceilingNeed;
		string name;
		bool cycle = true;
		cout << "Введите длинну комнаты. Введите число..." << endl;
		cin >> len;
		cout << "Введите ширину комнаты. Введите число..." << endl;
		cin >> wid;
		cout << "Введите название комнаты..." << endl;
		cin >> name;
		while (cycle) {
			cout << "Нужно ли клеить потолки? y/n" << endl;
			cin >> ans;
			switch (ans) {
			case 'y':
				ceilingNeed = true;
				cycle = false;
				break;
			case 'n':
				ceilingNeed = false;
				cycle = false;
				break;
			default:
				cout << "Ответ не распознан!" << endl;

			}
		}
		Room r(len, wid, name, ceilingNeed);
		kvartira.addRoom(r);


	}


	cout << "Вывод характеристик комнат, в которых планируется поклеить обои:" << endl;

	for (int i = 0; i < roomNumber; i++)
	{
		cout<< "Название комнаты: " << kvartira.rooms[i].name << endl;
		cout << "Длина комнаты: " << kvartira.rooms[i].len << endl;
		cout << "Ширина комнаты: " << kvartira.rooms[i].wid << endl;
		cout << "Поклеить потолок: ";
		if (kvartira.rooms[i].ceilingNeed == 1)
			cout << "нужно" << endl;
		else
			cout << "не нужно" << endl;
	}


	cout << "Сколько видов обоев планируется использовать? " << endl;
	cin >> rulonNumber;
	cout << "Введите характеристики для каждого вида обоев: " << endl;
	vector<Rulon> rulonList(rulonNumber);

	for (int i = 0; i < rulonNumber; i++)
	{
		Rulon rulon;
		cout << "Введите название рулона: " << endl;
		cin >> rulon.name;
		cout << "Введите длину рулона: " << endl;
		cin >> rulon.len;
		cout << "Введите ширину рулона: " << endl;
		cin >> rulon.wid;
		cout << "Введите цену рулона: " << endl;
		cin >> rulon.price;

		rulonList[i] = rulon;
	}

	for (int i = 0; i < rulonNumber; i++)
	{
		cout << "Введите название рулона: " << rulonList[i].name << endl;
		cout << "Введите длину рулона: " << rulonList[i].len << endl;
		cout << "Введите ширину рулона: " << rulonList[i].wid << endl;
		cout << "Введите цену рулона: " << rulonList[i].price << endl;
	}

	for (int i = 0; i < roomNumber; i++)
	{
		if (kvartira.rooms[i].ceilingNeed == 1)
			totalAreaWall += 2 * (kvartira.rooms[i].len + kvartira.rooms[i].wid) * 2.5 + (kvartira.rooms[i].len * kvartira.rooms[i].wid);
		else
			totalAreaWall += 2 * (kvartira.rooms[i].len + kvartira.rooms[i].wid) * 2.5;
		
	}

	cout << "Общая площадь стен и потолков которые нужно поклеить: " << totalAreaWall << endl;

	int kolvoRulonov = 0; //сколько рулонов понадобится
	float totalCost = 0.0; //итоговая стоимость

	for (int i = 0; i < rulonNumber; i++)
	{
		cout << "При использовании рулона типа " << rulonList[i].name << ": " << endl;
		float plosh = (rulonList[i].len * rulonList[i].wid);
		kolvoRulonov = ceil(totalAreaWall / plosh);
		totalCost = kolvoRulonov * rulonList[i].price;

		cout << "Рулонов пригодится: " << kolvoRulonov << endl;
		cout << "Общая стоимость: " << totalCost << endl;
	}




	return 0;
}