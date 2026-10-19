#include <iostream>
using namespace std;


class Animal // base class
{
private:
    bool isAlive;
public:
    Animal(bool isAlive): isAlive(isAlive)  {}
    void isLive(){
        cout << "The animal is exists: " <<boolalpha<<isAlive<<endl;
    }// creates function that shows that the animal is alive
};
class Mammal : public Animal
{
private:
    bool hasHair;
public:
    Mammal(bool isAlive,bool hasHair) : Animal(isAlive), hasHair(hasHair) {}
    void MammalStatus(){
        cout << "Mammals has hair: " <<boolalpha<< hasHair<<endl;
    }  
};// create mammal class inheriting from Animal class
class Person : public Mammal
{
private:
    string name;
public:
    Person(bool isAlive,bool hasHair , string name) : Mammal(isAlive,hasHair), name(name){}
    void existPerson(){
        cout << "This persons name is: " << name<<endl;
    }// this function returns a persons name

};// create person class inheriting from mammal class

int main(){
    Person mugarura(true,true,"Allan");
    mugarura.isLive();
    mugarura.MammalStatus();
    mugarura.existPerson();
    return 0;
}