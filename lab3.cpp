#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846 

using namespace std;

class Sphere {
private:
    double radius;

public:
    // Default constructor
    Sphere() {
        cout << "Default constructor called" << endl;
        radius = 0.0;
    }

    // Parameterized constructor
    Sphere(double r) {
        cout << "Parameterized constructor called" << endl;
        radius = r;
    }

    // Copy constructor
    Sphere(const Sphere& other) {
        cout << "Copy constructor called" << endl;
        radius = other.radius;
    }

    // Delegating constructor
    Sphere(double r, bool isInitialized) : Sphere(r) {}

    // Destructor
    ~Sphere() {
        cout << "Destructor called" << endl;
    }

    // Method to calculate volume
    double volume() {
        return (4.0 / 3.0) * M_PI * pow(radius, 3);
    }

    // Method to calculate surface area
    double surfaceArea() {
        return 4.0 * M_PI * pow(radius, 2);
    }

    // Method to get radius
    double getRadius() {
        return radius;
    }

    // Method to set radius
    void setRadius(double r) {
        radius = r;
    }
};

int main() {
    // Creating instances of the Sphere class
    Sphere sphere1;
    cout << "Radius of sphere1: " << sphere1.getRadius() << endl;

    Sphere sphere2(3.0);
    cout << "Radius of sphere2: " << sphere2.getRadius() << endl;

    Sphere sphere3(5.0, true);
    cout << "Radius of sphere3: " << sphere3.getRadius() << endl;

    Sphere sphere4 = sphere2;
    cout << "Radius of sphere4: " << sphere4.getRadius() << endl;

    // Interaction with class methods
    cout << "Volume of sphere2: " << sphere2.volume() << endl;
    cout << "Surface area of sphere2: " << sphere2.surfaceArea() << endl;

    // Working with an array of class instances
    const int numSpheres = 3;
    Sphere sphereArray[numSpheres] = { Sphere(2.0), Sphere(4.0), Sphere(6.0) };
    for (int i = 0; i < numSpheres; ++i) {
        cout << "Volume of sphere" << i + 1 << ": " << sphereArray[i].volume() << endl;
        cout << "Surface area of sphere" << i + 1 << ": " << sphereArray[i].surfaceArea() << endl;
    }

    return 0;
}
