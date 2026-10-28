#include<bits/stdc++.h>
using namespace std;


class Burger{
public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;  
};

class BasicBurger : public Burger{
public:
    void prepare() override {
        cout << "Preparing Basic Burger" << endl;
    }
};

class StandardBurger : public Burger{
  public:
    void prepare() override {
        cout << "Preparing Standard Burger" << endl;
    }
};

class PremiumBurger : public Burger{
  public:
    void prepare() override {
        cout << "Preparing Premium Burger" << endl;
    }
};

class BurgerFactory{
public:
    Burger* createBurger(const string& type) {
        if (type == "Basic") {
            return new BasicBurger();
        } else if (type == "Standard") {
            return new StandardBurger();
        } else if (type == "Premium") {
            return new PremiumBurger();
        } else {
            return nullptr;
        }
    }
};

int main() {
    BurgerFactory factory;

    Burger* basicBurger = factory.createBurger("Basic");
    if (basicBurger) {
        basicBurger->prepare();
        delete basicBurger;
    }

    Burger* standardBurger = factory.createBurger("Standard");
    if (standardBurger) {
        standardBurger->prepare();
        delete standardBurger;
    }

    Burger* premiumBurger = factory.createBurger("Premium");
    if (premiumBurger) {
        premiumBurger->prepare();
        delete premiumBurger;
    }

    return 0;
}