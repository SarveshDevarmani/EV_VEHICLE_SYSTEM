
#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "Customer.h"
#include "CustomerData.h"
#include "Vehicle.h"
#include "chargingStation.h"
#include "charger.h"
#include "Admin.h"
#include "Maintenance.h"
#include "Booking.h"

using namespace std;

bool vehicleBelongsToCustomer(
    const vector<Vehicle>& vehicles,
    int vehicleId,
    int customerId)
{
    for (const Vehicle& vehicle : vehicles)
    {
        if (vehicle.getVehicleId() == vehicleId &&
            vehicle.getOwnerCustomerId() == customerId)
        {
            return true;
        }
    }

    return false;
}

bool stationExists(const Admin& admin, int stationId)
{
    for (int i = 0; i < admin.getStationCount(); i++)
    {
        if (admin.getStation(i).getStationId() == stationId)
        {
            return true;
        }
    }

    return false;
}

bool slotAlreadyBooked(
    const vector<Booking>& bookings,
    int chargerId,
    const string& date,
    const string& time)
{
    for (const Booking& booking : bookings)
    {
        if (booking.getChargerId() == chargerId &&
            booking.getDate() == date &&
            booking.getTime() == time &&
            booking.getStatus() == "Booked")
        {
            return true;
        }
    }

    return false;
}

void showAvailableChargers(
    Admin& admin,
    const vector<Booking>& bookings,
    int stationId,
    const string& date,
    const string& time)
{
    bool found = false;

    for (int i = 0; i < admin.getChargerCount(); i++)
    {
        charger& ch = admin.getCharger(i);

        if (ch.getStationId() == stationId &&
            ch.checkAvailability() &&
            !slotAlreadyBooked(
                bookings, ch.getChargerId(), date, time))
        {
            ch.displayCharger();
            found = true;
        }
    }

    if (!found)
    {
        cout << "\nNo available chargers for this date and time.\n";
    }
}

