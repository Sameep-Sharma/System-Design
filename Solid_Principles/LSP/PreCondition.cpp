#include<bits/stdc++.h>
using namespace std;

// A Precondition must be satisfied before a method can be executed.
// Sub classes can weaken the precondition of the base class method, but they cannot strengthen it.

class User {
public:
    //Precondition: Password must be at least 8 characters long
    virtual void setPassword(string password) {
        if (password.length() < 8) {
            throw invalid_argument("Password must be at least 8 characters long");
        }
        // Set the password
        cout << "Password set successfully" << endl;
    } 
};

class AdminUser : public User {
  public:
    //Precondition: Password must be at least 6 characters long
    void setPassword(string password) override {
        if (password.length() < 6) {
            throw invalid_argument("Password must be at least 6 characters long");
        }
        // Set the password
        cout << "Admin password set successfully" << endl;
    }
};


int main() {
    User* user = new User();
    user->setPassword("password123"); // Valid password

    AdminUser* admin = new AdminUser();
    admin->setPassword("admin"); // Invalid password, will throw an exception

    delete user;
    delete admin;

    return 0;
}