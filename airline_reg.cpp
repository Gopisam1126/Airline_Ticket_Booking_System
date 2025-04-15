#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

class Passenger {
public:
    string name;
    int age;
    string gender;
    string flight;
    string seat;

    Passenger(const string &name, int age, const string &gender, const string &flight, const string &seat) : name(name), age(age), gender(gender), flight(flight), seat(seat) {}
};

class AirlineRegistrationSystem {

    private:
        vector<Passenger> bookings;

    public:
        void bookTicket() {
            string name, gender, flight, seat;
            int age;
            cout << "\n--- Ticket Booking ---" << endl;
            cout << "Enter Passenger Name: ";
            getline(cin, name);
            cout << "Enter Age: ";
            cin >> age;
            cin.ignore();
            cout << "Enter Gender (M/F): ";
            getline(cin, gender);
            cout << "Enter Flight Number: ";
            getline(cin, flight);
            cout << "Enter Seat Number (e.g., 12A): ";
            getline(cin, seat);

            
            bookings.emplace_back(name, age, gender, flight, seat);
            cout << "\nTicket booked successfully!\n" << endl;
        }

        void cancelTicket() {
            if(bookings.empty()){
                cout << "\nNo bookings available to cancel!" << endl;
                return;
            }
            string seat;
            cout << "\nEnter Seat Number to cancel booking: ";
            getline(cin, seat);
            bool found = false;
            for(auto it = bookings.begin(); it != bookings.end(); ++it){
                if(it->seat == seat){
                    cout << "Cancelling booking for passenger: " << it->name << endl;
                    bookings.erase(it);
                    found = true;
                    break;
                }
            }
            if(!found)
                cout << "No booking found with seat number: " << seat << "\n" << endl;
        }

        void displayAllBookings() {
            if(bookings.empty()){
                cout << "\nNo bookings available." << endl;
                return;
            }
            cout << "\n--- All Bookings ---" << endl;
            cout << left << setw(20) << "Name"
                << setw(5)  << "Age"
                << setw(10) << "Gender"
                << setw(15) << "Flight"
                << setw(10) << "Seat" << endl;
            cout << string(60, '-') << endl;
            for(const auto &p : bookings){
                cout << left << setw(20) << p.name 
                    << setw(5)  << p.age 
                    << setw(10) << p.gender 
                    << setw(15) << p.flight 
                    << setw(10) << p.seat << endl;
            }
            cout << endl;
        }

        void searchBooking() {
            if(bookings.empty()){
                cout << "\nNo bookings available." << endl;
                return;
            }
            string name;
            cout << "\nEnter Passenger Name to search: ";
            getline(cin, name);
            bool found = false;
            for(const auto &p : bookings){
                if(p.name == name){
                    cout << "\nBooking details for " << name << ":" << endl;
                    cout << "Age: "    << p.age 
                        << ", Gender: " << p.gender 
                        << ", Flight: " << p.flight 
                        << ", Seat: "   << p.seat << endl;
                    found = true;
                }
            }
            if(!found)
                cout << "No booking found for " << name << "\n" << endl;
        }

        void modifyBooking() {
            if(bookings.empty()){
                cout << "\nNo bookings available to modify." << endl;
                return;
            }
            string seat;
            cout << "\nEnter Seat Number for the booking to modify: ";
            getline(cin, seat);
            bool found = false;
            for(auto &p : bookings) {
                if(p.seat == seat) {
                    found = true;
                    cout << "\nCurrent Booking Details:" << endl;
                    cout << "Name: "   << p.name << "\nAge: " << p.age 
                        << "\nGender: " << p.gender << "\nFlight: " << p.flight 
                        << "\nSeat: "   << p.seat << "\n" << endl;
                    
                    cout << "Enter new Passenger Name (or press enter to keep unchanged): ";
                    string newName;
                    getline(cin, newName);
                    if(!newName.empty())
                        p.name = newName;
                    
                    cout << "Enter new Age (or 0 to keep unchanged): ";
                    int newAge;
                    cin >> newAge;
                    cin.ignore();
                    if(newAge > 0)
                        p.age = newAge;
                    
                    cout << "Enter new Gender (or press enter to keep unchanged): ";
                    string newGender;
                    getline(cin, newGender);
                    if(!newGender.empty())
                        p.gender = newGender;
                    
                    cout << "Enter new Flight Number (or press enter to keep unchanged): ";
                    string newFlight;
                    getline(cin, newFlight);
                    if(!newFlight.empty())
                        p.flight = newFlight;
                    
                    cout << "Enter new Seat Number (or press enter to keep unchanged): ";
                    string newSeat;
                    getline(cin, newSeat);
                    if(!newSeat.empty())
                        p.seat = newSeat;
                    
                    cout << "\nBooking modified successfully!\n" << endl;
                    break;
                }
            }
            if(!found)
                cout << "No booking found with seat number: " << seat << "\n" << endl;
        }
};

void showMenu() {
    cout << "\n*** Airline Registration System Menu ***" << endl;
    cout << "1. Book Ticket" << endl;
    cout << "2. Cancel Ticket" << endl;
    cout << "3. Display All Bookings" << endl;
    cout << "4. Search Booking" << endl;
    cout << "5. Modify Booking" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    AirlineRegistrationSystem ars;
    int choice;
    while (true) {
        showMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                ars.bookTicket();
                break;
            case 2:
                ars.cancelTicket();
                break;
            case 3:
                ars.displayAllBookings();
                break;
            case 4:
                ars.searchBooking();
                break;
            case 5:
                ars.modifyBooking();
                break;
            case 6:
                cout << "\nExiting the system. Goodbye!\n" << endl;
                return 0;
            default:
                cout << "\nInvalid choice. Please try again.\n" << endl;
                break;
        }
    }
    return 0;
}
