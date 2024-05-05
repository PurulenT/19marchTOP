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
	cout << "������� ������ ����� ��������? ������� �����..." << endl;
	cin >> roomNumber;
	Kvartira kvartira;


	for (int i = 0; i < roomNumber; i++)
	{
		char ans;
		float len, wid;
		bool ceilingNeed;
		string name;
		bool cycle = true;
		cout << "������� ������ �������. ������� �����..." << endl;
		cin >> len;
		cout << "������� ������ �������. ������� �����..." << endl;
		cin >> wid;
		cout << "������� �������� �������..." << endl;
		cin >> name;
		while (cycle) {
			cout << "����� �� ������ �������? y/n" << endl;
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
				cout << "����� �� ���������!" << endl;

			}
		}
		Room r(len, wid, name, ceilingNeed);
		kvartira.addRoom(r);


	}


	cout << "����� ������������� ������, � ������� ����������� �������� ����:" << endl;

	for (int i = 0; i < roomNumber; i++)
	{
		cout<< "�������� �������: " << kvartira.rooms[i].name << endl;
		cout << "����� �������: " << kvartira.rooms[i].len << endl;
		cout << "������ �������: " << kvartira.rooms[i].wid << endl;
		cout << "�������� �������: ";
		if (kvartira.rooms[i].ceilingNeed == 1)
			cout << "�����" << endl;
		else
			cout << "�� �����" << endl;
	}


	cout << "������� ����� ����� ����������� ������������? " << endl;
	cin >> rulonNumber;
	cout << "������� �������������� ��� ������� ���� �����: " << endl;
	vector<Rulon> rulonList(rulonNumber);

	for (int i = 0; i < rulonNumber; i++)
	{
		Rulon rulon;
		cout << "������� �������� ������: " << endl;
		cin >> rulon.name;
		cout << "������� ����� ������: " << endl;
		cin >> rulon.len;
		cout << "������� ������ ������: " << endl;
		cin >> rulon.wid;
		cout << "������� ���� ������: " << endl;
		cin >> rulon.price;

		rulonList[i] = rulon;
	}

	for (int i = 0; i < rulonNumber; i++)
	{
		cout << "������� �������� ������: " << rulonList[i].name << endl;
		cout << "������� ����� ������: " << rulonList[i].len << endl;
		cout << "������� ������ ������: " << rulonList[i].wid << endl;
		cout << "������� ���� ������: " << rulonList[i].price << endl;
	}

	for (int i = 0; i < roomNumber; i++)
	{
		if (kvartira.rooms[i].ceilingNeed == 1)
			totalAreaWall += 2 * (kvartira.rooms[i].len + kvartira.rooms[i].wid) * 2.5 + (kvartira.rooms[i].len * kvartira.rooms[i].wid);
		else
			totalAreaWall += 2 * (kvartira.rooms[i].len + kvartira.rooms[i].wid) * 2.5;
		
	}

	cout << "����� ������� ���� � �������� ������� ����� ��������: " << totalAreaWall << endl;

	int kolvoRulonov = 0; //������� ������� �����������
	float totalCost = 0.0; //�������� ���������

	for (int i = 0; i < rulonNumber; i++)
	{
		cout << "��� ������������� ������ ���� " << rulonList[i].name << ": " << endl;
		float plosh = (rulonList[i].len * rulonList[i].wid);
		kolvoRulonov = ceil(totalAreaWall / plosh);
		totalCost = kolvoRulonov * rulonList[i].price;

		cout << "������� ����������: " << kolvoRulonov << endl;
		cout << "����� ���������: " << totalCost << endl;
	}




	return 0;
}