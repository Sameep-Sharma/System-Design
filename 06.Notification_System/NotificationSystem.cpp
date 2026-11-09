#include<bits/stdc++.h>
using namespace std;


/*
===================================
    Notification System
===================================
*/


class INotification {
public:
    virtual string  getContent() const = 0;
    virtual ~INotification() {}
};

//Concrete Component: simple text notification
class TextNotification : public INotification {
private:
    string content;
public:
    TextNotification(const string& content) : content(content) {}
    string getContent() const override {
        return content;
    }
};

//Abstract Decorator: maintains a reference to an INotification object and defines an interface that conforms to INotification's interface

class INotificationDecorator : public INotification {
protected:
    INotification* notification;
public:
    INotificationDecorator(INotification* n) : notification(n) {}
    virtual ~INotificationDecorator() { delete notification; }
};

//Decorators: extend the functionality of the component by adding new behaviors

class TimeStampDecorator : public INotificationDecorator {
  public:
    TimeStampDecorator(INotification* n) : INotificationDecorator(n) {}
    string getContent() const override  {
        time_t now = time(0);
        char* dt = ctime(&now);
        string timestamp(dt);
        timestamp.pop_back(); // Remove the newline character
        return "[" + timestamp + "] " + notification->getContent();
    }
};

class SignatureDecorator : public INotificationDecorator {
private:
    string signature;
public:
    SignatureDecorator(INotification* n, const string& sig) : INotificationDecorator(n), signature(sig) {}
    string getContent() const override {
        return notification->getContent() + "\n-- " + signature;
    }
};

/*============================
  Observer Pattern Components
=============================*/

class IObserver {
public:
    virtual void update(INotification* notification) = 0;
    virtual ~IObserver() {}
};

class ISubject {
  public:
    virtual void registerObserver(IObserver* observer) = 0;
    virtual void removeObserver(IObserver* observer) = 0;
    virtual void notifyObservers(INotification* notification) = 0;
    virtual ~ISubject() {}  
};


//Concrete Subject: Notification Service
class NotificationObservable : public ISubject {
private:
    vector<IObserver*> observers;
    INotification* notification;
public:
  NotificationObservable() : notification(nullptr) {}
    void registerObserver(IObserver* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(IObserver* observer) override {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers(INotification* notification) override {
        for (IObserver* observer : vector<IObserver*>(observers)) {
            observer->update(notification);
        } 
    }

    void setNotification(INotification* n) {
        notification = n;
        notifyObservers(notification);
    }

    INotification* getNotification() const {
        return notification;
    }
    string getNotificationContent() const {
        return notification ? notification->getContent() : "";
    }
    ~NotificationObservable() = default;
  };

  //Concrete Observer: logger that logs notifications

class LoggerObserver : public IObserver {
private:
    NotificationObservable* observable;
public:
    LoggerObserver(NotificationObservable* obs) : observable(obs) {
        observable->registerObserver(this);
    }

    void update(INotification* notification) override {
        cout << "Logger: New Notification - " << notification->getContent() << endl;
    }

    ~LoggerObserver() {
        observable->removeObserver(this);
    }
};

/*============================
  Strategy Pattern Components (Concrete Observer 2)
=============================*/

class INotificationStrategy {
  public:
    virtual void sendNotification(const string& content) = 0;
    virtual ~INotificationStrategy() {}
};

class EmailNotificationStrategy : public INotificationStrategy {
  public:
    void sendNotification(const string& content) override {
        cout << "Email sent with content: " << content << endl;
    }
};

class SMSNotificationStrategy : public INotificationStrategy {
  public:
    void sendNotification(const string& content) override {
        cout << "SMS sent with content: " << content << endl;
    }
};

class PushNotificationStrategy : public INotificationStrategy {
  public:
    void sendNotification(const string& content) override {
        cout << "Push notification sent with content: " << content << endl;
    }
};

class NotificationEngine : public IObserver {
private:
    NotificationObservable* notificationObservable;
    vector<INotificationStrategy*> notificationStrategies;

public:
   NotificationEngine(NotificationObservable* observable) {

    this->notificationObservable = observable;

    notificationObservable->registerObserver(this);
}

    void addNotificationStrategy(INotificationStrategy* ns) {
        this->notificationStrategies.push_back(ns);
    }

    // Can have RemoveNotificationStrategy as well.

   void update(INotification* notification) override {

    string notificationContent = notification->getContent();

    for (auto strategy : notificationStrategies) {
        strategy->sendNotification(notificationContent);
    }

  }

  ~NotificationEngine() {

    notificationObservable->removeObserver(this);

    for (auto strategy : notificationStrategies) {
        delete strategy;
    }
}
};

/*============================
      NotificationService
=============================*/

// The NotificationService manages notifications. It keeps track of notifications. 
// Any client code will interact with this service.

//Singleton NotificationService
class NotificationService {
private:
    NotificationObservable* notificationObservable;
    static NotificationService* instance;
    vector<INotification*> notifications;

    NotificationService() {
        notificationObservable = new NotificationObservable();
    }
    
public:
    static NotificationService* getInstance() {
    if (!instance) {
    instance = new NotificationService();
    }
        return instance;
    }
     // Expose the observable so observers can attach.
    NotificationObservable* getNotificationObservable() {
        return notificationObservable;
    }

    //Creates a new notification and notifies observers

    void sendNotification(INotification* notification) {
        notifications.push_back(notification);
        notificationObservable->setNotification(notification);
    }

    ~NotificationService() {
        delete notificationObservable;
        for (auto notification : notifications) {
            delete notification;
        }
    } 
};

NotificationService* NotificationService::instance = nullptr;

int main() {
    NotificationService* notificationService = NotificationService::getInstance();

    // Create observers
    LoggerObserver* logger = new LoggerObserver(notificationService->getNotificationObservable());
    NotificationEngine* engine = new NotificationEngine(notificationService->getNotificationObservable());

    // Add strategies to the engine
    engine->addNotificationStrategy(new EmailNotificationStrategy());
    engine->addNotificationStrategy(new SMSNotificationStrategy());
    engine->addNotificationStrategy(new PushNotificationStrategy());

    // Create a simple notification
    INotification* simpleNotification = new TextNotification("This is a simple notification.");
    notificationService->sendNotification(simpleNotification);

    // Create a decorated notification with timestamp and signature
    INotification* decoratedNotification = new SignatureDecorator(
        new TimeStampDecorator(
            new TextNotification("This is a decorated notification.")
        ),
        "Admin"
    );
    notificationService->sendNotification(decoratedNotification);

    // Clean up
    delete logger;
    delete engine;

    return 0;
}     

    