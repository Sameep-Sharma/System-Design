#include<bits/stdc++.h>
using namespace std;

// Base class for shapes
class Shape {
  public:
    virtual double area() = 0; // Pure virtual function to double the area of the shape
    virtual double volume() = 0; // Pure virtual function to calculate the volume of the shape
};

//Square class that implements the Shape interface it should only implement the area method and not the volume method but it is forced to implement the volume method as well which violates the Interface Segregation Principle

class Square : public Shape {
  private:
    double side;

  public:
    Square(double s) : side(s) {}

    double area() override {
        return side * side;
    }

    double volume() override {
        // Volume is not applicable for a square, but we are forced to implement it
        throw logic_error("Volume is not applicable for a square");
    }
};

class Rectangle : public Shape {
  private:
    double length;
    double width;

  public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }

    double volume() override {
        // Volume is not applicable for a rectangle, but we are forced to implement it
        throw logic_error("Volume is not applicable for a rectangle");
    }
};

class Cube : public Shape {
  private:
    double side;

  public:
    Cube(double s) : side(s) {}

    double area() override {
        return 6 * side * side;
    }

    double volume() override {
        return side * side * side;
    }
};

int main() {
    Shape* square = new Square(5.0);
    Shape* rectangle = new Rectangle(4.0, 6.0);
    Shape* cube = new Cube(3.0);
    cout << "Area of square: " << square->area() << endl;
    cout << "Area of rectangle: " << rectangle->area() << endl;
    cout << "Area of cube: " << cube->area() << endl;
    cout << "Volume of cube: " << cube->volume() << endl; 
    try {
        cout << "Volume of square: " << square->volume() << endl; // This will throw an exception
    } catch (const logic_error& e) {
        cout << "Error: " << e.what() << endl;
    }


    return 0;
}