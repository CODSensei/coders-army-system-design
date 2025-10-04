#include<iostream>
#include<vector>

using namespace std;

// Product class representing any item of any ECommerece
class Product {
public:
	string name;
	double price;

	Product(string name, double price) {
		this->name = name;
		this->price= price;
	}
};

// Violating SRP
class ShoppingCart {
private:
	vector<Product*> products;

public:
	void addProduct(Product* p) {
		products.push_back(p);
	}

	const vector<Product*>& getProducts() {
		return products;
	}

	// 1. Calculate total price in cart
	double calcTotal() {
		double total = 0;
		for(auto p: products) {
			total += p->price;
		}
		return total;
	}
	
	// 2. Prints Invoice
	// void printInvoice() {
	// 	cout << "Shopping Cart Invoice\n";
	// 	for(auto p: products){
	// 		cout << p->name << " -$" << p->price << endl;
	// 	}
	// 	cout << "Total: $" << calcTotal() << endl;
	// }
	
	// 3.Saves to DB 
	// void saveToDB() {
	// 	cout << "Saving shopping cart to DB\n";
	// }
};

class CartInvoicePrinter {
private: 
	ShoppingCart* cart;
public:
	CartInvoicePrinter(ShoppingCart* cart) {
		this->cart = cart;
	}
	void printInvoice() {
		cout << "Shopping Cart Invoice\n";
		for(auto p: cart->getProducts()){
			cout << p->name << " -$" << p->price << endl;
		}
		cout << "Total: $" << cart->calcTotal() << endl;
	}
};

class CartToDB{
private: 
	ShoppingCart* cart;
public:
	CartToDB(ShoppingCart* cart) {
		this->cart = cart;
	}
	void saveToDB() {
		cout << "Saving shopping cart to DB\n";
	}
};

int main() {
	ShoppingCart* cart = new ShoppingCart();

	cart->addProduct(new Product("laptop", 1199));
	cart->addProduct(new Product("mouse", 30));

	// cart->printInvoice();
	// cart->saveToDB();
	//
	CartInvoicePrinter* printer = new CartInvoicePrinter(cart);
	printer->printInvoice();

	CartToDB* db = new CartToDB(cart);
	db->saveToDB();

	return 0;

}
