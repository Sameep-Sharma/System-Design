#include <iostream>
#include <string>

using namespace std;

// Component interface
class Coffee {
public:
    virtual double getCost() = 0;
    virtual string getDescription() = 0;
    virtual ~Coffee() {}
};

// Concrete component
class SimpleCoffee : public Coffee {
public:
    double getCost() override {
        return 1.00;
    }

    string getDescription() override {
        return "Simple coffee";
    }
};

// Abstract decorator
class CoffeeDecorator : public Coffee {
protected:
    Coffee* inner;
public:
    CoffeeDecorator(Coffee* inner) : inner(inner) {}
};

// Concrete decorators
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* inner) : CoffeeDecorator(inner) {}

    double getCost() override {
        return inner->getCost() + 0.50;
    }

    string getDescription() override {
        return inner->getDescription() + ", milk";
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* inner) : CoffeeDecorator(inner) {}

    double getCost() override {
        return inner->getCost() + 0.20;
    }

    string getDescription() override {
        return inner->getDescription() + ", sugar";
    }
};

class WhippedCreamDecorator : public CoffeeDecorator {
public:
    WhippedCreamDecorator(Coffee* inner) : CoffeeDecorator(inner) {}

    double getCost() override {
        return inner->getCost() + 1.00;
    }

    string getDescription() override {
        return inner->getDescription() + ", whipped cream";
    }
};

// Client
int main() {
    Coffee* myCoffee = new SimpleCoffee();
    cout << myCoffee->getDescription() << " costs $" << myCoffee->getCost() << endl;

    myCoffee = new MilkDecorator(myCoffee);
    cout << myCoffee->getDescription() << " costs $" << myCoffee->getCost() << endl;

    myCoffee = new SugarDecorator(myCoffee);
    cout << myCoffee->getDescription() << " costs $" << myCoffee->getCost() << endl;

    myCoffee = new WhippedCreamDecorator(myCoffee);
    cout << myCoffee->getDescription() << " costs $" << myCoffee->getCost() << endl;

    delete myCoffee; // Clean up memory
}