#include<iostream>
#include<string>
using namespace std;

//real life car

/*
Abstract class Car with pure virtual functions to represent the common interface for all types of cars.
then we make a derived class SportsCar that implements the pure virtual functions of the Car class.
*/

class Car{
  public:
    virtual void startEngine() = 0; 
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car(){} //destructor
};


class SportsCar : public Car{
  public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    // Constructor
    SportsCar(string b, string m)
    : brand(b),
      model(m),
      isEngineOn(false),
      currentSpeed(0),
      currentGear(0) {
}

    void startEngine(){
        isEngineOn = true;
        cout <<brand<<" "<<model<<" "<< "SportsCar engine started." << endl;
    }
    void shiftGear(int gear){
      if(!isEngineOn){
        cout << "Cannot shift gear. Engine is off." << endl;
        return;
      }
      currentGear = gear;
      cout <<brand<<" "<<model<<" "<< "SportsCar shifted to gear " << currentGear << endl;
    }
    void accelerate(){
      if(!isEngineOn){
        cout << "Cannot accelerate. Engine is off." << endl;
        return;
      }
      currentSpeed += 10;
      cout <<brand<<" "<<model<<" "<< "SportsCar accelerated to " << currentSpeed << " km/h" << endl;
    }
    void brake(){
      if(!isEngineOn){
        cout << "Cannot brake. Engine is off." << endl;
        return;
      }
      currentSpeed -= 10;
      if(currentSpeed < 0) currentSpeed = 0;
      cout <<brand<<" "<<model<<" "<< "SportsCar slowed down to " << currentSpeed << " km/h" << endl;
    }
    void stopEngine(){
      isEngineOn = false;
      currentSpeed = 0;
      currentGear = 0;
      cout <<brand<<" "<<model<<" "<< "SportsCar engine stopped." << endl;
    }
};

int main() {

  Car* myCar = new SportsCar("Ferrari", "488");
  myCar->startEngine();
  myCar->shiftGear(1);
  myCar->accelerate();
  myCar->shiftGear(2);
  myCar->accelerate(); myCar->brake();
  myCar->stopEngine();
  delete myCar;
}

