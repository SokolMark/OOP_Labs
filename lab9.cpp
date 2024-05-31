#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

class VectorException : public runtime_error {
public:
    explicit VectorException(const string& message) : runtime_error(message) {}
};

class IndexOutOfRangeException : public VectorException {
public:
    explicit IndexOutOfRangeException(int index)
        : VectorException("Index " + std::to_string(index) + " is out of range.") {}
};

class Vector {
private:
    vector<int> elements;
public:
    Vector() = default;
    Vector(initializer_list<int> init) : elements(init) {}

    // Overloading the index access operator
    int& operator[](int index) {
        if (index < 0 || static_cast<size_t>(index) >= elements.size()) {
            throw IndexOutOfRangeException(index);
        }
        return elements[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || static_cast<size_t>(index) >= elements.size()) {
            throw IndexOutOfRangeException(index);
        }
        return elements[index];
    }

    // Overloading the size determination operator
    int operator()() const {
        return static_cast<int>(elements.size());
    }

    // Overloading the % operator to find the remainder of division by a number for all elements
    Vector operator%(int divisor) const {
        if (divisor == 0) {
            throw VectorException("Division by zero is not allowed.");
        }
        Vector result;
        for (int elem : elements) {
            result.elements.push_back(elem % divisor);
        }
        return result;
    }

    // Overloading the + N operator to move to the right to the element with number n
    int operator+(int n) const {
        if (n < 0 || static_cast<size_t>(n) >= elements.size()) {
            throw IndexOutOfRangeException(n);
        }
        return elements[n];
    }

    // Method to add elements
    void push_back(int value) {
        elements.push_back(value);
    }

    // Method to print vector elements
    void print() const {
        for (int elem : elements) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        Vector v = { 1, 2, 3, 4, 5 };
        cout << "Vector elements: ";
        v.print();

        cout << "Accessing element at index 2: " << v[2] << endl;
        cout << "Size of vector: " << v() << endl;

        Vector modVector = v % 3;
        cout << "Vector after modulo 3: ";
        modVector.print();

        cout << "Element at position 3 using + operator: " << (v + 3) << endl;

        // Generating exceptions
        // cout << "Accessing element at index 10: " << v[10] << endl;
        // Vector modZero = v % 0;

    }
    catch (const VectorException& ex) {
        cerr << "Vector error: " << ex.what() << endl;
    }
    catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }

    return 0;
}

