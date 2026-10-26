#include<bits/stdc++.h>
using namespace std;



class Product {
  public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
  };

  //Violation of Single Responsibility Principle-: ShoppingCart class is responsible for both managing the products and calculating the total price.
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
  //       // 1.Calculate the total price of the products in the cart
  //       double calculateTotalPrice() {
  //           double total = 0;
  //           for (const auto& product : products) {
  //               total += product.price;
  //           }
  //           return total;
  //       }
  //       //2. Prints Invoice
  //       void printInvoice() {
  //           cout << "Invoice:" << endl;
  //           for (const auto& product : products) {
  //               cout << "Product: " << product.name << ", Price: " << product.price << endl;
  //           }
  //           cout << "Total Price: " << calculateTotalPrice() << endl;
  //       }

  //       //3. Saves to database
  //       void saveToDatabase() {
  //           // Code to save the shopping cart data to a database
  //           cout << "Saving shopping cart data to the database..." << endl;
  //       }
  //   };

//? Following SRP dividing classes into separate classes for each responsibility.



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

// 3. ShoppingCartStorage: Only responsible for saving cart to DB
class ShoppingCartStorage {
private:
    ShoppingCart* cart; 

public:
    ShoppingCartStorage(ShoppingCart* cart) { 
        this->cart = cart; 
    }

    void saveToDatabase() {
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToDatabase();

    return 0;
}