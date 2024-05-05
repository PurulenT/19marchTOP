#include "Rulon.h"

Rulon::Rulon()
{
	name = "Simple";
	len = 20;
	wid = 20;
	price = 5.00;
}

Rulon::Rulon(string name, float len, float wid, double price)
{
	this->name = name;
	this->len = len;
	this->wid = wid;
	this->price = price;
}