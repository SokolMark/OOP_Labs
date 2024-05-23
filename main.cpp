#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Show {
    char name[100];
    char theater[100];
    char date[20];
    double ticketPrice;
};

// Function to add a show
void AddShow(vector<Show>& shows) {
    Show newShow;
    cout << "Enter show name: ";
    cin.ignore();
    cin.getline(newShow.name, 100);
    cout << "Enter theater name: ";
    cin.getline(newShow.theater, 100);
    cout << "Enter show date: ";
    cin.getline(newShow.date, 20);
    cout << "Enter ticket price: ";
    cin >> newShow.ticketPrice;
    shows.push_back(newShow);

    ofstream logFile("log.txt", ios::app);
    logFile << "Added show: " << newShow.name << endl;
    cout << "Show added successfully." << endl;
}

// Function to delete a show
void DeleteShow(vector<Show>& shows, const char* name) {
    auto it = remove_if(shows.begin(), shows.end(), [name](Show& show) {
        return strcmp(show.name, name) == 0;
        });

    if (it != shows.end()) {
        shows.erase(it, shows.end());
        ofstream logFile("log.txt", ios::app);
        logFile << "Deleted show: " << name << endl;
        cout << "Show with name " << name << " deleted successfully." << endl;
    }
    else {
        cout << "Show with name " << name << " not found." << endl;
    }
}

// Function to edit a show
void EditShow(vector<Show>& shows, const char* name) {
    for (auto& show : shows) {
        if (strcmp(show.name, name) == 0) {
            cout << "Enter new theater name: ";
            cin.ignore();
            cin.getline(show.theater, 100);
            cout << "Enter new show date: ";
            cin.getline(show.date, 20);
            cout << "Enter new ticket price: ";
            cin >> show.ticketPrice;

            ofstream logFile("log.txt", ios::app);
            logFile << "Edited show: " << name << endl;
            cout << "Show with name " << name << " edited successfully." << endl;
            return;
        }
    }
    cout << "Show with name " << name << " not found." << endl;
}

// Function to sort shows by name
void SortShows(vector<Show>& shows) {
    sort(shows.begin(), shows.end(), [](const Show& a, const Show& b) {
        return strcmp(a.name, b.name) < 0;
        });

    ofstream logFile("log.txt", ios::app);
    logFile << "Sorted shows by name." << endl;
    cout << "Shows sorted successfully." << endl;
}

// Function to display all shows
void ShowShows(const vector<Show>& shows) {
    cout << "List of shows:" << endl;
    for (const auto& show : shows) {
        cout << "Name: " << show.name << ", Theater: " << show.theater
            << ", Date: " << show.date << ", Ticket Price: " << show.ticketPrice << endl;
    }
}

// Function to write data to file
void WriteToFile(const vector<Show>& shows) {
    ofstream outFile("shows.bin", ios::binary);
    size_t size = shows.size();
    outFile.write((char*)&size, sizeof(size));
    outFile.write((char*)shows.data(), size * sizeof(Show));
}

// Function to read data from file
void ReadFromFile(vector<Show>& shows) {
    ifstream inFile("shows.bin", ios::binary);
    if (inFile.is_open()) {
        size_t size;
        inFile.read((char*)&size, sizeof(size));
        if (size > shows.max_size()) {
            cerr << "Error: size exceeds maximum limit." << endl;
            return;
        }
        shows.resize(size);
        inFile.read((char*)shows.data(), size * sizeof(Show));
    }
    else {
        cerr << "Error: cannot open file." << endl;
    }
}

int main() {
    vector<Show> shows;
    ReadFromFile(shows);
    int choice;

    do {
        cout << "Menu:\n1) Add show\n2) Delete show\n3) Edit show\n4) Sort shows\n5) Show all shows\n6) Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            AddShow(shows);
            break;
        case 2: {
            char name[100];
            cout << "Enter show name to delete: ";
            cin.ignore();
            cin.getline(name, 100);
            DeleteShow(shows, name);
            break;
        }
        case 3: {
            char name[100];
            cout << "Enter show name to edit: ";
            cin.ignore();
            cin.getline(name, 100);
            EditShow(shows, name);
            break;
        }
        case 4:
            SortShows(shows);
            break;
        case 5:
            ShowShows(shows);
            break;
        case 6:
            WriteToFile(shows);
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}
