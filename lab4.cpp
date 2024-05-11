#include <iostream>
using namespace std;

class Time {
public:
    int hours;
    int minutes;
public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    Time operator+(const Time& t) const {
        int h = hours + t.hours;
        int m = minutes + t.minutes;
        if (m >= 60) {
            h++;
            m -= 60;
        }
        return Time(h, m);
    }

    bool operator>(const Time& t) const {
        if (hours > t.hours)
            return true;
        else if (hours == t.hours && minutes > t.minutes)
            return true;
        return false;
    }

    bool operator==(const Time& t) const {
        return (hours == t.hours && minutes == t.minutes);
    }

    void display() const {
        std::cout << hours << " hours and " << minutes << " minutes";
    }
    Time& operator++() {
        ++minutes;
        if (minutes >= 60) {
            ++hours;
            minutes -= 60;
        }
        return *this;
    }
};

Time operator++(Time& t, int) {
    Time temp = t;
    ++t.minutes;
    if (t.minutes >= 60) {
        ++t.hours;
        t.minutes -= 60;
    }
    return temp;
}

int main() {
    Time t1(2, 45);
    Time t2(1, 30);

    Time sum = t1 + t2;
    cout << "Sum of times: ";
    sum.display();
    cout << endl;

    if (t1 > t2)
        cout << "t1 is greater than t2" << endl;
    else
        cout << "t2 is greater than t1" << endl;

    ++t1;
    cout << "Incremented t1: ";
    t1.display();
    cout << endl;

    if (t1 == t2)
        cout << "t1 is equal to t2" << endl;
    else
        cout << "t1 is not equal to t2" << endl;

    return 0;
}