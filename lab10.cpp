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

template <typename T>
class Vector {
private:
    vector<T> elements;
public:
    Vector() = default;
    Vector(initializer_list<T> init) : elements(init) {}

    // Overloading the index access operator
    T& operator[](int index) {
        if (index < 0 || static_cast<size_t>(index) >= elements.size()) {
            throw IndexOutOfRangeException(index);
        }
        return elements[index];
    }

    const T& operator[](int index) const {
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
    Vector<T> operator%(T divisor) const {
        if (divisor == 0) {
            throw VectorException("Division by zero is not allowed.");
        }
        Vector<T> result;
        for (const T& elem : elements) {
            result.elements.push_back(elem % divisor);
        }
        return result;
    }

    // Overloading the + N operator to move to the right to the element with number n
    T operator+(int n) const {
        if (n < 0 || static_cast<size_t>(n) >= elements.size()) {
            throw IndexOutOfRangeException(n);
        }
        return elements[n];
    }

    // Method to add elements
    void push_back(T value) {
        elements.push_back(value);
    }

    // Method to print vector elements
    void print() const {
        for (const T& elem : elements) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        // Test with int
        Vector<int> v = { 1, 2, 3, 4, 5 };
        cout << "Vector<int> elements: ";
        v.print();

        cout << "Accessing element at index 2: " << v[2] << endl;
        cout << "Size of vector<int>: " << v() << endl;

        Vector<int> modVector = v % 3;
        cout << "Vector<int> after modulo 3: ";
        modVector.print();

        cout << "Element at position 3 in Vector<int> using + operator: " << (v + 3) << endl;

        // Test with double
        Vector<double> vD = { 1.1, 2.2, 3.3, 4.4, 5.5 };
        cout << "\nVector<double> elements: ";
        vD.print();

        cout << "Accessing element at index 2: " << vD[2] << endl;
        cout << "Size of vector<double>: " << vD() << endl;

        // Note: The modulo operator does not make sense for floating point types,
        // so this part of the example is omitted for Vector<double>.

        cout << "Element at position 3 in Vector<double> using + operator: " << (vD + 3) << endl;

        // Generating exceptions
        // cout << "Accessing element at index 10 in Vector<int>: " << v[10] << endl;
        // Vector<int> modZero = v % 0;

    }
    catch (const VectorException& ex) {
        cerr << "Vector error: " << ex.what() << endl;
    }
    catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }

    return 0;
}

