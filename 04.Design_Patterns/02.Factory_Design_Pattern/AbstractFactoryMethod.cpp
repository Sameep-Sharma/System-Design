#include<bits/stdc++.h>
using namespace std;

// ---Product1 ---> burger

class Burger{
  public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;
};

class BasicBurger : public Burger{
  public:
    void prepare()
    override {
        cout << "Preparing Basic Burger" << endl;
    }
};

class StandardBurger : public Burger{
  public:
    void prepare()
    override {
        cout << "Preparing Standard Burger" << endl;
    }
};

class PremiumBurger : public Burger{
  public:
    void prepare()
    override {
        cout << "Preparing Premium Burger" << endl;
    }
};

class BasicWheatBurger : public Burger{
  public:
    void prepare()
    override {
        cout << "Preparing Basic Wheat Burger" << endl;
    }
};

class StandardWheatBurger : public Burger{
  public:
    void prepare()
    override {
        cout << "Preparing Standard Wheat Burger" << endl;
    }
};

class PremiumWheatBurger : public Burger{
  public:
    void prepare()
    override {
        cout << "Preparing Premium Wheat Burger" << endl;
    }
};

//---Product2 ---> garlic bread
class GarlicBread{
  public:
    virtual void prepare() = 0;
    virtual ~GarlicBread() = default;
};

class BasicGarlicBread : public GarlicBread{
  public:
    void prepare()
    override {
        cout << "Preparing Basic Garlic Bread" << endl;
    }
};

class StandardGarlicBread : public GarlicBread{
  public:
    void prepare()
    override {
        cout << "Preparing Standard Garlic Bread" << endl;
    }
};

class PremiumGarlicBread : public GarlicBread{
  public:
    void prepare()
    override {
        cout << "Preparing Premium Garlic Bread" << endl;
    }
};

class BasicWheatGarlicBread : public GarlicBread{
  public:
    void prepare()
    override {
        cout << "Preparing Basic Wheat Garlic Bread" << endl;
    }
};

class StandardWheatGarlicBread : public GarlicBread{
  public:
    void prepare()
    override {
        cout << "Preparing Standard Wheat Garlic Bread" << endl;
    }
};

class PremiumWheatGarlicBread : public GarlicBread{
  public:
    void prepare()
    override {
        cout << "Preparing Premium Wheat Garlic Bread" << endl;
    }
};

//---Factory and its concrete factories
class MealFactory{
  public:
    virtual Burger* createBurger(const string& type) = 0;
    virtual GarlicBread* createGarlicBread(const string& type) = 0;
    virtual ~MealFactory() = default;
};

class SinghBurgerFactory : public MealFactory{
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

    GarlicBread* createGarlicBread(const string& type) override {
        if (type == "Basic") {
            return new BasicGarlicBread();
        } else if (type == "Standard") {
            return new StandardGarlicBread();
        } else if (type == "Premium") {
            return new PremiumGarlicBread();
        } else {
            return nullptr;
        }
    }
};

class KingBurgerFactory : public MealFactory{
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

    GarlicBread* createGarlicBread(const string& type) override {
        if (type == "Basic") {
            return new BasicWheatGarlicBread();
        } else if (type == "Standard") {
            return new StandardWheatGarlicBread();
        } else if (type == "Premium") {   
            return new PremiumWheatGarlicBread();
        } else {
            return nullptr;
        }
    }
};

int main()
{
  string type = "Basic";
  
  MealFactory* factory = new SinghBurgerFactory();
    Burger* burger = factory->createBurger(type);
    if (burger) {
        burger->prepare();
        delete burger;
    }

    GarlicBread* garlicBread = factory->createGarlicBread(type);
    if (garlicBread) {
        garlicBread->prepare();
        delete garlicBread;
    }

    delete factory;

    factory = new KingBurgerFactory();
    burger = factory->createBurger(type);
    if (burger) {
        burger->prepare();
        delete burger;
    }

    garlicBread = factory->createGarlicBread(type);
    if (garlicBread) {
        garlicBread->prepare();
        delete garlicBread;
    }

    delete factory;

    return 0; 
}