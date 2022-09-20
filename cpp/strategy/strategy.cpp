/*
The Strategy Pattern: define a family of algorithms,
encapsulates each one, and makes them interchangeable.
Strategy lets the algorithm vary independently from
clients that use it.
*/

/*
Category: Behavioral Pattern
*/

#include<iostream>

using namespace std;

class FlyBehavior {
public:    
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior
{
public:
    void fly() {
        cout << "FlyWithWings!" << endl;
    }
};

class QuackBehavior {
public:
    virtual void quack() = 0;

};

class Quack : public QuackBehavior {
public:
    void quack() {
        cout << "Quack!" << endl;
    }
};


class Duck {

public:
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;

public:
    virtual void display() = 0;

    void swim() {
        cout << "I'm swimming" << endl;
    }

    void performQuack() {
        quackBehavior->quack();
    }

    void performFly() {
        flyBehavior->fly();
    }

    void setFlyBehavior(FlyBehavior* flyBehaviorInstance) {
        flyBehavior = flyBehaviorInstance;
    }

    void setQuackBehavior(QuackBehavior* quackBehaviorInstance) {
        quackBehavior = quackBehaviorInstance;
    }

};

class MallardDuck : public Duck {

public:

    MallardDuck() {
        flyBehavior = new FlyWithWings();
        quackBehavior = new Quack();
    }

    void display() {
        cout << "MallrdDuck!" << endl;
    }

    ~MallardDuck() {
        delete this->flyBehavior;
        delete this->quackBehavior;
    }

};

int main() {
    MallardDuck mallardDuck;
    
    return 0;
}