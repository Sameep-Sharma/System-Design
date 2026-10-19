#include<bits/stdc++.h>
using namespace std;

// Base class for two-dimensional shapes
class TwoDimensionalShape {
  public:
    virtual double area() = 0; // Pure virtual function to calculate the area of the shape
};

// Base class for three-dimensional shapes
class ThreeDimensionalShape {
  public:
    virtual double area() = 0; // Pure virtual function to calculate the area of the shape
    virtual double volume() = 0; // Pure virtual function to calculate the volume of the shape
};

// Square class that implements the TwoDimensionalShape interface
class Square : public TwoDimensionalShape {
  private:
    double side;

  public:
    Square(double s) : side(s) {}

    double area() override {
        return side * side;
    }
};

// Rectangle class that implements the TwoDimensionalShape interface

class Rectangle : public TwoDimensionalShape {
  private:
    double length;
    double width;

  public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }
};

// Cube class that implements the ThreeDimensionalShape interface
class Cube : public ThreeDimensionalShape {
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
    TwoDimensionalShape* square = new Square(5);
    cout << "Area of square: " << square->area() << endl;

    TwoDimensionalShape* rectangle = new Rectangle(4, 6);
    cout << "Area of rectangle: " << rectangle->area() << endl;

    ThreeDimensionalShape* cube = new Cube(3);
    cout << "Area of cube: " << cube->area() << endl;
    cout << "Volume of cube: " << cube->volume() << endl;

    delete square;
    delete rectangle;
    delete cube;

    return 0;
}
