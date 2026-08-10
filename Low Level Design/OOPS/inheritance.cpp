#include<bits/stdc++.h>
#include<string.h>
using namespace std;


class Car{
  protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

    public:
    Car(string b, string m){
      this->brand = b;
      this->model = m;
      isEngineOn = false;
      currentSpeed = 0;
    }

    void startEngine(){
      isEngineOn = true;
      cout << "Engine started for " << brand << " " << model << endl;
    }

    void stopEngine(){
      isEngineOn = false;
      currentSpeed = 0;
      cout << "Engine stopped for " << brand << " " << model << endl;
    }

    void accelerate(){
      if(isEngineOn){
        currentSpeed += 10;
        cout << "Accelerating " << brand << " " << model << ". Current speed: " << currentSpeed << " km/h" << endl;
      } else {
        cout << "Cannot accelerate. Engine is off for " << brand << " " << model << endl;
      }
    }

    void brake(){
      if(currentSpeed > 0){
        currentSpeed -= 10;
        cout << "Braking " << brand << " " << model << ". Current speed: " << currentSpeed << " km/h" << endl;
      } else {
        cout << brand << " " << model << " is already at a standstill." << endl;
      }
    }

    //Destructor
    virtual ~Car() {
        cout << "Destroying Car: " << brand << " " << model << endl;
    }
};

class ManualCar: public Car{
  private:
    int gear;

  public:
  //Constructor
    ManualCar(string b, string m): Car(b, m){
      gear = 1;
    }

    void shiftGear(int g){
      if(g >= 1 && g <= 6){
        gear = g;
        cout << "Shifted to gear " << gear << " for " << brand << " " << model << endl;
      } else {
        cout << "Invalid gear. Please select a gear between 1 and 6." << endl;
      }
    }
};

class ElectricCar: public Car{
  private:
    int batteryLevel;

  public:
  //Constructor
    ElectricCar(string b, string m): Car(b, m){
      batteryLevel = 100; // Battery level in percentage
    }

    void chargeBattery(int amount){
      if(amount > 0 && amount <= 100){
        batteryLevel += amount;
        if(batteryLevel > 100) batteryLevel = 100;
        cout << "Charging " << brand << " " << model << ". Battery level: " << batteryLevel << "%" << endl;
      } else {
        cout << "Invalid charge amount. Please provide a value between 1 and 100." << endl;
      }
    }

    void checkBattery(){
      cout << "Battery level for " << brand << " " << model << ": " << batteryLevel << "%" << endl;
    }
};

int main()
{
  ManualCar* myManualCar = new ManualCar("Toyota", "Corolla");
  ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");

  myManualCar->startEngine();
  myManualCar->accelerate();
  myManualCar->shiftGear(2);
  myManualCar->brake();
  myManualCar->stopEngine();

  myElectricCar->startEngine();
  myElectricCar->accelerate();
  myElectricCar->checkBattery();
  myElectricCar->chargeBattery(20);
  myElectricCar->checkBattery();
  myElectricCar->stopEngine();

  delete myManualCar;
  delete myElectricCar;
}