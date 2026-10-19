#include<bits/stdc++.h>
using namespace std;

// A Postcondition must be satisfied after a method has been executed.
// Sub classes can strengthen the postcondition of the base class method, but they cannot weaken it.

class Car{
  protected:
    int speed;

public:
    Car() : speed(0) {}

    void accelerate(){
      cout<<"Accelerating the car..."<<endl;
      speed+=20;
    }

    //Postcondition: Speed must reduce after braking
    virtual void brake(){
      cout<<"Applying brakes"<<endl;
      speed-=10;
    }
};

//Subclass that strengthens the postcondition of the base class method

class HybridCar:public Car{
private:
  int chargeLevel;
public:
  HybridCar() : chargeLevel(100) {}

  //Postcondition: Speed must reduce and charge level must increase after braking
  void brake(){
    cout<<"Applying brakes in hybrid car"<<endl;
    speed-=20;
    chargeLevel+=10;
  }
};


int main() {
    Car* car = new Car();
    car->accelerate();
    car->brake(); // Valid postcondition

    HybridCar* hybridCar = new HybridCar();
    hybridCar->accelerate();
    hybridCar->brake(); // Valid postcondition, strengthens the base class postcondition

    delete car;
    delete hybridCar;

    return 0;
}






