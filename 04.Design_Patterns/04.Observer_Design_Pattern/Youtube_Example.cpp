#include<bits/stdc++.h>
using namespace std;


class ISubscriber {
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {}
};

//Abstract Observable interface: A youtube channel

class IChannel{
public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel() {}
};

//Concrete Observable class: A specific youtube channel

class Channel : public IChannel {
private:
    vector<ISubscriber*> subscribers;
    string channelName;
    string latestVideo;
  public:
    Channel(const string& name) : channelName(name) {}

    void subscribe(ISubscriber* subscriber) override {
      if(find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end())
        subscribers.push_back(subscriber);
    }

    void unsubscribe(ISubscriber* subscriber) override {
        subscribers.erase(remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
    }

    void notifySubscribers() override {
        for (auto subscriber : subscribers) {
            subscriber->update();
        }
    }

    void uploadVideo(const string& videoTitle) {
        latestVideo = videoTitle;
        cout << "Channel " << channelName << " uploaded a new video: " << latestVideo << endl;
        notifySubscribers();
    }

    string getLatestVideo() const {
        return latestVideo;
    }
};


class Subscriber : public ISubscriber {
private:
    string name;
    Channel* channel;
public:
   Subscriber(const string& name, Channel* channel) : name(name), channel(channel) {
        channel->subscribe(this);
    }

    void update() override {
        cout << "Subscriber " << name << " received notification: New video uploaded on channel " 
             << channel->getLatestVideo() << endl;
    }

    ~Subscriber() {
        channel->unsubscribe(this);
    }

};


int main() {
    Channel* techChannel = new Channel("Tech Guru");
    Subscriber* alice = new Subscriber("Alice", techChannel);
    Subscriber* bob = new Subscriber("Bob", techChannel);

    techChannel->uploadVideo("C++ Observer Pattern Tutorial");
    techChannel->uploadVideo("Understanding Design Patterns in C++");

    delete alice;
    delete bob;
    delete techChannel;

    return 0;
}
