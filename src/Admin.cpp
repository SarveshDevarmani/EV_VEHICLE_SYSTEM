#include "Admin.h"
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "charger.h"
#include "chargingStation.h"
#include "CustomerData.h"

using namespace std;

// ==================== CONSTRUCTOR ====================

Admin::Admin()
{
    adminId = 1;
    name = "Admin";
    email = "admin@123";
    password = "123";
    stationCount = 0;
}

// ==================== ADMIN LOGIN ====================

bool Admin::login(string email, string password)
{
    if (this->email == email && this->password == password)
    {
        cout << "Login Successful!" << endl;
        return true;
    }

    cout << "Invalid email or password." << endl;
    return false;
}

// ==================== ADMIN MENU ====================

void Admin::displayMenu()
{
    int choice;

    do
    {
        cout << "\n========== ADMIN MENU ==========" << endl;
        cout << "1. Manage Customers" << endl;
        cout << "2. Manage Stations" << endl;
        cout << "3. Manage Chargers" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number." << endl;
            continue;
        }

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

// ==================== CUSTOMER MANAGEMENT ====================

void Admin::manageCustomers()
{
    int choice;

    do
    {
        cout << "\n===== MANAGE CUSTOMERS =====\n";
        cout << "1. View All Customers\n";
        cout << "2. Search Customer by ID\n";
        cout << "3. Delete Customer by ID\n";
        cout << "4. Back to Admin Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\nDEBUG: View All Customers selected\n";
                viewAllCustomers();
                break;

            case 2:
            {
                int id;
                cout << "Enter Customer ID to search: ";
                cin >> id;
                searchCustomer(id);
                break;
            }

            case 3:
            {
                int id;
                cout << "Enter Customer ID to delete: ";
                cin >> id;
                deleteCustomer(id);
                break;
            }

            case 4:
                cout << "\nReturning to Admin Menu...\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 4);
}

void Admin::viewAllCustomers()
{
    cout << "DEBUG - Admin vector size: " << customers.size() << endl;
    if (customers.empty())
    {
        cout << "\nNo customers registered yet.\n";
        return;
    }

    cout << "\n===== ALL CUSTOMERS =====\n";

    for (const Customer& c : customers)
    {
        c.displayCustomer();
        cout << "-------------------------\n";
    }
}

void Admin::searchCustomer(int id)
{
    for (const Customer& c : customers)
    {
        if (c.getCustomerId() == id)
        {
            cout << "\n===== CUSTOMER FOUND =====\n";
            c.displayCustomer();
            return;
        }
    }

    cout << "\nCustomer not found!\n";
}

void Admin::deleteCustomer(int id)
{
    for (auto it = customers.begin(); it != customers.end(); ++it)
    {
        if (it->getCustomerId() == id)
        {
            customers.erase(it);
            cout << "\nCustomer deleted successfully!\n";
            return;
        }
    }

    cout << "\nCustomer not found!\n";
}

// ==================== CHARGER MANAGEMENT ====================

void Admin::ManageChargers()
{
    int choice;

    do
    {
        cout << "\n========== CHARGER MANAGEMENT ==========" << endl;
        cout << "1. Add Charger to Station" << endl;
        cout << "2. View Chargers of a Station" << endl;
        cout << "3. Update Charger Status" << endl;
        cout << "4. Check Charger Availability" << endl;
        cout << "5. Remove Charger" << endl;
        cout << "6. View All Chargers" << endl;
        cout << "7. Back to Admin Menu" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number." << endl;
            continue;
        }

        switch (choice)
        {
        // -------- 1. ADD CHARGER TO A STATION --------

        case 1:
        {
            if (stationCount == 0)
            {
                cout << "No stations exist. Add a station first." << endl;
                break;
            }

            int stationId;
            bool stationFound = false;

            cout << "Enter Station ID for the new charger: ";
            cin >> stationId;

            for (int i = 0; i < stationCount; i++)
            {
                if (stations[i].getStationId() == stationId)
                {
                    stationFound = true;
                    break;
                }
            }

            if (!stationFound)
            {
                cout << "Station not found. Charger cannot be added." << endl;
                break;
            }

            charger newCharger;
            newCharger.inputCharger();

            // Ensure the entered station ID matches the selected station.
            if (newCharger.getStationId() != stationId)
            {
                cout << "Station ID mismatch. Charger was not added." << endl;
                break;
            }

            bool chargerExists = false;

            for (int i = 0; i < static_cast<int>(chargers.size()); i++)
            {
                if (chargers[i].getChargerId() ==
                    newCharger.getChargerId())
                {
                    chargerExists = true;
                    break;
                }
            }

            if (chargerExists)
            {
                cout << "Charger ID already exists." << endl;
            }
            else
            {
                chargers.push_back(newCharger);
                cout << "Charger added successfully to Station "
                     << stationId << "." << endl;
            }

            break;
        }

        // -------- 2. VIEW CHARGERS OF A STATION --------

        case 2:
        {
            int stationId;
            bool stationFound = false;
            bool chargerFound = false;

            cout << "Enter Station ID: ";
            cin >> stationId;

            for (int i = 0; i < stationCount; i++)
            {
                if (stations[i].getStationId() == stationId)
                {
                    stationFound = true;
                    break;
                }
            }

            if (!stationFound)
            {
                cout << "Station not found." << endl;
                break;
            }

            cout << "\nChargers belonging to Station "
                 << stationId << ":" << endl;

            for (int i = 0; i < static_cast<int>(chargers.size()); i++)
            {
                if (chargers[i].getStationId() == stationId)
                {
                    chargers[i].displayCharger();
                    chargerFound = true;
                }
            }

            if (!chargerFound)
            {
                cout << "No chargers assigned to this station." << endl;
            }

            break;
        }

        // -------- 3. UPDATE CHARGER STATUS --------

        case 3:
        {
            int chargerId;
            int status;
            bool found = false;

            cout << "Enter Charger ID: ";
            cin >> chargerId;

            for (int i = 0; i < static_cast<int>(chargers.size()); i++)
            {
                if (chargers[i].getChargerId() == chargerId)
                {
                    cout << "Charger belongs to Station "
                         << chargers[i].getStationId() << endl;

                    cout << "Enter new status:" << endl;
                    cout << "1. Available" << endl;
                    cout << "0. Occupied" << endl;
                    cout << "Choice: ";
                    cin >> status;

                    if (status == 0 || status == 1)
                    {
                        chargers[i].updateStatus(status == 1);
                        cout << "Charger status updated successfully."
                             << endl;
                    }
                    else
                    {
                        cout << "Invalid status. Use 1 or 0." << endl;
                    }

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Charger not found." << endl;
            }

            break;
        }

        // -------- 4. CHECK CHARGER AVAILABILITY --------

        case 4:
        {
            int chargerId;
            bool found = false;

            cout << "Enter Charger ID: ";
            cin >> chargerId;

            for (int i = 0; i < static_cast<int>(chargers.size()); i++)
            {
                if (chargers[i].getChargerId() == chargerId)
                {
                    cout << "Station ID: "
                         << chargers[i].getStationId() << endl;

                    if (chargers[i].checkAvailability())
                    {
                        cout << "Charger is Available." << endl;
                    }
                    else
                    {
                        cout << "Charger is Occupied." << endl;
                    }

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Charger not found." << endl;
            }

            break;
        }

        // -------- 5. REMOVE CHARGER --------

        case 5:
        {
            int stationId;
            int chargerId;
            bool stationFound = false;
            bool chargerFound = false;

            cout << "Enter Station ID: ";
            cin >> stationId;

            for (int i = 0; i < stationCount; i++)
            {
                if (stations[i].getStationId() == stationId)
                {
                    stationFound = true;
                    break;
                }
            }

            if (!stationFound)
            {
                cout << "Station not found." << endl;
                break;
            }

            cout << "Enter Charger ID to remove: ";
            cin >> chargerId;

            for (int i = 0; i < static_cast<int>(chargers.size()); i++)
            {
                if (chargers[i].getChargerId() == chargerId &&
                    chargers[i].getStationId() == stationId)
                {
                    chargers.erase(chargers.begin() + i);
                    chargerFound = true;

                    cout << "Charger removed from Station "
                         << stationId << " successfully." << endl;
                    break;
                }
            }

            if (!chargerFound)
            {
                cout << "Charger not found under this station." << endl;
            }

            break;
        }

        // -------- 6. VIEW ALL CHARGERS --------

        case 6:
        {
            if (chargers.empty())
            {
                cout << "No chargers available." << endl;
                break;
            }

            cout << "\nTotal Chargers: " << chargers.size() << endl;

            for (int i = 0; i < static_cast<int>(chargers.size()); i++)
            {
                chargers[i].displayCharger();
            }

            break;
        }

        case 7:
            cout << "Returning to Admin Menu..." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 7);
}

// ==================== STATION MANAGEMENT ====================

void Admin::manageStations()
{
    int choice;

    do
    {
        cout << "\n========== MANAGE CHARGING STATIONS ==========" << endl;
        cout << "1. Add Station" << endl;
        cout << "2. View All Stations" << endl;
        cout << "3. Search Station by ID" << endl;
        cout << "4. Update Station Details" << endl;
        cout << "5. Delete Station" << endl;
        cout << "6. Back to Admin Menu" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number." << endl;
            continue;
        }

        switch (choice)
        {
        // -------- 1. ADD STATION AND TWO DEFAULT CHARGERS --------

        case 1:
        {
            if (stationCount >= 100)
            {
                cout << "Station storage is full." << endl;
                break;
            }

            chargingStation newStation;
            newStation.inputStation();

            int stationId = newStation.getStationId();
            bool exists = false;

            for (int i = 0; i < stationCount; i++)
            {
                if (stations[i].getStationId() == stationId)
                {
                    exists = true;
                    break;
                }
            }

            if (exists)
            {
                cout << "Station ID already exists." << endl;
                break;
            }

            // Find the next unused charger ID.
            int nextId = 1;

            for (int i = 0; i < static_cast<int>(chargers.size()); i++)
            {
                if (chargers[i].getChargerId() >= nextId)
                {
                    nextId = chargers[i].getChargerId() + 1;
                }
            }

            // Save the station and create its default chargers.
            stations[stationCount] = newStation;
            stationCount++;

            chargers.push_back(
                charger(nextId, stationId, "AC", 7.0)
            );

            chargers.push_back(
                charger(nextId + 1, stationId, "DC", 30.0)
            );

            cout << "Station added successfully." << endl;
            cout << "Two default chargers created:" << endl;
            cout << "Charger " << nextId
                 << " - AC, 7 kW" << endl;
            cout << "Charger " << nextId + 1
                 << " - DC, 30 kW" << endl;

            break;
        }

        // -------- 2. VIEW ALL STATIONS --------

        case 2:
        {
            if (stationCount == 0)
            {
                cout << "No stations available." << endl;
                break;
            }

            for (int i = 0; i < stationCount; i++)
            {
                stations[i].displayStation();

                cout << "Chargers at this station:" << endl;

                bool hasChargers = false;

                for (int j = 0; j < static_cast<int>(chargers.size()); j++)
                {
                    if (chargers[j].getStationId() ==
                        stations[i].getStationId())
                    {
                        chargers[j].displayCharger();
                        hasChargers = true;
                    }
                }

                if (!hasChargers)
                {
                    cout << "No chargers assigned." << endl;
                }
            }

            break;
        }

        // -------- 3. SEARCH STATION --------

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

                    cout << "\nChargers belonging to this station:"
                         << endl;

                    bool hasChargers = false;

                    for (int j = 0; j < static_cast<int>(chargers.size()); j++)
                    {
                        if (chargers[j].getStationId() == id)
                        {
                            chargers[j].displayCharger();
                            hasChargers = true;
                        }
                    }

                    if (!hasChargers)
                    {
                        cout << "No chargers assigned." << endl;
                    }

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

        // -------- 4. UPDATE STATION --------

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

        // -------- 5. DELETE STATION AND ITS CHARGERS --------

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
                    // Remove every charger assigned to this station.
                    for (int j = 0; j < static_cast<int>(chargers.size());)
                    {
                        if (chargers[j].getStationId() == id)
                        {
                            chargers.erase(chargers.begin() + j);
                        }
                        else
                        {
                            j++;
                        }
                    }

                    // Shift remaining stations to fill the empty position.
                    for (int j = i; j < stationCount - 1; j++)
                    {
                        stations[j] = stations[j + 1];
                    }

                    stationCount--;
                    found = true;

                    cout << "Station and its associated chargers deleted."
                         << endl;
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
