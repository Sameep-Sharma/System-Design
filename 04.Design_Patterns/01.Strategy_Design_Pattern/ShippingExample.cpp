#include<bits/stdc++.h>
using namespace std;


//--Step 1: Define the Strategy Interface (ShippingStrategy)

// --Base Class for Shipping Strategy--

//--This interface is simple and focused. Every strategy takes an order and returns a cost. The interface says nothing about how the cost is calculated, and that is the whole point.----

class ShippingStrategy {
public:
    virtual ~ShippingStrategy() {}
    virtual double calculateShippingCost(const Order& order) = 0;
};

// --Step 2: Implement Concrete Strategies (Shipping Methods)

class FlatRateShipping : public ShippingStrategy {
private:
    double flatRate;
public:
    FlatRateShipping(double rate) : flatRate(rate) {}
    double calculateShippingCost(const Order& order) override {
        return flatRate;
    }
};

class WeightBasedShipping : public ShippingStrategy {
private:
  double ratePerKg; 
public:
    WeightBasedShipping(double rate) : ratePerKg(rate) {}
    double calculateShippingCost(const Order& order) override {
        return order.getWeight() * ratePerKg;
    }
};

class DistanceBasedShipping : public ShippingStrategy {
private:
    double ratePerKm;
public:
    DistanceBasedShipping(double rate) : ratePerKm(rate) {}
    double calculateShippingCost(const Order& order) override {
        return order.getDistance() * ratePerKm;
    }
};

// --Step 3: Context Class (Order)

class ShippingCostService {
private:
    ShippingStrategy* strategy;
public:
    ShippingCostService(ShippingStrategy* strategy) : strategy(strategy) {}
    
    void setStrategy(ShippingStrategy* newStrategy) {
        strategy = newStrategy;
    }
    
    double calculateCost(const Order& order) {
        return strategy->calculateShippingCost(order);
    }
};

// --Step 4:Client Code
//Here is how the client uses the pattern:

void ecommerceApp(){
  Order order1;

  //Create Different strategy instances
  FlatRateShipping flatRate(10.0);
  WeightBasedShipping weightBased(2.0);
  DistanceBasedShipping distanceBased(0.5);

  //Create Context with a specific strategy
  ShippingCostService shippingService(&flatRate);

  cout << "Flat Rate Shipping Cost: $" << shippingService.calculateCost(order1) << endl;

  //Change strategy at runtime
  cout << "Switching to Weight Based Shipping..." << endl;
  shippingService.setStrategy(&weightBased);
  cout << "Weight Based Shipping Cost: $" << shippingService.calculateCost(order1) << endl;

  cout << "Switching to Distance Based Shipping..." << endl;
  shippingService.setStrategy(&distanceBased);
  cout << "Distance Based Shipping Cost: $" << shippingService.calculateCost(order1) << endl;

  // Adding a NEW strategy is easy:
    // 1. Create a new class implementing ShippingStrategy (e.g., FreeShippingStrategy)
    // 2. Client can then instantiate and use it:
    //    FreeShippingStrategy freeShipping;
    //    shippingService.setStrategy(&freeShipping);
    //    shippingService.calculateShippingCost(primeMemberOrder);
    // No modification to ShippingCostService is needed!

    int main() {
        ecommerceApp();
        return 0;
    }
}