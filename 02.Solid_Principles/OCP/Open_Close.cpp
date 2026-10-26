#include<bits/stdc++.h>
using namespace std;


// class Product {
//   public:
//     string name;
//     double price;

//     Product(string name, double price) {
//         this->name = name;
//         this->price = price;
//     }
// };

// class ShoppingCart {
//   private:
//       vector<Product> products;
//   public:
//       void addProduct(Product product) {
//           products.push_back(product);
//       }

//       const vector<Product>& getProducts(){
//           return products;
//       }
// };

// class PriceCalculator {
//   public:
//       double calculateTotalPrice(const vector<Product>& products) {
//           double total = 0;
//           for (const auto& product : products) {
//               total += product.price;
//           }
//           return total;
//       }
// };

// class InvoicePrinter {
//   public:
//       void printInvoice(const vector<Product>& products, double totalPrice) {
//           cout << "Invoice:" << endl;
//           for (const auto& product : products) {
//               cout << "Product: " << product.name << ", Price: " << product.price << endl;
//           }
//           cout << "Total Price: " << totalPrice << endl;
//       }
// };

// class DatabaseSaver {
//   public:
//     void saveToDatabase(const ShoppingCart& cart) {
//         // Code to save the shopping cart data to a database
//         cout << "Saving shopping cart data to the database..." << endl;
//     }

//     void saveToSQLDatabase(const ShoppingCart& cart) {
//         // Code to save the shopping cart data to a SQL database
//         cout << "Saving shopping cart data to the SQL database..." << endl;
//     }

//     void saveToNoSQLDatabase(const ShoppingCart& cart) {
//         // Code to save the shopping cart data to a NoSQL database
//         cout << "Saving shopping cart data to the NoSQL database..." << endl;
//     }

//     void saveToCloudDatabase(const ShoppingCart& cart) {
//         // Code to save the shopping cart data to a cloud database
//         cout << "Saving shopping cart data to the cloud database..." << endl;
//     }

//     This one is violating OCP
// };



//* FOLLOWING OCP PRINCIPLE

#include <iostream>
#include <vector>

using namespace std;

// Product class representing any item in eCommerce.
class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

//1. ShoppingCart: Only responsible for Cart related business logic.
class ShoppingCart {
private:
    vector<Product*> products; // Store heap-allocated products

public:
    void addProduct(Product* p) { 
        products.push_back(p);
    }

    const vector<Product*>& getProducts() { 
        return products;
    } 

    //Calculates total price in cart.
    double calculateTotal() {
        double total = 0;
        for (auto p : products) {
            total += p->price;
        }
        return total;
    }
};

// 2. ShoppingCartPrinter: Only responsible for printing invoices
class ShoppingCartPrinter {
private:
    ShoppingCart* cart; 

public:
    ShoppingCartPrinter(ShoppingCart* cart) { 
        this->cart = cart; 
    }

    void printInvoice() {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : cart->getProducts()) {
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << cart->calculateTotal() << endl;
    }
};

//Abstract class
class Persistence {
private:
    ShoppingCart* cart;

public:
    virtual void save(ShoppingCart* cart) = 0; // Pure virtual function
};

class SQLPersistence : public Persistence {
public:
    void save(ShoppingCart* cart) override {
        cout << "Saving shopping cart to SQL DB..." << endl;
    }
};

class MongoPersistence : public Persistence {
public:
    void save(ShoppingCart* cart) override {
        cout << "Saving shopping cart to MongoDB..." << endl;
    }
};

class FilePersistence : public Persistence {
public:
    void save(ShoppingCart* cart) override {
        cout << "Saving shopping cart to a file..." << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    Persistence* db = new SQLPersistence();
    Persistence* mongo = new MongoPersistence();
    Persistence* file = new FilePersistence();

    db->save(cart);   // Save to SQL database
    mongo->save(cart); // Save to MongoDB
    file->save(cart);  // Save to File

    return 0;
}