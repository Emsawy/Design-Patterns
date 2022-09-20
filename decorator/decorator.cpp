#include<iostream>
#include<string>

class Component {
public:
    virtual ~Component(){}
    virtual std::string Operation() const  = 0;
};

class ConcreteComponent : public Component{
    std::string Operation() const override {
        return "ConcereteComponent";
    }
};

class Decorator : public Component {
protected:
    Component* component_;

public:
    Decorator(Component* component) : component_(component){}
    std::string Operation() const override {
        return this->component_->Operation();
    }
};

class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component): Decorator(component) {}
    std::string Operation() const override {
        return "ConcreteComponentA(" + Decorator::Operation() + ")";
    } 
};
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component): Decorator(component) {}
    std::string Operation() const override {
        return "ConcreteComponentB(" + Decorator::Operation() + ")";
    } 
};

void ClientCode(Component* component) {
  std::cout << "RESULT: " << component->Operation();
}

int main() {
    Component* simple = new ConcreteComponent;
    std::cout << "Client: I've got a simple component:\n";
    ClientCode(simple);
    std::cout << "\n\n";

    simple = new ConcreteDecoratorA(simple);
    simple = new ConcreteDecoratorB(simple);

     std::cout << "Client: Now I've got a decorated component:\n";
    ClientCode(simple);
    std::cout << "\n";

    delete simple;
}