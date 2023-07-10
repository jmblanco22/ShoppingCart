#include "Item.h"
#include <iostream>
Item::Item(string name, double price, int quantity):itemName(name), itemPrice(price), itemQuantity(quantity)
{
}
void Item::setItemName(string name)
{
	itemName = name;
}

void Item::setItemPrice(double price)
{
	itemPrice = price;
}

void Item::setItemQuantity(int quantity)
{
	itemQuantity = quantity;
}

string Item::getItemName() const
{
	return itemName;
}

double Item::getItemPrice() const
{
	return itemPrice;
}

int Item::getItemQuantity() const
{
	return itemQuantity;
}

void Item::outputItemInfo()
{
	cout << itemName << " " << itemQuantity << " @ " << itemPrice << " = " << itemPrice * itemQuantity;
}
