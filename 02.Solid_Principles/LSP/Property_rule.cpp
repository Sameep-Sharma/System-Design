#include <bits/stdc++.h>
using namespace std;

//Property rule: The property rule states that a derived class should not weaken the properties of the base class. This means that if a base class has certain properties or invariants, the derived class should not violate those properties or invariants. If a derived class weakens the properties of the base class, it violates the Liskov Substitution Principle (LSP) because it can lead to unexpected behavior when using polymorphism.

//Class Invariant: A class invariant is a condition that must always hold true for an object of a class. It defines the valid state of an object and ensures that the object behaves correctly throughout its lifetime. Class invariants are typically established in the constructor and maintained by the methods of the class. If a derived class violates the class invariant of its base class, it can lead to unexpected behavior when using polymorphism, thus violating the Liskov Substitution Principle (LSP).

//Invariant: Balance can never be neg

class BankAccount {
  protected:
    double balance;
  public:
    BankAccount(double b){
        if (b < 0) {
            throw invalid_argument("Initial balance cannot be negative");
        }
        balance = b;
    }

    virtual void withdraw(double amount) {
        if (balance - amount < 0) {
            throw runtime_error("insufficient funds");
        }
        balance -= amount;
    }
  };

class CheatAccount : public BankAccount {
  public:
    CheatAccount(double b) : BankAccount(b) {}

    void withdraw(double amount) override {
        // Allowing withdrawal even if it results in a negative balance
        balance -= amount;
        cout<< "CheatAccount: Withdrawn " << amount << ", new balance: " << balance << endl;
    }
};

int main() {
    try {
        BankAccount* account = new CheatAccount(100);
        account->withdraw(150); // This should not be allowed as it violates the invariant
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
  }

//History Constraint: A history constraint is a condition that must hold true based on the history of method calls on an object. It defines the valid sequence of operations and ensures that the object behaves correctly based on its past interactions. If a derived class violates the history constraint of its base class, it can lead to unexpected behavior when using polymorphism, thus violating the Liskov Substitution Principle (LSP).


class BankAccount {
  protected:
    double balance;
  public:
    BankAccount(double b){
        if (b < 0) {
            throw invalid_argument("Initial balance cannot be negative");
        }
        balance = b;
    }

    //History constraint: The withdraw method should always be allowed 

    virtual void withdraw(double amount) {
        if (balance - amount < 0) {
            throw runtime_error("insufficient funds");
        }
        balance -= amount;
    }
  };

class FixedDepositAccount : public BankAccount {
  public:
    FixedDepositAccount(double b) : BankAccount(b) {}

    //LSP Violation

    void withdraw(double amount) override {
        throw runtime_error("Withdrawals are not allowed from a fixed deposit account");
    }
};

int main() {
    try {
        BankAccount* account = new FixedDepositAccount(100);
        account->withdraw(150);
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
  }

