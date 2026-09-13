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

class ShoppingCart {
  private:
      vector<Product> products;
  public:
      void addProduct(Product product) {
          products.push_back(product);
      }

      const vector<Product>& getProducts(){
          return products;
      }
  };

  class InvoicePrinter {  
    public:
      void printInvoice(const ShoppingCart& cart) {
          cout << "Invoice:" << endl;
          for (const auto& product : cart.getProducts()) {
              cout << "Product: " << product.name << ", Price: " << product.price << endl;
          }
          cout << "Total Price: " << calculateTotalPrice(cart) << endl;
      }
    };

  class DatabaseSaver {
    public:
      void saveToDatabase(const ShoppingCart& cart) {
          // Code to save the shopping cart data to a database
          cout << "Saving shopping cart data to the database..." << endl;
      }
    };

    class PriceCalculator {
      public:
        double calculateTotalPrice(const ShoppingCart& cart) {
            double total = 0;
            for (const auto& product : cart.getProducts()) {
                total += product.price;
            }
            return total;
        }
    };



int main() {
    cout << "Single Responsibility Principle" << endl;
    ShoppingCart cart;
    cart.addProduct(Product("Product 1", 10.99)); 
    cart.addProduct(Product("Product 2", 5.49));
    cart.addProduct(Product("Product 3", 7.99));
    cart.getProducts();

    PriceCalculator priceCalculator;
    double totalPrice = priceCalculator.calculateTotalPrice(cart);
    cout << "Total Price: " << totalPrice << endl;

    InvoicePrinter invoicePrinter;
    invoicePrinter.printInvoice(cart);

    DatabaseSaver databaseSaver;
    databaseSaver.saveToDatabase(cart);
    return 0;
}