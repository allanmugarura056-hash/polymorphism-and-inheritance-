#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle(const string& vehicleBrand, int vehicleYear)
        : brand(vehicleBrand), year(vehicleYear) {}

    void showVehicle() const {
        cout << "Brand: " << brand << "\nYear: " << year << '\n';
    }
};

class Car : public Vehicle {
protected:
    int numberOfDoors;

public:
    Car(const string& carBrand, int carYear, int doors)
        : Vehicle(carBrand, carYear), numberOfDoors(doors) {}

    void showCar() const {
        showVehicle(); // Inherited from Vehicle
        cout << "Doors: " << numberOfDoors << '\n';
    }
};

class ElectricCar : public Car {
private:
    int batteryCapacityKWh;

public:
    ElectricCar(const string& carBrand, int carYear, int doors, int capacity)
        : Car(carBrand, carYear, doors), batteryCapacityKWh(capacity) {}

    void showDetails() const {
        showCar(); // Uses members inherited through Car and Vehicle
        cout << "Battery capacity: " << batteryCapacityKWh << " kWh\n";
    }

    void charge() const { 
        cout << brand << " is charging.\n";
    }
};

int main() {
    ElectricCar myCar("Mugarura", 2026, 4, 60);

    cout << "Electric car details\n";
    myCar.showDetails();
    myCar.charge();
    return 0;
}
