#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_SHOWS = 100;

struct Show {
    char name[100];
    char theater[100];
    char date[20];
    double ticketPrice;
};

// Function to add a show
void AddShow(Show shows[], int& numShows) {
    if (numShows < MAX_SHOWS) {
        cout << "Enter show name: ";
        cin >> shows[numShows].name;
        cout << "Enter theater name: ";
        cin >> shows[numShows].theater;
        cout << "Enter show date: ";
        cin >> shows[numShows].date;
        cout << "Enter ticket price: ";
        cin >> shows[numShows].ticketPrice;
        cout << "Show added successfully." << endl;
        numShows++;

        ofstream logFile("log.txt", ios::app);
        if (logFile.is_open()) {
            logFile << "Added show: " << shows[numShows - 1].name << endl;
            logFile.close();
        }
    }
    else {
        cout << "Maximum number of shows reached" << endl;
    }
}

// Function to delete a show
void DeleteShow(Show shows[], int& numShows, const char* name) {
    for (int i = 0; i < numShows; ++i) {
        if (strcmp(shows[i].name, name) == 0) {
            for (int j = i; j < numShows - 1; ++j) {
                shows[j] = shows[j + 1];
            }
            numShows--;

            // Log the operation
            ofstream logFile("log.txt", ios::app);
            if (logFile.is_open()) {
                logFile << "Deleted show: " << name << endl;
                logFile.close();
            }

            cout << "Show with name " << name << " deleted successfully" << endl;
            return;
        }
    }
    cout << "Show with name " << name << " not found" << endl;
}

// Function to display all shows
void ShowShows(Show shows[], int numShows) {
    cout << "List of shows:" << endl;
    for (int i = 0; i < numShows; ++i) {
        cout << "Name: " << shows[i].name << ", Theater: " << shows[i].theater
            << ", Date: " << shows[i].date << ", Ticket Price: " << shows[i].ticketPrice << endl;
    }
}

int main() {
    Show shows[MAX_SHOWS];
    int numShows = 0;

    while (true) {
        cout << "Menu: " << endl;
        cout << "1) Add show" << endl;
        cout << "2) Delete show" << endl;
        cout << "3) Show all shows" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            AddShow(shows, numShows);
            break;
        }
        case 2: {
            char name[100];
            cout << "Enter show name to delete: ";
            cin >> name;
            DeleteShow(shows, numShows, name);
            break;
        }
        case 3: {
            ShowShows(shows, numShows);
            break;
        }
        case 4: {
            cout << "Exiting program" << endl;
            return 0;
        }
        default: {
            cout << "Invalid choice. Please try again" << endl;
            break;
        }
        }
    }
    return 0;
}