#include<bits/stdc++.h>
using namespace std;

class MySQlDatabase {
  public:
    void saveToMySQL(string data) {
        cout << "Saving data to MySQL database: " << data << endl;
    }
};

class MongoDB {
  public:
    void saveToMongoDB(string data) {
        cout << "Saving data to MongoDB database: " << data << endl;
    }
};

class UserService{
private:
  MySQlDatabase mysql; //Direct dependency on MySQL database, violates the Dependency Inversion Principle
  MongoDB mongo; //Direct dependency on MongoDB database, violates the Dependency Inversion Principle

public:
  void storetoSQL(string data) {
    mysql.saveToMySQL(data);
  }

  void storetoMongoDB(string data) {
    mongo.saveToMongoDB(data);
  }
};


int main() {
    UserService userService;
    userService.storetoSQL("User data for MySQL");
    userService.storetoMongoDB("User data for MongoDB");

    return 0;
}