void customerMenu(
    Customer& customer,
    Admin& admin,
    vector<Vehicle>& vehicles,
    vector<Booking>& bookings)
{
    int choice;

    do
    {
        cout << "\n========== CUSTOMER MENU ==========\n";
        cout << "1. Add Vehicle\n";
        cout << "2. View My Vehicles\n";
        cout << "3. Find Charging Stations\n";
        cout << "4. Check Charger Availability\n";
        cout << "5. Book Charger\n";
        cout << "6. View My Bookings\n";
        cout << "7. Cancel Booking\n";
        cout << "8. Logout\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            Vehicle vehicle;
            vehicle.inputVehicle(customer.getCustomerId());

            if (vehicle.getVehicleId() <= 0)
            {
                break;
            }

            bool duplicate = false;

            for (const Vehicle& existing : vehicles)
            {
                if (existing.getVehicleId() == vehicle.getVehicleId())
                {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate)
            {
                cout << "Vehicle ID already exists.\n";
            }
            else
            {
                vehicles.push_back(vehicle);
                cout << "Vehicle added successfully.\n";
            }

            break;
        }

        case 2:
        {
            bool found = false;

            for (const Vehicle& vehicle : vehicles)
            {
                if (vehicle.getOwnerCustomerId() ==
                    customer.getCustomerId())
                {
                    vehicle.displayVehicle();
                    found = true;
                }
            }

            if (!found)
            {
                cout << "You have not added any vehicles yet.\n";
            }

            break;
        }

        case 3:
        {
            if (admin.getStationCount() == 0)
            {
                cout << "No charging stations available.\n";
                break;
            }

            cout << "\n========== CHARGING STATIONS ==========\n";

            for (int i = 0; i < admin.getStationCount(); i++)
            {
                admin.getStation(i).displayStation();
            }

            break;
        }

        case 4:
        {
            int stationId;
            string date, time;

            cout << "Enter Station ID: ";
            cin >> stationId;

            if (!stationExists(admin, stationId))
            {
                cout << "Station not found.\n";
                break;
            }

            cout << "Enter Date (YYYY-MM-DD): ";
            cin >> date;

            cout << "Enter Time (HH:MM): ";
            cin >> time;

            showAvailableChargers(
                admin, bookings, stationId, date, time);

            break;
        }

        case 5:
        {
            int stationId, vehicleId, chargerId;
            string date, time;

            if (vehicles.empty())
            {
                cout << "Please add a vehicle before booking.\n";
                break;
            }

            cout << "Enter Station ID: ";
            cin >> stationId;

            if (!stationExists(admin, stationId))
            {
                cout << "Station not found.\n";
                break;
            }

            cout << "Enter your Vehicle ID: ";
            cin >> vehicleId;

            if (!vehicleBelongsToCustomer(
                    vehicles, vehicleId, customer.getCustomerId()))
            {
                cout << "Vehicle not found in your account.\n";
                break;
            }

            cout << "Enter Date (YYYY-MM-DD): ";
            cin >> date;

            cout << "Enter Time (HH:MM): ";
            cin >> time;

            cout << "\nAvailable chargers:\n";
            showAvailableChargers(
                admin, bookings, stationId, date, time);

            cout << "Enter Charger ID to book (0 to cancel): ";
            cin >> chargerId;

            if (chargerId == 0)
            {
                cout << "Booking cancelled.\n";
                break;
            }

            bool validCharger = false;

            for (int i = 0; i < admin.getChargerCount(); i++)
            {
                charger& ch = admin.getCharger(i);

                if (ch.getChargerId() == chargerId &&
                    ch.getStationId() == stationId &&
                    ch.checkAvailability() &&
                    !slotAlreadyBooked(
                        bookings, chargerId, date, time))
                {
                    validCharger = true;
                    break;
                }
            }

            if (!validCharger)
            {
                cout << "Charger unavailable or invalid selection.\n";
                break;
            }

            int bookingId = 1;

            for (const Booking& existing : bookings)
            {
                if (existing.getBookingId() >= bookingId)
                {
                    bookingId = existing.getBookingId() + 1;
                }
            }

            Booking booking;

            booking.createBooking(
                bookingId,
                customer.getCustomerId(),
                vehicleId,
                chargerId,
                date,
                time);

            bookings.push_back(booking);

            cout << "\nBooking successful!\n";
            cout << "Your Booking ID: " << bookingId << "\n";

            break;
        }

        case 6:
        {
            bool found = false;

            for (const Booking& booking : bookings)
            {
                if (booking.getCustomerId() == customer.getCustomerId())
                {
                    booking.displayBooking();
                    found = true;
                }
            }

            if (!found)
            {
                cout << "You have no bookings yet.\n";
            }

            break;
        }

        case 7:
        {
            int bookingId;
            bool found = false;

            cout << "Enter Booking ID to cancel: ";
            cin >> bookingId;

            for (Booking& booking : bookings)
            {
                if (booking.getBookingId() == bookingId &&
                    booking.getCustomerId() == customer.getCustomerId())
                {
                    booking.cancelBooking();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Your booking was not found.\n";
            }

            break;
        }

        case 8:
            cout << "Logging out...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 8);
}

int main()
{
    Admin admin;
    Maintenance maintenance;

    vector<Vehicle> vehicles;
    vector<Booking> bookings;

    int choice;

    do
    {
        cout << "\n===================================================================================";
        cout << "\n\n========================= EV CHARGING MANAGEMENT SYSTEM =========================";
        cout << "\n===================================================================================\n";

        cout << "\n1. Register Customer";
        cout << "\n2. Customer Login";
        cout << "\n3. Admin";
        cout << "\n4. Exit\n\n";

        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            Customer newCustomer;
            newCustomer.inputCustomer();

            bool duplicate = false;

            for (const Customer& existing : customers)
            {
                if (existing.getCustomerId() ==
                    newCustomer.getCustomerId())
                {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate)
            {
                cout << "Customer ID already exists.\n";
            }
            else
            {
                customers.push_back(newCustomer);
                cout << "Customer registered successfully.\n";
            }

            break;
        }

        
case 2:
{
    string enteredEmail, enteredPassword;
    bool loggedIn = false;

    cout << "\nEnter Email: ";
    cin >> enteredEmail;

    cout << "\nEnter Password: ";
    cin >> enteredPassword;

    for (Customer& customer : customers)
    {
        if (customer.login(enteredEmail, enteredPassword))
        {
            cout << "\nLogin Successful!\n";

            customerMenu(
                customer,
                admin,
                vehicles,
                bookings
            );

            loggedIn = true;
            break;
        }
    }

    if (!loggedIn)
    {
        cout << "Invalid email or password.\n";
    }

    break;
}


        case 3:
        {
            string enteredEmail;
            string enteredPassword;

            cout << "\nEnter Admin Email: ";
            cin >> enteredEmail;

            cout << "Enter Admin Password: ";
            cin >> enteredPassword;

            if (admin.login(enteredEmail, enteredPassword))
            {
                admin.displayMenu();
            }

            break;
        }

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
