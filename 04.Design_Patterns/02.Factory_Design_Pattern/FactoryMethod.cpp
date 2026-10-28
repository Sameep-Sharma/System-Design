#include<bits/stdc++.h>
using namespace std;


//Product class and subclasses
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

class BasicWheatBurger : public Burger{
  public:
    void prepare() override {
        cout << "Preparing Basic Wheat Burger" << endl;
    }
};

class StandardWheatBurger : public Burger{
  public:
    void prepare() override {
        cout << "Preparing Standard Wheat Burger" << endl;
    }
};

class PremiumWheatBurger : public Burger{
  public:
    void prepare() override {
        cout << "Preparing Premium Wheat Burger" << endl;
    }
};

//Factory and its concrete factories
class BurgerFactory{
  public:
    virtual Burger* createBurger(const string& type) = 0;
    virtual ~BurgerFactory() = default;
};

class SinghBurgerFactory : public BurgerFactory{
  public:
    Burger* createBurger(const string& type) override {
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

class KingBurgerFactory : public BurgerFactory{
  public:
    Burger* createBurger(const string& type) override {
        if (type == "Basic") {
            return new BasicWheatBurger();
        } else if (type == "Standard") {
            return new StandardWheatBurger();
        } else if (type == "Premium") {
            return new PremiumWheatBurger();
        } else {
            return nullptr;
        }
    }
};

int main()
{
  string type = "Basic";
  
  BurgerFactory* factory = new SinghBurgerFactory();
    Burger* burger = factory->createBurger(type);
    if (burger) {
        burger->prepare();
        delete burger;
    }

    delete factory;

    factory = new KingBurgerFactory();
    burger = factory->createBurger(type);
    if (burger) {
        burger->prepare();
        delete burger;
    }

    delete factory;

    return 0; 
}