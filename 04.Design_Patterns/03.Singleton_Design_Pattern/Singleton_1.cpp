#include<bits/stdc++.h>
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton(){
      cout << "Constructor called" << endl;
    }
public:
    static Singleton* getInstance() {
        return instance;
    }
};

Singleton* Singleton::instance = new Singleton();

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    cout << (s1 == s2) << endl;
    return 0;
}
