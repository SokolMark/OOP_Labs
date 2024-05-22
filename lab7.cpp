#include <iostream>
#include <string>

using namespace std;

class Liquid {
protected:
    string name;
    double density;

public:
    Liquid(const string& name, double density) : name(name), density(density) {}

    virtual ~Liquid() {}

    virtual void setName(const string& newName) {
        name = newName;
    }

    virtual void setDensity(double newDensity) {
        density = newDensity;
    }

    virtual string getName() const {
        return name;
    }

    virtual double getDensity() const {
        return density;
    }
};

class Milk : public Liquid {
private:
    double boilingPoint;

public:
    Milk(const string& name, double density, double boilingPoint)
        : Liquid(name, density), boilingPoint(boilingPoint) {}

    void setBoilingPoint(double newBoilingPoint) {
        boilingPoint = newBoilingPoint;
    }

    double getBoilingPoint() const {
        return boilingPoint;
    }
};

Liquid* createLiquid() {
    return new Liquid("Water", 1.0);
}

void printLiquidInfo(const Liquid& liquid) {
    cout << "Name: " << liquid.getName() << ", Density: " << liquid.getDensity() << endl;
}

int main() {
    // Creating an object of the Milk class
    Milk milk("Cow Milk", 1.03, 100.0);

    // Calling a function with passing an object of the Milk class where an object of the Liquid class is expected
    printLiquidInfo(milk);

    return 0;
}
