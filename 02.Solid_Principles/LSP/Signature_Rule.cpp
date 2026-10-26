#include<bits/stdc++.h>
using namespace std;

//Signature Rule: The signature rule states that the signature of a method in a derived class must match the signature of the method in the base class. This means that the method name, return type, and parameter types must be the same in both the base and derived classes. If a derived class changes the signature of a method from the base class, it violates the Liskov Substitution Principle (LSP) because it can lead to unexpected behavior when using polymorphism.


// class Parent
// {
//   public:
//     virtual void print(string msg){
//       cout<< "Parent: " << msg << endl; 
//     }
// };

// class Child : public Parent
// {
//   public:
//     void print(string msg) override{
//       cout<< "Child: " << msg << endl; 
//     }
// };

// class Client{
//   private:
//     Parent* parent;

//   public:
//     Client(Parent* p){
//       this -> parent = p;
//     }
//     void printMsg()
//     {
//       parent->print("Hello from Client");
//     }
// };

// int main()
// {
//   Parent* p = new Parent();
//   Parent* c = new Child();

//   Client* client = new Client(p);

//   client -> printMsg(); // Output: Parent: Hello from Client
// }


//Return type rule: the return type of an overridden method in a derived class must be the same as the return type of the method in the base class. If a derived class changes the return type of a method from the base class, it violates the Liskov Substitution Principle (LSP) because it can lead to unexpected behavior when using polymorphism.

//doign narrow return type is called covariance


// class Animal{
   //some common animal properties and methods
// };

// class Dog : public Animal{
   //some dog-specific properties and methods
// };

// class Parent{
//   public:
//     virtual Animal* getAnimal(){
//       cout<< "Parent: Returningt an animal instance" << endl;
//       return new Animal();
//     }
// };

// class Child: public Parent{
//   public:
//   Dog * getAnimal() override{
//       cout<< "Child: Returning a dog instance" << endl;
//       return new Dog();
//     }
// };

// class Client{
//   private:
//     Parent* parent;

//   public:
//     Client(Parent* p){
//       this -> parent = p;
//     }
//     void takeAnimal(){
//       parent->getAnimal();
//     }
// };

// int main()
// {
//   Parent* p = new Parent();
//   Parent* c = new Child();

//   Client* client = new Client(c);

//   client -> takeAnimal(); // Output: Parent: Returning an animal instance
// }


//Exception rule: The exception rule states that a derived class should not throw new or broader checked exceptions than those declared by the base class method. If a derived class throws new or broader checked exceptions, it violates the Liskov Substitution Principle (LSP) because it can lead to unexpected behavior when using polymorphism.

/*
|---std::logic_error  <--- For logical errors in the program
|   |---std::invalid_argument  <--- For invalid arguments
|   |---std::domain_error  <--- For domain errors
|   |---std::length_error  <--- For length errors
|   |---std::out_of_range  <--- For out of range errors
|   |---std::overflow_error  <--- For overflow errors
|   |---std::underflow_error  <--- For underflow errors
|   |---std::range_error  <--- For range errors
|   |---std::ios_base::failure  <--- For I/O stream failures
|
|---std::runtime_error  <--- For runtime errors 
|    |---std::system_error  <--- For system errors
|    |---std::regex_error  <--- For regular expression errors
|    |---std::future_error  <--- For future errors
|    |---std::bad_alloc  <--- For memory allocation errors
|    |---std::bad_cast  <--- For bad type casting errors
*/

class Parent{
  public:
    virtual void getValue()noexcept(false){ //Parent throws logic_error
      throw logic_error("Parent: Logic error occurred");
    }
};

class Child:public Parent{
public:
    void getValue()noexcept(false) override{ //Child throws invalid_argument
      throw out_of_range("Child: Error");
    }
};

class Client{
  private:
    Parent* parent;
  public:
    Client(Parent *p){
      this -> parent = p;
    }
    void takeValue(){
      try{
        parent->getValue();
      }
      catch(const logic_error& e){
        cout<<"Logic Error Exception: "<<e.what() << endl;
      }
    }
};

int main()
{
  Parent *parent = new Parent();
  Child *child = new Child();

  Client* client = new Client(child);
  client -> takeValue();
  return 0;

}






