#include<bits/stdc++.h>
using namespace std;


//Component interface  :defines a common interface for concrete components and decorators

class Character {
public:
    virtual void getAbilities() = 0;
    virtual ~Character() {}
};

//Concrete component : implements the component interface

class Mario : public Character {
public:
    void getAbilities() override {
        cout << "Mario: Jump, Run" << endl;
    }
};

//Abstract Decorator : maintains a reference to a Character object and defines an interface that conforms to Character's interface

class CharacterDecorator : public Character {
protected:
    Character* character;
public:
    CharacterDecorator(Character* c) : character(c) {}
    virtual ~CharacterDecorator() { delete character; }
};

//Concrete Decorators : extend the functionality of the component by adding new behaviors

class HeightDecorator : public CharacterDecorator {
  public:
    HeightDecorator(Character* c) : CharacterDecorator(c) {}
    void getAbilities() override {
        character->getAbilities();
        cout << "Height: Tall" << endl;
    }
};

class SpeedDecorator : public CharacterDecorator {
  public:
    SpeedDecorator(Character* c) : CharacterDecorator(c) {}
    void getAbilities() override {
        character->getAbilities();
        cout << "Speed: Fast" << endl;
    }
};

class PowerUpDecorator : public CharacterDecorator {
  public:
    PowerUpDecorator(Character* c) : CharacterDecorator(c) {}
    void getAbilities() override {
        character->getAbilities();
        cout << "Power-Up: Fireball" << endl;
    }
};


int main() {
    Character* mario = new Mario();
    cout << "Base Abilities:" << endl;
    mario->getAbilities();

    cout << "\nDecorated Abilities:" << endl;
    Character* decoratedMario = new PowerUpDecorator(new SpeedDecorator(new HeightDecorator(mario)));
    decoratedMario->getAbilities();

    delete decoratedMario; // Clean up memory
    return 0;
}