/*
The Observer Pattern: define a one-to-many
    dependency between objects so that when one
    object changes state, all of its dependents are
    notified and updated automatically.
*/

/*
Category: Behavioral Pattern
*/

#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

/****************** Interfaces *********************/

class IObserver {
public:
    virtual ~IObserver(){};
    virtual void update(string message) = 0;
};

class ISubject {
public:    
    virtual ~ISubject(){};
    virtual void registerObserver(IObserver*) = 0;
    virtual void removeObserver(IObserver*) = 0;
    virtual void notifyObserver() = 0;
};


/****************** Concrete classes *********************/

class WeatherData : public ISubject {
private:
    unordered_set<IObserver *> observers;
    string message;
public:
    ~WeatherData() override {
        std::cout << "Goodbye, I was the Subject.\n";
    }
    
    void registerObserver(IObserver* observer) override {
        observers.insert(observer);
    }
    void removeObserver(IObserver* observer) override {
        observers.erase(observer);
    }
    void notifyObserver() override {
        unordered_set<IObserver *>::iterator beg = observers.begin();
        while(beg != observers.end()) {
            (*beg)->update(message);
            ++beg;
        }
    }
    void makeSomeBusinessLogic() {
        message = "test observer pattern";
        notifyObserver();
    }
};

class Observer: public IObserver {
public: 
    string _name;
    string _message;
    ISubject* _subject;
public:
    Observer(ISubject* subject, string name): _subject(subject), _name(name) {
        subject->registerObserver(this);
    }

    void update(string message) override {
        _message = message; 
        cout << _name << ":message updated -> " << _message << endl;
    }
};

int main() {
    
    WeatherData subject;
    
    Observer observer1(&subject, "o1");
    Observer observer2(&subject, "o2");

    subject.makeSomeBusinessLogic();
    


    return 0;
}