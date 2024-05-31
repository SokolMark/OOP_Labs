#include <iostream>
#include <cmath>
#include <vector>
#include <memory>

using namespace std;

class Vector {
protected:
    vector<double> coordinates;
public:
    Vector(const vector<double>& coords) : coordinates(coords) {}
    virtual ~Vector() = default;

    virtual double module() const = 0;

    const vector<double>& getCoordinates() const {
        return coordinates;
    }
};

class Vector2D : public Vector {
public:
    Vector2D(double x, double y) : Vector({ x, y }) {}

    double module() const override {
        return sqrt(coordinates[0] * coordinates[0] + coordinates[1] * coordinates[1]);
    }
};

class Vector3D : public Vector {
public:
    Vector3D(double x, double y, double z) : Vector({ x, y, z }) {}

    double module() const override {
        return sqrt(coordinates[0] * coordinates[0] +
            coordinates[1] * coordinates[1] +
            coordinates[2] * coordinates[2]);
    }
};

void printVectorDetails(const Vector& vector) {
    const auto& coords = vector.getCoordinates();
    cout << "Coordinates: ";
    for (double coord : coords) {
        cout << coord << " ";
    }
    cout << "\nModule: " << vector.module() << endl;
}

int main() {
    unique_ptr<Vector> vec2D = make_unique<Vector2D>(3.0, 4.0);
    unique_ptr<Vector> vec3D = make_unique<Vector3D>(1.0, 2.0, 2.0);

    cout << "Vector2D details:" << endl;
    printVectorDetails(*vec2D);

    cout << "\nVector3D details:" << endl;
    printVectorDetails(*vec3D);

    return 0;
}
