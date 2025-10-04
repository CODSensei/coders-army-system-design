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

// violating OCP
// class CartToDB{
// private: 
// 	ShoppingCart* cart;
// public:
// 	CartToDB(ShoppingCart* cart) {
// 		this->cart = cart;
// 	}
// 	void saveToDB() {
// 		cout << "Saving shopping cart to DB\n";
// 	}
// 	void saveToMongo() {
// 		cout << "Saving shopping cart to Mongo DB\n";
// 	}
// 	void saveToFile() {
// 		cout << "Saving shopping cart to File\n";
// 	}
// };

class Persistence {
private:
	ShoppingCart* cart;

public:
	virtual void save(ShoppingCart* cart) = 0;
};

class SaveToDB: public Persistence{
public:
	void save(ShoppingCart* cart) override {
		cout << "Saving shopping cart to DB\n";
	}
};

class SaveToMongo: public Persistence{
public:
	void save(ShoppingCart* cart) override {
		cout << "Saving shopping cart to MongoDB\n";
	}
};

class SaveToFile: public Persistence{
public:
	void save(ShoppingCart* cart) override {
		cout << "Saving shopping cart to File\n";
	}
};

int main() {
	ShoppingCart* cart = new ShoppingCart();

	cart->addProduct(new Product("laptop", 1199));
	cart->addProduct(new Product("mouse", 30));

	CartInvoicePrinter* printer = new CartInvoicePrinter(cart);
	printer->printInvoice();

	// CartToDB* db = new CartToDB(cart);
	// db->saveToDB();
	// db->saveToMongo();
	// db->saveToFile();
	
	Persistence* db = new SaveToDB();
	Persistence* mongo = new SaveToMongo();
	Persistence* file = new SaveToFile();

	db->save(cart);
	mongo->save(cart);
	file->save(cart);



	return 0;

}
