#include <iostream>
#include <cmath>

using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:
    // Constructor
    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Getters and setters
    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double x_val) { x = x_val; }
    void setY(double y_val) { y = y_val; }

    // Methods for vector operations
    double magnitude() const {
        return sqrt(x * x + y * y);
    }

    Vector2D add(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D subtract(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    double dotProduct(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    // Method for vector normalization
    Vector2D normalize() const {
        double mag = magnitude();
        if (mag != 0) {
            return Vector2D(x / mag, y / mag);
        }
        else {
            // Avoid division by zero if the vector is zero
            return Vector2D();
        }
    }

    // Operator overloading
    Vector2D operator+(const Vector2D& other) const {
        return add(other);
    }

    Vector2D operator-(const Vector2D& other) const {
        return subtract(other);
    }

    double operator*(const Vector2D& other) const {
        return dotProduct(other);
    }

    // Method for vector output
    friend ostream& operator<<(ostream& os, const Vector2D& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

int main() {
    // Example usage of the Vector2D class
    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.0, 2.0);

    cout << "Vector v1: " << v1 << endl;
    cout << "Vector v2: " << v2 << endl;

    // Examples of calling methods and operations with vectors
    cout << "Magnitude of v1: " << v1.magnitude() << endl;
    cout << "Magnitude of v2: " << v2.magnitude() << endl;

    Vector2D v3 = v1 + v2;
    cout << "v1 + v2 = " << v3 << endl;

    Vector2D v4 = v1 - v2;
    cout << "v1 - v2 = " << v4 << endl;

    double dot = v1 * v2;
    cout << "Dot product of v1 and v2: " << dot << endl;

    Vector2D normalized_v1 = v1.normalize();
    cout << "Normalized v1: " << normalized_v1 << endl;

    return 0;
}
