#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string name;

public:
    explicit Animal(const string& animalName) : name(animalName) {}
    virtual void makeSound() const {
        cout << name << " makes a sound.\n";
    }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    explicit Dog(const string& dogName) : Animal(dogName) {}
    void makeSound() const override {
        cout << name << " says: Woof!\n";
    }
};

class Cat : public Animal {
public:
    explicit Cat(const string& catName) : Animal(catName) {}
    void makeSound() const override {
        cout << name << " says: Meow!\n";
    }
};

int main() {
    Dog dog("Mugarura's dog");
    Cat cat("Mugarura's cat");

    // Both calls use an Animal pointer, but the object's type selects the
    // overridden function at runtime.
    Animal* animals[] = {&dog, &cat};
    for (Animal* animal : animals) {
        animal->makeSound();
    }

    return 0;
}