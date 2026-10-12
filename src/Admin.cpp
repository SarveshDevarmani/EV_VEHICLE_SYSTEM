#include "Admin.h"
#include <iostream>

using namespace std;

Admin::Admin()
{
    adminId = 1;
    name = "Admin";
    email = "admin@123";
    password = "123";
    stationCount = 0;
}

bool Admin::login(string email, string password)
{
    if (this->email == email && this->password == password)
    {
        cout << "Login Successful" << endl;
        return true;
    }

    cout << "Invalid email or password" << endl;
    return false;
}

void Admin::displayMenu()
{
    int choice;

    do
    {
        cout << "\n===== Admin Menu =====" << endl;
        cout << "1. Manage Customers" << endl;
        cout << "2. Manage Stations" << endl;
        cout << "3. Manage Chargers" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            manageCustomers();
            break;

        case 2:
            manageStations();
            break;

        case 3:
            ManageChargers();
            break;

        case 4:
            cout << "Exiting Admin Menu..." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 4);
}

void Admin::manageCustomers()
{
    cout << "Customer Management Selected." << endl;
}

void Admin::ManageChargers()
{
    cout << "Charger Management Selected." << endl;
}

void Admin::manageStations()
{
    int choice;

    do
    {
        cout << "\n===== Manage Charging Stations =====" << endl;
        cout << "1. Add Station" << endl;
        cout << "2. View All Stations" << endl;
        cout << "3. Search Station by ID" << endl;
        cout << "4. Update Station Details" << endl;
        cout << "5. Delete Station" << endl;
        cout << "6. Back to Admin Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (stationCount >= 100)
            {
                cout << "Station storage is full." << endl;
                break;
            }

            chargingStation newStation;
            newStation.inputStation();

            bool exists = false;

            for (int i = 0; i < stationCount; i++)
            {
                if (stations[i].getStationId() ==
                    newStation.getStationId())
                {
                    exists = true;
                    break;
                }
            }

            if (exists)
            {
                cout << "Station ID already exists." << endl;
            }
            else
            {
                stations[stationCount] = newStation;
                stationCount++;

                cout << "Station added successfully." << endl;
            }

            break;
        }

        case 2:
            if (stationCount == 0)
            {
                cout << "No stations available." << endl;
            }
            else
            {
                for (int i = 0; i < stationCount; i++)
                {
                    stations[i].displayStation();
                }
            }

            break;

        case 3:
        {
            int id;
            bool found = false;

            cout << "Enter Station ID to search: ";
            cin >> id;

            for (int i = 0; i < stationCount; i++)
            {
                if (stations[i].getStationId() == id)
                {
                    stations[i].displayStation();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Station not found." << endl;
            }

            break;
        }

        case 4:
        {
            int id;
            bool found = false;

            cout << "Enter Station ID to update: ";
            cin >> id;

            for (int i = 0; i < stationCount; i++)
            {
                if (stations[i].getStationId() == id)
                {
                    stations[i].updateStationDetails();

                    cout << "Station updated successfully." << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Station not found." << endl;
            }

            break;
        }

        case 5:
        {
            int id;
            bool found = false;

            cout << "Enter Station ID to delete: ";
            cin >> id;

            for (int i = 0; i < stationCount; i++)
            {
                if (stations[i].getStationId() == id)
                {
                    for (int j = i; j < stationCount - 1; j++)
                    {
                        stations[j] = stations[j + 1];
                    }

                    stationCount--;
                    found = true;

                    cout << "Station deleted successfully." << endl;
                    break;
                }
            }

            if (!found)
            {
                cout << "Station not found." << endl;
            }

            break;
        }

        case 6:
            cout << "Returning to Admin Menu..." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 6);
}
