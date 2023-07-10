#include <iostream>
#include "ShoppingCart.h"
using namespace std;

char getMenuChoice();
void processMenuChoice(char, ShoppingCart&);

int main() {
	string custName;
	char choice;

	// COMPLETE THIS FUNCTION

	// Asks user to enter customer name
	// Displays title, customer name, and date
	// choice = getMenuChoice();
	//
	// set up while loop to check for choice of 'q'
	//		if not 'q', processMenuChoice
	//		call getMenuChoice() again
	cout << "**** Shopping Cart ****" << endl << endl;

	cout << "Enter customer's name: ";
	getline(cin, custName);
	cout << endl;
	ShoppingCart cart(custName);
	
	cout << "Customer Name: " << custName << " Today's Date: " << cart.getCurrentDate() << endl << endl;

	

	do {
		cout << "-- Online Shopping Menu --" << endl;
		cout << "\ta - Add item to cart" << endl;
		cout << "\td - Remove item from cart" << endl;
		cout << "\tc - Change item quantity" << endl;
		cout << "\tp - Change item price" << endl;
		cout << "\to - Output shopping cart" << endl;
		cout << "\tq - Quit" << endl << endl;

		choice = getMenuChoice();

		if (choice != 'q') {
			processMenuChoice(choice, cart);
		}

	} while (choice != 'q');

	return 0;
}

char getMenuChoice() {
	string menuOptions = "adcpoq";
	char choice;

	do {
		cout << "\tEnter your choice: ";
		cin >> choice;
		cout << endl;
	} while (menuOptions.find(choice) == string::npos);

	return choice;
}

void processMenuChoice(char choice, ShoppingCart& theCart) {
	string name = "";
	double price = 0.0;
	int quantity = 0;
	

	switch (choice) {
	case 'a':
		// get the item name, price, quantity from user
		cout << "-- Add Item to Cart --" << endl;
		cin.ignore();
		cout << "\tEnter the item name: ";
		getline(cin, name);

		cout << "\tEnter the item price: ";
		cin >> price;

		cout << "\tEnter the item quantity: ";
		cin >> quantity;

		// create an Item object and add it to the cart
		cout << endl<< endl;
		theCart.addItemToCart(Item(name, price, quantity));
		
		break;

	case 'd':
		cout << "-- Remove Item From Cart -- " << endl;
		
		cin.ignore();
		// get the item name from user
		cout << "\tEnter the item name: ";
		getline(cin, name);

		// remove the item from the cart
		cout << endl << endl;
		theCart.removeItemFromCart(name);
		
		

		break;

	case 'c':
		cout << "-- Change Item Quantity --" << endl;
		cin.ignore();
		// get the item name and new quantity from user
		cout << "\tEnter the item name: ";
		getline(cin, name);

		cout << "\tEnter the new quantity: ";
		cin >> quantity;

		// change the item quantity
		cout << endl << endl; 
		theCart.changeItemQuantity(name, quantity);
		
		

		break;

	case 'p':
		cout << "-- Change Item Price --" << endl;
		cin.ignore();
		// get the item name and new price from user
		cout << "\tEnter the item name: ";
		getline(cin, name);

		cout << "\tEnter the new price: ";
		cin >> price;

		// change the item price
		cout << endl << endl;
		theCart.changeItemPrice(name, price);
		
		

		break;

	case 'o':
		// display cart info
		theCart.outputCartInfo();
		cout << endl << endl;

		break;
	}
}
