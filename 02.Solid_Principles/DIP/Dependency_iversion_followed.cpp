#include<bits/stdc++.h>
using namespace std;

class Database {
  public:
    virtual void save(string data) = 0; // Abstract method to save data
};

class MySQlDatabase : public Database {
  public:
    void save(string data) override {
        cout << "Saving data to MySQL database: " << data << endl;
    }
};


class MongoDB : public Database {
  public:
    void save(string data) override {
        cout << "Saving data to MongoDB database: " << data << endl;
    }
};

class UserService{
  private:
    Database* database; // Dependency Injection: UserService depends on the abstract Database class, not on concrete implementations
  public:
    UserService(Database* db) : database(db) {} // Constructor injection

    void store(string data) {
        database->save(data); // Use the abstract method to save data
    } 
  };

  int main() {
    MySQlDatabase mysql;
    MongoDB mongo;

    UserService userService1(&mysql); // Inject MySQL database dependency
    userService1.store("User data for MySQL");

    UserService userService2(&mongo); // Inject MongoDB database dependency
    userService2.store("User data for MongoDB");

    return 0; 
}