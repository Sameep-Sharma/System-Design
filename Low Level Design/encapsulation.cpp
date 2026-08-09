#include<iostream>
#include<string>
using namespace std;

//real life car

class SportsCar {
  private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

  public:

    // Constructor
    SportsCar(string b, string m)
    : brand(b),
      model(m),
      isEngineOn(false),
      currentSpeed(0),
      currentGear(0) {
}

  //but  we are allowing to see the speed and gear 
  //we will use getter and setter methods to access and modify private members of the class

  int getCurrentSpeed() {
      return currentSpeed;
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
SportsCar* myCar = new SportsCar("Ferrari", "488");
  myCar->startEngine();
  myCar->shiftGear(1);
  myCar->accelerate();
  myCar->shiftGear(2);
  myCar->accelerate(); myCar->brake();
  myCar->stopEngine();
  cout << "Current speed: " << myCar->getCurrentSpeed() << " km/h" << endl;
  //setting arbitrary values to speed
  // myCar->currentSpeed = 100; //this should not be allowed as it breaks encapsulation. We should not be able to set the speed directly from outside the class.

  delete myCar;
}

