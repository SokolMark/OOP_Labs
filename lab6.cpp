#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

using namespace std;

class Logger {
private:
    vector < string> log;

public:
    void addRecord(const string& record) {
        log.push_back(record);
    }

    void saveLog() {
        ofstream file("log.txt");
        if (file.is_open()) {
            // Write class name and number of entities
            file << "ClassName: Book\n";
            file << "time: " << currentDateTime() << "\n";
            for (const auto& record : log) {
                file << record << "\n";
            }
            file.close();
            cout << "Log saved successfully.\n";
        }
        else {
            cerr << "Unable to open log file.\n";
        }
    }

    string currentDateTime() const {
        time_t now = time(0);
        struct tm timeinfo;
        localtime_s(&timeinfo, &now);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y.%m.%d %H:%M:%S", &timeinfo);
        return buffer;
    }
};

class Book {
private:
    static int numInstances;
    string name;

public:
    Book(const string& name) : name(name) {
        numInstances++;
    }

    ~Book() {
        numInstances--;
    }

    static int getNumInstances() {
        return numInstances;
    }

    string getName() const {
        return name;
    }
};

int Book::numInstances = 0;

int main() {
    Logger logger;

    Book book1("Book1");
    logger.addRecord("object1Name: " + book1.getName());
    logger.addRecord("object1Field1: field1 Value");
    logger.addRecord("object1Field2: field2 Value");

    Book book2("Book2");
    logger.addRecord("object2Name: " + book2.getName());
    logger.addRecord("object2Field1: field1 Value");
    logger.addRecord("object2Field2: field2 Value");

    logger.saveLog();

    return 0;
}
