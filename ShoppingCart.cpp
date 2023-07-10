#include "ShoppingCart.h"
#include "DataUtility.h"
#include "Item.h"
#include <iomanip>
using namespace std;

ShoppingCart::ShoppingCart(string name)
{
	customerName = name;
	currentDate = getDateString();
}

string ShoppingCart::getCustomerName() const
{
	return customerName;
}

string ShoppingCart::getCurrentDate() const
{
	return currentDate;
}

int ShoppingCart::findItemInCart(string name)
{
	for (size_t i = 0; i < cart.size(); i++) {
		if (cart.at(i).getItemName() == name) {
			return i;
		}
	}
	return cart.size();
}


void ShoppingCart::addItemToCart(Item item)
{
	if (findItemInCart(item.getItemName()) < cart.size()) {
		cout << "\t>>> Item " << item.getItemName() << " already in cart <<<" << endl << endl;
	}
	else {
		cart.push_back(item);
		cout << "\t>>> Item " << item.getItemName() << " added to cart <<<" << endl << endl;
	}

	
}


void ShoppingCart::changeItemQuantity(string name, int quantity)
{
	
		if (findItemInCart(name) <  cart.size()) {
			cart.at(findItemInCart(name)).setItemQuantity(quantity);
			cout << "\t>>> Item " << name << " quantity changed to new quantity: " << quantity << " <<<" << endl << endl;
		}
		else {
			cout << "\t>>> Item "<< name << "is not in the cart <<<" << endl << endl;
		}
	
}

void ShoppingCart::changeItemPrice(string name, double price)
{
	
		if (findItemInCart(name) < cart.size()) {
			cart.at(findItemInCart(name)).setItemPrice(price);
			cout << "\t>>> Item " << name << "price changed to new price: $" << price << " <<<" << endl << endl; 
		}
		else {
			cout << "\t>>> Item " << name <<" is not in the cart <<< " << endl << endl;
		}
	
}

void ShoppingCart::removeItemFromCart(string name)
{
	if (findItemInCart(name) < cart.size()) {
		cart.erase(cart.begin() + findItemInCart(name));
		cout << "\t>>> Item " << name << " has been removed from cart<<<" << endl << endl;
	}
	else {
		cout << "\t>>>Item " << name << " is not in the cart<<<" << endl << endl;
	}
	
}

void ShoppingCart::outputCartInfo()
{
	double total = 0;
	cout << "-- Output Shopping Cart --" << endl;
	cout << "\t" << getCustomerName() << "'s Shopping Cart - " << getCurrentDate() << endl << endl;
	cout << "\tNumber of items: " << getItemCount() << endl;
	cout << "\t---------------------" << endl;

	for (int i = 0; i < cart.size(); i++) {
		/*-- Output Shopping Cart --
 John Smith's Shopping Cart - 01/21/21
 Number of Items: 6
 ---------------------
 Pretzels 2 @ $2.34 = $4.68
 Milk 1 @ $1.49 = $1.49
 Pepsi 2 @ $1.99 = $3.98
 Chunky Monkey Ice Cream 1 @ $4.50 = $4.50

 Total: $14.65
 */
		cout <<"\t"<< cart.at(i).getItemName() << " " << cart.at(i).getItemQuantity() << " @ $" << fixed << setprecision(2)
			<< cart.at(i).getItemPrice() << " = $" << fixed << setprecision(2) 
			<< cart.at(i).getItemPrice() * cart.at(i).getItemQuantity() << endl;
		total += cart.at(i).getItemPrice()*cart.at(i).getItemQuantity();
	}
	cout << "\tTotal $" << fixed << setprecision(2) << total << endl << endl;
}


int ShoppingCart::getItemCount() const
{
	int totalAmount = 0;
	for (int i = 0; i < cart.size(); i++) {
		totalAmount += cart.at(i).getItemQuantity();
	}
	return totalAmount;
}
